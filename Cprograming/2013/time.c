#include <stdio.h>
#include <stdlib.h>
#include "time.h"

void initTime(Time *time)
{
    time->hour = 0;
    time->minute = 0;
    time->second = 0;
    return;
}

void setTime(Time *time, int hour, int minute, int second)
{
    time->hour = hour;
    time->minute = minute;
    time->second = second;
    return;
}

void addTime(Time *time, int hour, int minute, int second)
{
    int tmp = 0;
    time->second += second;
    tmp = (time->second) / 60;
    time->second %= 60;
    time->minute += minute;
    time->minute += tmp;
    tmp = (time->minute) / 60;
    time->minute %= 60;
    time->hour += hour;
    time->hour += tmp;
    time->hour %= 24;
    return;
}

void printTime(Time *time)
{
#ifdef H24
    printf("%d%d:", (time->hour) / 10, (time->hour) % 10);
#endif
#ifndef H24
    printf("%d%d", ((time->hour) % 12) / 10, ((time->hour) % 12) % 10);
    if(time->hour < 12) printf("am:");
    else printf("pm:");
#endif
    printf("%d%d:%d%d\n", (time->minute) / 10, (time->minute) % 10, (time->second) / 10, (time->second) % 10);
    return;
}
