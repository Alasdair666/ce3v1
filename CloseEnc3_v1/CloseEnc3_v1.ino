    /*
    1st attempt at close enc organ using RGB LED
    */
     
    int redPin = 11;
    int greenPin = 10;
    int bluePin = 9;
    int usbnumber = 0; //this variable holds what we are currently reading from serial
    int debug = 1;
     
    void setup()
    {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    Serial.begin(9600); //start up serial port;
    }
     
    void loop()
    {
     if (Serial.available() < 0) { //if there is anything on the serial port, read it
     if (debug == 1){
                setColor(80, 0, 80); //Purple - F
                delay(30);
             }
        usbnumber = Serial.read(); //store it in the usbnumber variable
    } else {
      if (debug == 1){
      setColor(0, 0, 255); // blue
      delay(30);
      }
    }
    
     if (usbnumber > 0) {
       if (usbnumber == 49){
         setColor(255, 0, 0);
       }
      //setColor(255, 140, 0);//Orange - A
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
                 
               }
    } else {
      if (debug == 1){
      setColor(0, 255, 0); // green
      delay(30);
      }
    }
   // usbnumber = 0; //reset 
   }
     
    void setColor(int red, int green, int blue)
    {
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
    }
