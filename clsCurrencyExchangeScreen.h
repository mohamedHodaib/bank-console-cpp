#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUsersListScreen.h"
#include "AddNewUserScreen.h"
#include "DeleteUserScreen - Copy.h"
#include "clsUpdateUserScreen - Copy.h"
#include "clsFindUserScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculator.h"
class clsCurrencyExchangeScreen :protected clsScreen
{
    enum enCurrencyMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short _ReadCurrencyMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate::ReadshortNumberBetween(1, 5);
        return Choice;
    }

    static  void _GoBackToCurrencyMainMenue()
    {
        cout << setw(37) << left << "" <<
            "\n\tPress any key to go back to Currency Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeMainScreen();
    }

    static void _ListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowCurrenciesList();
    }

    static void _FindCurrencyScreen()
    {
        clsFindCurrency::ShowFindUserScreen();

    }

    static void _UpdateRateScreen()
    {
        clsUpdateRate::ShowUpdateCurrencyRateScreen();

    }

    static void _CurrencyCalculatorScreen()
    {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
        

    }

    static void _PerfromCurrencyMainMenueOption(enCurrencyMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enCurrencyMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ListCurrenciesScreen();
            _GoBackToCurrencyMainMenue();
            break;
        }
        case enCurrencyMainMenueOptions::eFindCurrency:
            system("cls");
            _FindCurrencyScreen();
            _GoBackToCurrencyMainMenue();
            break;

        case enCurrencyMainMenueOptions::eUpdateRate:
            system("cls");
            _UpdateRateScreen();
            _GoBackToCurrencyMainMenue();
            break;

        case enCurrencyMainMenueOptions::eCurrencyCalculator:
            system("cls");
            _CurrencyCalculatorScreen();
            _GoBackToCurrencyMainMenue();
            break;
        
        }

    }
public :
	static void ShowCurrencyExchangeMainScreen() {

        system("cls");
        _DrawScreenHeader("\t\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyMainMenueOption((enCurrencyMainMenueOptions)_ReadCurrencyMainMenueOption());
	}
};

