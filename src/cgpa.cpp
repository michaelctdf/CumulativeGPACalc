#include "../include/cgpa.h"
#include "global.cpp"

using namespace std;

void Semester::getGradePoints() {
    string inputtedGrades;
    cout << "Enter grades: ";
    cin.ignore();
    getline(cin, inputtedGrades);
    
    removeSpaces(inputtedGrades);
    makeLowercase(inputtedGrades);
    inputtedGrades = inputtedGrades.substr(0, classes);

    for (int i = 0; i < inputtedGrades.length(); i++) {
            gradePoints += gradeToPoint(inputtedGrades[i]);
    }
    
    gradePoints += honors;
    totalPoints += gradePoints;
    semGPA = (float)gradePoints / (float)classes;
    currSemester++;
    updateCumGPA();
    showCurrGPAs();
}

void Semester::getClassesInSemester() {
    cout << "\nEnter # of classes taken in Semester " << numSemester << ": ";
    cin >> classes;
    totalClasses += classes;
    if (hasHonors) {
    cout << "Enter # of Honors classes: ";
    cin >> honors;
    }
}

void Semester::showCurrGPAs() {
    cout << fixed << setprecision(2) << "Semester " << numSemester << " GPA: " << semGPA << endl;
    cout << fixed << setprecision(2) << "Current cumulative GPA: " << cumGPA << endl;
}

void welcome() {
    askHonors();
    getSemestersTaken();
}

void askHonors() {
    cout << "Will Honors classes be considered? (y/n): ";
    char in;
    cin >> in;
    switch(in) {
        case 'y':
            hasHonors = true;
            break;
        case 'n':
            hasHonors = false;
            break;
        default:
            cout << "Invalid response." << endl;
            askHonors();
            break;
    }
}

void getSemestersTaken() {
    cout << "Enter # of semesters taken: ";
    cin >> numOfSemesters;
    if (numOfSemesters <= 0)
    {
        cout << "Invalid # of semesters." << endl;
        getSemestersTaken();
    }
    
}

void askEditSemester(vector<Semester*> &passVect) {
    cout << "Edit semester? (y/n): ";
    cin.ignore();
    char in; 
    cin >> in;
    switch (in)
    {
    case 'y':
        cout << "Which semester?: ";
        int reqSem; 
        cin >> reqSem;
        while(reqSem > semesters.size() || reqSem <= 0) {
            cout << "Invalid semester, input existing one: ";
            cin >> reqSem;
        }
        editSemester(passVect, reqSem);
        break;

    case 'n':
        break;

    default:
        cout << "Invalid input." << endl;
        askEditSemester(passVect);
        break;
    }
}

void editSemester(vector<Semester*> &vect, int &semID) {
    int targetSemID;
    for (int i = 0; i < vect.size(); i++) {
        if (semID == vect[i]->numSemester) {
            totalPoints -= vect[i]->gradePoints;
            totalClasses -= vect[i]->classes;
            targetSemID = i;
            break;
        }
        cout << "No matching semester found. Exiting..." << endl;
        return;
    }
    vect[targetSemID]->getClassesInSemester();
    vect[targetSemID]->getGradePoints();
    vect[targetSemID]->showCurrGPAs();
    askEditSemester(vect);
}

int gradeToPoint(char pCurrGrade) {
    char currGrade = tolower(pCurrGrade);
    switch(currGrade) {
        case 'a':
            return 4;
            break;
        case 'b':
            return 3;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 1;
            break;
        case 'f':
            return 0;
            break;
        default:
            return -999;
    }
}

void updateCumGPA() {
    cumGPA = (float)totalPoints / (float)totalClasses;
}

