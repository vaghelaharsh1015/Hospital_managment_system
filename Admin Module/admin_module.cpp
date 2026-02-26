
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

// DATA STRUCTURES 

struct Patient {
    int id;
    string name;
    int age;
    string contact;
    string address;
    string bloodGroup;
    string patientType; 
    double amountDue = 0.0;
    bool isPaid = false;
};

struct Doctor {
    int doctorID;
    string name;
    string specialization;
    string department;
    bool available = true;
};

struct Appointment {
    int appointmentID;
    string patientName;
    string doctorName;
    string dateTime;
    string status; 
};

struct EmergencyPatient {
    int id;
    string name;
    int severity;
    string condition;

    bool operator<(const EmergencyPatient& other) const {
        return severity < other.severity; 
    }
};

//  ADMIN MODULE 

class AdminModule {
private:
    vector<Patient> patients;           
    vector<Doctor> doctors;             
    queue<Appointment> apptQueue;       
    stack<Appointment> cancelledStack;  
    priority_queue<EmergencyPatient> emgQueue;   
    
    int nextPatientId = 101;

public:
    AdminModule() {
        doctors.push_back({2001, "Dr. Rajesh Vaghela", "Neurologist", "Neurology"});
        doctors.push_back({2002, "Dr. Sarah Williams", "Cardiologist", "Cardiology"});
    }

