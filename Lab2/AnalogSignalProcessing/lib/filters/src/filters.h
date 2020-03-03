#ifndef FILTERS_HEADER
#define FILTERS_HEADER

void pushTemp(double arr[3], double newTemp);
void swap(double &a, double &b);
void sortArr(double arr[3]);

void calculateMedian(double rawBuff[3], double medianBuff[3]);
double getWeighterAverage(double medianBuff[3]);

#endif
