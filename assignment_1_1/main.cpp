#include <limits>
#include "classes.cpp"


using namespace std;



int main() {
    map<int, Student> studentMap;
    map<int, Test> testMap;
    map<pair<int, int>, Result> resultMap;

    int addStudentCount = 1;
    int addTestCount = 1;


    while (true) {
        startMenu();
        int input = 0;

        if (!(cin >> input)) {
            cout << "This is not a number, please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        if (input == 1) {
            //Getting the info from user
            cout<<"Please enter the full name of the student"<<endl;
            string sName;
            getline(cin,sName);
            cout<<"Please enter the email of the student"<<endl;
            string sEmail;
            getline(cin,sEmail);


            //Creating a new object from the input information
            Student newStudent(addStudentCount, sName, sEmail);
            studentMap.emplace(addStudentCount, newStudent);

            //Confirmation
            cout<<"You have added the following student: "<<endl;
            studentMap[addStudentCount].display();
            cout<<"\n \n"<<endl;
            addStudentCount++;


        }


         if (input == 2) {
            cout<<"Please enter the ID of the student you wish to edit"<<endl;
            int id = 0;
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (id > studentMap.size()) {
                cout<<"That student doesn't exist"<<endl;
            }

            if (id <= studentMap.size()) {
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
            ;
        }


         if (input == 3) {
            cout<<"Please enter the ID of the student you wish to remove"<<endl;
            int id = 0;
            //Writing over the student instead of erasing due to the
            //reuse of any id being outlawed
            cin>>id;
            string removeName = studentMap[id].name;
            string blank = "";
            Student blankStudent(id, blank, blank);
            studentMap[id] = blankStudent;
            cout<<"The student, " << removeName << ", has now been removed!"<<endl;


        }


         if (input == 4) {
            cout<<"Please enter the course name of the test"<<endl;
            string courseName;
            getline(cin,courseName);
            cout<<"Please enter the name of the test"<<endl;
            string testName;
            getline(cin,testName);
            cout<<"Please enter the date of the test"<<endl;
            string testDate;
            getline(cin,testDate);

            Test newTest(addTestCount, courseName, testName, testDate);
            testMap.emplace(addTestCount, newTest);
            testMap[addTestCount].display();


            addTestCount++;
        }


         if (input == 5) {
             cout<<"Please enter the ID of the test you wish to edit"<<endl;
             int id = 0;
             cin>>id;
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             if (id > testMap.size()) {
                 cout<<"That test doesn't exist"<<endl;
             }

             if (id <= testMap.size()) {
                 //Re-running the first if-loop
                 cout<<"Please enter the course name of the test"<<endl;
                 string courseName;
                 getline(cin,courseName);
                 cout<<"Please enter the name of the test"<<endl;
                 string testName;
                 getline(cin,testName);
                 cout<<"Please enter the date of the test"<<endl;
                 string testDate;
                 getline(cin,testDate);

                 //Updating the object with new info
                 Test updatedTest(id, courseName, testName, testDate);
                 testMap[id] = updatedTest;
                 cout<<"The test has now been updated"<<endl;

             }
         }

             if (input == 6) {
                 cout<<"Please enter the ID of the test you wish to remove"<<endl;
                 int id = 0;
                 //Writing over the test instead of erasing due to the
                 //reuse of any id being outlawed
                 cin>>id;
                 string removeName = testMap[id].name;
                 string blank = "";
                 Test blankTest(id, blank, blank, blank);
                 testMap[id] = blankTest;
                 cout<<"The test, " << removeName << ", has now been removed!"<<endl;

            }


            if (input == 7) {
                cout<<"Please enter the student ID that you want to add a result to"<<endl;
                int studentID = 0;
                cin>>studentID;
                if(studentMap.find(studentID) == studentMap.end()) {
                    cout<<"That student doesn't exist"<<endl;
                    continue;
                }

                cout<<"Please enter the test ID that you want to add a result to"<<endl;
                int testID = 0;
                cin>>testID;
                if(testMap.find(testID) == testMap.end()) {
                    cout<<"That test doesn't exist"<<endl;
                    continue;
                }

                cout<<"Please enter the grade of the test"<<endl;
                int grade = 0;
                cin>>grade;

                Student student = studentMap[studentID];
                Test test = testMap[testID];
                Result newResult(studentMap[studentID].id, testMap[testID].course, testMap[testID].id,
                    testMap[testID].name, grade);



                resultMap.emplace(make_pair(studentID, testID), newResult);

                cout << "Result added successfully!"<<endl;
                resultMap[make_pair(studentID, testID)].display();
            }


            if (input == 8) {
                cout<<"Please enter the Student ID for which you would like to edit a test result"<<endl;
                int studentID = 0;
                cin>>studentID;
                if(studentMap.find(studentID) == studentMap.end()) {
                    continue;
                }
                cout<<"Please enter the Test ID of which you would like to change the result"<<endl;
                int testID = 0;
                cin>>testID;
                if(testMap.find(testID) == testMap.end()) {
                    continue;
                }
                cout<<"Please enter the new grade of the test"<<endl;
                int grade = 0;
                cin>>grade;
                resultMap[make_pair(studentID, testID)].grade = grade;
                cout<<"The following has been saved:"<<endl;
                resultMap[make_pair(studentID, testID)].display();

            }


            if (input == 9) {
                cout<<"Please enter the Student ID of which you want to remove a test a result"<<endl;
                int studentID = 0;
                cin>>studentID;
                if(studentMap.find(studentID) == studentMap.end()) {
                    continue;

                }
                cout<<"Please enter the Test ID of the result you want to remove"<<endl;
                int testID = 0;
                cin>>testID;
                if(testMap.find(testID) == testMap.end()) {
                    continue;

                }
                cout<<"The following result has been removed:"<<endl;
                resultMap[make_pair(studentID, testID)].display();
                resultMap.erase(make_pair(studentID, testID));

            }

            //Displaying all items
            if (input == 10) {
                cout << "Student details:\n";
                for (const auto& pair : studentMap) {
                    pair.second.displayAll();
                }
                cout << "\nTest details:\n";
                for (const auto& pair : testMap) {
                    pair.second.displayAll();
                }
                cout<<"\nTest details:\n";
                for (const auto& pair : resultMap) {
                    pair.second.displayAll();
                }
            }


            if (input == 11) {
                return 0;
            }
    }
}