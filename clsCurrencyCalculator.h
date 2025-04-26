#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include"clsUser - Copy.h"
#include "clsInputValidate.h"
#include"clsCurrency.h"
class clsCurrencyCalculator:protected clsScreen
{
	static string _ReadCurrencyCode() {
		string CurrencyCode = "";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return CurrencyCode;
	}
	static void _PrintCurrency(clsCurrency Currency,string Title)
	{
		cout << "\n" << Title;
		cout << "\n___________________";
		cout << "\nCountry        : " << Currency.Country();
		cout << "\nCode           : " << Currency.CurrencyCode();
		cout << "\nName           : " << Currency.CurrencyName();
		cout << "\nRate(1$)       : " << Currency.Rate();
		cout << "\n___________________\n";

	}
	static double _ReadAmount() {
		double Amount;
		cout << "\nEnter The Amount To Exchange:";
		Amount = clsInputValidate::ReadDblNumber();
		return Amount;
	}
	static double _AmountInDollar(double Rate,double Currency1Amount) {
		return Currency1Amount / Rate;
	}
	static double _AmountInCurrency2(double Rate, double DollarAmount){
		return DollarAmount * Rate;
	}
	static void _PrintCalculationsResults(double Amount,clsCurrency CurrencyFrom,clsCurrency CurrencyTo) {
		_PrintCurrency(CurrencyFrom, "Convert From:");
		double AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << Amount << "  " << CurrencyFrom.CurrencyCode() << " = " <<
			AmountInUSD << " USD ";
		if (CurrencyTo.CurrencyCode() == "USD")return;
		cout << "\nConverting From USD to:\n";
		_PrintCurrency(CurrencyTo, "To");
		double AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);
		cout << Amount << "  " << CurrencyFrom.CurrencyCode() << " = " <<
			AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode();
	}
	static clsCurrency _GetCurrency(string Message) {
		cout << Message;
		string CurrencyCode1 = _ReadCurrencyCode();
		clsCurrency  Currency1 = clsCurrency::FindByCode(CurrencyCode1);
		return Currency1;
	}

public :
	static void ShowCurrencyCalculatorScreen() {
		  char Answer = 'y';
	  do {
		  system("cls");
		  _DrawScreenHeader("\tCurrency Calculator Screen");
		  clsCurrency Currency1 = _GetCurrency("\nPlease Enter  Currency1: ");
		  clsCurrency Currency2 = _GetCurrency("\nPlease Enter  Currency2: ");
		  double AmountInCurrency1 = _ReadAmount();
		  _PrintCalculationsResults(AmountInCurrency1, Currency1, Currency2);
		  cout << "\n\nDo You Want To Perform another Calculation?y/n?";
		  cin >> Answer;
	  } while (Answer == 'y'||Answer == 'Y');
	}
};

