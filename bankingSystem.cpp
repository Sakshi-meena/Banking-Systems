#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Account class to manage individual accounts
class Account
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    Account(int accNumber, string accHolderName, double initialBalance)
        : accountNumber(accNumber), accountHolderName(accHolderName), balance(initialBalance) {}

    // Deposit money into the account
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Withdraw money from the account
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    // Display account details
    void display() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Get account number
    int getAccountNumber() const { return accountNumber; }
};

// Bank class to manage multiple accounts
class Bank
{
private:
    vector<Account> accounts;

public:
    // Add a new account to the bank
    void addAccount(const Account &account)
    {
        accounts.push_back(account);
        cout << "Account added successfully!" << endl;
    }

    // Find an account by account number
    Account *findAccount(int accNumber)
    {
        for (auto &account : accounts)
        {
            if (account.getAccountNumber() == accNumber)
            {
                return &account;
            }
        }
        return nullptr;
    }

    // Deposit money into an account
    void deposit(int accNumber, double amount)
    {
        Account *account = findAccount(accNumber);
        if (account)
        {
            account->deposit(amount);
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

    // Withdraw money from an account
    void withdraw(int accNumber, double amount)
    {
        Account *account = findAccount(accNumber);
        if (account)
        {
            account->withdraw(amount);
        }
        else
        {
            cout << "Account not found!" << endl;
        }
    }

    // Display all accounts
    void displayAllAccounts() const
    {
        for (const auto &account : accounts)
        {
            account.display();
            cout << "------------------------" << endl;
        }
    }
};

// Main function to demonstrate the banking system
int main()
{
    Bank bank;

    // Create and add some accounts
    bank.addAccount(Account(101, "John Doe", 5000.00));
    bank.addAccount(Account(102, "Jane Smith", 3000.00));

    // Main loop
    while (true)
    {
        cout << "Banking System Menu:" << endl;
        cout << "1. Display All Accounts" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            bank.displayAllAccounts();
        }
        else if (choice == 2)
        {
            int accNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accNumber;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            bank.deposit(accNumber, amount);
        }
        else if (choice == 3)
        {
            int accNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accNumber;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            bank.withdraw(accNumber, amount);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
