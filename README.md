 Weather Balloon Project

To send a payload containing gps, electronics, and camera to altitude of ~30km via a weather balloon

![idea of how everything is connected](weather balloons.png)
Diagram 1: Image visualization of how the payload is connected to the weather balloon via a parachute

--Overall design Considerations--
- Legal under Canadian law
> Under 4kg
> Balloon must be under 115 cu. ft according to Canadian Aviation Regulations 602.42
- Reach 30km

Data Collection System

We used SFE_MMA8452Q for data collection module alongside a SD card module controlled by an Arduino Uno.

I wired the SFE_MMA8452Q and SD card module to Arduino Uno according to online guides and modified the example code to write data to the SD card. 
