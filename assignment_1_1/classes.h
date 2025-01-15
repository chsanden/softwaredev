
#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <iostream>
#include <map>
using namespace std;



class Student{

public:
    int id;
    string name;
    string email;

    Student() : id(-1), name(""), email("") {}

    Student(int id, string name, string email) : id(id), name(name), email(email) {}

    void displayAll() const {
        cout << "student id = " << id << ", name = " << name << ", email = " << email << endl;
    }

    void display() const {
        cout << "Student id: " << id << "\nName: " << name << "\ne-mail: " << email << endl;
    }
};

class Test {
    public:
    int id;
    string course;
    string name;
    string date;

    Test() : id(-1), course(""), name(""), date("") {}

    Test(int id, string course, string name, string date) : id(id), course(course), name(name), date(date) {}

    void display() const {
        cout << "Test id: " << id
        << "\nCourse name: "<< course
        << "\nTest name: " << name
        << "\nDate: " << date << endl;
    }

    void displayAll() const {
        cout << "test id = " << id
        << ", course name = " << course
        << ", test name = " << name
        << ", date = " << date << endl;
    }
};

class Result {
    public:
    int studentId;
    string courseName;
    int testId;
    string testName;
    int grade;

    Result() : studentId(-1),courseName(""), testId(-1), testName(""), grade(-1) {}

    Result(int studentId, string courseName, int testId, string testName, int grade) : studentId(studentId),
    courseName(courseName), testId(testId), testName(testName), grade(grade){}

    void display() const {
        cout << "Student ID: " << studentId
        << "\nCourse Name: " << courseName
        << "\nTest ID: " << testId
        << "\nTest Name: " << testName
        << "\nGrade: " << grade << endl;
    }

    void displayAll() const {
        cout << "student id = " << studentId
        <<", course name = " << courseName
        << ", test id = " << testId
        << ", test name = " << testName
        << ", grade = " << grade << endl;
    }

};


#endif //CLASSES_H
