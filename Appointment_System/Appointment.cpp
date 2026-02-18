#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Define the Data Structure
struct Appointment {
    int id;
    string patient;
    string doctor;
    string dateTime;
    string status;
};

int main() {
    //Create the Vector
    vector<Appointment> list;

    Appointment app1 = {101, "Alice", "Dr. Smith", "10:00 AM", "Booked"};
    list.push_back(app1);

    Appointment app2 = {102, "Bob", "Dr. Jones", "11:30 AM", "Booked"};
    list.push_back(app2);

    cout << "Appointments booked successfully!\n";


    // --- RESCHEDULING ---
    int searchID = 101;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == searchID) {
            list[i].dateTime = "02:00 PM";
            list[i].status = "Rescheduled";
            cout << "Appointment 101 rescheduled.\n";
        }
    }


    // --- CANCELLING ---
    // We look through the list to find ID 102 and change the status
    int cancelID = 102;
    for (int i = 0; i < list.size(); i++) {
        if (list[i].id == cancelID) {
            list[i].status = "Cancelled";
            cout << "Appointment 102 cancelled.\n";
        }
    }


    // --- DISPLAYING ALL  ---
    cout << "\n--- Current System Status ---\n";
    for (int i = 0; i < list.size(); i++) {
        cout << "ID: " << list[i].id 
             << " | Patient: " << list[i].patient 
             << " | Time: " << list[i].dateTime 
             << " | Status: " << list[i].status << endl;
    }

    return 0;
}