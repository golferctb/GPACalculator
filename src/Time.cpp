#include <iostream>

class Time {
    private:
        double day;
        double hour;
        double minute;
        double second;
    public:
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
        
};