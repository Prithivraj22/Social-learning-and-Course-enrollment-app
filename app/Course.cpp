#include "Course.h"

Course::Course(int id, string title, string category, string tutor, string syllabus, int difficulty, double price, float rating)
    : id(id), title(title), category(category), tutor(tutor), syllabus(syllabus), difficulty(difficulty), price(price), rating(rating) {}
