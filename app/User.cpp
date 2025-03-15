#include "User.h"
#include <iostream>
using namespace std;

int User::totalUsers = 0;

User::User(string name) : name(name) {
    totalUsers++;
}

void User::enroll(int courseId) {
    enrolledCourses.push_back(courseId);
    rewards.addPoints(10);
    courseCompletion[courseId] = false;
    cout << "\n[+] " << name << " enrolled in Course ID " << courseId << " and earned 10 points!\n";
}

void User::completeCourse(int courseId) {
    if (courseCompletion.find(courseId) != courseCompletion.end() && !courseCompletion[courseId]) {
        courseCompletion[courseId] = true;
        rewards.addPoints(20);
        cout << "\n[✔] " << name << " completed Course ID " << courseId << " and earned 20 points!\n";
    } else {
        cout << "\n[!] Course not found or already completed!\n";
    }
}

void User::showRewards() {
    rewards.showRewards(name);
}
