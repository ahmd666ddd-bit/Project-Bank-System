#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string UserName, Password;
		bool LoginFaild = false; 
		short FaildLoginCount = 0;

		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!";
				cout << "\nYou have " << (3 - FaildLoginCount)
					<< " Trial(s) to login.\n\n";
			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}

			cout << "\n Enter UserName: ";
			cin >> UserName;

			cout << "\n Enter Passwrd: ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		 
		CurrentUser.RegisterInLogin();

			clsMainScreen::ShowMainMenue();
			return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();

	}
};

