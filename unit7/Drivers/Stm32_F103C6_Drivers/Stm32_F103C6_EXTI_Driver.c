/*
 * Stm32_F103C6_EXTI_Driver.c
 *
 *  Created on: Aug 6, 2023
 *      Author: Abdelrahman Raafat Mohamed
 */

#include "Stm32_F103C6_EXTI_Driver.h"
#include "Stm32_F103C6_GPIO_Driver.h"

/**================================================================
 *						Generic Variables
 *===================================================================
 */
void (* GP_IRQ_Callback[15])(void);

/**================================================================
 *						Generic Macros
 *===================================================================
 */
#define AFIO_GPIO_EXTI_Mapping(x)   (   (x==GPIOA)?0:\
		                                (x==GPIOB)?1:\
				                        (x==GPIOC)?2:\
						                (x==GPIOD)?3:0  )

/**================================================================
 *						Generic Functions
 *===================================================================
 */
void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;

	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}

}

void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
		{
		case 0:
			NVIC_IRQ6_EXTI0_Disable;
			break;
		case 1:
			NVIC_IRQ7_EXTI1_Disable;
			break;
		case 2:
			NVIC_IRQ8_EXTI2_Disable;
			break;
		case 3:
			NVIC_IRQ9_EXTI3_Disable;
			break;
		case 4:
			NVIC_IRQ10_EXTI4_Disable;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_Disable;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI10_15_Disable;
			break;
		}

}

void update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//1- Configure GPIO to be AF Input -> Floating Input
	GPIO_PinConfig_t PinCfg;
	//Update the GPIO Pin to be Floating Input
	PinCfg.GPIO_PinNumber= EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO ;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCfg);
	//===================================================================

	//2- UPDATE AFIO to Route between EXTI line with Port A , B ,C ,D
	uint8_t AFIO_EXTICR_Index = EXTI_Config->EXTI_PIN.EXTI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber % 4)/4 ;

	//Clear the Four bit
	AFIO->EXTICR[AFIO_EXTICR_Index] &= ~(0xF << AFIO_EXTICR_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port)&0xF) << AFIO_EXTICR_Position);
	//=======================================================================================================

	//3- Update Rising or falling register
	EXTI->RTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RASING)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RASING_FALLING)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	//=======================================================================================================
	//4- Update IRQ Handling CALLback
	GP_IRQ_Callback[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_Callback;

	//=======================================================================================================
	//5- Enable/Disable IRQ
	if (EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |=(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Enable_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	}else
	{
		EXTI->IMR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	}


}


/**================================================================
 *						APIS Functions Definition
 *===================================================================
 */

/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_DeInit
 * @brief 		-Reset all EXTI Registers and NVIC corresponding IRQ Mask
 * @retval		-none
 * Note			-none
 */
void MCAL_EXTI_GPIO_DeInit (void)
{
	EXTI->EMR= 		0x00000000;
	EXTI->FTSR= 	0x00000000;
	EXTI->RTSR= 	0x00000000;
	EXTI->IMR= 		0x00000000;
	EXTI->SWIER= 	0x00000000;

	//rc_w1 cleared by writing "1" into  PR
	EXTI->PR= 	0xFFFFFFFF;

	//Disable EXTI IRQ From NVIC
	NVIC_IRQ6_EXTI0_Disable      ;
	NVIC_IRQ7_EXTI1_Disable  	  ;
	NVIC_IRQ8_EXTI2_Disable  	  ;
	NVIC_IRQ9_EXTI3_Disable  	  ;
	NVIC_IRQ10_EXTI4_Disable  	  ;
	NVIC_IRQ23_EXTI5_9_Disable   ;
	NVIC_IRQ40_EXTI10_15_Disable ;


}


/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief 		-this is used to Initializes EXTI from specific GPIO pin and specify the mask/trigger condition and IRQ callback
 * @param[in]	-EXTI_Config: set by @ref EXTI_define , @ref EXTI_Trigger_define , @ref EXTI_IRQ_define
 * @retval		-none
 * Note			-Stm32F103C6 MCU has GPIO A,B,C,D Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * 				 also mandatory to enable RCC clock for AFIO and corresponding GPIO
 */

void MCAL_EXTI_GPIO_Init (EXTI_PinConfig_t* EXTI_Config)
{
	update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn			-MCAL_EXTI_GPIO_Init
 * @brief 		-this is used to Initializes EXTI from specific GPIO pin and specify the mask/trigger condition and IRQ callback
 * @param[in]	-EXTI_Config: set by @ref EXTI_define , @ref EXTI_Trigger_define , @ref EXTI_IRQ_define
 * @retval		-none
 * Note			-Stm32F103C6 MCU has GPIO A,B,C,D Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 * 				 also mandatory to enable RCC clock for AFIO and corresponding GPIO
 */

void MCAL_EXTI_GPIO_update (EXTI_PinConfig_t* EXTI_Config)
{
	update_EXTI(EXTI_Config);
}


/**================================================================
 *						ISR Functions
 *===================================================================
 */

void EXTI0_IRQHandler(void)
{
	// cleared by  written "1"  into the bit pending register (EXTI_PR)
	EXTI->PR |= 1<<0 ;
	// CALL IRQ CALL
	GP_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void)
{
	// cleared by  written "1"  into the bit pending register (EXTI_PR)
	EXTI->PR |= 1<<1 ;
	// CALL IRQ CALL
	GP_IRQ_Callback[1]();
}

void EXTI2_IRQHandler(void)
{
	// cleared by  written "1"  into the bit pending register (EXTI_PR)
	EXTI->PR |= 1<<2 ;
	// CALL IRQ CALL
	GP_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void)
{
	// cleared by  written "1"  into the bit pending register (EXTI_PR)
	EXTI->PR |= 1<<3 ;
	// CALL IRQ CALL
	GP_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void)
{
	// cleared by  written "1"  into the bit pending register (EXTI_PR)
	EXTI->PR |= 1<<4 ;
	// CALL IRQ CALL
	GP_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if (EXTI->PR & 1<<5) {EXTI->PR |= (1<<5)  ;  GP_IRQ_Callback[5]();}
	if (EXTI->PR & 1<<6) {EXTI->PR |= (1<<6)  ;  GP_IRQ_Callback[6]();}
	if (EXTI->PR & 1<<7) {EXTI->PR |= (1<<7)  ;  GP_IRQ_Callback[7]();}
	if (EXTI->PR & 1<<8) {EXTI->PR |= (1<<8)  ;  GP_IRQ_Callback[8]();}
	if (EXTI->PR & 1<<9) {EXTI->PR |= (1<<9)  ;  GP_IRQ_Callback[9]();}
}

void EXTI15_10_IRQHandler(void)
{
	if (EXTI->PR & 1<<10) {EXTI->PR |= (1<<10)  ;  GP_IRQ_Callback[10]();}
	if (EXTI->PR & 1<<11) {EXTI->PR |= (1<<11)  ;  GP_IRQ_Callback[11]();}
	if (EXTI->PR & 1<<12) {EXTI->PR |= (1<<12)  ;  GP_IRQ_Callback[12]();}
	if (EXTI->PR & 1<<13) {EXTI->PR |= (1<<13)  ;  GP_IRQ_Callback[13]();}
	if (EXTI->PR & 1<<14) {EXTI->PR |= (1<<14)  ;  GP_IRQ_Callback[14]();}
	if (EXTI->PR & 1<<15) {EXTI->PR |= (1<<15)  ;  GP_IRQ_Callback[15]();}
}









