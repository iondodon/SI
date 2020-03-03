void pushTemp(double arr[3], double newTemp) {
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = newTemp;
}

void swap(double &a, double &b) {
    double c = a;
    a = b;
    b = c;
}

void sortArr(double arr[3]) {
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
    if(arr[1] > arr[2]) swap(arr[1], arr[2]);
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
}

void calculateMedian(double rawBuff[3], double medianBuff[3]) {
    sortArr(rawBuff);
    pushTemp(medianBuff, rawBuff[1]);
}

double getWeighterAverage(double medianBuff[3]) {
    sortArr(medianBuff);
    return (medianBuff[0] + medianBuff[2]) / 2;
}