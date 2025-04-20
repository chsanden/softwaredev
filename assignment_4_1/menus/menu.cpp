#include "menu.h"
#include <iostream>
#include <sqlite3.h>
#include "../utils/utils.h"


void getStudent(const SQLite::Database &db)
{
    print_header("Get student");
    std::cout << "Enter the ID of the student" << std::endl;

    int id;
    std::cin >> id;
    SQLite::Statement query(db, "SELECT * FROM students WHERE id = ?");
    query.bind(1, id);
    if (query.tryExecuteStep() == SQLITE_ROW)
    {
        std::cout << "Student found" << std::endl;
        std::cout << "id: " << query.getColumn("id") << ", name: " << query.getColumn("name") <<
            ", email: " << query.getColumn("email") << ", year: " << query.getColumn("year") << std::endl;
    }
    else
    {
        std::cout << "Student not found" << std::endl;
    }
}

void addStudent(const SQLite::Database &db)
{
    print_header("Add student");
    std::cout << "Enter student name" << std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Enter student email" << std::endl;
    std::string email;
    std::getline(std::cin, email);
    std::cout << "Enter student year" << std::endl;
    int year;
    std::cin >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    SQLite::Statement insert_statement(db, "INSERT INTO students (name, email, year) VALUES (?, ?, ?)");
    insert_statement.bind(1, name);
    insert_statement.bind(2, email);
    insert_statement.bind(3, year);
    insert_statement.executeStep();

    SQLite::Statement query(db, "SELECT * FROM students WHERE name = ?");
    query.bind(1, name);

    bool found = false;
    while (query.tryExecuteStep() == SQLITE_ROW)
    {
        found = true;
        std::cout << "Added student: " << "id: " << query.getColumn("id") << ", name: " <<
                query.getColumn("name") << ", email: " << query.getColumn("email") <<
                ", year: " << query.getColumn("year") << std::endl;
    }
    if (!found)
    {
        std::cout << "Error: Unable to find the newly added student." << std::endl;
    }
    
}

void editStudent(const SQLite::Database &db)
{
    print_header("Edit student");
    std::cout << "Enter student ID:" << std::endl;
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    SQLite::Statement check_statement(db, "SELECT * FROM students WHERE id = ?");
    check_statement.bind(1, id);
    if (check_statement.tryExecuteStep() != SQLITE_ROW)
    {
        std::cout << "Student not found" << std::endl;
        return;
    }

    std::cout << "Enter student name" << std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Enter student email" << std::endl;
    std::string email;
    std::getline(std::cin, email);
    std::cout << "Enter student year" << std::endl;
    int year;
    std::cin >> year;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    SQLite::Statement update_statement(
        db, "UPDATE students SET name = ?, email = ?, year = ? WHERE id = ?");
    update_statement.bind(1, name);
    update_statement.bind(2, email);
    update_statement.bind(3, year);
    update_statement.bind(4, id);
    update_statement.executeStep();

    std::cout << "Student was edited successfully" << std::endl;
}

void deleteStudent (SQLite::Database &db)
{
    print_header("Remove student");
    std::cout << "Enter student ID" << std::endl;
    int id;
    std::cin >> id;
    const std::string delStatement = "DELETE FROM students WHERE id = " + std::to_string(id);
    int rowsAffected = db.exec(delStatement);

    if (rowsAffected != 1)
    {
        std::cout << "Student not found" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    std::cout << "Student was removed successfully" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void searchStudent(const SQLite::Database &db)
{
    // Search function that supports SQL LIKE wildcards (%)
    // Example: 'Jo%' will match 'John', 'Joseph', etc.
    print_header("Search student");
    std::cout << "Enter the name pattern to search for:" << std::endl;

    while (true)
    {
        std::string searchString;
        std::getline(std::cin, searchString);
        SQLite::Statement query(db, "SELECT * FROM students WHERE name LIKE ?");
        query.bind(1, searchString);
        if (searchString.empty())
        {
            break;
        }

        bool rowsFound = false;

        while (query.tryExecuteStep() == SQLITE_ROW)
        {
            rowsFound = true;
            int id = query.getColumn("id");
            std::string name = query.getColumn("name");
            std::string email = query.getColumn("email");
            int year = query.getColumn("year");
            std::cout << "id: " << id << ", name: " << name << ", email: " <<
                    email << ", year: " << year << std::endl;
        }
        if (!rowsFound)
        {
            std::cout << "No students found" << std::endl;
        }
        break;
    }
}

void readAll(const SQLite::Database &db)
{
    SQLite::Statement queryAll(db, "SELECT * FROM students");
    bool rowsFound = false;

    while (queryAll.tryExecuteStep() == SQLITE_ROW)
    {
        rowsFound = true;
        int id = queryAll.getColumn("id");
        std::string name = queryAll.getColumn("name");
        std::string email = queryAll.getColumn("email");
        int year = queryAll.getColumn("year");
        std::cout  << "id: " << id << ", name: " << name << ", email: " << email << ", year: "<< year << std::endl;
        if (queryAll.isDone())
        {
            std::cout << "No more students in the database" << std::endl;
        }
    }
    if (!rowsFound)
    {
        std::cout << "No students found" << std::endl;
    }
}

bool menuExit(bool &exit)
{
    exit = true;
    return true;
}

void menuPrint()
{
    print_header("Menu");
    std::cout << "1. Read all students" << std::endl;
    std::cout << "2. Get student" << std::endl;
    std::cout << "3. Add student" << std::endl;
    std::cout << "4. Edit student" << std::endl;
    std::cout << "5. Remove student" << std::endl;
    std::cout << "6. Search student" << std::endl;
    std::cout << "7. Exit" << std::endl;

}


