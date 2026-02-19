#include <iostream>
using namespace std;

int main()
{
    int appointmentID;
    string patientName;
    string doctorName;
    string dateTime;
    string status;
    int choice;

    status = "Not Booked";

    cout << "----- Appointment Module -----" << endl;
    cout << "1. Book Appointment" << endl;
    cout << "2. Cancel Appointment" << endl;
    cout << "3. Reschedule Appointment" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nEnter Appointment ID: ";
        cin >> appointmentID;

        cout << "Enter Patient Name: ";
        cin >> patientName;

        cout << "Enter Doctor Name: ";
        cin >> doctorName;

        cout << "Enter Date & Time: ";
        cin >> dateTime;

        status = "Booked";

        cout << "\nAppointment Booked Successfully!" << endl;
    }
    else if (choice == 2)
    {
        status = "Cancelled";
        cout << "\nAppointment Cancelled!" << endl;
    }
    else if (choice == 3)
    {
        cout << "\nEnter New Date & Time: ";
        cin >> dateTime;

        status = "Rescheduled";
        cout << "Appointment Rescheduled Successfully!" << endl;
    }
    else
    {
        cout << "\nInvalid Choice!" << endl;
    }

    cout << "\n----- Appointment Details -----" << endl;
    cout << "Appointment ID: " << appointmentID << endl;
    cout << "Patient Name: " << patientName << endl;
    cout << "Doctor Name: " << doctorName << endl;
    cout << "Date & Time: " << dateTime << endl;
    cout << "Status: " << status << endl;

    return 0;
}