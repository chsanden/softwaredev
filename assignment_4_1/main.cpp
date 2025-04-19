#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>
#include <sqlite3.h>

int main()
{
    const SQLite::Database db("school.sqlite", SQLite::OPEN_READONLY);
    SQLite::Statement queryAll(db, "SELECT * FROM students");

    while (queryAll.tryExecuteStep() == SQLITE_ROW)
    {
        int id = queryAll.getColumn("id");
        std::string name = queryAll.getColumn("student_name");
        std::string email = queryAll.getColumn("student_email");
        int year = queryAll.getColumn("student_year");
        std::cout  << "id: " << id << ", name: " << name << ", email: " << email << ", year: "<< year << std::endl;
        if (queryAll.isDone())
        {
            std::cout << "No more students in the database" << std::endl;
        }
    }
    if (queryAll.tryExecuteStep() != SQLITE_ROW)
    {
        std::cout << "No students found" << std::endl;
    }

}