#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
	private:

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

		static string _ReadAccountNumber()
		{
			string AccountNumber;
			cout << "\nPlease enter Account Number: ";
			cin >> AccountNumber;
			return AccountNumber;
		}

	public:

		static void ShowWithdrawScreen()
		{
			_DrawScreenHeader("\t   Withdraw Screen");

			string AccountNumber = _ReadAccountNumber();

			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
				AccountNumber = _ReadAccountNumber();
			}

			clsBankClient Client = clsBankClient::Find(AccountNumber);
			_PrintClient(Client);

			double Amount = 0;
			cout << "\nPlease enter Withdraw amount? ";
			Amount = clsInputValidate::ReadDblNumber();

			cout << "\nAre you sure you want to perform this transaction? ";
			char answer = 'n';
			cin >> answer;

			if (toupper(answer) == 'Y')
			{
				if(Client.Withdraw(Amount))
				{
					cout << "\nAmount Withdraw Successfully.\n";
					cout << "\nNew Balance Is: " << Client.AccountBalance;
				}
				else
				{
					cout << "\nCannot withdraw, Insuffecient Balance!\n";
					cout << "\nAmout to withdraw is: " << Amount;
					cout << "\nYour Balance is: " << Client.AccountBalance;

				}
			}
			else
			{
				cout << "\nOperation was cancelled.\n";
			}

		}
	};

