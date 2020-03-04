void pushTemp(int *arr, int newTemp) {
    arr[0] = arr[1];
    arr[1] = arr[2];
    arr[2] = newTemp;
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void sortArr(int *arr) {
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
    if(arr[1] > arr[2]) swap(arr[1], arr[2]);
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
}

void calculateMedian(int *rawBuff, int *medianBuff) {
    sortArr(rawBuff);
    pushTemp(medianBuff, rawBuff[1]);
}

int getWeighterAverage(int *medianBuff) {
    int weight0 = 50, weight1 = 25, weight2 = 10;
    return (medianBuff[0] * weight0 + medianBuff[1] * weight1 + medianBuff[2] * weight2)
             / 
            (weight1 + weight1 + weight2);
}
