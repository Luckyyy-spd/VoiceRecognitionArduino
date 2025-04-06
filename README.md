# Voice-Controlled Assistant with Arduino

## Overview

This project implements a voice-controlled assistant using an Arduino board, which can respond to various voice commands. The assistant can play music, provide medication information, and respond to queries about food choices, quotes, riddles, podcasts, and stories.

## Features

- Voice recognition for commands such as:
  - Play music
  - Stop music
  - Provide medication information
  - Suggest food choices
  - Share quotes
  - Tell riddles
  - Play podcasts
  - Narrate stories
- Integration with DFPlayer Mini for audio playback
- Serial communication for debugging and status updates

## Required Hardware

To set up this project, you will need the following components:

1. **Arduino Board**: Any compatible Arduino board (e.g., Arduino Uno, Nano, Mega).
2. **Voice Recognition Module**: 
   - **VR Module**: Voice Recognition Module V3 (compatible with Arduino).
3. **DFPlayer Mini**: 
   - **DFPlayer Mini MP3 Player Module**: For audio playback.
4. **Micro SD Card**: 
   - A micro SD card (at least 4GB) to store audio files.
5. **Speaker**: 
   - A small speaker or audio output device to play sounds.
6. **Wires**: 
   - Jumper wires for connections.
7. **Breadboard** (optional): 
   - For easier connections and prototyping.

## Wiring Diagram

Here’s a basic wiring setup for the components:

- **Voice Recognition Module**:
  - Connect the `TX` pin of the VR module to pin `6` on the Arduino.
  - Connect the `RX` pin of the VR module to pin `7` on the Arduino.
  - Connect `VCC` to `5V` and `GND` to `GND`.

- **DFPlayer Mini**:
  - Connect `TX` of DFPlayer to `Arduino RX` (e.g., pin `10`).
  - Connect `RX` of DFPlayer to `Arduino TX` (e.g., pin `11`).
  - Connect `VCC` to `5V` and `GND` to `GND`.
  - Connect the speaker to the `SPK1` and `SPK2` pins of the DFPlayer.

## Software Setup

1. **Arduino IDE**: Make sure you have the Arduino IDE installed on your computer.
2. **Libraries**: Install the following libraries via the Library Manager in the Arduino IDE:
   - `SoftwareSerial`
   - `VoiceRecognitionV3`
   - `DFRobotDFPlayerMini`

3. **Upload the Code**: Copy the provided code into the Arduino IDE and upload it to your Arduino board.

## Usage

1. Power on the Arduino and ensure all components are connected properly.
2. Use voice commands to interact with the assistant. For example, say "Hey Eli" to activate the assistant, followed by commands like "Play music" or "Tell me a quote."

## Troubleshooting

- Ensure all connections are secure.
- Check that the micro SD card is properly formatted and contains the necessary audio files.
- If the voice recognition module does not respond, verify the wiring and ensure the module is powered correctly.

## License

This project is open-source. Feel free to modify and use it as you wish.
