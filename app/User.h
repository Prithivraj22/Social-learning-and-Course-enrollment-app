#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Rewards.h"
using namespace std;

class User {
public:
    static int totalUsers;
    string name;
    vector<int> enrolledCourses;
    unordered_map<int, bool> courseCompletion;
    Rewards rewards;
    
    User(string name);
    void enroll(int courseId);
    void completeCourse(int courseId);
    void showRewards();
};

#endif
