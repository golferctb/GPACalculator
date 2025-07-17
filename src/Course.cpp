#include <iostream>
#include <string>
using namespace std;

class Course {
    private:
        string courseName;
        int credits;
        float grade;
    public:
        float getGradeValue(string grade) {
            float value;
            if(grade == "A+")
                value = 4.3;
            else if (grade == "A")
                value =  4.0;
            else if (grade == "A-")
                value =  3.7;
            else if (grade == "B+")
                value =  3.3;
            else if (grade == "B")
                value =  3.0;
            else if (grade == "B-")
                value =  2.7;
            else if (grade == "C+")
                value =  2.3;
            else if (grade == "C")
                value = 2;
            else if (grade == "C-")
                value = 1.7;
            else if (grade == "D+")
                value = 1.3;
            else if (grade == "D")
                value = 1;
            else if (grade == "D-")
                value = 0.7;
            else if (grade == "F")
                value = 0;
            else
                throw runtime_error("Please enter a valid grade.");
            return value;
        }
        void setCourseName(string c) {
            courseName = c;
        }
        void setCredits(int c) {
            credits = c;
        }
        void setGrade(string g) {
            grade = getGradeValue(g);
        }
        string getCourseName() {
            return courseName;
        }
        int getCredits() {
            return credits;
        }
        float getGrade() {
            return grade;
        }
        void print() {
            
            cout << "----------" << endl;
            cout << "Course Name: " << courseName << endl;
            cout << "Credits: " << credits << endl;
            cout << "Grade: " << grade << endl;
            cout << "----------" << endl;
        }
};