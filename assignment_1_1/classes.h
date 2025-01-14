
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

    void display() const {
        cout << "student id = " << id << ", name = " << name << ", email = " << email << endl;
    }
};



#endif //CLASSES_H
