#include <fstream>
#include <sstream>
#include "rapidjson/document.h"
#include <iostream>
#include <list>
#include "student.h"


int main() {
    std::list<Student*>studentArray;

    std::ifstream file("students.json");
    if(!file.is_open()) {
        std::cerr<<"Failed to open students.json"<<std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string jsonString = buffer.str();

    rapidjson::Document document;
    if (document.Parse(jsonString.c_str()).HasParseError()) {
        std::cerr<<"Failed to parse JSON"<<std::endl;
        return 1;
    }

    if (!document.IsArray()) {
        std::cerr<<"JSON is not an array"<<std::endl;
        return 1;
    }


    for (int i = 0; i < document.Size(); i++) {
        const rapidjson::Value &student = document[i];
        auto* s = new Student();

        if(student.HasMember("id") && student["id"].IsInt()) {
            s->setId(student["id"].GetInt());
        }

        if (student.HasMember("name")&&student["name"].IsString()) {
            s->setName(student["name"].GetString());
        }

        if (student.HasMember("age") && student["age"].IsInt()) {
            s->setAge(student["age"].GetInt());
        }

        if (student.HasMember("attendance") && student["attendance"].IsInt()) {
            s->setAttendance(student["attendance"].GetInt());
        }
        studentArray.push_back(s);
    }

    if(studentArray.empty()) {
        std::cerr<<"No students found in JSON"<<std::endl;
        return 1;
    }

    auto it = studentArray.begin();
    Student* youngest = *it;
    Student* oldest = *it;
    it++;
    for (; it != studentArray.end(); it++) {
        Student* current = *it;
        if(current->getAge() < youngest->getAge()) {
            youngest = current;
        }
        if(current->getAge() > oldest->getAge()) {
            oldest = current;
        }
    }

        int totalAge = 0;
        int count = 0;
        for(auto* i : studentArray) {
            totalAge += i->getAge();
            count++;
        }
        int averageAge = 0;
        if(count>0) {
            averageAge = totalAge/count;
        }

        std::cout<<"Youngest: "<<youngest->getName()
        <<"\nOldest: "<<oldest->getName()
        <<"\nAverage age: "<<averageAge<<std::endl;

        for (auto* i : studentArray) {
            if(i->getAttendance()<30) {
                std::cout<<"Bad student: "<<i->getName()<<std::endl;
            }
        }

        for (auto* i : studentArray) {
            delete i;
        }
    return 0;
    }









