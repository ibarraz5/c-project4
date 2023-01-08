/********************************************************
 *
 * SER486 Assignment 4
 * Ivan Barraza Duran
 *
 * implemented provide support for using the internal temperature sensor
 * of the Atmega328p
 *
 * void temp_init();
 * int temp_is_data_ready();
 * void temp_start();
 * long temp_get();
 */


#define ADMUX (*((volatile char *)0x7C))
#define ADCSRA (*((volatile char *)0x7A))
#define ADCL (*((volatile char *)0x78))
#define ADCH (*((volatile char *)0x79))



void temp_init(){
    ADMUX = 0xC8; // Internal Voltage Reference (1.1v) and Internal Temp sensor
}

/*
temp_start()
This code starts the conversion process of the ADC
returns:
    nothing
changes:
    Changes the ADCSRA register
*/
void temp_start(){
    // set the prescalar to 64
    ADCSRA |= 0x06;

    // enable the ADC by setting bit 7 of ADCSRA
    ADCSRA |= 0x80;

    // start the conversion by setting bit 6 of ADCSRA to 1
    ADCSRA |= 0x40;

}

/*
temp_is_data_ready()
This code checks the status of the ADC conversion.
returns:
    int:
        0 if the ADC is still converting
        1 if the ADC is done converting
changes:
*/
int temp_is_data_ready(){
    int status = (ADCSRA & 0x40) >> 6;
    return status == 0;
}


/*
temp_get()
This returns the current internal temperature in degrees Celsius from the ADC.
returns:
    long - The internal temperature reading from the ADC
changes:
*/
long temp_get(){
    long cur_adcl = ADCL & 0x00FF;
    long cur_adch = ADCH << 8;
    long reading = cur_adcl | cur_adch;
    long  degrees = (long)((reading * 101.0/100.0)) - 273.0;
    return degrees;
}