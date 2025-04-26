#pragma once
#include<iostream>
#include"check.h"
#include"random.h"
using namespace std;
namespace print {
	void PrintPerfectNumbersFrom1ToN(int Number)
	{
		for (int i = 1; i <= Number; i++)
		{
			if (check::isPerfectNumber(i))
			{
				cout << i << endl;
			}
		}
	}
	void PrintDigitsInReversedOrder(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}
	int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0, Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}
		return FreqCount;
	}
	void PrintAllDigitsFrequencey(int Number)
	{
		cout << endl;
		for (int i = 0; i < 10; i++)
		{
			short DigitFrequency = 0;
			DigitFrequency = CountDigitFrequency(i, Number);
			if (DigitFrequency > 0)
			{
				cout << "Digit " << i << " Frequencey is "
					<< DigitFrequency << " Time(s).\n";
			}
		}
	}
	void PrintDigits(int Number)
	{
		int Remainder = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			cout << Remainder << endl;
		}
	}
	void PrintInvertedNumberPattern(int Number)
	{
		cout << "\n";
		for (int i = Number; i >= 1; i--)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << "\n";
		}
	}
	void PrintNumberPattern(int Number)
	{
		cout << "\n";
		for (int i = 1; i <= Number; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout << i;
			}
			cout << "\n";
		}
	}
	void PrintLetterPattern(int Number)
	{
		cout << "\n";
		for (int i = 65; i <= 65 + Number - 1; i++)
		{
			for (int j = 1; j <= i - 65 + 1; j++)
			{
				cout << char(i);
			}
			cout << "\n";
		}
	}
	void PrintWordsFromAAAtoZZZ()
	{
		cout << "\n";
		string word = "";
		for (int i = 65; i <= 90; i++)
		{
			for (int j = 65; j <= 90; j++)
			{
				for (int k = 65; k <= 90; k++)
				{
					word = word + char(i);
					word = word + char(j);
					word = word + char(k);
					cout << word << endl;
					word = "";
				}
			}
			cout << "\n____________________________\n";
		}
	}
	

}
