#include <iostream>
#include <string>
#include <iomanip> // (input/output manipulators) For formatting currency

using namespace std;

class bill_module
{
public:
    double consultantFees;
    double medicineCharge;
    double roomCharge;
    double totalAmount; //  Sum of all charges (consultantFees + medicineCharge + roomCharge)
    string discharge;   //  Date and time when patient was discharged
    bool isPaid;        //  To check payment status

    // 1. Constructor: Sets values ​​as soon as the object is created
    bill_module(double fees, double medicine, double room, string disch_date)
    {
        consultantFees = fees;
        medicineCharge = medicine;
        roomCharge = room;
        discharge = disch_date;
        isPaid = false; 
        calculateTotal(); // The total will be calculated as soon as the bill is created.
    }

    // Calculate Method: To sum up all three costs
    void calculateTotal()
    {
        totalAmount = consultantFees + medicineCharge + roomCharge;
    }

    // generateBill() - To prepare bill details
    void generateBill()
    {
        cout << "\n Generating Bill for Date: " << discharge << "..." << endl;
        calculateTotal(); // Make sure Total is up to date.
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
        cout << "Discharge Date: " << discharge << endl;

        // fixed and setprecision(2) will make the price look like $150.00
        cout << fixed << setprecision(2);

        cout << "Consultant Fees:   $" << consultantFees << endl;
        cout << "Medicine Charge:   $" << medicineCharge << endl;
        cout << "Room Charge:       $" << roomCharge << endl;
        cout << "------------------------------------" << endl;
        cout << "TOTAL AMOUNT:     $" << totalAmount << endl;
        cout << "STATUS:           " << (isPaid ? "PAID" : "UNPAID") << endl;
        cout << "====================================" << endl;
    }
};

int main()
{
    // Using Bill in the main function
    // bill_module patientBill(150.00, 85.50, 400.00, "2024-02-20 02:00 PM");

    double c, m, r;
    string d;

    cout << "\n--- Hospital Biling System ---" << endl;

    // 1. Taking input from the user
    cout << "Enter Consultant Fees: ";
    cin >> c;

    cout << "Enter Medicine Charges: ";
    cin >> m;

    cout << "Enter Room Charges: ";
    cin >> r;

    cout << "Enter Discharge Date_Time: " << endl; // (e.g., 18-02-2024 02:00 PM)
    cin.ignore();                                  //  To clear the buffer before taking the string
    getline(cin, d);                               //  To read the entire line (with space)

    // 2. Creating an object with user data (Dynamic Allocation)
    bill_module patientBill(c, m, r, d);

    patientBill.generateBill();       // Bill will be generated.
    patientBill.printInvoice();       // Bill before payment
    patientBill.processPayment();     // Payment will be processed.
    patientBill.printInvoice();       // Post-payment bill (with PAID status)

    return 0;
}
