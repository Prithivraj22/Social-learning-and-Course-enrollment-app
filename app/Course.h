#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <vector>
using namespace std;

class Course {
public:
    int id;
    string title, category, tutor, syllabus;
    int difficulty;
    double price;
    float rating;
    vector<string> reviews;
    
    Course(int id, string title, string category, string tutor, string syllabus, int difficulty, double price, float rating);
};

#endif
