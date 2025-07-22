#include <iostream>

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;

class Time {
    private:
        double day;
        double hour;
        double minute;
        double second;
    public:
        Time() {
            day = 0;
            hour = 0;
            minute = 0;
            second = 0;
        }
        Time(double d, double h, double m, double s) {
            
            day = d;
            hour = h;
            minute = m;
            second = s;
        }
        void setDay(double d) {
            day = d;
        }
        void setHour(double h) {
            hour = h;
        }
        void setMinute(double m) {
            minute = m;
        }
        void setSecond(double s) {
            second = s;
        }
        double getDay() {
            return day;
        }
        double getHour() {
            return hour;
        }
        double getMinute() {
            return minute;
        }
        double getSecond() {
            return second;
        }
        double getTotalSecs() {
            double totalSecs = (second + (minute * SECONDS_PER_MINUTE) + (hour * MINUTES_PER_HOUR * SECONDS_PER_MINUTE) + (day * HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE));
            return totalSecs;
        }
        double getTotalMinutes() {
            double totalMinutes = (second / SECONDS_PER_MINUTE) + minute + (hour * MINUTES_PER_HOUR) + (day * HOURS_PER_DAY * MINUTES_PER_HOUR);
            return totalMinutes;
        }
        
};