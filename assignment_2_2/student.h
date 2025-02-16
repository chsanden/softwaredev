
#ifndef STUDENT_H
#define STUDENT_H
#include <string>


using namespace std;
class Student {
private:
    int id;
    string name;
    int age;
    int attendance;

public:
    Student() : id(0), name(""), age(0), attendance(0) {}
    explicit Student(int id) : id(id), name(""), age(0), attendance(0) {}

    void setId(const int id)
    {
        this -> id = id;
    }
    void setName(const string& name)
    {
        this -> name = name;
    }
    void setAge(const int age)
    {
        this -> age = age;
    }
    void setAttendance (const int attendance)
    {
        this -> attendance = attendance;
    }

    int getID() const {
        return id;
    }
    string getName() const
    {
        return name;
    }
    int getAge() const
    {
        return age;
    }
    int getAttendance() const
    {
        return attendance;
    }
};











#endif //STUDENT_H
