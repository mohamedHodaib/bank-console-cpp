#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
class clsTransferLogScreen:protected clsScreen
{
    static void _PrintTranferLogRecordLine(clsBankClient::stTransferRegister Transfer)
    {

        cout << setw(8) << left << "" << "| " << setw(18) << left << Transfer.DateTime;
        cout << "| " << setw(10) << left << Transfer.SourceAccountNumber;
        cout << "| " << setw(10) << left << Transfer.DestinationAccountNumber;
        cout << "| " << setw(10) << left << Transfer.TransferAmount;
        cout << "| " << setw(10) << left << Transfer.SourceAccountBalance;
        cout << "| " << setw(10) << left << Transfer.DestinationAccountBalance;
        cout << "| " << setw(10) << left << Transfer.UserName;
    }
public :
	static void ShowTransferLogScreen() {
            vector <clsBankClient::stTransferRegister> vTransferLog = clsBankClient::GetTransfersList();

            string Title = "\t  Transfer Log Screen";
            string SubTitle = "\t    (" + to_string(vTransferLog.size()) + ") Records(s).";

            _DrawScreenHeader(Title, SubTitle);

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;         
            cout << setw(8) << left << "" <<"| " << left << setw(18) << "Date/Time";
            cout << "| " << left << setw(10) << "s.Acct";
            cout << "| " << left << setw(10) << "d.Acct";
            cout << "| " << left << setw(10) << "Amount";
            cout << "| " << left << setw(10) << "s.Balance";
            cout << "| " << left << setw(10) << "d.Balance";
            cout << "| " << left << setw(10) << "User";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;

            if (vTransferLog.size() == 0)
                cout << "\t\t\t\tNo Users Available In the System!";
            else

                for (clsBankClient::stTransferRegister Transfer : vTransferLog)
                {

                    _PrintTranferLogRecordLine(Transfer);
                    cout << endl;
                }

            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "______________________________________________\n" << endl;
        
	}
};

