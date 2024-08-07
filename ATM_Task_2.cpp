#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

struct Account {
    int AccountNumber;
    std::string AccountHolder;
    double balance;
};

std::vector<Account> accounts;
int currentAccount = -1;


bool ValidAccountNumber(int AccountNumber){ //Checks to see if your the account number matches with the fake account numbers created
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].AccountNumber == AccountNumber) {
            currentAccount = i;
            return true;
        }
    }
    return false;
}

void CreateAccount(){
    Account newAccount;
    std::cout << "Enter account number: ";
    std::cin >> newAccount.AccountNumber;
    std::cin.ignore();
    std::cout << "Enter account holder name: ";
    std::getline(std::cin, newAccount.AccountHolder);
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);
    std::cout << "Account created successfully." << std::endl;
}
void Transfer(){
    int targetAccountNumber;
    double amount;
    std::cout << "Enter target account number: ";
    std::cin >> targetAccountNumber;
    std::cout << "Enter amount to transfer: $";
    std::cin >> amount;

    int targetIndex = -1;
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].AccountNumber == targetAccountNumber) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex != -1 && amount > 0 && amount <= accounts[currentAccount].balance) {
        accounts[currentAccount].balance -= amount;
        accounts[targetIndex].balance += amount;
        std::cout << "Transfer successful." << std::endl;
    } else {
        std::cout << "Transfer failed. Check account number, balance, and amount." << std::endl;
    }
}

void CheckBalance(){ //this function shows their balance
    std::cout << "Your balance is: $" << std::fixed << std::setprecision(2) << accounts[currentAccount].balance << std::endl;
}

void Withdraw(){ //This function takes the user input and holds in a double, to then subtract it from their current account balance.
    double subtraction;
    std::cout << "Enter the amount you would like to withdraw from your account: $";
    std::cin >> subtraction;
    if(subtraction <= accounts[currentAccount].balance){
        accounts[currentAccount].balance -= subtraction;
        std::cout << "Please take your cash below." << std::endl;
        CheckBalance();
    }
    else{
        std::cout << "Insuffient Funds, please try again." << std::endl;
    }
}

void Deposit(){ //this function takes user input and adds it to the current account balance.
    double addiation;
    std::cout << "Enter amount to deposit: ";
    std::cin >> addiation;
    if (addiation > 0) {
        accounts[currentAccount].balance += addiation;
        std::cout << "Deposit successful." << std::endl;
        CheckBalance();
    } else {
        std::cout << "Invalid deposit amount." << std::endl;
    }
}

void Menu(){ //The ATM menu options
    std::cout << "1. Create New Account" << std::endl;
    std::cout << "2. Check Balance" << std::endl;
    std::cout << "3. Withdraw" << std::endl;
    std::cout << "4. Deposit" << std::endl;
    std::cout << "5. Transfer" << std::endl;
    std::cout << "6. Sign out" << std::endl;
}
void ReturningUser(){
    int AccountNumber;
    std::cout << "Enter Bank Account Number: ";
    std::cin >> AccountNumber;

    if (ValidAccountNumber(AccountNumber)) {
        int choice2;
        do{
            Menu();
            std::cout << "Please pick an option (Numbers 1-6): ";
            std::cin >> choice2;

            switch (choice2) {
            case 1:
                CreateAccount();
                break;
            case 2:
                CheckBalance();
                break;
            case 3:
                Withdraw();
                break;
            case 4:
                Deposit();
                break;
            case 5:
                Transfer();
                break;
            case 6:
                std::cout << "Thank you for using the ATM. Have a good day!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice2 != 6);
    } else {
        std::cout << "Authentication failed. Invalid account number." << std::endl;
    }
}

int main(){
    int choice1;
    
    std::cout << "Welcome to the ATM." << std::endl;
    std::cout << "1. New User" <<std::endl;
    std::cout << "2. Returning User" <<std::endl;
    std::cout << "Select an option (1 or 2): " <<std::endl;
    std::cin>>choice1;

    switch (choice1)
    {
    case 1:
        CreateAccount();
        ReturningUser();
        break;
    
    default:
        ReturningUser();
        break;
    }

    return 0;
}