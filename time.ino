
void timerun() {
  // put your main code here, to run repeatedly:
  ++ss;
  if (ss == 60)
  {
    ++ms;
    ss = 00;
    lcd.setCursor(0, 0);
    lcd.print("                ");
    if (ms == 60)
    {
      ++hs;
      ms = 00;
      lcd.setCursor(0, 0);
      lcd.print("                ");
      if (hs == 24)
      {
        daterun();
        hs = 00;
        lcd.setCursor(0, 0);
        lcd.print("                ");
      }
    }
  }
}

void displaytime()
{
  lcd.setCursor(0, 0);
  lcd.print("TIME:");
  lcd.print(hs, DEC);
  lcd.print(":");
  lcd.print(ms, DEC);
  lcd.print(":");
  lcd.print(ss, DEC);
}
