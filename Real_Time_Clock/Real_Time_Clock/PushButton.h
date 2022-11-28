/*
 * PushButton.h
 *
 * Created: 11/16/2022 9:35:58 PM
 *  Author: osama
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_

void BUTTON_INIT(unsigned char port, unsigned char pin);
unsigned char BUTTON_READ(unsigned char port, unsigned char pin);


#endif /* PUSHBUTTON_H_ */