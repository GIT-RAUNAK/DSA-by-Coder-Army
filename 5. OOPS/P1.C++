/*Challenge: Design a Customer class for a bank system that manages customer information and basic operations.
Attributes:
name: String containing the customer's full name.
accountNumber: Unique integer identifying the customer's account.
accountBalance: Double representing the current balance in the account.
isActive: Boolean indicating whether the account is active.
Methods:
deposit(amount): Adds the specified amount to the account balance.
withdraw(amount): Deducts the specified amount from the account balance (check for sufficient funds).
transfer(amount, targetAccount): Transfers the specified amount to another customer's account (within the system).
printDetails(): Prints the customer's name, account number, and current balance.
*/

#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    string name;
    int accountNumber;
    double accountBalance;
    bool isActive;

    void deposit(double amount) {
        accountBalance += amount;
    }

    void withdraw(double amount) {
        if (accountBalance >= amount) {
            accountBalance -= amount;
        } else {
            cout << "Insufficient funds!\n";
        }
    }

    void transfer(double amount, Customer &targetAccount) {
        if (accountBalance >= amount) {
            accountBalance -= amount;
            targetAccount.accountBalance += amount;
        } else {
            cout << "Insufficient funds for transfer!\n";
        }
    }

    void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << accountBalance << endl;
        cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    }
};

int main() {
    Customer c1, c2;

    // Initialize manually
    c1.name = "Raunak";
    c1.accountNumber = 1001;
    c1.accountBalance = 5000;
    c1.isActive = true;

    c2.name = "Aman";
    c2.accountNumber = 1002;
    c2.accountBalance = 3000;
    c2.isActive = true;

    // Basic operations
    c1.deposit(2000);
    c1.withdraw(1000);
    c1.transfer(1500, c2);

    // Print details
    c1.printDetails();
    cout << endl;
    c2.printDetails();

    return 0;
}

