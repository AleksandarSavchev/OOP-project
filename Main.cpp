// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bank.h"

using std::cin;
using std::cout;

int BankMenu(Bank mybank)
{
	int number,amount;
	unsigned int id;
	char name[126], address[126],accounttype[32],iban[32],iban1[32];
	while (true)
	{
		cout << "1    List customers\n";
		cout << "2    Add new customer\n";
		cout << "3    Delete customer\n";
		cout << "4    List all accounts\n";
		cout << "5    List customer accounts\n";
		cout << "6    Add new account\n";
		cout << "7    Delete account\n";
		cout << "8    Withdraw from account\n";
		cout << "9    Deposit to account\n";
		cout << "10   Transfer\n";
		cout << "11   Display info for the bank\n";
		cout << "12   Quit\n";
		cout << "Choose one by typing its number here: ";
		cin >> number;
		if (number == 1)
		{
			cout << "\n";
			mybank.listCustomers();
		}
		else if (number == 2)
		{
			cout << "Enter customer's ID:";
			cin >> id;
			cout <<"\n";
			cin.ignore();
			cout << "Enter customer's name:";
			cin.getline(name, 126);
			cout << "\n";
			cout << "Enter customer's address:";
			cin.getline(address, 126);
			cout << "\n";
			mybank.addCustomer(id, name, address);
		}
		else if (number == 3)
		{
			cout << "Enter customer's ID:";
			cin >> id;
			mybank.deleteCustomer(id);
		}
		else if (number == 4)
		{
			cout << "\n";
			mybank.listAccounts();
		}
		else if (number == 5)
		{
			cout << "Enter customer's ID:";
			cin >> id;
			cout << "\n";
			mybank.listCustomerAccounts(id);
		}
		else if (number == 6)
		{
			cin.ignore();
			cout << "Enter account's type(e.g. Savings Account):";
			cin.getline(accounttype,32);
			cout << "\n";
			cout << "Enter account's IBAN:";
			cin.getline(iban, 32);
			cout << "\n";
			cout << "Enter owner's ID:";
			cin>>id;
			cout << "\n";
			cout << "Enter amount:";
			cin >> amount;
			cout << "\n";
			mybank.addAccount(accounttype, iban, id, amount);
		}
		else if (number == 7)
		{
			cin.ignore();
			cout << "Enter account's IBAN:";
			cin.getline(iban, 32);
			mybank.deleteAccount(iban);
		}
		else if (number == 8)
		{
			cin.ignore();
			mybank.listAccounts();
			cout << "Enter account's IBAN:";
			cin.getline(iban, 32);
			cout << "Enter amount you want to withdraw: ";
			cin >> amount;
			mybank.withdraw(iban, amount);
		}
		else if (number == 9)
		{
			cin.ignore();
			mybank.listAccounts();
			cout << "Enter account's IBAN:";
			cin.getline(iban, 32);
			cout << "Enter amount you want to deposit: ";
			cin >> amount;
			mybank.deposit(iban, amount);
		}
		else if (number == 10)
		{
			cin.ignore();
			mybank.listAccounts();
			cout << "Enter donator's IBAN:";
			cin.getline(iban, 32);
			cout << "Enter receiver's IBAN:";
			cin.getline(iban1, 32);
			cout << "Enter amount you want to transfer: ";
			cin >> amount;
			mybank.transfer(iban,iban1, amount);
		}
		else if (number == 11)
		{
			mybank.display();
		}
		else if (number == 12)
		{
			return 0;
		}
		else
		{
			cout << "You have enteres a wrong number! Try again.\n";
		}
		cout << "\n";
		cout << "\n";
	}
}
int main()
{
	Bank mybank("FMI","Sofia");
	BankMenu(mybank);
    return 0;
}

