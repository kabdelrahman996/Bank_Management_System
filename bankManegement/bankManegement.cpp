#include <iostream>
#include <cstdlib>


#include "bank.h"

int main() {

    int choice, age, phone, acc_number, acc_number2;
    double amount;
    string name, address;

    Bank b1;
    Account acc2(rand(), 45, 1587436954, "Mohammed Ahmed", "Cairo", 150000);

    cout << "**************************** Hello and Welcome to the Management System of the Bank ****************************" << endl;

    Account acc1(0, 0, 0, "", "", 0);

    do {
        cout << "Choose The Proccess You want:" << endl;
        cout << "1- Open New Account.\n2- Access Your Account.\n3- Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Please Enter Your name: ";
            cin >> name;
            cout << "Please Enter Your Address: ";
            cin >> address;
            cout << "Enter Your Age: ";
            cin >> age;
            cout << "Now, Enter Your Phone Number: 0";
            cin >> phone;
            cout << "What is the amount you want to deposit? ";
            cin >> amount;

            acc1 = Account(rand(), age, phone, name, address, amount);

            cout << "Your Account has successfully created." << endl;
            acc1.display();
            break;

        case 2:
            cout << "Enter your account number: ";
            cin >> acc_number;
            if (acc1.get_acc_number() == acc_number) {
                acc1.display();
                cout << "What Do You Want to Do? " << endl;
                do {
                    cout << "1- Deposit.\n2- Withdraw.\n3- Transfer.\n4- Exit." << endl;
                    cin >> choice;
                    switch (choice) {
                    case 1:
                        cout << "Enter The Amount: ";
                        cin >> amount;
                        acc1.deposit(amount);
                        break;
                    case 2:
                        cout << "Enter The Amount: ";
                        cin >> amount;
                        acc1.withdraw(amount);
                        break;
                    case 3:
                        cout << "Enter The Account number you want to transfer to.... : ";
                        cin >> acc_number2;
                        cout << "Enter The Amount: ";
                        cin >> amount;
                        acc1.transfer(acc2, amount);
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Error: Invalid choice." << std::endl;
                        break;
                    }
                } while (choice != 4);
            }
            else {
                cout << "Error: Invalid account number." << endl;
            }
            break;

        case 3:
            break;

        default:
            cout << "Error: Invalid choice." << std::endl;
            break;
        }

    } while (choice != 3);

    return 0;
}