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
        if(line.empty()) {
            continue;
        }
        allCourses.push_back(readData(line));
    }
}

void calculateGPA(vector<Course> courses) {
    float totalGradePts = 0.0;
    int creditSum = 0;

    string fileName;
    
    cout << "Welcome to the GPA calculator! (Version 1.0)" << endl;
    cout << "Please enter the csv file to be processed: --> ";
    cin >> fileName;
    readFile(fileName);

    for(Course c : allCourses) {
        totalGradePts += (c.getCredits() * c.getGrade());
        creditSum += c.getCredits();
    }
    
    cout << "Your commulative GPA is " << (totalGradePts / creditSum) << endl;
    return;
}

// Displays the console menu
void displayMenu() {
    cout << "Welcome to the Calculator suite by Cale B.! Please type the number option and press enter!" << endl;
    cout << "1. GPA Calculator" << endl << endl;
    char choice;
    cin >> choice;
    
    switch (choice) {
        case '1':
            calculateGPA(allCourses);
            break;
        default:
            cout << "Please enter a valid option." << endl;
    }
    return;
}