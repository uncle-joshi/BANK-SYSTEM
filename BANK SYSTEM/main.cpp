#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a bank account
struct Account {
  string name;
  string cnic;
  string phoneNumber;
  string address;
  float balance;
};

// Function to display the main menu
void displayMenu() {
  cout << "\nMenu:\n";
  cout << "1. Create Account\n";
  cout << "2. View Account Details\n";
  cout << "3. Deposit\n";
  cout << "4. Withdraw\n";
  cout << "5. Exit\n";
  cout << "Enter your choice: ";
}

// Function to create a new account
void createAccount(vector<Account> &accounts) {
  Account newAccount;
  cout << "\nEnter your name: ";
  cin.ignore(); // Consume newline character from previous input
  getline(cin, newAccount.name);
  cout << "Enter your CNIC: ";
  getline(cin, newAccount.cnic);
  cout << "Enter your phone number: ";
  getline(cin, newAccount.phoneNumber);
  cout << "Enter your address: ";
  getline(cin, newAccount.address);
  cout << "Enter initial balance: $";
  cin >> newAccount.balance;
  accounts.push_back(newAccount);
  cout << "Account created successfully!\n";
}

// Function to view account details
void viewAccountDetails(const vector<Account> &accounts) {
  string name;
  cout << "Enter your name: ";
  cin.ignore(); // Consume newline character from previous input
  getline(cin, name);

  bool found = false;
  for (const Account &account : accounts) {
    if (account.name == name) {
      cout << "\nAccount Details:\n";
      cout << "Name: " << account.name << endl;
      cout << "CNIC: " << account.cnic << endl;
      cout << "Phone Number: " << account.phoneNumber << endl;
      cout << "Address: " << account.address << endl;
      cout << "Balance: $" << fixed << setprecision(2) << account.balance
           << endl;
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "\033[31mAccount not found!\033[0m\n"; // Red color for the warning
                                                   // message
  }
}

// Function to deposit money into an account
void deposit(vector<Account> &accounts) {
  string name;
  float amount;
  cout << "Enter your name: ";
  cin.ignore(); // Consume newline character from previous input
  getline(cin, name);
  cout << "Enter amount to deposit: $";
  cin >> amount;

  bool found = false;
  for (Account &account : accounts) {
    if (account.name == name) {
      account.balance += amount;
      cout << "Deposit successful! New balance: $" << fixed << setprecision(2)
           << account.balance << endl;
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "\033[31mAccount not found!\033[0m\n"; // Red color for the warning
                                                   // message
  }
}

// Function to withdraw money from an account
void withdraw(vector<Account> &accounts) {
  string name;
  float amount;
  cout << "Enter your name: ";
  cin.ignore(); // Consume newline character from previous input
  getline(cin, name);
  cout << "Enter amount to withdraw: $";
  cin >> amount;

  bool found = false;
  for (Account &account : accounts) {
    if (account.name == name) {
      if (amount <= account.balance) {
        account.balance -= amount;
        cout << "Withdrawal successful! New balance: $" << fixed
             << setprecision(2) << account.balance << endl;
      } else {
        cout << "\033[31mInsufficient funds!\033[0m\n"; // Red color for the
                                                        // warning message
      }
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "\033[31mAccount not found!\033[0m\n"; // Red color for the warning
                                                   // message
  }
}

int main() {
  vector<Account> accounts;

  cout << "Welcome to the Online Banking System!\n";

  while (true) {
    displayMenu();
    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
      createAccount(accounts);
      break;
    case 2:
      viewAccountDetails(accounts);
      break;
    case 3:
      deposit(accounts);
      break;
    case 4:
      withdraw(accounts);
      break;
    case 5:
      cout << "\nThank you for using the                         Online "
              "Banking System!\n";
      return 0;
    default:
      cout
          << "\nInvalid choice. Please try                       again.\n"; // Show this message for invalid choices
      break; // Add a break statement to exit the switch
    }
  }
  return 0;
}