
boolean L = true;

void settime() {
  // put your setup code here, to run once:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("set the time");
  timeloop();
}

void timeloop() {
  while (L) {
   

    while (count == 1)
    {
      int val = digitalRead(buttonpin);
      if (val == HIGH)
      { ++hs;
        if (hs > 23)
        {
          hs = 0;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      lcd.setCursor(0, 1);
      lcd.print(hs, DEC);
      delay(150);
      int val1 = digitalRead(modepin);
      if (val1 == HIGH)
      {
        ++count;
      }
    }
    lcd.setCursor(0, 1);
    lcd.print("                ");
    while (count == 2)
    {
      int val = digitalRead(buttonpin);
      if (val == HIGH)
      { ++ms;
        if (ms > 59)
        {
          ms = 0;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      lcd.setCursor(0, 1);
      lcd.print(ms, DEC);
      delay(150);
      int val1 = digitalRead(modepin);
      if (val1 == HIGH)
      {
        ++count;
      }
    }
    lcd.setCursor(0, 1);
    lcd.print("                ");

    while (count == 3)
    {
      int val = digitalRead(buttonpin);
      if (val == HIGH)
      { ++ss;
        if (ss > 59)
        {
          ss = 0;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      lcd.setCursor(0, 1);
      lcd.print(ss, DEC);
      delay(150);
      int val1 = digitalRead(modepin);
      if (val1 == HIGH)
      {
        ++count;
      }
    }

    L = false;
  }


}
