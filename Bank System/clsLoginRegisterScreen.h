#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsLoginRegisterScreen : protected clsScreen
{
private: 

	static void _PrintLoginRegisterRecordLine(clsUser::stLogInRegisterRecord LogInRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LogInRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LogInRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LogInRegisterRecord.Password;
		cout << "| " << setw(10) << left << LogInRegisterRecord.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}
		vector <clsUser::stLogInRegisterRecord> vLoginRegisterRecord = clsUser::GetRegisterInLoginList();
		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		for (clsUser::stLogInRegisterRecord Record : vLoginRegisterRecord)
		{
			_PrintLoginRegisterRecordLine(Record);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

