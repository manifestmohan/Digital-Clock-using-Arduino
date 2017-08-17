int value()
{
  int i = 0;
  count = 0;
  while (count == 0)
  {
    t.update();
    val = digitalRead(buttonpin);
    if (val == HIGH)
    { ++i;
      if (i > 60)
      {
        i = 0;
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
    }
    lcd.setCursor(0, 1);
    lcd.print(i,DEC);
    delay(150);
    int val1 = digitalRead(modepin);
    if (val1 == HIGH)
    {
      ++count;
    }
  }
  return i;
}

