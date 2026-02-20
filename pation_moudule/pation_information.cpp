#include <iostream>
#include <string>
#include <vector>

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
};

//  thise is Function to Register Patient 
void registerPatient(vector<Patient> &hospital, int &nextId) {
    Patient p;
    p.id = nextId++; 
    
    cout << "\n *** New Patient Registration ***" << endl;
    cout << "Assigned ID: " << p.id << endl;  
    
    cout << "Enter Name: "; cin >> p.name;
    cout << "Enter Age: "; cin >> p.age;
    cout << "Enter Weight (kg): "; cin >> p.weight;
    cout << "Enter Gender: "; cin >> p.gender;
    cout << "Enter Contact No: "; cin >> p.contact;
    cout << "Enter Address: "; cin >> p.address;
    cout << "Enter Blood Group: "; cin >> p.bloodGroup;

    hospital.push_back(p);
    cout << "\nPatient registered successfully!" << endl;
} 
// thise is function of update patient
void updatePatient(vector<Patient> &hospital) {
    int searchId;
    bool found = false;
    cout << "\nEnter Patient ID to update: "; cin >> searchId;

    for (int i = 0; i < hospital.size(); i++) {
        if (hospital[i].id == searchId) {
            found = true;
            int updatechoice;

            cout << "\n**** Patient Found: " << hospital[i].name << " **** " << endl;
            cout << "1. Update contact no" << endl;
            cout << "2. Update blood group" << endl;
            cout << "3. Update address" << endl;
            cout << "4. Update your Weight" << endl;
            cout << "Select Choice: "; 
            cin >> updatechoice;

            switch(updatechoice) {
                case 1:
                    cout << "Enter your new contact no: ";
                    cin >> hospital[i].contact;
                    break;
                case 2:
                    cout << "Enter your blood group: ";
                    cin >> hospital[i].bloodGroup;
                    break;
                case 3:
                    cout << "Update your address: ";
                    cin >> hospital[i].address;
                    break;
                case 4:
                    cout << "Update your weight: ";
                    cin >> hospital[i].weight;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            cout << "Your medical information is up to date!" << endl;
            break;
        }
    }
    if (!found) cout << "Patient not found!" << endl;
}

int main() {
    vector<Patient> hospital; 
    int choice;
    int nextId = 101;

    while (true) {
        cout << "\n *=*=*=*=*=*=* HOSPITAL SYSTEM *=*=*=*=*=*=*" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. Update Patient Information" << endl;
        cout << "3. View All Registered Patients" << endl;
        cout << "4. View Medical History" << endl;
        cout << "5. Exit" << endl;
        cout << "Select your choice (1 to 5): ";
        cin >> choice;

        if (choice == 1) {
            registerPatient(hospital, nextId);
        } 
        else if (choice == 2) {
            updatePatient(hospital);
        }
        else if (choice == 3) {
            cout << "\n***/ All Registered Patients /***" << endl;
            for (const auto& p : hospital) {
                cout << "ID: " << p.id << " | Name: " << p.name << " | Phone: " << p.contact << " | Weight: " << p.weight << endl;
            }
        }
        else if (choice == 4) {
            int searchId;
            cout << "Enter Patient ID to see history: "; cin >> searchId;
            bool historyFound = false;
            for (const auto& p : hospital) {
                if (p.id == searchId) {
                    cout << "\n*** Medical History for " << p.name << "***" << endl;
                    cout << "History: " << p.history << endl;
                    cout << "Blood Group: " << p.bloodGroup << endl;
                    cout << "Weight: " << p.weight << " kg" << endl;
                    historyFound = true;
                }
            }
            if (!historyFound) cout << "Patient not found!" << endl;
        }
        else if (choice == 5) {
            cout << "System closed. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid Option! Try again." << endl;
        }
    }
    return 0;
}