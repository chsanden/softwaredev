#ifndef MENU_H
#define MENU_H

#include <SQLiteCpp/SQLiteCpp.h>

void menuPrint();

void getStudent(const SQLite::Database &db); //Done

void addStudent(const SQLite::Database &db); //Done

void editStudent(const SQLite::Database &db); //Done

void deleteStudent(SQLite::Database &db); //Done

void searchStudent(const SQLite::Database &db); //Done

void readAll(const SQLite::Database &db); //Done

bool menuExit(bool &exit);



#endif //MENU_H
