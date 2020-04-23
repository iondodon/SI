#include <Arduino.h>
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "timer-api.h"

#define OFS_Lab1 1000
#define REC_Lab1 1000
int rec_cnt_Lab1 = OFS_Lab1;
void TaskLab1() {
    Lab1 lab1;
    lab1.setup();
    lab1.loop();
}

#define OFS_Lab2 10000
#define REC_Lab2 1000
int rec_cnt_Lab2 = OFS_Lab2;
void TaskLab2() {
    Lab1 lab2;
    lab2.setup();
    lab2.loop();
}

#define OFS_Lab3 100000
#define REC_Lab3 1000
int rec_cnt_Lab3 = OFS_Lab3;
void TaskLab3() {
    Lab1 lab3;
    lab3.setup();
    lab3.loop();
}

#define OFS_Lab4 1000000
#define REC_Lab4 1000
int rec_cnt_Lab4 = OFS_Lab4;
void TaskLab4() {
    Lab1 lab4;
    lab4.setup();
    lab4.loop();
}

void timer_handle_interrupts(int timer) {
    if(--rec_cnt_Lab1 <= 0) {
        TaskLab1();
        rec_cnt_Lab1 = REC_Lab1;
    }
    if(--rec_cnt_Lab2 <= 0) {
        TaskLab2();
        rec_cnt_Lab2 = REC_Lab2;
    }
    if(--rec_cnt_Lab3 <= 0) {
        TaskLab3();
        rec_cnt_Lab3 = REC_Lab3;
    }
    if(--rec_cnt_Lab4 <= 0) {
        TaskLab4();
        rec_cnt_Lab4 = REC_Lab4;
    }
}

void setup() {
    timer_init_ISR_1KHz(TIMER_DEFAULT);
}

void loop() { }