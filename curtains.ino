//TMP36 Pin Variables
int temperaturePin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade 
                        //(500 mV offset) to make negative temperatures an option
                        
int led_blue = 13;

int led_red = 12;


/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor                       
                       //last button beneath the file bar (looks like a box with an antenae)
}
 
void loop()                     // run over and over again
{
  
 float temperature = getVoltage(temperaturePin);  //getting the voltage reading from the temperature sensor
 temperature = (((temperature - .5) * -100)* 1.8) + 32;  
 //converting from 10 mv per degree wit 500 mV offset
                                                  //to degrees ((volatge - 500mV) times 100)
  Serial.println(temperature);                     //printing the result
  
  if(temperature < 70.00)
  {
    digitalWrite(led_red, LOW); // I am turning this one on
    digitalWrite(led_blue, HIGH); 
  }
  
  if (temperature > 80)
  {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_blue, LOW);
    
  }
else
  {
    digitalWrite(led_red, LOW); 
    digitalWrite(led_blue, LOW); 
  }
 

  
}

                                   //waiting a second


/*
 * getVoltage() - returns the voltage on the analog input defined by
 * pin
 */
float getVoltage(int pin){
 return (analogRead(pin) * .004882814); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

