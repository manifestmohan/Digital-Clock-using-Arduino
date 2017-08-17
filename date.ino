void daterun()
{
  ++dd;
  int dn = 0;
  if ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))
  {
    dn = 1;
  }
  else if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
  {
    dn = 3;
  }
  else
  {
    dn = 2;
  }

  switch (mm)
  {
    case 1: if (dd == 32)
      {
        ++mm;
        dd = 1;
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
      break;
    case 2: if (yy % 4 == 0)
      {
        if (dd == 30)
        {
          ++mm;
          dd = 1;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      else
      {
        if (dd == 29)
        {
          ++mm;
          dd = 1;
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
      break;
    case 3: if (dd == 31)
      {
        ++mm;
        dd = 1;
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
      break;

  }
  if (mm == 13)
  {
    ++yy;
    mm = 1;
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }
}


