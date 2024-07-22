#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<int, double> accounts; // Account number/balance
int currentAccount = -1;

bool ValidAccountNumber(int AccountNumber){ //Checks to see if your the account number matches with the fake account numbers created
    if (accounts.find(AccountNumber) != accounts.end()) {
        currentAccount = AccountNumber;
        return true;
    } else {
        return false;
    }
}

void CheckBalance(){ //this function shows their balance
    std::cout << "Your balance is: $" << accounts[currentAccount] << std::endl;
}

void Withdraw(){ //This function takes the user input and holds in a double, to then subtract it from their current account balance.
    double subtraction;
    std::cout << "Enter the amount you would like to withdraw from your account";
    std::cin >> subtraction;
    if(subtraction <= accounts[currentAccount]){
        accounts[currentAccount] -= subtraction;
        std::cout << "Please take your cash below." << std::endl;
        std::cout << "Your new balance is: $" << accounts[currentAccount] << std::endl;
    }
    else{
        std::cout << "Insuffient Funds, please try again." << std::endl;
    }
}

void Deposit(){ //this function takes user input and adds it to the current account balance.
    double addiation;
    std::cout << "Enter amount to deposit: ";
    std::cin >> addiation;
    accounts[currentAccount] += addiation;
    std::cout << "Your new balance is: $" << accounts[currentAccount] << std::endl;
}

void Menu(){ //The ATM menu options
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Deposit" << std::endl;
    std::cout << "4. Sign out" << std::endl;
}

int main(){
    //Fake account numbers to test
    accounts[2468642] = 1500;
    accounts[1357900] = 200;
    accounts[9876543] = 5000;

    int AccountNumber;

    std::cout << "Welcome to the ATM." << std::endl;
    std::cout << "Enter Bank Account Number: ";
    std::cin >> AccountNumber;

    if (ValidAccountNumber(AccountNumber)) {
        int choice;
        do{
            Menu();
            std::cout << "Please pick an option (Numbers 1-4): ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                CheckBalance();
                break;
            case 2:
                Withdraw();
                break;
            case 3:
                Deposit();
                break;
            case 4:
                std::cout << "Thank you for using the ATM. Have a good day!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } while (choice != 4);
    } else {
        std::cout << "Authentication failed. Invalid account number." << std::endl;
    }

    return 0;
}