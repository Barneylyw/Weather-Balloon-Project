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
<p align="center"><img width="50%" alt="wired up SD card module" src="https://github.com/user-attachments/assets/9cdfccef-6ca2-401f-970f-4ce5a1672fdd" /></p>
Image 2: SD card module wired up inside the payload

<p align="center"><img width="2048" height="1536" alt="SFE_MMA8452Q output to txt file" src="https://github.com/user-attachments/assets/3df0161a-751c-420d-8176-a1c26d4604a7" /></p>
Image 3: output of Combined.ino to a .txt file; this was sent to my team to communicate that the time wasn't changing while everything else works

I first tested out the acceleration and temperature sensing from SFE_MMA8452Q using the MMA8452Q_Basic.ino for acceleration and C_and_F.ino for temperature, then I combined both into Combined.ino and used that for the overall data collection system.

--GPS system--

Our original idea was to wire up the SIM808 module with the Arduino to send the payload's location to our phones once it lands; we modified the example code Vehicle_Tracking.ino from SIM808 to fit our needs, where it will send its location to one of our phones when we send it a message. However, when tested, the system can only get its GPS location and will not send or reply to any text messages. To meet our timeline, we decided to buy an off-the-shelf car tracker (Tracki) to achieve the same results.

--Parachute--

Off-the-shelf 1-metre-wide parachute from High Altitude Science; we connected it to the finished payload and tested it in a stairwell to verify it would open.

--Cameras--

An off-the-shelf action camera and an unused dashcam were used to record its journey
<p align="center"><img width="1536" height="2048" alt="2 camera in payload" src="https://github.com/user-attachments/assets/55e92254-e6e4-47b5-8b66-2fad7148129e" /></p>
Image 4: The two cameras in the payload, with the action camera on the right and the dashcam on the left
