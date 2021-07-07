# Danbo-PR-Robot-V1.0
![hDanbo1](https://user-images.githubusercontent.com/80456446/124104052-29ed4d80-da62-11eb-8235-2a1862d6db36.jpg)

# Description
Danbo pr robot is a robot that distributes flyers among people. It makes a speech about pixels. We first use 2 arduino uno for the transmitting and receiving parts, we connect between them using nrf. We use driver circuits for motors and amplifier circuit for speaker.

![Danbo1](https://user-images.githubusercontent.com/80456446/124104070-2f4a9800-da62-11eb-8614-97e2f99b5425.jpg)

# Components used
1- Arduino Uno 
https://ram-e-shop.com/product/kit-arduino-uno/

2- Dc Motors
https://store.fut-electronics.com/products/dc-motor-with-metal-gear-3-2-kg-cm-133-rpm-6v?_pos=33&_sid=25a962ad2&_ss=r

3- Servo Motor (15 kg.cm)
https://ram-e-shop.com/product/servo-motor-with-magnetic-encoder-360-15-5-kg-cm-metal-gears-fb5311m/

4-Servo 10kg.cm
https://ram-e-shop.com/product/servo-mg995/

5- lm386
https://free-electronic.com/product/lm741cn/

6- Ceramic capacitor 100n f
https://free-electronic.com/product/ceramic-capacitor-100nf-50v/

7- Electrolytic capacitor 1000u
https://free-electronic.com/product/irf540n/

8- Electrolytic capacitor 100uf
https://free-electronic.com/product/electrolytic-capacitor-100uf-50v/

9- IRF540N
https://free-electronic.com/product/irf540n/

10- NRF 24L01
https://free-electronic.com/product/nrf24l01-wireless-module-2-4-ghz-rf-transceiver/

11 - Variable resistance(10k)
https://free-electronic.com/product/potentiometer-wth118-10-kohm/

12- Resistance 470 ohm
https://free-electronic.com/product/resistor-470-ohm-3w/

13- Resistance 10k ohm
https://free-electronic.com/product/resistor-10-kohm-3w/

14- Diode ln4007

15- Resistance 5k

## Mechanical structure
1- 6mm wood (For body)

2- 3mm wood (For head)

3- 6mm acrylic (For gears)

4- M4 Screws (4m) 

5- M4 nuts 

6- 15 Cm Wheels

# Steps to build the mechanical structure

1- Create 3D Model
![58710cf5-95d3-4f55-bb44-d71eec74a273](https://user-images.githubusercontent.com/80456446/124105861-f01d4680-da63-11eb-8ea3-ccd6564e28c4.jpg)![fb0c4b6c-20fe-4ef7-932a-8400b34acadb](https://user-images.githubusercontent.com/80456446/124105864-f0b5dd00-da63-11eb-8eb5-7d0ea5544a80.jpg)![Screenshot (331)](https://user-images.githubusercontent.com/80456446/124105867-f1e70a00-da63-11eb-82b3-52324f64f036.png)![Screenshot (332)](https://user-images.githubusercontent.com/80456446/124105880-f3b0cd80-da63-11eb-914f-4bc3c32352f2.png)![Screenshot (333)](https://user-images.githubusercontent.com/80456446/124105889-f57a9100-da63-11eb-979a-b67810952e02.png)![2bd5ae67-7fae-40e5-9a05-6af3d5f4042c](https://user-images.githubusercontent.com/80456446/124105896-f7445480-da63-11eb-9ae5-d608fe965a32.jpg)![9b517ff1-30e2-4df8-80e0-305ad7b346fc](https://user-images.githubusercontent.com/80456446/124105900-f7dceb00-da63-11eb-90c2-45b050ea9ba5.jpg)![49eeb6c1-c135-4f6c-8a2b-e80cf61adb4f](https://user-images.githubusercontent.com/80456446/124105902-f7dceb00-da63-11eb-9cf2-64ee6498648a.jpg)

We create a 3D model about Danbo's skeleton using “Solidworks" It would be easier for us to confirm every servo's position and angle of movement in the 3D model. After creating the 3D model, we convert it to 2D for laser cutting. We used 6mm(thickness) wood to laser cut the Danbo body and 3mm (thickness) wood to the Danbo head.

(Hint: You can find the design in the epo, if you are using older version of solidWorks please download the IGS files and drag it and drop it in your solidworks app)

(Hint: you can print the body using the Dxf files in the repo) 

The DXfile in google drive:
https://drive.google.com/drive/folders/12dDjX8gE220Q_c95igGJB5SD7zqggt2-?usp=sharing


2- Servo installation:
![WhatsApp Image 2020-12-24 at 10 36 02 AM (3)](https://user-images.githubusercontent.com/80456446/124106671-b7ca3800-da64-11eb-8fcb-d8f959a7ec68.jpeg)
![WhatsApp Image 2020-12-24 at 10 27 34 AM (1)](https://user-images.githubusercontent.com/80456446/124106674-b993fb80-da64-11eb-8526-cb111a3f19ef.jpeg)
There are 2 servos on Danbo's neck, 2 servos for the shoulders


3- Flyers Mechanism :
Assemble the flyer mechanism as shoen in the design

4- Gearbox design:
![IMG_0938](https://user-images.githubusercontent.com/80456446/124107032-1becfc00-da65-11eb-8067-2213467ef210.jpg)


https://user-images.githubusercontent.com/80456446/124107049-1f808300-da65-11eb-9a47-21ff029a761d.mp4

![IMG_0935_(1)](https://user-images.githubusercontent.com/80456446/124107057-214a4680-da65-11eb-8033-479539db2538.jpg)
By Gear generator and some calculations, we Design gear box to give us desired velocity and torque. By Gear generator and some calculations, we Design gear box to give us desired velocity and torque.

5- Assemble the body and the head:
![WhatsApp Image 2020-12-24 at 10 36 02 AM (1)](https://user-images.githubusercontent.com/80456446/124107860-f1e80980-da65-11eb-914e-548ff25d9370.jpeg)
![WhatsApp Image 2020-12-24 at 10 36 02 AM (3)](https://user-images.githubusercontent.com/80456446/124107863-f1e80980-da65-11eb-9e14-a9a82616afa2.jpeg)
![WhatsApp Image 2020-12-24 at 10 36 02 AM (4)](https://user-images.githubusercontent.com/80456446/124107867-f280a000-da65-11eb-9351-e984a7561d25.jpeg)
![WhatsApp Image 2020-12-24 at 10 36 02 AM](https://user-images.githubusercontent.com/80456446/124107869-f3193680-da65-11eb-9fc5-e36dcde4b0fa.jpeg)

![IMG_20201221_203423](https://user-images.githubusercontent.com/80456446/124107832-e98fce80-da65-11eb-8dc6-f3a823bcc82a.jpg)

https://user-images.githubusercontent.com/80456446/124108085-2b207980-da66-11eb-9232-283778431745.mp4

1- Fix the head plates with screws and nuts

2- Fix the legs together with the body and base

3- Put the wheels and gearbox together in the base plate

4- Fix the arm servos with the arm structure and head servo with the head structure.


## Control
1- Transmitter Stage controller
In this stage we will design the controller of the robot we begin with the circuit design

Components used in this circuit:
In this circuit we use: 
-Arduino UNO

-nrf24l01 module

-two joysticks 

- push bottoms

Schematic:
![Danbo2](https://user-images.githubusercontent.com/80456446/124108374-73d83280-da66-11eb-8fd8-d67deff0e69c.jpg)

PCB layout:
![Danbo3](https://user-images.githubusercontent.com/80456446/124108533-8fdbd400-da66-11eb-9a3d-8720aaf5c268.jpg)

Transmitter code of the Arduino:
Uplad the code to your microcontroller, you can find the code in the repo

Shape of the shield:
![Danbo4](https://user-images.githubusercontent.com/80456446/124108845-d4676f80-da66-11eb-82c1-a73a02b3c35c.jpg)

Driver circuit:
![Danbo5](https://user-images.githubusercontent.com/80456446/124108907-e3e6b880-da66-11eb-807c-23d7f11a417f.jpg)

Driver PCB Design:
![Danbo6](https://user-images.githubusercontent.com/80456446/124108963-f3fe9800-da66-11eb-9e47-1a20710369a7.jpg)


2- Receiver stage:
In this stage we will get from the controller the buffers and begin to control the robot by several of instructions

Components used in this circuit:
In this stage we use:
-Arduino uno 

-nrf 24l01 module

-our driver circuits. 

- 3 dc motor. 

- 2 servo motor

Receiver code:
Uplad the code to your microcontroller, you can find the code in the repo


3- Speakers
Amplifier circuit:
![Danbo7](https://user-images.githubusercontent.com/80456446/124109313-4b9d0380-da67-11eb-95a7-c22b6b93cfff.jpg)


Amplifier PCB
![Danbo8](https://user-images.githubusercontent.com/80456446/124109407-62dbf100-da67-11eb-927b-708f831db9fa.jpg)
We use this circuit in order to amplify the sound coming from the speaker.

Speaker's code:
Uplad the code to your microcontroller, you can find the code in the repo


## Pixels'21 Projects video
Our Beautiful Projects 🖤✨
https://www.youtube.com/watch?v=BeQG_2XT7rU&list=PLy8wlMYqB2WyBJAQLZQQEhgkKTbwseKvb

## More Projects
for more projects in different enginneering fields, please visit our wevbsite:
https://pixelseg.com/project-contest
![Screenshot (149)](https://user-images.githubusercontent.com/80456446/124113398-b18b8a00-da6b-11eb-8faf-70db2402673c.png)


## Pixels App 
![187960930_3955292401216930_6844533153445761662_n](https://user-images.githubusercontent.com/80456446/124113684-00392400-da6c-11eb-8779-cea0193eefb6.jpg)

“Pixels Egypt” mobile app is considered an important and easy way to stay in touch with us.

The app will help you to:

- Browse different online courses and resources in different fields like Computer, Communication, Power, and Mechanical Engineering.
- You will find courses, videos, books and more.
- Follow our news.
- Share our knowledge.
- Be one of the family.

Get it now on Google Play:

https://play.google.com/store/apps/details


## Follow Pixels:

- Facebook:

https://www.facebook.com/PixelsEgyptOrg

- YouTube:

https://www.youtube.com/c/PixelsEgypt

- Instagram:

https://www.instagram.com/pixelsegypt/

- Twitter:

https://twitter.com/pixelsegypt?lang=en



