#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int sqrtButtonPIn = A2;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'*', '0', '#', 'D'},
  {'7', '8', '9', 'C'}
};

byte rowPins[ROWS] = {8, 9, 10, 11};
byte colPins[COLS] = {12, 13, A0, A1};

Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String expression = "";  
String num1 = "", num2 = "";  
char op = '\0';  
boolean isSecondNum = false;  
boolean resultDisplayed = false;  
int answer = 0;
int SQRTstate =0; 

void setup() {
  pinMode(sqrtButtonPIn, INPUT);
  lcd.begin(16, 2);
  lcd.print("Calculator");
  delay(2000);
  lcd.clear();
  
}

void loop() {
  char key = myKeypad.getKey();
  SQRTstate = analogRead(sqrtButtonPIn);

  if(SQRTstate == HIGH){
      lcd.print("Sqrt(");
      num1+=key;
      int SQRTnum = num1.toInt();
      answer = sqrt(SQRTnum);
      lcd.print(answer);
    }

  if (key != NO_KEY && (key >= '0' && key <= '9')) {
    if (!isSecondNum) {
      num1 += key;  
    } else {
      num2 += key;  
    }

    expression += key;  
    lcd.setCursor(0, 0);
    lcd.print(expression);  
  }

  if (!isSecondNum && key != NO_KEY && (key == 'A' || key == 'B' || key == '*' || key == 'D')) {
    isSecondNum = true;  
    switch (key) {
      case 'A': op = '+'; break;
      case 'B': op = '-'; break;
      case '*': op = '*'; break;
      case 'D': op = '/'; break;
    }
    expression += op;  
    lcd.setCursor(0, 0);
    lcd.print(expression);  
  }

  if (isSecondNum && key != NO_KEY && key == '#') {
    if (op == '+') {
      answer = num1.toInt() + num2.toInt();
    } else if (op == '-') {
      answer = num1.toInt() - num2.toInt();
    } else if (op == '*') {
      answer = num1.toInt() * num2.toInt();
    } else if (op == '/') {
      if (num2.toInt() != 0) {
        answer = num1.toInt() / num2.toInt();
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Error: Div by 0");
        delay(2000);
        resetCalculator();
        return;
      }
    }

    lcd.setCursor(0, 1);
    lcd.print("");  
    lcd.print(answer);  
    resultDisplayed = true;
  }

  if (key != NO_KEY && key == 'C') {
    resetCalculator();
  }
}

void resetCalculator() {
  lcd.clear();
  
  expression = "";
  num1 = "";
  num2 = "";
  op = '\0';
  isSecondNum = false;
  resultDisplayed = false;
  answer = 0;
}
