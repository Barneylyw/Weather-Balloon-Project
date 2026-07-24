Weather Balloon Project

To send a payload containing gps, electronics, and camera to altitude of ~30km via a weather balloon

<img width="1200" height="900" alt="weather balloon" src="https://github.com/user-attachments/assets/5f28afc6-eaf3-41f5-9c44-c16992499a6c" />
Diagram 1: Image visualization of how the payload is connected to the weather balloon via a parachute

--Overall design Considerations--
- Legal under Canadian law
> Under 4kg
> Balloon must be under 115 cu. ft according to Canadian Aviation Regulations 602.42
- Reach 30km


--Data Collection System--

We used SFE_MMA8452Q for data collection module alongside a SD card module controlled by an Arduino Uno.

I wired the SFE_MMA8452Q and SD card module to the Arduino Uno according to online guides and modified the example code to write data to the SD card. 
<p align="center">
<img width="50%" alt="wired up sensor" src="https://github.com/user-attachments/assets/57878f1e-78ea-4207-906c-b3c53018ffe5" />
</p>
Image 1: SFE_MMA8452Q wired up to Arduino according to online guides
<img width="2048" height="1536" alt="wired up SD card module" src="https://github.com/user-attachments/assets/9cdfccef-6ca2-401f-970f-4ce5a1672fdd" />
Image 2: SD card module wired up inside the payload

I first tested out the acceleration and temperature sensing from SFE_MMA8452Q using the MMA8452Q_Basic.ino for acceleration and C_and_F.ino for temperature, then I combined both into Combined.ino and used that for the overall data collection system.

--GPS system--
Our original idea was to wire up the SIM808 module with the Arduino to send the payload's location to our phones once it lands, we modified the example code Vehicle_Tracking.ino from SIM808 fit our needs 


