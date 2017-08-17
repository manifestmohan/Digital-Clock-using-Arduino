

void setcountdown() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter H:");
  h = value();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter M:");
  m = value();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter S:");
  s = value();
}

void countdown()
{
  val = 1;
  while (val == 1)
  {
    t.update();
    delay(1000);
    displaytime();
    lcd.setCursor(0, 1);
    lcd.print("CDtimer:");
    lcd.print(h, DEC);
    lcd.print(":");
    lcd.print(m, DEC);
    lcd.print(":");
    lcd.print(s, DEC);
    val1 = 0;
    val1 = digitalRead(buttonpin);
    if (val1 == HIGH)
    {
      val = 3;
    }
    --s;
    if (s == -1)
    {
      --m;
      s = 59;
      if (m == -1)
      {
        --h;
        m = 59;
      }
    }
    if ((h == 0) && (m == 0) && (s == 0))
    {
      val = 2;
    }
    if ((h == 9) || (m == 9) || (s == 9))
    {
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
  }
  val = 1;
  val1 = 0;
}

