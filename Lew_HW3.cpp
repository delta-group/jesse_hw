//******************************************************************
// Assignment 3 Checkbook Balancing Revisited
// Programmer: Jesse Lew
// Completed : 9/24/16
// Status    : Complete
//
// A program to help you balance your checkbook at the end of the month.
//******************************************************************

#include <iostream>      // input/output declarations
#include <iomanip>       // i/o manupulator declarations
using namespace std;


// define variables 
char transactionType;            // for C, D, or E input
static float balance;            // beginning balance amount
static float transactionAmount;  // amount for transaction
static float serviceCharges;     // service charges total
bool validInput = false;    // initialize and force input validation loops
static bool under800fee = false; // check for under $800 or fee at end of month


// declare check function
void check(float &transactionAmount, float &balance, float &serviceCharges, 
           bool &under800fee);
// declare deposit function
void deposit(float &transactionAmount, float &balance, float &serviceCharges);


// define main function
int main()
{
    serviceCharges = 0;             // initialize service charges
    
    // program description
    cout << "Checkbook Balancing Program" << endl; 
    cout << "\n";  // spacing
    
    // initial balance
    cout << "Enter the beginning balance: ";
    cin >> balance;  // no input validation requested...
    if(balance < 800 && under800fee == false)  // check for under 800
    {
        cout << "Service charge: $5.00 balance below $800.00" << endl;
        under800fee = true;
        serviceCharges += 5.0;
    }
    cout << "\n";  // spacing

    // list commands
    cout << "Commands:" << endl;
    cout << "C 9999.99 - process a check for $9,999.99" << endl;
    cout << "D 9999.99 - process a deposit for $9,999.99" << endl;
    cout << "E - end the program" << endl;
    cout << "\n";  // spacing
    
    // transaction type and amount
    cout << "Enter transaction type and amount, separated by a space: ";
    cin >> transactionType;
    if(transactionType != 'E')  // if E then skip second input
    {
        cin >> transactionAmount;
    }
    
    // transaction loop
    while(transactionType != 'E')
    {
        // input validation loop for transaction type
        while(validInput == false)
        {
            if(transactionType == 'C' || transactionType == 'D' || 
            transactionType == 'E')
            {
                break;
            }
            else
            {
                cout << "ERROR: You must enter C, D, or E.\n";  // error message
                cout << "Enter transaction type and amount, "
                        "separated by a space: ";          // try again
                cin >> transactionType;
                if(transactionType != 'E')  // if E then skip second input
                {
                    cin >> transactionAmount;
                }
            }
        }
        
        // transaction amount
        // cout << "Enter transaction amount: ";
        // cin >> transactionAmount;
        
        // input validation loop for transaction amount
        while(validInput == false)
        {
            if(transactionAmount > 0)
            {
                break;
            }
            else
            {
                cout << "ERROR: You must enter an amount greater than zero.\n";
                cout << "Enter transaction type and amount, "
                        "separated by a space: ";          // try again
                cin >> transactionType;
                if(transactionType != 'E')  // if E then skip second input
                {
                    cin >> transactionAmount;
                }
            }
        }
        
        // call check function
        if(transactionType == 'C')
        {
            check(transactionAmount, balance, serviceCharges, under800fee);
        }
        
        // call deposit function
        if(transactionType == 'D')
        {
            deposit(transactionAmount, balance, serviceCharges);
        }
    
        // new transaction prompt
        cout << "Enter transaction type and amount, separated by a space: ";
        cin >> transactionType;
        if(transactionType != 'E')  // if E then skip second input
        {
            cin >> transactionAmount;
        }
    }

    // end of month
    cout << "Processing end of month" << endl;
    balance = balance - serviceCharges;
    cout << "Final balance: $" << fixed << setprecision(2) << balance << endl;
    
    return 0;
}


// define check function
void check(float &transactionAmount, float &balance, float &serviceCharges, 
           bool &under800fee)
{
    cout << "Processing check for $" << transactionAmount << endl;
    balance = balance - transactionAmount;
    serviceCharges += 0.25;
    // print balance and charges
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "Service charge: $0.25 for a check" << endl;
    if(balance < 800 && under800fee == false)  // check for under 800
    {
        cout << "Service charge: $5.00 balance below $800.00" << endl;
        under800fee = true;
        serviceCharges += 5.0;
    }
    if(balance < 0)  // check for negative balance
    {
        cout << "Service charge: $25.00 insufficient funds charge" << endl;
        serviceCharges += 25.0;
    }
    cout << "Total service charges: $" << fixed << setprecision(2) 
         << serviceCharges << endl;
    cout << "\n";  // spacing
}


// define deposit function
void deposit(float &transactionAmount, float &balance, float &serviceCharges)
{
    cout << "Processing chack for $" << fixed << setprecision(2) 
         << transactionAmount << endl;
    balance = balance + transactionAmount;
    // print balance and charges
    cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "Total service charges: $" << fixed << setprecision(2) 
         << serviceCharges << endl;
    cout << "\n";  // spacing
}
