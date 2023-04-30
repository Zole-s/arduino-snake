#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
byte applePos[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte snakePos[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};
void drawSnake(int index, int line) {
   lcd.createChar(index, snakePos);
   lcd.setCursor(index, line);
   lcd.write(1);
}
void drawApples() {
    int e = random(15);
    lcd.createChar(e, applePos);
    lcd.setCursor(e, random(2));
    lcd.write(2);
}
void setup() {
   lcd.begin(16, 2);
   drawSnake(1, 0);
}
int i = 0;
int dirRight = 1;
int io = 0;
int dirDown = 0;
int appleposX = 1;
int appleposY = 1;
int score = 0;
void loop() { 
  if (score > 8) {
    lcd.print("YOU WIN!");
    return;
  }
  if (digitalRead(2) == HIGH) {
      if (dirRight == 1) dirRight = -1;
      else dirRight = 1;
      if (dirDown == -1) dirDown = 1;
      else dirDown = -1;
  }
  /** On frame update **/
  lcd.clear();
  io+=dirDown;
  i+=dirRight;
  if (i > 15) i = 0, io = io == 1 ? 0 : 1;
  if (i < 0) i = 15, io = io == 1 ? 0 : 1;
  if (io - appleposY < 1 && i - appleposX < 1) {
    appleposX = random(15);
    appleposY = random(1);
    score++;
  }
  drawSnake(i, io);
  drawSnake(appleposX, appleposY);
  lcd.setCursor(15, 1);
  lcd.print(score);
  delay(333);
}
