#include <iostream>
#include <string>
#include <iomanip> // For formatting currency

using namespace std;

class bill_module
{
public:
    string patientId;   // Patient ID from registration
    string patientName; // Patient Name
    double consultantFees;
    double medicineCharge;
    double roomCharge;
    double totalAmount; // Sum of all charges
    string discharge;   // Date and time when patient was discharged
    bool isPaid;        // To check payment status

    // Constructor: Sets values as soon as the object is created
    bill_module(string p_id, string p_name, double fees, double medicine, double room, string disch_date)
    {
        patientId = p_id;
        patientName = p_name;
        consultantFees = fees;
        medicineCharge = medicine;
        roomCharge = room;
        discharge = disch_date;
        isPaid = false;
        calculateTotal(); // Calculate the total as soon as the bill is created
    }

    // Calculate Method: To sum up all three costs
    void calculateTotal()
    {
        totalAmount = consultantFees + medicineCharge + roomCharge;
    }

    // generateBill() - To prepare bill details
    void generateBill()
    {
        cout << "\n Generating Bill for Patient: " << patientName << " (ID: " << patientId << ")..." << endl;
        calculateTotal();
    }

    // processPayment() - To take payment
    void processPayment()
    {
        double amountPaid;

        cout << "\nTotal Amount to pay is: $" << totalAmount << endl;

        cout << "Enter payment amount: $";
        cin >> amountPaid;

        if (amountPaid >= totalAmount)
        {
            isPaid = true;
            cout << "Payment Successful! Change returned: $" << (amountPaid - totalAmount) << endl;
        }
        else
        {
            cout << "Insufficient amount! Payment failed." << endl;
        }
    }

    // Print Method: To print the bill neatly on the screen
    void printInvoice()
    {
        cout << "\n====================================" << endl;
        cout << "          HOSPITAL INVOICE          " << endl;
        cout << "====================================" << endl;
        cout << "Patient ID:       " << patientId << endl;
        cout << "Patient Name:     " << patientName << endl;
        cout << "Discharge Date:   " << discharge << endl;
        cout << "------------------------------------" << endl;

        // fixed and setprecision(2) formats the price to two decimal places
        cout << fixed << setprecision(2);

        cout << "Consultant Fees:   $" << consultantFees << endl;
        cout << "Medicine Charge:   $" << medicineCharge << endl;
        cout << "Room Charge:       $" << roomCharge << endl;
        cout << "------------------------------------" << endl;
        cout << "TOTAL AMOUNT:      $" << totalAmount << endl;
        cout << "STATUS:            " << (isPaid ? "PAID" : "UNPAID") << endl;
        cout << "====================================" << endl;
    }
};

int main()
{
    string p_id, p_name, d;
    double c, m, r;

    cout << "\n--- Hospital Billing System ---" << endl;

    // 1. Taking Patient ID and Name first
    cout << "Enter Patient ID: ";
    cin >> p_id;

    cout << "Enter Patient Name: ";
    cin.ignore(); // Clear the buffer before using getline
    getline(cin, p_name);

    // 2. Taking billing details
    cout << "Enter Consultant Fees: ";
    cin >> c;

    cout << "Enter Medicine Charges: ";
    cin >> m;

    cout << "Enter Room Charges: ";
    cin >> r;

    cout << "Enter Discharge Date_Time (e.g., 20-02-2024 02:00 PM): ";
    cin.ignore();
    getline(cin, d); // FIXED: Added this line to actually read the date

    // 3. Creating the object with all the data
    bill_module patientBill(p_id, p_name, c, m, r, d);

    patientBill.generateBill();
    patientBill.printInvoice();
    patientBill.processPayment();
    patientBill.printInvoice();

    return 0;
}