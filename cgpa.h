#ifndef CGPA_H
#define CGPA_H
#include <vector>

using namespace std;

class Semester {
    public:
        int numSemester;
        void getClassesInSemester();
        void getGradePoints();
        void showCurrGPAs();
        float semGPA = 0;
        int classes;
        int gradePoints = 0;
        int honors = 0;
        Semester(int numSemester) {
            this->numSemester = numSemester;
        }
        ~Semester() {}
};

int numOfSemesters;
int currSemester = 1;
int totalPoints = 0;
int totalClasses = 0;
float cumGPA;
bool hasHonors;
char *grade;

void welcome();

void updateCumGPA();

void askHonors();

void getSemestersTaken();

int gradeToPoint(char pCurrGrade);

void askEditSemester(vector<Semester*> &passVect);

vector<Semester*> semesters;

void editSemester(vector<Semester*> &vect, int &semID);

#endif

