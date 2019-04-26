#include<iostream>
#include<windows.h>
#include "Bank.h"

using namespace std;

class Saving_Acc : public Bank_Acc
{
	private:
		void interest_deposit ()
		{
			double interest = getBalance() * 0.02;
			UpdateBalance (interest);
		}
	public:
		Saving_Acc (string pAcc) : Bank_Acc (pAcc)
		{
			
		}
		void stimulateDays ()
		{
			//Assuming 2% interest monthly
			int days;
			cout<<"Enter Months to stimulate: ";
			cin>>days;
			
			for (int i=1; i<=days; i++)
			{
				cout<<"Month "<<i<<endl;
				Sleep (2500);
				interest_deposit ();
			}
		}
		void deposit (double amount)
		{
			if (amount > 500 && amount < 50000)
			{
				cout<<"Requesting Trasaction. Please wait.\n";
				Sleep (2000);
				cout<<"Depositing Amount Rs."<<amount<<"/\n";
				Sleep (1500);
				UpdateBalance (amount);
				cout<<"Amount successfully deposited...\n";
			}
			else if (amount >= 50000)
			{
				cout<<"Requesting Trasaction. Please wait.\n";
				Sleep (2000);
				cout<<"WithHolding Tax for amount Rs."<<amount<<"/ will be Rs."<<amount * 0.003<<"/\n";
				Sleep (1000);
				cout<<"Depositing Amount Rs."<<amount - (amount * 0.003)<<"/\n";
				Sleep (1500);
				UpdateBalance ((amount - (amount * 0.003)));
				cout<<"Amount successfully deposited...\n";
			}
			else
			{
				cout<<"Requesting Trasaction. Please wait.\n";
				Sleep (2000);
				cout<<"Sorry not enough amount to Deposit.\n";
			}
			
			cout<<"Updated Balance is Rs."<<getBalance()<<endl;
			system("pause");
			system("cls");
		}
		void withdraw (double amount)
		{
			double bal = getBalance ();
			cout<<"Requesting Trasaction. Please wait.\n";
			Sleep (2000);
			cout<<"Checking for current Account Balance...\n";
			Sleep (1000);
			if (bal >= amount)
			{
				cout<<"Balance confirmed...\nWithdrawing amount...\n";
				Sleep (1000);
				UpdateBalance (-amount);
				cout<<"Amount successfully withdrawn...\n";
				Sleep(500);
				cout<<"Remaining Account Balance is Rs."<<getBalance()<<endl;
			}
			else
			{
				cout<<"Not enough balance to proceed request...\n";
				Sleep (500);
				cout<<"Cancelling request\n";
			}
			
			system("pause");
			system("cls");
		}
};


