#include "cgpa.cpp"

using namespace std;

int main() {
    welcome();

    for (int i = numOfSemesters; i > 0; i--) {
        Semester* semester = new Semester(i);
        semesters.push_back(semester);
    }
    
    for (int i = semesters.size(); i > 0; i--) {
        semesters[i - 1]->getClassesInSemester();
        semesters[i - 1]->getGradePoints();  
    }

    askEditSemester(semesters);

    for (int i = 0; i < semesters.size(); i++) {
        delete semesters[i];
    }
    
    semesters.clear();

    return 0;
}
