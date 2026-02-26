#include <iostream>
#include <string>
#include <vector>
#include <limits> // Required for clearing input buffer

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    float weight;
    string contact;
    string address;
    string bloodGroup;
    string history; 
    string patientType; // Stores "Regular" or "Emergency"
};

// Function to Register a New Patient
void registerPatient(vector<Patient> &hospital, int &nextId) {
    Patient p;
    p.id = nextId++; 
    
    cout << "\n--- NEW PATIENT REGISTRATION ---" << endl;
    cout << "Assigned Patient ID: " << p.id << endl;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cout << "Enter Name: "; 
    getline(cin, p.name);
    
    cout << "Enter Age: "; cin >> p.age;
    cout << "Enter Gender: "; cin >> p.gender;
    cout << "Enter Weight (kg): "; cin >> p.weight;
    cout << "Enter Contact No: "; cin >> p.contact;
    
    cin.ignore();
    cout << "Enter Address: "; 
    getline(cin, p.address);
    
    cout << "Enter Blood Group: "; cin >> p.bloodGroup;

    // Logic for Regular vs Emergency
    int typeChoice;
    cout << "\nSelect Patient Category:" << endl;
    cout << "1. Regular" << endl;
    cout << "2. Emergency" << endl;
    cout << "Choice: ";
    cin >> typeChoice;

    if (typeChoice == 2) {
        p.patientType = "Emergency";
    } else {
        p.patientType = "Regular";
    }

    hospital.push_back(p);
    cout << "\nSUCCESS: Patient registered as [" << p.patientType << "]" << endl;
}

// Function to View All Patients
void viewAllPatients(const vector<Patient> &hospital) {
    if (hospital.empty()) {
        cout << "\nNo patients registered in the system." << endl;
        return;
    }

    cout << "\n------------------------------------------------------------" << endl;
    cout << "ID\tNAME\t\tTYPE\t\tCONTACT" << endl;
    cout << "------------------------------------------------------------" << endl;
    for (const auto& p : hospital) {
        cout << p.id << "\t" << p.name << "\t\t[" << p.patientType << "]\t" << p.contact << endl;
    }
    cout << "------------------------------------------------------------" << endl;
}

// Function to Update Patient Information
void updatePatient(vector<Patient> &hospital) {
    int searchId;
    bool found = false;
    cout << "\nEnter Patient ID to update: "; cin >> searchId;

    for (int i = 0; i < hospital.size(); i++) {
        if (hospital[i].id == searchId) {
            found = true;
            int updateChoice;
            cout << "\nUpdating Records for: " << hospital[i].name << endl;
            cout << "1. Update Contact No\n2. Update Weight\n3. Update Address\nSelect: ";
            cin >> updateChoice;

            if (updateChoice == 1) {
                cout << "New Contact: "; cin >> hospital[i].contact;
            } else if (updateChoice == 2) {
                cout << "New Weight: "; cin >> hospital[i].weight;
            } else if (updateChoice == 3) {
                cout << "New Address: "; cin.ignore(); getline(cin, hospital[i].address);
            }
            cout << "Record updated successfully!" << endl;
            break;
        }
    }
    if (!found) cout << "Error: Patient ID not found!" << endl;
}

int main() {
    vector<Patient> hospital; 
    int choice;
    int nextId = 101;

    while (true) {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. Update Patient Record" << endl;
        cout << "3. View All Patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Select Option: ";
        cin >> choice;

        switch (choice) {
            case 1: registerPatient(hospital, nextId); break;
            case 2: updatePatient(hospital); break;
            case 3: viewAllPatients(hospital); break;
            case 4: cout << "Exiting System..." << endl; return 0;
            default: cout << "Invalid Selection! Please try again." << endl;
        }
    }
    return 0;
}