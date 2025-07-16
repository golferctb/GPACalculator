//============================================================================
// Name        : TestProject.cpp
// Author      : Cale Bible
// Version     :
// Copyright   : This is a personal project
// Description : Commulative GPA Calculator
//============================================================================

#include <iostream>
#include <string>
#include <vector>
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
};

Course readData(string line, string delimeter) {
    
    // Finds the name of the course.
    string courseName = line.substr(0, line.find(delimeter));
    // Removes the course name to continue checking values.
    line = line.substr(line.find(delimeter) + delimeter.size(), line.size());
    // Finds the string value for credits
    string credits = line.substr(0, line.find(delimeter));
    line = line.substr(line.find(delimeter) + delimeter.size(), line.size());
    string grade = line.substr(0, line.find(delimeter));;

    Course newCourse;
    newCourse.setCourseName(courseName);
    newCourse.setCredits(stoi(credits));
    newCourse.setGrade(grade);

    // Debugging
    cout << newCourse.getCourseName() << " ";
    cout << newCourse.getCredits() << " ";
    cout << newCourse.getGrade() << " ";

    return newCourse;
}

//TODO: Write this function
void readFile(string fileName) {

}


// Function that converts grade input to grade point value.
int main() {
    readData("Math,3,A+", ",");
}