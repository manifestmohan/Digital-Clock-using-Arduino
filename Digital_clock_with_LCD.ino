#include <Timer.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

Timer t;
short buttonpin = 9;
short modepin = 8;
short ledpin = 13;
short m1 = 1;
short swatch = 0;

short hs = 0, ms = 0, ss = 0, val1 = 0, val = 0, count = 1;

short h = 0, m = 0, s = 0;

short dd = 1, mm = 1, yy = 2000;

short ha = 0, ma = 0, sa = 0, ch = 0;

boolean alarmcontrol = false;

void setup() {


  lcd.begin(16, 2);
  lcd.write("Digital Clock");
  delay(2000);
  lcd.clear();

  pinMode(buttonpin, INPUT);
  pinMode(modepin, INPUT);
  pinMode(ledpin, OUTPUT);
  t.every(1000, timerun);

  settime();
  setdate();
}

void loop() {

  t.update();
  displaytime();
  val = 0;
  val = digitalRead(buttonpin);
  if (val == HIGH)
  {
    m1 = 1;
    mode();
    t.update();
  }
  switch (m1)
  {
    case 1: lcd.setCursor(0, 1);
      lcd.print("DATE:");
      lcd.print(dd, DEC);
      lcd.print("-");
      lcd.print(mm, DEC);
      lcd.print("-");
      lcd.print(yy, DEC);
      break;
    case 2: lcd.setCursor(0, 1);
      lcd.print("StopWat:");
      stopwatch();
      lcd.print(h, DEC);
      lcd.print(":");
      lcd.print(m, DEC);
      lcd.print(":");
      lcd.print(s, DEC);
      val = 0;
      delay(1000);
      val = digitalRead(modepin);
      if (val == HIGH)
      {
        swatch = 1;
        while (swatch == 1)
        {
          t.update();
          displaytime();
          delay(1000);
          lcd.setCursor(0, 1);
          lcd.print("Stopwat:");
          lcd.print(h, DEC);
          lcd.print(":");
          lcd.print(m, DEC);
          lcd.print(":");
          lcd.print(s, DEC);
          val = 0;
          val = digitalRead(buttonpin);
          if (val == HIGH)
          {
            ++swatch;
            h = m = s = 0;
            m1 = 1;
          }
        }
      }
      swatch = 0;
      break;
    case 3: lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("CountDowntimer");
      h = m = s = 0;
      setcountdown();
      countdown();
      val = HIGH;
      if (val == HIGH)
      {
        swatch = 1;
        while (swatch == 1)
        {
          t.update();
          displaytime();
          delay(1000);
          lcd.setCursor(0, 1);
          lcd.print("CDtimer:");
          lcd.print(h, DEC);
          lcd.print(":");
          lcd.print(m, DEC);
          lcd.print(":");
          lcd.print(s, DEC);
          val = 0;
          val = digitalRead(buttonpin);
          if (val == HIGH)
          {
            ++swatch;
            h = m = s = 0;
            m1 = 1;
          }
        }
      }
      swatch = 0;
      break;
    case 4: lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Alarm ");
      delay(2000);
      t.update();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter choice");
      ch = value();
      lcd.clear();
      switch (ch)
      {
        case 1: lcd.setCursor(0, 0);
          lcd.print("Alarm ON");
          delay(2000);
          t.update();
          alarmcontrol = true;
          break;
        case 2:
          lcd.setCursor(0, 0);
          lcd.print("Alarm OFF");
          delay(2000);
          t.update();
          alarmcontrol = false;
          digitalWrite(ledpin, LOW);
          break;
        case 3: lcd.setCursor(0, 0);
          lcd.print("Alarm SET");
          delay(2000);
          t.update();
          ha = ma = sa;
          setalarm();
          break;
        default : lcd.setCursor(0, 0);
          lcd.print("InValid choice");

      }
      m1 = 1;
      break;
    default : lcd.setCursor(0, 1);
      lcd.print("    InValid     ");
  }

  if (alarmcontrol == true)
  {
    if ((hs >= ha) && (ms >= ma) && (ss >= sa))
    {
      while (alarmcontrol == true)
      {
        t.update();
        displaytime();
        digitalWrite(ledpin, HIGH);
        lcd.setCursor(0, 1);
        lcd.print(" turn OFF alarm  ");
        val = 0;
        val = digitalRead(buttonpin);
        if (val == HIGH)
        {
          digitalWrite(ledpin, LOW);
          alarmcontrol = false;
          m1 = 1;
        }
      }
    }
  }


}


