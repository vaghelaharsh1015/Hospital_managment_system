#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// Patient Class
class Patient
{
public:
    int id;
    string name;
};

// Doctor Class
class Doctor
{
public:
    int id;
    string name;
};

// Appointment Class
class Appointment
{
public:
    int appointmentID;
    Patient patient;
    Doctor doctor;
    string dateTime;
    string status;

    void bookAppointment()
    {
        cout << "Enter Appointment ID: ";
        cin >> appointmentID;

        cout << "Enter Patient ID: ";
        cin >> patient.id;
        cout << "Enter Patient Name: ";
        cin >> patient.name;

        cout << "Enter Doctor ID: ";
        cin >> doctor.id;
        cout << "Enter Doctor Name: ";
        cin >> doctor.name;

        cin.ignore();
        cout << "Enter Date & Time: ";
        getline(cin, dateTime);

        status = "Scheduled";
        cout << "Appointment Booked Successfully!" << endl;
    }

    void cancelAppointmentById(queue<Appointment> &appointmentQueue,
                               stack<Appointment> &cancelledStack)
    {
        if (appointmentQueue.empty())
        {
            cout << "No Appointments to Cancel!" << endl;
            return;
        }

        int id;
        cout << "Enter Appointment ID to Cancel: ";
        cin >> id;

        queue<Appointment> temp;
        bool found = false;

        while (!appointmentQueue.empty())
        {
            Appointment a = appointmentQueue.front();
            appointmentQueue.pop();

            if (a.appointmentID == id && found == false)
            {
                a.status = "Cancelled";
                cancelledStack.push(a);
                found = true;
            }
            else
            {
                temp.push(a);
            }
        }

        appointmentQueue = temp;

        if (found)
            cout << "Appointment Cancelled Successfully!" << endl;
        else
            cout << "Appointment ID not found!" << endl;
    }

    void showAppointment()
    {
        cout << "Appointment ID: " << appointmentID << endl;
        cout << "Patient: " << patient.name << endl;
        cout << "Doctor: " << doctor.name << endl;
        cout << "Date & Time: " << dateTime << endl;
        cout << "Status: " << status << endl;
        cout << "---------------------------" << endl;
    }
};

int main()
{
    queue<Appointment> appointmentQueue; // For booking
    stack<Appointment> cancelledStack;   // For cancelled appointments

    int choice;

    while (true)
    {
        cout << "\n===== APPOINTMENT SYSTEM =====" << endl;
        cout << "1. Book Appointment" << endl;
        cout << "2. Cancel Appointment" << endl;
        cout << "3. Reschedule Appointment" << endl;
        cout << "4. View All Appointments" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Appointment a;
            a.bookAppointment();
            appointmentQueue.push(a);
        }

        else if (choice == 2)
        {

            Appointment a;
            a.cancelAppointmentById(appointmentQueue, cancelledStack);
        }

        else if (choice == 3)
        {
            if (!appointmentQueue.empty())
            {
                Appointment a = appointmentQueue.front();
                appointmentQueue.pop();

                cin.ignore();
                cout << "Enter New Date & Time: ";
                getline(cin, a.dateTime);
                a.status = "Rescheduled";

                appointmentQueue.push(a);
                cout << "Appointment Rescheduled!" << endl;
            }
            else
            {
                cout << "No Appointment Found!" << endl;
            }
        }

        else if (choice == 4)
        {
            if (appointmentQueue.empty())
            {
                cout << "No Appointments Available!" << endl;
            }
            else
            {
                queue<Appointment> temp = appointmentQueue;
                while (!temp.empty())
                {
                    temp.front().showAppointment();
                    temp.pop();
                }
            }
        }

        else if (choice == 5)
        {
            cout << "System Closed. Goodbye!" << endl;
            break;
        }

        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}