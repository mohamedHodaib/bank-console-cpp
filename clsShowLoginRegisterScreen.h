#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsUser - Copy.h"
#include <iomanip>
class clsShowLoginRegisterScreen:protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser::stLogedInUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.DateTime;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permission;
    }

public:

    static void ShowLoginRegister()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }
        vector <clsUser::stLogedInUser> vUsers = clsUser::GetLogedInUsersList();

        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "Date/Time";
        cout << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser::stLogedInUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

};

