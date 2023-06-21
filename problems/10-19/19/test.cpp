#include <iostream>
#include <algorithm>
#include <string>
#include<map>
#include <list>
using namespace std;


/*
You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
- A leap year occurs on any year evenly divisible by 4, but not on a 
    century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century 
    (1 Jan 1901 to 31 Dec 2000)?
*/
class MyDateClass {       
  public:             
    int dayofweek;
    int day;        // Attribute (int variable)
    int month;
    int year;
    bool isleapyear;

    void incrementDate(){
        dayofweek = (dayofweek + 1) % 7; 
        day++;
        if (day > getmonthdays(month)) {
            incrementMonth();
            day = 1;
        }
    }

    int getmonthdays(int month) {
        if (month == 4 || month == 6 || month == 9 || month == 11){
            return 30;
        } else if (month == 2){
            if (isleapyear) return 29;
            else return 28;
        } else return 31;
    }

    void incrementMonth() {
        month++;
        if (month > 12) {
            incrementYear();
            month = 1;
        }
    }

    void incrementYear() {
        year++;
        if (year % 4 == 0){
            if (year % 100 == 0) {
                if (year % 400 == 0) isleapyear = true;
                else isleapyear = false;
            } else isleapyear = true;
        } else isleapyear = false;
    }

    string dayName(){
        switch (dayofweek)
        {
        case 0:
            return "Monday";
        case 1:
            return "Tuesday";
        case 2:
            return "Wednesday";
        case 3:
            return "Thursday";
        case 4:
            return "Friday";
        case 5:
            return "Saturday";
        case 6:
            return "Sunday";
        default:
            return "Unknown";
        }
    }

    void printDate() {
        cout << "Date: " << dayName() << ", " << month << "/" << day << "/" << year;
    }
};


int main() {
    int sundaycounter = 0;

    MyDateClass d;
    d.dayofweek = 0; d.day = 1; d.month = 1; d.year = 1900; d.isleapyear = false;
    while (d.year < 2001) {
        d.incrementDate();
        // d.printDate();
        if (d.dayofweek == 6 && d.day == 1 && d.year > 1900) sundaycounter++;
        // cout << " --- Sunday counter: " << sundaycounter << endl;
    }
    cout << "Number of Sundays between 1/1/1901 -> 12/31/2000 occuring on the ";
    cout << "first of the month: " << sundaycounter << endl;
}