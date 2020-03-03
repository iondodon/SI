#ifndef FILTERS_HEADER
#define FILTERS_HEADER

void pushTemp(double *arr, double newTemp);
void swap(double &a, double &b);
void sortArr(double *arr);

void calculateMedian(double *rawBuff, double *medianBuff);
double getWeighterAverage(double *medianBuff);

#endif
