#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include"clsUser - Copy.h"
#include "clsInputValidate.h"
class clsUpdateRate:protected clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\n\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry        : " << Currency.Country();
        cout << "\nCode           : " << Currency.CurrencyCode();
        cout << "\nName           : " << Currency.CurrencyName();
        cout << "\nRate(1$)       : " << Currency.Rate();
        cout << "\n___________________\n";

    }
public:
    static void ShowUpdateCurrencyRateScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter  Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency  Currency = clsCurrency::FindByCode(CurrencyCode);

        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            double NewRate = 0;
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";
            cout << "Enter New Rate:" ;
            cin >> NewRate;
            Currency.UpdateRate(NewRate);
            cout << "\n\nCurrency Updated Successfully:-)\n";
            _PrintCurrency(Currency);
        }

    }
};

