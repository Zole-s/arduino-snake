# Snake on Arduino UNO

A simple snake on Arduino UNO with One-button control made on LCD Display base

# Board Assembly

* Connect a button to pin 2.
* lcd(13, 12, 11, 10, 9, 8) - LCD Pins.

# Program Part

* Requirements

1. LiquidCrystal.h

* Build

1. Clone the repository:
```bash
  git clone https://github.com/MichnoAZ/arduino-snake
```
2. Connect arduino uno to PC and see the list of connected devices:
```bash
snap connections arduino-cli
```
3. Connect:
```bash
sudo snap connect arduino-cli: <plug id>
```
4. Build project:
```bash
arduino-cli compile -b arduino:avr:uno .
```
5. Load project:
```bash
arduino-cli upload . -p COM<id>
```
6. Boot Arduino UNO
