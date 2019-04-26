#include<iostream>
#include<fstream>

using namespace std;

class Bank_Acc
{
	protected:
		long int acc_num;
	private:
		double balance;
	public:
		Bank_Acc ()
		{
			acc_num = generate_accnum();
		}
		long long int generate_accnum ()
		{
			long long int acc_num;
			ifstream read("customer_acc.txt");
			
			read>>acc_num;
			read.close();
			
			
			ofstream write("customer_acc.txt");
			write<<++acc_num;
			write.close();
			
			return acc_num;
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
		void setAcc_Num (long int pAcc)
		{
			if (pAcc > 0)
				acc_num = pAcc;
			else
				acc_num = 0;
		}
		double getBalance () const
		{
			return balance;
		}
		long int getAcc_Num () const
		{
			return acc_num;
		}
		double UpdateBalance (double amount)
		{
			balance = balance + amount;
			return balance;
		}
		virtual double withdraw (double) = 0;
		virtual double deposit (double) = 0;
		
};


