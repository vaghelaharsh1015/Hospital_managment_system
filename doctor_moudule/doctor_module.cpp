#include <iostream>
#include <string>

using namespace std;

class Doctor
{
public:
    int doctorID;
    string name;
    string specialization;
    string department;
    bool available;
    int maxPatientPerDay;
    Doctor *next;

    Doctor(int id, string n, string spec, string dept, int maxP)
    {
        doctorID = id;
        name = n;
        specialization = spec;
        department = dept;
        available = true;
        maxPatientPerDay = maxP;
        next = NULL;
    }
};

class Hospital
{
private:
    Doctor *head;

public:
    Hospital() { head = NULL; }

    void addDoctor(int id, string n, string spec, string dept, int maxP)
    {
        Doctor *newDoc = new Doctor(id, n, spec, dept, maxP);
        if (head == NULL)
        {
            head = newDoc;
        }
        else
        {
            Doctor *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newDoc;
        }
        cout << "Doctor " << n << " added successfully! [Linked List]" << endl;
    }

    void assignDepartment(int id, string newDept)
    {
        Doctor *temp = head;
        bool found = false;
        while (temp != NULL)
        {
            if (temp->doctorID == id)
            {
                temp->department = newDept;
                cout << "Doctor ID " << id << " assigned to " << newDept << " department." << endl;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
            cout << "Doctor with ID " << id << " not found!" << endl;
    }

    void displayDoctors()
    {
        cout << "\n--- Current Doctor List ---" << endl;
        Doctor *temp = head;
        while (temp != NULL)
        {
            cout << "ID: " << temp->doctorID << " | Name: " << temp->name
                 << " | Dept: " << temp->department
                 << " | Status: " << (temp->available ? "Available" : "Busy") << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Hospital myHospital;

    myHospital.addDoctor(2001, "Dr. Sarah Williams", "Cardiologist", "Cardiology", 20);
    myHospital.addDoctor(2002, "Dr. Rajesh Vaghela", "Neurologist", "Neurology", 15);

    myHospital.displayDoctors();

    myHospital.assignDepartment(2001, "Emergency");

    myHospital.displayDoctors();

    return 0;
}