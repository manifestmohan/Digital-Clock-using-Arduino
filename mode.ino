void mode()
{
  count = 0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter mode");
  while (count == 0)
  {
    t.update();
    val = digitalRead(buttonpin);
    if (val == HIGH)
    { ++m1;
      if (m1 > 4)
      {
        m1 = 1;
      }
    }
    lcd.setCursor(0, 1);
    lcd.print(m1,DEC);
    delay(150);
    int val1 = digitalRead(modepin);
    if (val1 == HIGH)
    {
      ++count;
    }
  }
}
