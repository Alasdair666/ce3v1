    /*
    1st attempt at close enc organ using RGB LED
    */
     
    int redPin = 11;
    int greenPin = 10;
    int bluePin = 9;
    int usbnumber = 0; //this variable holds what we are currently reading from serial
     
    void setup()
    {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(9600); //start up serial port;
    }
     
    void loop()
    {
     if (Serial.available() > 0) { //if there is anything on the serial port, read it
       usbnumber = Serial.read(); //store it in the usbnumber variable
    }
    
     if (usbnumber > 0) {
         switch(usbnumber){
                 case 49:  setColor(255, 0, 0); //red - G
                   break;
                 case 50:  setColor(255, 140, 0);//Orange - A
                   break;
                 case 51:  setColor(80, 0, 80); //Purple - F
                   break;
                 case 52:  setColor(255, 255, 0); //Yellow - F an octave lower
                   break;
                 case 53:  setColor(250, 250, 250); // White - C
                   break;
                 case 54:  setColor(0, 0, 0); // off
                   break;
               }
    }
    
   }
     
    void setColor(int red, int green, int blue)
    {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
    }
