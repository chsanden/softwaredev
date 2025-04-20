#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>
#include "menus/menu.h"
#include "utils/utils.h"

int main()
{
    SQLite::Database db("school.sqlite", SQLite::OPEN_READWRITE);
    bool exit = false;


    while (!exit)
    {
        menuPrint();
        int choice;
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cout << "Invalid input, try again" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch (choice)
        {
            case 1: readAll(db); break;
            case 2: getStudent(db); break;
            case 3: addStudent(db); break;
            case 4: editStudent(db); break;
            case 5: deleteStudent(db); break;
            case 6: searchStudent(db); break;
            case 7: menuExit(exit); break;
            default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}