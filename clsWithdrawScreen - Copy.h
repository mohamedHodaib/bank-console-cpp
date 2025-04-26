#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBankClient.h"
using namespace std;
class clsWithdrawScreen:protected clsScreen
{
private:
	static void _Print(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PIN;
		cout << "\nBalance     : " << Client.AccBalance;
		cout << "\n___________________\n";
	}
public:
	static void WithdrawScreen() {
		system("cls");
		_DrawHeaderScreen("\tWithDraw Screen");
		string AccountNumber;
		cout << "\nPlease enter The account number?";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_Print(Client);
		double Amount;
		do {
			cout << "\nEnter the amount of WithDraw?";
			cin >> Amount;
		} while (Amount < 1);
		char Answer;
		cout << "Are you sure to perform this Transaction?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmout to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.AccBalance;

			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

		}
};

