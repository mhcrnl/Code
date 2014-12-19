#include <stdio.h>
#include "book.h"
#include "date.h"

unsigned int leap_year(unsigned int year)
{
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 !=0)) return 1;
    return 0;
}

unsigned int count_days(struct Date date_borrowed,struct Date date_returned)
{
    unsigned int days[2] = {0};
    unsigned int month_to_day[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    days[0] = date_borrowed.day + month_to_day[date_borrowed.month - 1];
    if(date_borrowed.month > 2) days[0] += leap_year(date_borrowed.year);
    days[1] = date_returned.day + month_to_day[date_returned.month - 1];
    if(date_returned.month > 2) days[1] += leap_year(date_returned.year);
    unsigned int i = 0;
    for(i = date_borrowed.year ; i < date_returned.year ; i++) days[1] += (365 + leap_year(i));
    return days[1] - days[0] + 1;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned)
{
    unsigned int digit = 1, flag[2];
    unsigned int importance = book.importance;
    while(importance != 0)
    {
        if(importance == 1) flag[1] = digit;
        else if(importance % 2 == 1) flag[0] = digit;
        importance /= 2;
        digit++;
    }
    unsigned int days = count_days(date_borrowed, date_returned);
    unsigned int days_allowed[4] = {90, 10, 100, 5};
    if(days_allowed[book.type] >= days) return 0;
    else return (days - days_allowed[book.type]) * (flag[1] - flag[0] - 1);
}

int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2007;
    date_borrowed.month = 11;
    date_borrowed.day   = 14;
    date_returned.year  = 2007;
    date_returned.month = 12;
    date_returned.day   = 3;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}
