/*
 * utlits.h
 *
 * Created: 8/1/2023 5:51:23 PM
 *  Author: DELL
 */ 


#ifndef UTLITS_H_
#define UTLITS_H_

#define setbit(reg,bit) (reg|=(1<<bit))

#define clearbit(reg,bit) (reg&=~(1<<bit))

#define togglebit(reg,bit) (reg^=(1<<bit))

 

#endif /* UTLITS_H_ */