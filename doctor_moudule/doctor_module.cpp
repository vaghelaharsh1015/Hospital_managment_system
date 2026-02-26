#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  1. Doctor Class 
class Doctor {
public:
    int doctorID;
    string name;
    string specialization;
    string department;
    bool available;
    Doctor *next;

    Doctor(int id, string n, string spec, string dept){
        doctorID = id;
        name = n;
        specialization = spec;
        department = dept;
        available = true;
        next = NULL;
    }
};

//  2. Main Hospital Class to manage Doctors
class Hospital {
private:
    Doctor *docHead;         

public:
    Hospital() {
        docHead = NULL;
    }

    // add doctor function  
    void addDoctor(int id, string n, string spec, string dept){
        Doctor *newDoc = new Doctor(id, n, spec, dept);
        if (docHead == NULL) {
            docHead = newDoc;
        } else {
            Doctor *temp = docHead;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newDoc;
        }
        cout << "Doctor " << n << " added successfully!" << endl;
    }

    void viewDoctors() {
        cout << "\n--- Hospital Doctor List ---" << endl;
        Doctor *temp = docHead;
        if (temp == NULL) {
            cout << "No doctors available." << endl;
            return;
        }
        while (temp != NULL) {
            cout << "ID: " << temp->doctorID << " | Name: " << temp->name 
                 << " | Dept: " << temp->department << " | Status: " 
                 << (temp->available ? "Available" : "Busy") << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Hospital myHospital;
    int choice;
    
    // Initial doctor information 
    myHospital.addDoctor(2001, "Dr. Rajesh Vaghela", "Neurologist", "Neurology");
    myHospital.addDoctor(2002, "Dr. Sarah Williams", "Cardiologist", "Cardiology");

    while (true) {
        cout << "\n========== DOCTOR MANAGEMENT SYSTEM ==========" << endl;
        cout << "1. View All Doctors" << endl;
        cout << "2. Add New Doctor" << endl;
        cout << "3. Exit" << endl;
        cout << "Select Option: ";
        cin >> choice;

        if (choice == 1) {
            myHospital.viewDoctors();
        }
        else if (choice == 2) {
            int id; string n, spec, dept;
            cout << "Doctor ID: "; cin >> id;
            cout << "Name: "; cin.ignore(); getline(cin, n);
            cout << "Specialization: "; getline(cin, spec);
            cout << "Department: "; getline(cin, dept);
            myHospital.addDoctor(id, n, spec, dept);
        }
        else if (choice == 3) {
            cout << "Exiting System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}