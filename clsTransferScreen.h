#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"

using namespace std;
class clsTransferScreen:protected clsScreen
{
    enum enTransfer { From = 0, To = 1 };
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc.Number  : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
	static string _ReadAccountNumber(enTransfer FromOrTo) {
        if (FromOrTo == From) {
            cout << "\nPlease enter AccountNumber to transfer From? ";
        }
        else {
            cout << "\nPlease enter AccountNumber to transfer To? ";
        }
            string AccountNumber = clsInputValidate::ReadString();
            while (!clsBankClient::IsClientExist(AccountNumber))
            {
                cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
                AccountNumber = clsInputValidate::ReadString();
            }

            return AccountNumber;
	}
   static  double _ReadAmount(clsBankClient Client1) {
       double Amount = 0;
       cout << "\nPlease enter Transfer amount? ";
       Amount = clsInputValidate::ReadDblNumber();
       while (Amount > Client1.AccountBalance) {
           cout << "Amount exceeds the available balance,Enter another Amount?";
           Amount = clsInputValidate::ReadDblNumber();
       }
       return Amount;
    }
public :
	static void Transfer() {
		system("cls");
		_DrawScreenHeader("\tTransfer Screen");
        clsBankClient Client1 =clsBankClient::Find(_ReadAccountNumber(From));
        _PrintClient(Client1);
        clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber(To));
        _PrintClient(Client2);
        double Amount = _ReadAmount(Client1);
        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Transfer(Amount, Client2);
                cout << "\n Transfer done Successfully.\n";
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
        _PrintClient(Client1);
        _PrintClient(Client2);
	}
};

