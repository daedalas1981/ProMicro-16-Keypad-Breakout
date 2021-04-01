# Arduino

## Arduino Pro Micro Version
In order for the RobotDyn 4x4 KeyPad to read the values from the analog output, the 5V-16 MHz version of the board must be used.

## Arduino Pro Micro Leonardo
The firmware / IDE settings need to be the Leonardo. This is so the device can broadcast itself over USB as a HID device. (Human Interface Device). It will show up in Windows as a Leonardo USB HID Device.

## Arduino IDE / INO
Please note the SETUP for the Encoders. Change as needed for One or Two.
```
// ENCODER SETUP
bool encoderOneEnable = true; // DEFAULT ENCODER on R_ENC1
bool encoderTwoEnable = true; // SECONDARY ENCODER on R_ENC2
```
Also the pinouts are set for use with the breakout board. Change what suits your needs.

## Key Mapping
The .INO file is broken into 4 CASES. Each Case has 16 key mappings.
- Case 0 - 15 Keys + 1 Mode Key - Mode 1 - Default - System Macros
- Case 1 - 15 Keys + 1 Mode Key - Mode 2 -  Unique Left Control + F13-F24 Keys + Copy / Paste
- Case 2 - 15 Keys + 1 Mode Key - Mode 3 -  F13-F24 Keys + Copy / Paste
- Case 3 - 15 Keys + 1 Mode Key - Mode 4 -  F1-F12 Keys + Save/Close/Quit

Create combinations of KeyPresses, but just remember to release them again!
```
KeyPress.releaseALL();
```
