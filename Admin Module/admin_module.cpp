#include <iostream>
#include <string>
#include <vector>

using namespace std;

class admin_module
{
private:
    int adminId;
    string name;
    string email;
    string password;
    string role;      // Admin permission level (e.g., "SuperAdmin", "BillingAdmin","ReceptionAdmin")
    string lastLogin; //  DateTime lastLogin — Last time admin logged into the system

public:
    // Constructor to set the data dynamically based on user input
    admin_module(int id, string n, string e, string pass, string r)
    {
        adminId = id;
        name = n;
        email = e;
        password = pass;
        role = r;
    }

    void managePatients()
    {
        cout << "[Admin] Patient module opened. New patients will be registered here." << endl;
    }

    void manageDoctors()
    {
        cout << "[Admin] Doctor module opened. Doctor information can be added here." << endl;
    }

    void manageAppointments()
    {
        cout << "[Admin] Checking the appointment list..." << endl;
    }

    void manageBilling()
    {
        cout << "[Admin] Billing Module: The final bill of the patient will be generated here." << endl;
    }

    void generateReports()
    {
        cout << "[Admin] Generating hospital revenue and patient reports." << endl;
    }

    void assignDepartment()
    {
        cout << "[Admin] Assign doctors to departments " << endl;
    }

    void viewDashboard()
    {
        cout << "\n----- Hospital Dashboard -----" << endl;
        cout << "Admin ID: " << adminId << endl;
        cout << "Admin Name: " << name << endl; 
        cout << "Role: " << role << endl;
        // cout << "Last Login: " << lastLogin << endl;
        cout << "------------------------------\n"<< endl;
    }
};

int main()
{

    int inputId;
    string inputName, inputEmail, inputPassword, inputRole;

    cout << "==== ADMIN REGISTRATION ====" << endl;

    cout << "Enter Admin ID: ";
    cin>> inputId;

    // We use cin.ignore() here to clear the "Enter" key press from the buffer
    // before using getline(), otherwise it skips the next input.
    cin.ignore();

    cout << "Enter Full Name: ";
    getline(cin, inputName);

    cout << "Enter Email-Id: ";
    getline(cin, inputEmail);

    cout << "Enter Password: ";
    getline(cin, inputPassword);

    cout << "Enter Role: ";
    getline(cin, inputRole);

    // Now we create the Admin object using the variables we just collected
    admin_module myAdmin(inputId, inputName, inputEmail, inputPassword, inputRole);

    // Views the dashboard to prove the dynamic data was saved
    myAdmin.viewDashboard();
}