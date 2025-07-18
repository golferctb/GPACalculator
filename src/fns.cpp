#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
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
    string grade = line.substr(0, line.find(delimeter));

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

void quadraticSolver() {
    float a;
    float b;
    float c;
    
    cout << "Please enter a, b, c value. Press enter after each value " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    
    float delta = (b * b) - 4*a*c;
    
    if(delta < 0) {
        cerr << "There are no real solutions" << endl;
        return;
    }

    float x1 = (-b+sqrt(delta))/(2*a);
    float x2 = (-b-sqrt(delta))/(2*a);

    cout << "Solutions: {" << x1 << "," << x2 << "}" << endl;
}

// Displays the console menu
void displayMenu() {
    cout << "Welcome to the Calculator suite by Cale B.! Please type the number option and press enter!" << endl;
    bool cont = true;


    while(cont) {
        cout << "1. GPA Calculator" << endl;
        cout << "2. Quadratic Solver" << endl;
        cout << "Press q to quit.";
        cout << endl; // Adds an extra space for choosing options.
        char choice;
        cin >> choice;
    
        switch (choice) {
            case '1':
                calculateGPA(allCourses);
                break;
            case '2':
                quadraticSolver();
                break;
            case 'q':
                cont = false;
                break;
            default:
                cout << "Please enter a valid option." << endl;
        }
    }

    cout << "Thank you for using the program. See you soon!" << endl;
    
    return;
}