void ClearBuffer()
{
    for(int i = TotalICPins - 1; i >=  0; i--)
    {
       Data[i] = LOW;
    }
    UpdateData();
} 
