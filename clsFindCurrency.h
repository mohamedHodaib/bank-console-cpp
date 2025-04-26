#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include"clsUser - Copy.h"
#include "clsInputValidate.h"
#include"clsCurrency.h"
class clsFindCurrency:protected clsScreen
{
    enum enFindOption{Code = 1,Country = 2};
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
    static enFindOption _ReadFindOption() {
        short Option;
        cout << "\n\n Find By [1]Code [2]Country?";
        cin >> Option;
        return enFindOption(Option);
    }
    static void _ShowResults(clsCurrency Currency) {
        if (Currency.IsEmpty()) {
            cout << "\n\nCurrency Not Found:-)";
        }
        else {
            cout << "\n\nCurrency  Found:-)";
        }
        _PrintCurrency(Currency);
    }
public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");
      enFindOption Option  =  _ReadFindOption();
      clsCurrency Currency = clsCurrency::FindByCode("");
      if (Option == Country) {
          string CountryName;
          cout << "\nPlease Enter Country Name:";
          cin >> CountryName;
           Currency = clsCurrency::FindByCountry(CountryName);
           _ShowResults(Currency);
      }
      else {
          string CurrencyCode;
          cout << "\nPlease Enter Currency Code:";
          cin >>CurrencyCode ;
         Currency = clsCurrency::FindByCode(CurrencyCode);
         _ShowResults(Currency);
      }
    }

};

