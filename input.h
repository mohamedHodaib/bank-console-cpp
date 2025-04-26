#pragma once
#include<iostream>
#include<string>
using namespace std;
namespace input {
	int ReadPositiveNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "please enter a valid number: ";
				cin >> Number;
			}
		} while (Number <= 0);
		return Number;
	}
	string ReadPassword()
	{
		string Password;
		cout << "Please enter a 3-Letter Password (all capital)?\n";
		cin >> Password;
		return Password;
	}
	string ReadText()
	{
		string Text;
		cout << "Please enter Text?\n";
		getline(cin, Text);
		return Text;
	}
	int ReadNumber(string Message) {
		int Number;
		cout << Message;
			cin >> Number;
			while (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "please enter a valid number: ";
				cin >> Number;
			}
			return Number;
	}
}
