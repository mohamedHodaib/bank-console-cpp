#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser - Copy.h"
#include <iomanip>
#include"clsCurrency.h"
class clsListCurrenciesScreen:protected clsScreen
{
    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) <<
            left << Currency.Country();
        cout << "| " << setw(12) << left << Currency.CurrencyCode();
        cout << "| " << setw(30) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();

    }
public:
    static void ShowCurrenciesList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " <<
            left << setw(30) << "Country";
        cout << "| " << left << setw(12) << "code";
        cout << "| " << left << setw(30) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

