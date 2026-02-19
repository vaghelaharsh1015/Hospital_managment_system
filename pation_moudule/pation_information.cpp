#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string contact;
    string address;
    string bloodGroup;
    string history; 
};

int main() {
    vector<Patient> hospital; 
    int choice;
    int nextId = 101;

    while (true) {
        cout << "\n ========== HOSPITAL SYSTEM ==========" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. Update Patient Information" << endl;
        cout << "3. View All Registered Patients" << endl;
        cout << "4. View Medical History" << endl;
        cout << "5. Exit" << endl;
        cout << "select your choice(1 to 5): ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.id = nextId++;
            
            cout << "\n--- New Patient Registration ---" << endl;
            cout << "Assigned ID: ";cin >> p.id;
            cout << "Enter Name: ";cin >> p.name;
            cout << "Enter Age: "; cin >> p.age;
            cout << "Enter Gender: "; cin >> p.gender;
            cout << "Enter Contact No: "; cin >> p.contact;
            cout << "Enter Address: "; cin >> p.address;
            cout << "Enter Blood Group: "; cin >> p.bloodGroup;

            hospital.push_back(p);
            cout << "\n Patient registered successfully!" << endl;
        } 
        else if (choice == 2) {
            int searchId;
            bool found = false;
            cout << "Enter Patient ID to update: "; cin >> searchId;

            for (int i = 0; i < hospital.size(); i++) {
                if (hospital[i].id == searchId) {
                    cout << "Enter New Contact No: "; cin >> hospital[i].contact;
                    cout << "Update Medical History: "; cin.ignore(); getline(cin, hospital[i].history);
                    found = true;
                    cout << "Information Updated!" << endl;
                    break;
                }
            }
            if (!found) cout << " Patient not found!" << endl;
        }
        else if (choice == 3) {
            cout << "\n--- All Registered Patients ---" << endl;
            for (const auto& p : hospital) {
                cout << "ID: " << p.id << " | Name: " << p.name << " | Phone: " << p.contact << endl;
            }
        }
        else if (choice == 4) {
            int searchId;
            cout << "Enter Patient ID to see history: "; cin >> searchId;
            for (const auto& p : hospital) {
                if (p.id == searchId) {
                    cout << "\n--- Medical History for " << p.name << " ---" << endl;
                    cout << "History: " << p.history << endl;
                    cout << "Blood Group: " << p.bloodGroup << endl;
                }
            }
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
