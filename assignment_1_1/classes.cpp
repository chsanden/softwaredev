#include "classes.h"
using namespace std;

static void startMenu() {
    cout<<"Please choose:"<<endl
    <<"\n"
    << "1. Add student" <<endl
    <<"2. Edit student" <<endl
    <<"3. Remove student" <<endl
    <<"\n"
    << "4. Add test" <<endl
    <<"5. Edit test" <<endl
    <<"6. Remove test" <<endl
    <<"\n"
    << "7. Add test result"<<endl
    <<"8. Edit test result"<<endl
    <<"9. Remove test result"<<endl
    <<"\n"
    <<"10. Show all info"<<endl
    <<"11. Exit"<<endl;
    int input = 0;
    cin >> input;
    if (input == 11) {
        return;
    }
    if (input == 1) {

    }
    if (input == 2) {

    }
    if (input == 3) {

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

    }
    else {
        cout<<"An error has occoured"<<endl;
    }
}

