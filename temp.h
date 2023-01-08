/*
 *
 * this file provides function declarations for Atmega328P
 * internal temperature funcitonality
 *
 * Ivan Barraza Duran
 * SER486 HW4
 *
 */

#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED


void temp_init(); // initializes registers for reading internal temp using ADC 

int temp_is_data_ready(); // checks whether the ADC conversion is complete 

void temp_start(); // starts an ADC conversion to get the internal temp 

long temp_get(); // return the temperature obtained from the ADC 



#endif 