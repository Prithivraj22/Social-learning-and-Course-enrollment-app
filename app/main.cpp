#include "User.h"
#include "Course.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<Course> courses = {
        {1, "C++ Basics", "Programming", "Alice", "Loops, Functions, OOP", 1, 499.99, 4.5},
        {2, "Data Structures", "CS", "Bob", "Arrays, Linked Lists, Trees", 2, 799.99, 4.7},
        {3, "Machine Learning", "AI", "Charlie", "Regression, Neural Networks", 3, 1499.99, 4.8}
    };
    
    User user("Prithiv");
    unordered_map<int, Course> courseMap;
    for (const auto& course : courses) {
        courseMap[course.id] = course;
    }
    
    while (true) {
        cout << "\n--- Course Enrollment System ---\n";
        cout << "1. View Courses\n2. Enroll in Course\n3. Complete Course\n4. Show Rewards\n5. Exit\nChoose an option: ";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            cout << "\nAvailable Courses:\n";
            for (const auto& course : courses) {
                cout << course.id << ". " << course.title << " - " << course.category
                     << " | Tutor: " << course.tutor << " | Price: $" << course.price
                     << " | Rating: " << course.rating << "\nSyllabus: " << course.syllabus << "\n";
            }
        } 
        else if (choice == 2) {
            cout << "Enter Course ID to enroll: ";
            int courseId;
            cin >> courseId;
            
            if (courseMap.find(courseId) != courseMap.end()) {
                user.enroll(courseId);
            } else {
                cout << "Invalid Course ID!\n";
            }
        } 
        else if (choice == 3) {
            cout << "Enter Course ID to mark as completed: ";
            int courseId;
            cin >> courseId;
            user.completeCourse(courseId);
        }
        else if (choice == 4) {
            user.showRewards();
        } 
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
