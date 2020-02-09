int RCLK = 5;
int SER = 6;
int SRCLK = 7;

#define TotalIC 1
#define TotalICPins TotalIC * 8

boolean Data[TotalICPins];

void setup()
{
  pinMode(SER, OUTPUT);
  pinMode(RCLK, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  ClearBuffer();
}              


void loop()
{
   for(int i = TotalICPins - 1; i >=  0; i--)
   {
      Data[i] = HIGH;
      UpdateData();
      delay(300);
      ClearBuffer();
   }

   for(int i = 1;i < TotalICPins - 1;  i++)
   {
      Data[i] = HIGH;
      UpdateData();
      delay(300);
      ClearBuffer();
   }
   
}
