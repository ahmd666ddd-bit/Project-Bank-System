#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"
#include <iomanip>

class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOption{
		eListClient=1, eAddNewClient=2, eDeleteClient=3,
		eUpdateClient=4, aFindClient=5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegisterScreen=8, eExit = 9
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between 1 to 9? ");
		return Choice;
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNweClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpDateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _Login()
    {
        clsUser CurrentUser = clsUser::Find("", "");
    }

    static void PerfromMainMenueOption(enMainMenueOption MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOption::eListClient:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::aFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eLoginRegisterScreen:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOption::eExit:
        {
            system("cls");
           _Login();
            break;
        }
        }
    }

    public:

        static void ShowMainMenue()
        {
            system("cls");
            _DrawScreenHeader("\t\tMian Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            PerfromMainMenueOption((enMainMenueOption)_ReadMainMenueOption());
        }

};

