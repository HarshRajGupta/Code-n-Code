#include <bits/stdc++.h>

void start();

int main() {
    std::cout << "Hi! Welcome to Mr. Zamar`s ATM Machine!\n\n";
    start();
    return 0;
}

void printMainMenu() {
    std::cout << "d -> Deposit Money\n"
        << "w -> Withdraw Money\n"
        << "b -> Request Balance\n"
        << "q -> Quit\n\n> ";
}

void login() {/* PHASE 2 */ }

void createAccount() {/* PHASE 2 */ }

void printIntroMenu() {
    std::cout << "l -> Login\n"
        << "c -> Create New Account\n"
        << "q -> Quit\n\n> ";
}

void start() {
    bool isLoggedIn = false;
    do {
        std::cout << "Please select an option from the menu below:\n\n";

        if (!isLoggedIn) printIntroMenu();
        else  printMainMenu();

        char menuInput;
        std::cin >> menuInput;

        if (!isLoggedIn) {
            switch (menuInput) {
            case 'l': {
                login();
                break;
            }
            case 'c': {
                createAccount();
                break;
            }
            case 'q': {
                std::cout << "Thanks for stopping by!";
                exit(0);
            }
            default: std::cout << "Invalid input. Please try again.\n";
            }
        }
        else {/* PHASE 2 */ }
    } while (true);
}