#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>

void login();
void registration();
void forgot();
int menu();

using namespace std;

int main()
{
    switch (menu())
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\n\n\t\t\tThank you for using this program :)" << endl;
        break;

    default:
        cout << "\n\n\t\t\t Invalid Input, Please select from the options given above \n"
             << endl;
        main();
    }
}


int menu() {
    int c, lineLength = 50; 

    cout << setfill('_') << setw(lineLength+18) << "" << endl; // Upper bar

    cout << setfill(' ') <<  setw(lineLength-3) <<  "Welcome to the Login Page" << endl; // Login Page

    cout << setfill('_');   // Menu Part
    cout << setw((lineLength - 10) / 2) << "" ; 
    cout << "\t\tMenu\t\t";
    cout << setw((lineLength - 10) / 2) << "" << endl;
    cout << endl;

    cout << "\t|  Press 1 to LOGIN                    |" << endl;
    cout << "\t|  Press 2 to REGISTER                 |" << endl;
    cout << "\t|  Press 3 if you forgot your PASSWORD |" << endl;
    cout << "\t|  Press 4 to Exit                     |" << endl;

    cout << "\n\tPlease Enter your choice :";
    cin >> c;
    
    cout << endl;

    return c;
}


void login()
{
    int count;
    string userId, pass, id, password;
    system("cls"); // clear screen

    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\n\n\t\t\t\t\t Username: ";
    cin >> userId;
    cout << "\t\t\t Password: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << "\n\n\t\t\t\t\t Welcome, you are logged in " << userId << endl;

        main();
    }
    else
    {
        cout << "\n\n\t\t\t\t\t Login Error, Please try again or check in your username and password! \n"
             << endl;
        main();
    }
}

void registration()
{
    string ruserId, rpass, rid, rpassword;
    system("cls");
    cout << "\t\t Please enter the username: ";
    cin >> ruserId;
    cout << "\n\t\t\t Enter your password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\tRegistration is Successful\n";
    main();
}

void forgot()
{
    int option;
    system("cls");

    cout << "\t\t\t You forgot your password? No problem! \n";
    cout << "Press 1. Search your id by username " << endl;
    cout << "Press 2. to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, spass, sId;
        system("cls");
        cout << "\n\t\t\t Enter your username you remember: ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n\t\t\t\t\t User found! \n"
                 << endl;
            cout << "\n\n Your password is: " << spass << endl;

            main();
        }
        else
        {
            cout << "\n\n\t\t\t\t\t User not found! \n"
                 << endl;
        }
        break;
    }
    case 2:
    {
        main();
    }
    default:
        cout << "\t\t\t Wrong choice please try again! \n"
             << endl;
        forgot();
    }
}
