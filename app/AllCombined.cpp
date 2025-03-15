#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Course {
public:
    int id;
    string title, category, tutor, syllabus;
    int difficulty;
    double price;
    float rating;
    vector<string> reviews;

    Course(int id, string title, string category, string tutor, string syllabus, int difficulty, double price, float rating)
        : id(id), title(title), category(category), tutor(tutor), syllabus(syllabus), difficulty(difficulty), price(price), rating(rating) {}
};

class Rewards {
public:
    static int globalRewardThresholds[3];
    int rewardPoints = 0;
    vector<string> badges;
    
    void addPoints(int points) {
        rewardPoints += points;
        assignBadge();
    }
    
    void assignBadge() {
        if (rewardPoints >= globalRewardThresholds[0] && badges.empty()) {
            badges.push_back("Bronze Learner");
        } else if (rewardPoints >= globalRewardThresholds[1] && badges.size() == 1) {
            badges.push_back("Silver Scholar");
        } else if (rewardPoints >= globalRewardThresholds[2] && badges.size() == 2) {
            badges.push_back("Gold Master");
        }
    }
    
    void showRewards(const string& userName) {
        cout << "\nRewards for " << userName << ": " << rewardPoints << " points\n";
        if (!badges.empty()) {
            cout << "Badges Earned: ";
            for (const auto& badge : badges) {
                cout << badge << " ";
            }
            cout << "\n";
        }
    }
};

int Rewards::globalRewardThresholds[3] = {30, 60, 100};

class User {
public:
    static int totalUsers;
    string name;
    vector<int> enrolledCourses;
    unordered_map<int, bool> courseCompletion;
    Rewards rewards;
    
    User(string name) : name(name) {
        totalUsers++;
    }
    
    void enroll(int courseId) {
        enrolledCourses.push_back(courseId);
        rewards.addPoints(10); // Earn 10 points per course
        courseCompletion[courseId] = false;
        cout << "\n[+] " << name << " enrolled in Course ID " << courseId << " and earned 10 points!\n";
    }
    
    void completeCourse(int courseId) {
        if (courseCompletion.find(courseId) != courseCompletion.end() && !courseCompletion[courseId]) {
            courseCompletion[courseId] = true;
            rewards.addPoints(20); // Earn extra points on completion
            cout << "\n[✔] " << name << " completed Course ID " << courseId << " and earned 20 points!\n";
        } else {
            cout << "\n[!] Course not found or already completed!\n";
        }
    }
    
    void showRewards() {
        rewards.showRewards(name);
    }
};

int User::totalUsers = 0;

void filterCourses(const vector<Course>& courses) {
    cout << "\nFilter by: 1. Category 2. Difficulty 3. Rating 4. Price\nChoose option: ";
    int option;
    cin >> option;
    
    if (option == 1) {
        cout << "Enter Category: ";
        string category;
        cin >> category;
        for (const auto& course : courses) {
            if (course.category == category) {
                cout << course.id << ". " << course.title << " - " << course.category << "\n";
            }
        }
    } else if (option == 2) {
        cout << "Enter Max Difficulty (1-5): ";
        int level;
        cin >> level;
        for (const auto& course : courses) {
            if (course.difficulty <= level) {
                cout << course.id << ". " << course.title << " - Difficulty: " << course.difficulty << "\n";
            }
        }
    } else if (option == 3) {
        cout << "Enter Min Rating: ";
        float rating;
        cin >> rating;
        for (const auto& course : courses) {
            if (course.rating >= rating) {
                cout << course.id << ". " << course.title << " - Rating: " << course.rating << "\n";
            }
        }
    } else if (option == 4) {
        cout << "Enter Max Price: ";
        double price;
        cin >> price;
        for (const auto& course : courses) {
            if (course.price <= price) {
                cout << course.id << ". " << course.title << " - Price: $" << course.price << "\n";
            }
        }
    }
}

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
        cout << "1. View Courses\n2. Enroll in Course\n3. Complete Course\n4. Show Rewards\n5. Filter Courses\n6. Exit\nChoose an option: ";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            for (const auto& course : courses) {
                cout << course.id << ". " << course.title << " - " << course.category << " | Rating: " << course.rating << "\n";
            }
        } 
        else if (choice == 2) {
            int courseId;
            cin >> courseId;
            if (courseMap.find(courseId) != courseMap.end()) user.enroll(courseId);
            else cout << "Invalid Course ID!\n";
        } 
        else if (choice == 3) {
            int courseId;
            cin >> courseId;
            user.completeCourse(courseId);
        }
        else if (choice == 4) {
            user.showRewards();
        }
        else if (choice == 5) {
            filterCourses(courses);
        }
        else if (choice == 6) break;
    }
    return 0;
}
