# Arduino Scoreboard System

This project is an Arduino-based scoreboard system that displays scores for two teams on an LCD screen. The scores are stored in the EEPROM, ensuring they are not lost when the power is turned off.

## Project Overview

The Arduino scoreboard system is designed to keep track of the scores for two teams. The scores are displayed on an LCD screen and can be updated using push buttons. To ensure the scores are not lost during a power outage, the system saves the scores in the EEPROM of the Arduino.

### Features

- **Score Persistence**: Scores are saved in the EEPROM and remain intact even when the power is turned off.
- **Real-time Display**: Scores are displayed in real-time on a 16x2 LCD screen.
- **User Interaction**: Scores can be updated using push buttons.

### Project Components

- Arduino Uno
- 16x2 LCD Display
- 5 Push Buttons
- Resistors (10kΩ)
- Breadboard
- Jumper Wires

## Wiring Diagram

![Scoreboard System](/score-board/score_board.png)

## Instructions

1. **Wiring**: Follow the wiring diagram to connect the components.
2. **Code Upload**: Upload the Arduino code to your Arduino Uno.
3. **Operation**: Use the push buttons to update the scores. The updated scores will be displayed on the LCD and saved in the EEPROM.

## Tinkercad Project Link

Access the project on Tinkercad using the following link: [Tinkercad Project Link](https://www.tinkercad.com/things/iMH2kyJcNYo-score-board)
