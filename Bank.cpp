#include<iostream>

using namespace std;

class Bank_Acc
{
	protected:
		const string acc_num;
	private:
		double balance;
	public:
		Bank_Acc (string pAcc) : acc_num(pAcc)
		{
			balance = 0;
		}
		void setBalance (double bal)
		{
			if (bal > 500)
				balance = bal;
			else
			{
				cout<<"Not enough amount...\nBalance set to 0.\n";
			}
		}
		double getBalance () const
		{
			return balance;
		}
		void UpdateBalance (double amount)
		{
			balance = balance + amount;
		}
		virtual void withdraw (double) = 0;
		virtual void deposit (double) = 0;
		
};

