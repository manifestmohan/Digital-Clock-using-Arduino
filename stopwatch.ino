

void stopwatch()
{
  ++s;
  if (s == 60)
  {
    ++m;
    lcd.setCursor(0, 1);
    lcd.print("                ");
    s = 0;
    if (m == 60)
    {
      ++h;
      lcd.setCursor(0, 1);
      lcd.print("                ");
      m = 0;
      if (h == 24)
      {
        h = 0;
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
    }
  }
}





