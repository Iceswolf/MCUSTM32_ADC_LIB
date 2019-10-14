#define ADC_SR    (unsigned int*) (0x40012000) //status register controllare il bit 1 per interrupt fine lettura!
#define fine_let  (unsigned int)  (1<<1)

#define ADC1_CR1  (unsigned int*) (0x40012004) //control register 1
#define EOCIE     (unsigned int)  (1<<5)       //abilitazione interrupt

#define ADC1_CR2  (unsigned int*) (0x40012008) //control register 2 
#define CONT      (unsigned int)  (1<<1)       //conversione continua
#define SWSTART   (unsigned int)  (1<<30)      //inizia conversione
#define ADCON     (unsigned int)  (1<<0)       //accendi l'adc

#define ADC_SMPR1 (unsigned int*) (0x4001200c)
#define ADC_SMPR2 (unsigned int*) (0x40012010)
#define SMP       (unsigned int)  (1<<0)       //sampling time individually for each channel 15 cicli

#define ADC_SQR1  (unsigned int*) (0x4001202c) //These bits are written by software with the channel number (0..18)
#define ADC_SQR2  (unsigned int*) (0x40012030) //assigned as the xxth in the conversion sequence.     
#define ADC_SQR3  (unsigned int*) (0x40012034)

#define ADC_DR    (unsigned int*) (0x4001204c) //dove vengono conservati i dati  DATA[15:0]: Regular data

int adc_result(int canale, char *a);
int adc_result(int canale, char *a){
unsigned int* puntatore;
int valore =0;
unsigned int temp;

if(a=="on"){
puntatore=ADC1_CR2;

*puntatore&=3;
if(*puntatore != 3){
*puntatore |= ADCON;
*puntatore |= CONT;
}

puntatore=ADC_SQR3;
*puntatore=canale;

puntatore=ADC1_CR2;
temp= (*puntatore)& SWSTART;
if(temp != SWSTART){
*puntatore |= SWSTART;
}
puntatore=ADC_SR;

  if(*puntatore==0x12){
    puntatore=ADC_DR;
    valore=(*puntatore);
    printf("%d \n",valore);  

    }
  }
else if(a=="off"){
puntatore=ADC1_CR2;
*puntatore &=~(ADCON);
  }
return(valore);
}