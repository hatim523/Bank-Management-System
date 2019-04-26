#include<iostream>
#include<windows.h>
#include "Bank.h"

using namespace std;

class Current_Acc : public Bank_Acc
{
	public:
		Current_Acc (string pAcc) : Bank_Acc (pAcc)
		{
			
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

int main()
{
	Current_Acc c1("12364889");
	c1.deposit(85000);
	c1.withdraw(75000);
}
