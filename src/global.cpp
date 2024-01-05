#include "../include/global.h"

void makeLowercase(string &line) {
    for (int i = 0; i < line.length(); i++) {
        line[i] = tolower(line[i]);
    }
}

void removeSpaces(string &line) {
        int count = 0;
        for (int i = 0; line[i]; i++) {
            if(line[i] != ' ') {
                line[count++] = line[i];
            }
        }
        line[count] = '\0';
    }



