#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter FirsName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccountBalance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public: 

	static void ShowUpDateClientScreen()
	{

		if (!CheckAccessRight(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("\t UpDate Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";

		ReadClientInfo(Client1);

		clsBankClient::enSaveResults SaveResults;
		SaveResults = Client1.Save();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;
		}
		case clsBankClient::enSaveResults::svFileEmpeltyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		}

	}
};

