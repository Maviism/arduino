#include <EEPROM.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32, 16,2);

int LEDPIN = 13;
int increment_button_pin1 = 4;
int decrement_button_pin1 = 3;
int increment_button_pin2 = 7;
int decrement_button_pin2 = 6;
int reset_button_pin = 5;

int increment1_state = 0;
int decrement1_state = 0;
int increment2_state = 0;
int decrement2_state = 0;
int reset_state = 0;

int score_team1 = 0;
int score_team2 = 0;


// EEPROM addresses for storing data
const int score_team1_address = 0;
const int score_team2_address = 1;

void setup()
{
  pinMode(LEDPIN, OUTPUT);
  pinMode(increment_button_pin1, INPUT);
  pinMode(decrement_button_pin1, INPUT);
  pinMode(increment_button_pin2, INPUT);
  pinMode(decrement_button_pin2, INPUT);
  pinMode(reset_button_pin, INPUT);
  
  Serial.begin(9600);
  
  score_team1 = EEPROM.read(score_team1_address);
  score_team2 = EEPROM.read(score_team2_address);
  
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Welcome To");
  lcd.setCursor(0,1);
  lcd.print("Score Board");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEAM 1 | Team 2");
  lcd.setCursor(7,1);
  lcd.print("|");
  updateScore(3, 1, score_team1);
  updateScore(12, 1, score_team2);
}

void loop()
{
  increment1_state = digitalRead(increment_button_pin1);
  decrement1_state = digitalRead(decrement_button_pin1);
  increment2_state = digitalRead(increment_button_pin2);
  decrement2_state = digitalRead(decrement_button_pin2);
  reset_state = digitalRead(reset_button_pin);
  
  if(reset_state == HIGH) {
    Serial.println("restart button pressed");
    score_team1 = 0;
    score_team2 = 0;

    updateEEPROMScore(score_team1_address, score_team1);
    updateEEPROMScore(score_team2_address, score_team2);

    updateScore(3, 1, score_team1);
    updateScore(12, 1, score_team2);
  }
  
  if (increment1_state == HIGH) {
    Serial.println("Increment button 1 pressed");
    score_team1++;
    updateEEPROMScore(score_team1_address, score_team1);
    updateScore(3,1, score_team1);
  } 

  if (decrement1_state == HIGH) {
    Serial.println("Decrement button 1 pressed");
    score_team1--;
    updateEEPROMScore(score_team1_address, score_team1);
    updateScore(3,1, score_team1);    
  } 

  if (increment2_state == HIGH) {
    Serial.println("Increment button 2 pressed");
    score_team2++;
    updateEEPROMScore(score_team2_address, score_team2);
    updateScore(12,1, score_team2);
  } 

  if (decrement2_state == HIGH) {
    Serial.println("Decrement button 2 pressed");
    score_team2--;
    updateEEPROMScore(score_team2_address, score_team2);
    updateScore(12,1, score_team2);
  } 
}

void updateScore(int col, int row, int score) {
  lcd.setCursor(col, row);
  if (score < 10 || score > 0) {
    lcd.print("  "); // Clear previous 2-digit score
  }
  lcd.setCursor(col, row);
  lcd.print(score);
  delay(200);
}

void updateEEPROMScore(int address, int score){
  EEPROM.update(address, score);
}