#include <limits>
#include "classes.cpp"


using namespace std;

int main() {

    map<int, Student> studentMap;
    int addCount = 1;




    while (true) {
        startMenu();
        int input = 0;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (input == 1) {
            //Getting the info from user
            cout<<"Please enter the full name of the student"<<endl;
            string sName;
            getline(cin,sName);
            cout<<"Please enter the email of the student"<<endl;
            string sEmail;
            getline(cin,sEmail);

            //Creating a new object from the information
            Student newStudent(addCount, sName, sEmail);
            studentMap.emplace(addCount, newStudent);

            //Confirmation
            cout<<"You have added the following student: "<<endl;
            studentMap[addCount].display();
            cout<<"\n \n"<<endl;
            addCount++;
            input = 0;
        }
        if (input == 2) {
            cout<<"Please enter the ID of the student you wish to edit"<<endl;
            int id = 0;
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            //Re-running the first if-loop
            cout<<"Please enter the full name of the student"<<endl;
            string sName;
            getline(cin,sName);
            cout<<"Please enter the email of the student"<<endl;
            string sEmail;
            getline(cin,sEmail);

            //Updating the object with new info
            Student updatedStudent(id, sName, sEmail);
            studentMap[id] = updatedStudent;
            cout<<"The student has now been updated"<<endl;

        }
        if (input == 3) {
            cout<<"Please enter the ID of the student you wish to remove"<<endl;
            int id = 0;
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string blank = "";
            Student blankStudent(id, blank, blank);
            studentMap[id] = blankStudent;
            cout<<"The student has now been removed!"<<endl;

        }
        if (input == 4) {

        }
        if (input == 5) {

        }
        if (input == 6) {

        }
        if (input == 7) {

        }
        if (input == 8) {

        }
        if (input == 9) {

        }
        if (input == 10) {
            if (studentMap.empty()) {
                cout << "No students to display.\n";
            }

            cout << "List of students:\n";
            for (const auto& pair : studentMap) {
                pair.second.display();
            }
        }
        if (input == 11) {
            return 0;
        }

    }







    return 0;
}

