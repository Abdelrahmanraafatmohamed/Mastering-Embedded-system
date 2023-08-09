/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Abdelrahman Raafat Mohamed
 */

#include "Stm32_F103C6_GPIO_Driver.h"

uint8_t GET_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}

/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-Initializes GPIOX PINy according to the specified parameters in the PinConfig
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param[in] 	-PinConfig pointer to a GPIO_PinConfig_t structure that contains
 *				 the configuration information for the specified GPIO PIN.
 * @retval		-none
 * Note			-Stm32F103C6 MCU has GPIO A,B,C,D Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */

void MCAL_GPIO_Init (GPIO_TypeDef* GPIOX , GPIO_PinConfig_t* pinconfig)
{
	//Port configuration register low (GPIOx_CRL) Configure PINS from 0 >>> 7
	//Port configuration register High (GPIOx_CRH) Configure PINS from 8 >>> 15
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config = 0;

	configregister = (pinconfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOX->CRL : &GPIOX->CRH;

	// clear CNF8[1:0] MODE8[1:0]
	(*configregister) &=~(0Xf << GET_CRLH_Position(pinconfig->GPIO_PinNumber));

	//if pin is output
	if((pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)||(pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)||(pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)||(pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		// set CNF8[1:0] MODE[1:0]
		PIN_Config = (((pinconfig->GPIO_MODE - 4 << 2) | (pinconfig->GPIO_Output_Speed)) & 0x0F);


	}
	//IF pin is input
	else // MODE = 00: INPUT mode (reset state)
	{
		if((pinconfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (pinconfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			//set CNF8[1:0] MODE[1:0]00
			PIN_Config = (((pinconfig->GPIO_MODE  << 2) | (0x0)) & 0x0F);
		}else if (pinconfig->GPIO_MODE == GPIO_MODE_AF_INPUT)  //consider it as input floating
		{
			//set CNF8[1:0] MODE[1:0]00
			PIN_Config = (((pinconfig->GPIO_MODE  << 2) | (0x0)) & 0x0F);
		}
		else //PU PD Input
		{
			PIN_Config = ((((GPIO_MODE_INPUT_PU)  << 2) | (0x0)) & 0x0F);
			if (pinconfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//PxODR = 1 Input Pull up : table 20. port bit configuration table
				GPIOX->ODR |= pinconfig->GPIO_PinNumber;

			}
			else
			{
				//PxODR = 1 Input Pull up : table 20. port bit configuration table
				GPIOX->ODR &= ~(pinconfig->GPIO_PinNumber);

			}

		}
	}  // write on CRL OR CRH
	(*configregister) |= ((PIN_Config)<< GET_CRLH_Position(pinconfig->GPIO_PinNumber));
}

/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-Reset all GPIO Registers
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval		-none
 * Note			-none
 */

void MCAL_GPIO_DeInit (GPIO_TypeDef* GPIOX)
{
	//GPIOX->BRR = 0x00000000;
	// GPIOX->BSRR= 0x00000000;
	// GPIOX->CRH= 0x44444444;
	// GPIOX->CRL =0x44444444;
	// GPIOX->IDR =; (Read only)
	// GPIOX->LCKR= 0x00000000;
	// GPIOX->ODR= 0x00000000;


	//or you can use the reset controller
	//APB2 peripherals reset register (RCC APB2RSTR)
	//Set and cleared by software
	if(GPIOX == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);  // Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if (GPIOX == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);  // Bit 3 IOPARST: IO port B reset
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOX == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);  // Bit 4 IOPARST: IO port C reset
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOX == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);  // Bit 5 IOPARST: IO port D reset
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOX == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);  // Bit 6 IOPARST: IO port E reset
		RCC->APB2RSTR &= ~(1<<6);
	}


}
/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Read Specific PIN
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param[in]	-PinNumber: Set pin number according @ref GPIO_PINS_define
 * @retval		-The input pin value (two values based on @ref GPIO_PIN_state )
 * Note			-none
 */

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOX , uint16_t PinNumber)
{
	uint8_t bitstatus;
	if (((GPIOX->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus ;
}

/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief 		-Read the input port value
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 *
 * @retval		-The input port value
 * Note			-none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOX )
{
	uint16_t port_value;
	port_value = (uint16_t)(GPIOX->IDR);
	return port_value;
}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-Write on specific input pin
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param[in]	-PinNumber: Specific the port bit to read. set by @ref GPIO_PINS_define
 * @param[in]	-Value: Pin value
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOX , uint16_t PinNumber, uint8_t value)
{

	if (value != GPIO_PIN_RESET)
	{
		//GPIOX->ODR |=PinNumber;
		//OR
		//Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOX->BSRR =(uint32_t)PinNumber ;
	}
	else
	{
		//BRy: Port x Reset bit y (y= 0 .. 15)
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOX->BRR=(uint32_t)PinNumber;
	}

}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-Write on output port
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOX , uint16_t value)
{
	GPIOX->ODR = (uint32_t)value;
}
/**================================================================
 * @Fn			-MCAL_GPIO_togglePin
 * @brief 		-toggle on specified GPIO pin
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param[in]	-PinNumber: Specific the port bit to read. set by @ref GPIO_PINS_define
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_togglePin(GPIO_TypeDef* GPIOX , uint16_t PinNumber)
{
	GPIOX->ODR ^= (PinNumber);
}
/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief 		-the locking mechanism allows the IO configuration to be forzen
 * @param[in]	-GPIOx: where x can be (A..E depending on device used) to select the GPIO Peripheral
 * @param[in]	-PinNumber: Specific the port bit to read. set by @ref GPIO_PINS_define
 * @retval		-Ok if pin Config is locked or ERROR if pin not locked (ok & error are defined @ref GPIO_RETURN_LOCK)
 * Note			-none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOX , uint16_t PinNumber)
{
	//Bit 16 LCKK[16]: Lock key
	//This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//0: Port configuration lock key not active
	//1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//LOCK key writing sequence:
	//Write 1
	//Write 0
	//Write 1
	//Read 0
	//Read 1 (this read is optional but confirms that the lock is active)
	//Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//Any error in the lock sequence will abort the lock.
	//Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//These bits are read write but can only be written when the LCKK bit is 0.
	//0: Port configuration not locked
	//1: Port configuration locked.

	// set LCKK[16]
	volatile uint32_t tmp = 1<<16;
	//set the LCKy
	tmp |=PinNumber;
	//Write 1
	GPIOX->LCKR =tmp;
	//Write 0
	GPIOX->LCKR = PinNumber;
	//Write 1
	GPIOX->LCKR =tmp;
	//Read 0
	tmp=GPIOX->LCKR ;
	//Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOX->LCKR & 1<<16))
	{

		return GPIO_RETURN_LOCK_Enabled;
	}else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}
}

