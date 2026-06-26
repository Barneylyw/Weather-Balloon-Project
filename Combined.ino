#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> // Must include Wire library for I2C
#include <SFE_MMA8452Q.h> // Includes the SFE_MMA8452Q library
#include <SPI.h> //Data logger
#include <SD.h> //Data logger
#include <RTClib.h>

const int chipSelect = 4;

RTC_DS3231 rtc;

File dataFile;
DateTime now;


// Begin using the library by creating an instance of the MMA8452Q
//  class. We'll call it "accel". That's what we'll reference from
//  here on out.
MMA8452Q accel;

// The setup function simply starts serial and initializes the
//  accelerometer.

#define ONE_WIRE_BUS 8

#define VCC2  5 // define pin 5 or any other digial pin here as VCC2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  sensors.begin();
  Serial.begin(9600);
  Serial.println("Combined Test Code!");
  
  pinMode(VCC2,OUTPUT);//define a digital pin as output
  digitalWrite(VCC2, HIGH);// set the above pin as HIGH so it acts as 5V

  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1) ;
  }
  Serial.println("card initialized.");
  
  dataFile = SD.open("datalog.txt", FILE_WRITE);

  // Open up the file we're going to log to!
  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (! dataFile) {
    Serial.println("error opening datalog.txt");
    // Wait forever since we cant write data
    while (1) ;
  }

  
  // Choose your adventure! There are a few options when it comes
  // to initializing the MMA8452Q:
  //  1. Default init. This will set the accelerometer up
  //     with a full-scale range of +/-2g, and an output data rate
  //     of 800 Hz (fastest).
  accel.init();
  //  2. Initialize with FULL-SCALE setting. You can set the scale
  //     using either SCALE_2G, SCALE_4G, or SCALE_8G as the value.
  //     That'll set the scale to +/-2g, 4g, or 8g respectively.
  //accel.init(SCALE_4G); // Uncomment this out if you'd like
  //  3. Initialize with FULL-SCALE and DATA RATE setting. If you
  //     want control over how fast your accelerometer produces
  //     data use one of the following options in the second param:
  //     ODR_800, ODR_400, ODR_200, ODR_100, ODR_50, ODR_12,
  //     ODR_6, or ODR_1. 
  //     Sets to 800, 400, 200, 100, 50, 12.5, 6.25, or 1.56 Hz.
  //accel.init(SCALE_8G, ODR_6);
}

void loop() {
  print_serial();

  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("\t");
    Serial.println("Successfully opened datalogger");
    dataFile.print(accel.cx, 3);
    dataFile.print("\t");
    dataFile.print(accel.cy, 3);
    dataFile.print("\t");
    dataFile.print(accel.cz, 3);
    dataFile.print("\t");
    byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    dataFile.print("Portrait Up");
    break;
  case PORTRAIT_D:
    dataFile.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    dataFile.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    dataFile.print("Landscape Left");
    break;
  case LOCKOUT:
    dataFile.print("Flat");
    break;
  }
    dataFile.print("    ");
    dataFile.print(Celsius);
    dataFile.print(" C  ");
    dataFile.print(Fahrenheit);
    dataFile.println(" F");
    dataFile.print("    ");
    dataFile.print(now.hour());
    dataFile.print(":");
    dataFile.print(now.minute());
    dataFile.print(":");
    dataFile.print(now.second());
    
    dataFile.flush();
    dataFile.close();
    delay(1000);
  }


  else {
    Serial.println("error opening datalog.txt");
  }
}

// temperature sensor function
void temp() {
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  Serial.print(Celsius);
  Serial.print(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");

}

void print_serial(){
// Use the accel.available() function to wait for new data
  //  from the accelerometer.
  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();
    
    // accel.read() will update two sets of variables. 
    // * int's x, y, and z will store the signed 12-bit values 
    //   read out of the accelerometer.
    // * floats cx, cy, and cz will store the calculated 
    //   acceleration from those 12-bit values. These variables 
    //   are in units of g's.
    // Check the two function declarations below for an example
    // of how to use these variables.
    printCalculatedAccels();
    //printAccels(); // Uncomment to print digital readings
    
    // The library also supports the portrait/landscape detection
    //  of the MMA8452Q. Check out this function declaration for
    //  an example of how to use that.
    printOrientation();
    
    Serial.println(); // Print new line every time.
  temp();
  delay(1000);
  }
}

// The function demonstrates how to use the accel.x, accel.y and
//  accel.z variables.
// Before using these variables you must call the accel.read()
//  function!
void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.cx, accel.cy,
//  and accel.cz variables.
// Before using these variables you must call the accel.read()
//  function!
void printCalculatedAccels()
{ 
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.readPL()
// function, which reads the portrait/landscape status of the
// sensor.
void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}

