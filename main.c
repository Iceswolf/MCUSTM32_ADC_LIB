#include <stdio.h>
#include <stdlib.h>
#include <clock.c>
#include <config.c>
#include <adc.c>

int adc_result(int canale,char *a);

void main (void){

  
attiva_clock(1,'a');
attiva_clock(2,'a');

gpio_config('a',0,"analog","default","default","default");


double risultato;

while(1){  
  risultato=adc_result(0,"on");
    printf("%lf \n",risultato/4095);
  }
}