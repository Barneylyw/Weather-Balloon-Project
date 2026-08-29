Weather Balloon Project

To send a payload containing gps, electronics, and camera to altitude of ~30km via a weather balloon

<img width="50%" alt="weather balloon" src="https://github.com/user-attachments/assets/5f28afc6-eaf3-41f5-9c44-c16992499a6c" />
Diagram 1: Image visualization of how the payload is connected to the weather balloon via a parachute

--Overall design Considerations--
- Legal under Canadian law
> Under 4kg (I think it's an FAA restriction, but better safe than sorry)
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


I first tested out the acceleration and temperature sensing from SFE_MMA8452Q using the MMA8452Q_Basic.ino for acceleration and C_and_F.ino for temperature, then I combined both into Combined.ino and used that for the overall data collection system.
<p align="center"><img width="50%" alt="SFE_MMA8452Q output to txt file" src="https://github.com/user-attachments/assets/3df0161a-751c-420d-8176-a1c26d4604a7" /></p>
Image 3: output of Combined.ino to a .txt file; this was sent to my team to communicate that the time wasn't changing while everything else works
--GPS system--

Our original idea was to wire up the SIM808 module with the Arduino to send the payload's location to our phones once it lands; we modified the example code Vehicle_Tracking.ino from SIM808 to fit our needs, where it will send its location to one of our phones when we send it a message. However, when tested, the system can only get its GPS location and will not send or reply to any text messages. To meet our timeline, we decided to buy an off-the-shelf car tracker (Tracki) to achieve the same results.

--Cameras--

An off-the-shelf action camera and an unused dashcam were used to record its journey
<p align="center"><img width="50%" alt="2 camera in payload" src="https://github.com/user-attachments/assets/55e92254-e6e4-47b5-8b66-2fad7148129e" /></p>
Image 4: The two cameras in the payload, with the action camera on the right and the dashcam on the left

Here is the final payload, it weighs 517g:
<p align="center"><img width="50%" alt="cameras and GPS wired up in payload" src="https://github.com/user-attachments/assets/56c371f8-5735-49d2-bd8f-0593702f3a2e" /></p>
Image 5: Cameras, data collection system, and GPS all assembled into the payload


--Parachute--

Off-the-shelf 1-metre-wide parachute from High Altitude Science; we connected it to the finished payload and tested it in a stairwell to verify it would open.
We then used the mass of the payload alongside the area of the parachute to determine its descent rate

--Flight--

To determine how much helium we would need to achieve the targeted 30km, we used the SondeHub weather balloon calculator to determine how much helium we need. We changed our target burst altitude until we got the highest projected burst altitude while staying under 115cu ft.  
I also created balloon burst graphs.xlsx to gain an understanding of how the balloon behaves with different payload mass, burst altitude, etc...
<p align="center"><img width="50%" height="786" alt="image" src="https://github.com/user-attachments/assets/a0ffb9e8-b73c-4671-8570-8ce52c4e47a1" /> </p>
Image 6: SondeHub Calculator results showing we need 114.5 cu ft. to achieve 33.6km burst altitude.

Then we need to determine its rough flight path. We used the predict.sondehub.org tool to predict its path (20240824-balloon flight path0_standard_profile_2024082318Z.kml) and landing site after entering our predicted launch time (Aug 24, 2024, noon) and location (Ayr, ON).
<p align="center"><img width="50%" alt="predicted land location" src="https://github.com/user-attachments/assets/e97e8ee8-5d75-4c67-8802-ab576e0eda74" /></p>
Image 7: Predicted landing location near Hagersville, ON at ~6 pm

We contacted NavCan to ensure legality and completed simple documentation (balloon.pdf)
