//============================================================================
// Name        : main.cpp
// Author      : Cale Bible
// Version     :
// Copyright   : This is a personal project
// Description : Commulative GPA Calculator
//============================================================================

// Include statements/preliminary statements
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Course.cpp"
using namespace std;

// Global variables
vector<Course> allCourses;

Course readData(string line) {
    const string delimeter = ",";
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


    return newCourse;
}

//TODO: Finish this function!!!!!!!
void readFile(string fileName) {
    string line;
    ifstream fileStream(fileName);

    // First line is heading file.
    getline (fileStream, line);

    while(getline (fileStream, line)) {
        if(!line.empty()) {
            allCourses.push_back(readData(line));
        }
    }
}


// Function that converts grade input to grade point value.
int main() {
    readFile("TestFile.csv");
    
    float totalGradePts = 0.0;
    int creditSum = 0;

    for(Course c : allCourses) {
        totalGradePts += (c.getCredits() * c.getGrade());
        creditSum += c.getCredits();
    }

    cout << "Your Commulative GPA is: " << (totalGradePts/creditSum) << endl;
}