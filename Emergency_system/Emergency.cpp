#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Patient Class
class Patient {
public:
    int id;
    string name;
    int age;

    Patient() {}

    Patient(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }
};

//EmergencyPatient Class

// severityLevel:
// 1 = Critical
// 2 = High
// 3 = Moderate
// 4 = Low

class EmergencyPatient : public Patient {
public:
    int severityLevel;
    string arrivalTime;
    string condition;

    EmergencyPatient() {}

    EmergencyPatient(int i, string n, int a,
                     int s, string time, string cond)
        : Patient(i, n, a)
    {
        severityLevel = s;
        arrivalTime = time;
        condition = cond;
    }
};

// Queue for Emergency Patients
queue<EmergencyPatient> emergencyQueue;

// Register Emergency Patient 
void registerEmergencyPatient() {
    int id, age, severity;
    string name, arrival, condition;

    cout << "\n--- Register Emergency Patient ---\n";
    cout << "Enter Patient ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Severity Level (1-Critical to 4-Low): ";
    cin >> severity;

    cin.ignore(); 
    cout << "Enter Arrival Time: ";
    getline(cin, arrival);

    cout << "Enter Emergency Condition: ";
    getline(cin, condition);

    EmergencyPatient ep(id, name, age, severity, arrival, condition);
    emergencyQueue.push(ep);

    cout << "Emergency patient registered successfully!\n";
}

// Serve Emergency Patient 
void serveEmergencyPatient() {
    if (emergencyQueue.empty()) {
        cout << "\nNo emergency patients to serve.\n";
        return;
    }

    EmergencyPatient ep = emergencyQueue.front();
    emergencyQueue.pop();

    string doctorName, department;

    cout << "\n--- Serving Emergency Patient ---\n";
    cout << "ID: " << ep.id << endl;
    cout << "Name: " << ep.name << endl;
    cout << "Age: " << ep.age << endl;
    cout << "Condition: " << ep.condition << endl;
    cout << "Severity Level: " << ep.severityLevel << endl;
    cout << "Arrival Time: " << ep.arrivalTime << endl;

    cin.ignore(); // clear buffer
    cout << "\nAssign Doctor Name: ";
    getline(cin, doctorName);

    cout << "Assign Department: ";
    getline(cin, department);

    cout << "\n--- Doctor Assigned Successfully ---\n";
    cout << "Doctor Name: " << doctorName << endl;
    cout << "Department: " << department << endl;
    cout << "Patient is under treatment.\n";
}

// Main Function

int main() {
    int choice;

    while (true) {
        cout << "\n====== EMERGENCY MANAGEMENT SYSTEM ======\n";
        cout << "1. Register Emergency Patient\n";
        cout << "2. Serve Emergency Patient\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            registerEmergencyPatient();
        }
        else if (choice == 2) {
            serveEmergencyPatient();
        }
        else if (choice == 3) {
            cout << "System closed. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}