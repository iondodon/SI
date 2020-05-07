#pragma once
#include <Arduino.h>
#include "myKeypad.h"

FILE *myStdioOpen(Stream *);
FILE *myStdioOpen(Print *);
FILE *myStdioOpen(MyKeypad *);
