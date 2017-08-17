void setalarm() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter H:");
  ha = value();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter M:");
  ma = value();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("enter S:");
  sa = value();
}
