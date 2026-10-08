#include <iostream>
#include <ctime>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string rfidID;

    void display() {
        cout << "\nRoll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "RFID ID: " << rfidID << endl;
    }
};

int main() {

    Student s[10];
    int n = 0;
    int choice;

    do {
        cout << "\n===== RFID ATTENDANCE SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Mark Attendance\n";
        cout << "4. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {

            if (n < 10) {
                cout << "Enter Roll No: ";
                cin >> s[n].rollNo;

                cout << "Enter Name: ";
                cin >> s[n].name;

                cout << "Enter RFID ID: ";
                cin >> s[n].rfidID;

                n++;

                cout << "\nStudent Added Successfully!\n";
            }
        }

        else if (choice == 2) {

            if (n == 0) {
                cout << "\nNo students added.\n";
            }
            else {
                for (int i = 0; i < n; i++) {
                    s[i].display();
                }
            }
        }

        else if (choice == 3) {

            string id;

            cout << "Enter RFID ID: ";
            cin >> id;

            bool found = false;

            for (int i = 0; i < n; i++) {

                if (s[i].rfidID == id) {
                    cout << "\nRFID Verified!\n";
                    cout << "Student: " << s[i].name << endl;
                    cout << "Attendance Marked Successfully!\n";
                    time_t now = time(0);
                    cout << "Date & Time: " << ctime(&now);
                    found = true;
                }
            }

            if (!found) {
                cout << "\nRFID Not Registered!\n";
            }
        }

        else if (choice == 4) {
            cout << "\nThank You!\n";
        }

        else {
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}