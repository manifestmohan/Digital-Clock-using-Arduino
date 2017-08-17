boolean K = true;
void setdate() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("set the date");
  dateloop();
}

void dateloop() {
  while (K) {


    while (count == 4)
    {
      int val = digitalRead(buttonpin);
      if (val == HIGH)
      { ++dd;
        if (dd > 31)
        {
          dd = 1;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      lcd.setCursor(0, 1);
      lcd.print(dd, DEC);
      delay(150);
      int val1 = digitalRead(modepin);
      if (val1 == HIGH)
      {
        ++count;
      }
    }
    lcd.setCursor(0, 1);
    lcd.print("                ");
    while (count == 5)
    {
      int val = digitalRead(buttonpin);
      if (val == HIGH)
      { ++mm;
        if (mm > 12)
        {
          mm = 1;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      lcd.setCursor(0, 1);
      lcd.print(mm, DEC);
      delay(150);
      int val1 = digitalRead(modepin);
      if (val1 == HIGH)
      {
        ++count;
      }
    }
    lcd.setCursor(0, 1);
    lcd.print("                ");
    while (count == 6)
    {
      int val = digitalRead(buttonpin);
      if (val == HIGH)
      {
        ++yy;
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
      lcd.setCursor(0, 1);
      lcd.print(yy, DEC);
      delay(150);
      int val1 = digitalRead(modepin);
      if (val1 == HIGH)
      {
        ++count;
      }
    }
    K = false;
  }
  lcd.setCursor(0, 0);
  lcd.print("                ");

}
