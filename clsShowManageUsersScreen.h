#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsBankClient.h"
using namespace std;
class clsShowManageUsersScreen:protected clsScreen
{
	enum enManageUsers { eListUsers = 1, eAddNewuser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainmenue = 6 };
	static short _ReadManageUsersOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}
	static void _ShowAllUsersScreen() {

	}
	static void _ShowAddNewUsersScreen() {

	}
	static void _ShowDeleteUserScreen() {

	}
	static void _ShowUpdateUserScreen() {

	}
	static void _ShowFindUserScreen() {

	}
	static void _GoBackToManageMenueScreen() {
		cout << "\n\nPress any key to back to Manage Users Screen.....";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _PerformManageUsersOptions(enManageUsers Option) {
		switch (Option) {
		case eListUsers:
			system("cls");
			_ShowAllUsersScreen();
			_GoBackToManageMenueScreen();
			break;
		case eAddNewuser:
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageMenueScreen();
			break;
		case eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageMenueScreen();
			break;
		case eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageMenueScreen();
			break;
		case eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageMenueScreen();
			break;
		}
	}

public :
	static void ShowManageUsersScreen() {
		system("cls");
		_DrawHeaderScreen("\tManage Users Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New user.\n";
		cout << setw(37) << left << "" << "\t[3] Delete user.\n";
		cout << setw(37) << left << "" << "\t[4] Update user Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find user.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUsersOptions(enManageUsers(_ReadManageUsersOption()));
	}

};

