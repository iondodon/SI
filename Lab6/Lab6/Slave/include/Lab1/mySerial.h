#pragma once

class MySerial {
    public:
    MySerial();
    void openStream();
    int hasMessage();
};