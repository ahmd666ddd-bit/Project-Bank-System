#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

	class clsTransferScreen : protected clsScreen
	{
	private:

		static void _PrintClient(clsBankClient Client)
		{
			cout << "\nClient Card:";
			cout << "\n___________________";
			cout << "\nFull Name   : " << Client.FullName();
			cout << "\nAcc. Number : " << Client.AccountNumber();
			cout << "\nBalance     : " << Client.AccountBalance;
			cout << "\n___________________\n";

		}

		static string _ReadAccountNumber()
		{
			string AccountNumber;
			cout << "\nPlease enter Account Number to Transfer from: ";
			cin >> AccountNumber;
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
				AccountNumber = _ReadAccountNumber();
			}
			return AccountNumber;
		}

		static float RaedAmount(clsBankClient SourceClient)
		{
			double Amount = 0;
			cout << "\nEnter Transfer amount? ";
			Amount = clsInputValidate::ReadDblNumber();
			while (Amount > SourceClient.AccountBalance)
			{
				cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
				Amount = clsInputValidate::ReadDblNumber();
			}

			return Amount;
		}

	public:

		static void ShowTransferScreen()
		{
			_DrawScreenHeader("\t   Transfer Screen");

			clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
			_PrintClient(SourceClient);

			clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
			_PrintClient(DestinationClient);

			float Amount = RaedAmount(SourceClient);
			cout << "\nAre you sure you want to perform this operation? y/n? ";
			char Answer = 'n';
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
				{
					cout << "\nTransfer done successfully\n";
				}
				else
				{
					cout << "\nTransfer Faild \n";
				}

				_PrintClient(SourceClient);
				_PrintClient(DestinationClient);
			}
		}


	};

