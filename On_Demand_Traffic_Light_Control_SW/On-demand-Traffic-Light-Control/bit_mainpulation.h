/*
 * bit_mainpulation.h
 *
 * Created: 10/9/2022 11:23:48 PM
 *  Author: 20109
 */ 


#ifndef BIT_MAINPULATION_H_
#define BIT_MAINPULATION_H_

#define PORT_MASK                  0XFF
#define BIT_MASK                   (uint8)1

#define SET_BIT(REG, BIT_POS)       (REG |= (BIT_MASK << BIT_POS))
#define CLEAR_BIT(REG, BIT_POS)     (REG &= ~(BIT_MASK << BIT_POS))
#define TOG_BIT(REG, BIT_POS)       (REG ^= (BIT_MASK << BIT_POS))
#define READ_BIT(REG, BIT_POS)      ((REG >> BIT_POS) & BIT_MASK)



#endif /* BIT_MAINPULATION_H_ */