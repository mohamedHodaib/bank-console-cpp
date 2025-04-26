#pragma once
#include<iostream>
using namespace std;
enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };
namespace randoms {
	int RandomNumber(int From, int To)
	{
		srand((unsigned)time(NULL));
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		}
	}
	string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}
	string GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
		return Key;
	}
	void GenerateKeys(short NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}

}