    //  PATIENT MANAGEMENT 
    void managePatients() {
        int choice;
        cout << "\n--- PATIENT MANAGEMENT ---\n";
        cout << "1. Register Patient\n2. Update Details\n3. View Patients\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.id = nextPatientId++;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, p.name);
            cout << "Enter Age: "; cin >> p.age;
            cout << "Enter Contact: "; cin >> p.contact;
            cin.ignore();
            cout << "Enter Address: "; getline(cin, p.address);
            cout << "Enter Blood Group: "; cin >> p.bloodGroup;
            p.patientType = "Regular";
            patients.push_back(p);
            cout << "SUCCESS: Registered with ID: " << p.id << endl;
        }
        else if (choice == 2) {
            int sid; 
            cout << "Enter Patient ID: "; 
            cin >> sid;
            bool found = false;

            for (auto &p : patients) {
                if (p.id == sid) {
                    found = true;
                    cout << "1.Name 2.Contact 3.Address 4.Age\nChoice: ";
                    int upd; cin >> upd;
                    cin.ignore();
                    if (upd == 1) { cout << "New Name: "; getline(cin, p.name); }
                    else if (upd == 2) { cout << "New Contact: "; cin >> p.contact; }
                    else if (upd == 3) { cout << "New Address: "; getline(cin, p.address); }
                    else if (upd == 4) { cout << "New Age: "; cin >> p.age; }
                    cout << "Updated Successfully!\n";
                    break;
                }
            }
            if (!found) cout << "Patient Not Found!\n";
        }
        else if (choice == 3) {
            cout << "\nID\tName\tAge\tBlood\tPaid\n";
            for (const auto& p : patients) {
                cout << p.id << "\t" << p.name << "\t" << p.age 
                     << "\t" << p.bloodGroup << "\t"
                     << (p.isPaid ? "Yes" : "No") << endl;
            }
        }
    }

    // DOCTOR MANAGEMENT 
    void manageDoctors() {
        int choice;
        cout << "\n--- DOCTOR MANAGEMENT ---\n";
        cout << "1.Add Doctor\n2.View Doctors\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Doctor d;
            cout << "Doctor ID: "; cin >> d.doctorID;
            cin.ignore();
            cout << "Name: "; getline(cin, d.name);
            cout << "Specialization: "; getline(cin, d.specialization);
            cout << "Department: "; getline(cin, d.department);
            doctors.push_back(d);
            cout << "Doctor Added Successfully!\n";
        } 
        else {
            for (const auto& d : doctors) {
                cout << "ID: " << d.doctorID 
                     << " | " << d.name 
                     << " | " << d.specialization 
                     << " | " << d.department << endl;
            }
        }
    }

    //  APPOINTMENTS 
    void manageAppointments() {
        int choice;
        cout << "\n--- APPOINTMENTS ---\n";
        cout << "1.Book\n2.Cancel\n3.Reschedule\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            Appointment a;
            cout << "Appt ID: "; cin >> a.appointmentID;
            cin.ignore();
            cout << "Patient Name: "; getline(cin, a.patientName);
            cout << "Doctor Name: "; getline(cin, a.doctorName);
            cout << "Date/Time: "; getline(cin, a.dateTime);
            a.status = "Scheduled";
            apptQueue.push(a);
            cout << "Appointment Booked!\n";
        }
        else if (choice == 2 && !apptQueue.empty()) {
            Appointment a = apptQueue.front();
            apptQueue.pop();
            a.status = "Cancelled";
            cancelledStack.push(a);
            cout << "Appointment Cancelled!\n";
        }
        else if (choice == 3 && !apptQueue.empty()) {
            cin.ignore();
            cout << "New Date/Time: ";
            getline(cin, apptQueue.front().dateTime);
            apptQueue.front().status = "Rescheduled";
            cout << "Appointment Rescheduled!\n";
        }
    }

    //  BILLING 
    void manageBilling() {
        int id;
        cout << "Enter Patient ID: ";
        cin >> id;

        for (auto &p : patients) {
            if (p.id == id) {
                double f, m, r;
                cout << "Doctor Fees: "; cin >> f;
                cout << "Medicine Cost: "; cin >> m;
                cout << "Room Charges: "; cin >> r;

                p.amountDue = f + m + r;
                cout << "Total Amount: $" << p.amountDue << endl;

                double paid;
                cout << "Enter Payment: ";
                cin >> paid;

                if (paid >= p.amountDue) {
                    p.isPaid = true;
                    cout << "Payment Successful! Change: $" 
                         << (paid - p.amountDue) << endl;
                } else {
                    cout << "Insufficient Payment!\n";
                }
                return;
            }
        }
        cout << "Patient Not Found!\n";
    }

    //  EMERGENCY 
    void manageEmergency() {
        int choice;
        cout << "\n--- EMERGENCY ---\n";
        cout << "1.Register\n2.Serve Next\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            EmergencyPatient ep;
            cout << "ID: "; cin >> ep.id;
            cin.ignore();
            cout << "Name: "; getline(cin, ep.name);
            cout << "Severity (1-4): "; cin >> ep.severity;
            cin.ignore();
            cout << "Condition: "; getline(cin, ep.condition);
            emgQueue.push(ep);
            cout << "Emergency Patient Added!\n";
        }
        else if (choice == 2 && !emgQueue.empty()) {
            cout << "Serving: " << emgQueue.top().name << endl;
            emgQueue.pop();
        }
        else {
            cout << "No Emergency Patients!\n";
        }
    }

    //  REPORT 
    void generateReport() {
        cout << "\n-*-------- HOSPITAL REPORT ----------*-\n";
        cout << "Total Patients: " << patients.size() << endl;
        cout << "Total Doctors: " << doctors.size() << endl;
        cout << "Scheduled Appointments: " << apptQueue.size() << endl;
        cout << "Cancelled Appointments: " << cancelledStack.size() << endl;
        cout << "Emergency Waiting: " << emgQueue.size() << endl;
        cout << "*********************************************\n";
    }
};

//  MAIN FUNCTION 

int main() {
    AdminModule admin;
    int choice;

    do {
        cout << "\n*=*=*=*=*=*  HOSPITAL MANAGEMENT SYSTEM =*=*=*=*=*=*=\n";
        cout << "1.Patient Management\n";
        cout << "2.Doctor Management\n";
        cout << "3.Appointments\n";
        cout << "4.Billing\n";
        cout << "5.Emergency\n";
        cout << "6.Generate Report\n";
        cout << "0.Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: admin.managePatients(); break;
            case 2: admin.manageDoctors(); break;
            case 3: admin.manageAppointments(); break;
            case 4: admin.manageBilling(); break;
            case 5: admin.manageEmergency(); break;
            case 6: admin.generateReport(); break;
        }

    } while(choice != 0);

    cout << "Thank You!\n";
    return 0;
}
