// #include <iostream>
// #include <string>

// using namespace std;

// class Doctor
// {
// public:
//     int doctorID;
//     string name;
//     string specialization;
//     string department;
//     bool available;
//     int maxPatientPerDay;
//     Doctor *next;

//     Doctor(int id, string n, string spec, string dept, int maxP)
//     {
//         doctorID = id;
//         name = n;
//         specialization = spec;
//         department = dept;
//         available = true;
//         maxPatientPerDay = maxP;
//         next = NULL;
//     }
// };

// class Hospital
// {
// private:
//     Doctor *head;

// public:
//     Hospital() { head = NULL; }

//     void addDoctor(int id, string n, string spec, string dept, int maxP)
//     {
//         Doctor *newDoc = new Doctor(id, n, spec, dept, maxP);
//         if (head == NULL)
//         {
//             head = newDoc;
//         }
//         else
//         {
//             Doctor *temp = head;
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = newDoc;
//         }
//         cout << "Doctor " << n << " added successfully! [ in Linked List]" << endl;
//     }

//     void assignDepartment(int id, string newDept)
//     {
//         Doctor *temp = head;
//         bool found = false;
//         while (temp != NULL)
//         {
//             if (temp->doctorID == id)
//             {
//                 temp->department = newDept;
//                 cout << "Doctor ID " << id << " assigned to " << newDept << " department." << endl;
//                 found = true;
//                 break;
//             }
//             temp = temp->next;
//         }
//         if (!found)
//             cout << "Doctor with ID " << id << " not found!" << endl;
//     }

//     void displayDoctors()
//     {
//         cout << "\n--- Current Doctor List ---" << endl;
//         Doctor *temp = head;
//         while (temp != NULL)
//         {
//             cout << "ID: " << temp->doctorID << " | Name: " << temp->name
//                  << " | Dept: " << temp->department
//                  << " | Status: " << (temp->available ? "Available" : "Busy") << endl;
//             temp = temp->next;
//         }
//     }
// };

// int main()
// {
//     Hospital myHospital;

//     myHospital.addDoctor(2001, "Dr. hitesh kakdiya", "Cardiologist", "Cardiology", 20);
//     myHospital.addDoctor(2002, "Dr. Rajesh Vaghela", "Neurologist", "Neurology", 15);

//     myHospital.displayDoctors();

//     myHospital.assignDepartment(2001, "Emergency");

//     myHospital.displayDoctors();

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- 1. Patient Structure (Vector based) ---
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

// --- 2. Doctor Class (Linked List based) ---
class Doctor {
public:
    int doctorID;
    string name;
    string specialization;
    string department;
    bool available;
    Doctor *next;

    Doctor(int id, string n, string spec, string dept) {
        doctorID = id;
        name = n;
        specialization = spec;
        department = dept;
        available = true;
        next = NULL;
    }
};

// --- 3. Main Hospital Class to manage both ---
class Hospital {
private:
    vector<Patient> patients; // Patient store karva mate vector
    Doctor *docHead;          // Doctor store karva mate Linked List
    int nextPatientId;

public:
    Hospital() {
        docHead = NULL;
        nextPatientId = 101;
    }

    // --- Patient Functions ---
    void registerPatient() {
        Patient p;
        p.id = nextPatientId++;
        cout << "\n--- New Patient Registration (ID: " << p.id << ") ---" << endl;
        cout << "Enter Name: "; cin.ignore(); getline(cin, p.name);
        cout << "Enter Age: "; cin >> p.age;
        cout << "Enter Weight (kg): "; cin >> p.weight;
        cout << "Enter Contact No: "; cin >> p.contact;
        cout << "Enter Blood Group: "; cin >> p.bloodGroup;
        patients.push_back(p);
        cout << "Patient Registered Successfully!" << endl;
    }

    void viewPatients() {
        cout << "\n--- Registered Patient List ---" << endl;
        for (const auto& p : patients) {
            cout << "ID: " << p.id << " | Name: " << p.name << " | Phone: " << p.contact << endl;
        }
    }

    // --- Doctor Functions ---
    void addDoctor(int id, string n, string spec, string dept) {
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

    // Default Doctors (Data Structures Viva mate sara lagshe)
    myHospital.addDoctor(2001, "Dr. Rajesh Vaghela", "Neurologist", "Neurology");
    myHospital.addDoctor(2002, "Dr. Sarah Williams", "Cardiologist", "Cardiology");

    while (true) {
        cout << "\n========== HOSPITAL MANAGEMENT SYSTEM ==========" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. View All Doctors" << endl;
        cout << "4. Add New Doctor" << endl;
        cout << "5. Exit" << endl;
        cout << "Select Option: ";
        cin >> choice;

        if (choice == 1) {
            myHospital.registerPatient();
        } 
        else if (choice == 2) {
            myHospital.viewPatients();
        }
        else if (choice == 3) {
            myHospital.viewDoctors();
        }
        else if (choice == 4) {
            int id; string n, spec, dept;
            cout << "Doctor ID: "; cin >> id;
            cout << "Name: "; cin.ignore(); getline(cin, n);
            cout << "Specialization: "; getline(cin, spec);
            cout << "Department: "; getline(cin, dept);
            myHospital.addDoctor(id, n, spec, dept);
        }
        else if (choice == 5) {
            cout << "Exiting System. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}