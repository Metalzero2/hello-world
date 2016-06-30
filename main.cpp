#include <ZerooneSupermodifiedRoboLab.h>
//#include <ZerooneSupermodified.h>
#include <Wire.h>

ZerooneSupermodifiedRoboLab motor (ZO_HW_SERIAL_1,13);   //  Motor  RS485 Uart ayarlarý 
int pin = 50;
int8_t toggle1=0;
int id=4;
boolean dataIsHere = false;
boolean noInterrupt = false;
int32_t temp1;

//******************************************************************************************************************
void setup() 
{

  Serial.begin(115200);
  Serial1.begin(57600);
  pinMode(pin, OUTPUT);
  pinMode(pin, LOW);


// START --- Set timer1 interrupt at 10Hz

  cli();//stop interrupts
  
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  
  TCCR1B |= (1 << WGM12); // turn on CTC mode  
  TCCR1B |= (1 << CS12); // Set CS10 and CS12 bits for 256 prescaler 
  
  // set compare match register for 1hz increments
  OCR1A = 62500;// = (16*10^6) / (256*1) - 1 (must be <65536)
  
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  
  sei();//start p interrupts
  
// END --- Set timer1 interrupt at 10Hz

//  WDTCSR |= _BV(WDCE);
//  WDTCSR &= ~( _BV(WDE) );
}


//******************************************************************************************************************
void loop() 
{
//  temp1 = motor.getAbsolutePosition(id);
//  Serial.println(temp1);
/*
  if(dataIsHere)
  {
    temp1 = motor.getAbsolutePosition(id);
    Serial.println(temp1);
    dataIsHere = false;
    noInterrupt = false;
  }*/
;
}






//******************************************************************************************************************
ISR(TIMER1_COMPA_vect)
{
  //WDTCSR |= _BV(WDIE);
  temp1 = motor.getAbsolutePosition(id);
  Serial.println(temp1);
//  

/*
  if(noInterrupt == false)
  {
    if (toggle1)
    {
      digitalWrite(pin,HIGH);
      toggle1 = 0;
    }
    else
    {
      digitalWrite(pin,LOW);
      toggle1 = 1;
    }
    dataIsHere = true;
    noInterrupt = true;
  }
*/
}
