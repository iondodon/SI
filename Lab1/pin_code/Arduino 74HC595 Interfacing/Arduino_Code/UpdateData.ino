void UpdateData()
{
   digitalWrite(RCLK, LOW);
   for(int i = TotalICPins - 1; i >=  0; i--)
   {
        digitalWrite(SRCLK, LOW);   
        digitalWrite(SER, Data[i]);
        digitalWrite(SRCLK, HIGH);

  }
  digitalWrite(RCLK, HIGH);
}
