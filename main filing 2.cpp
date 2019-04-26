#include<iostream>
#include<fstream>
#include<windows.h>
#include "Bank.h"
#include "Authentication.h"
#include "Person.h"

using namespace std;


class Saving_Acc : virtual public Bank_Acc, public Authentication, public Person
{
	private:
		void interest_deposit ()
		{
			double interest = getBalance() * 0.02;
			UpdateBalance (interest);
		}
	public:
		Saving_Acc ()
		{
			
		}
		void login_Saving ()
		{
			Authentication::login();
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
		friend int operator >> (istream &, Saving_Acc&);
		friend void operator << (ostream &, Saving_Acc&);
};

class Current_Acc : virtual public Bank_Acc, public Authentication, public Person
{
	public:
		Current_Acc ()
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

char * generate_filename (Saving_Acc s1);

int operator >> (istream &in, Saving_Acc &e1)
{
	//Person details
	string name, cnic, address, number;
	int age;
	char sex;
	
	cout<<"Name: ";
	in>>name;
	e1.setName(name);
	
//	cout<<"Age: ";
//	in>>age;
//	e1.setAge(age);
//	
//	cout<<"Gender (M/F): ";
//	in>>sex;
//	e1.setSex(sex);
//	
//	cout<<"CNIC: ";
//	in>>cnic;
//	e1.setCNIC(cnic);
//	
//	cout<<"Address: ";
//	in>>address;
//	e1.setAddress(address);
//	
//	cout<<"Number: ";
//	in>>number;
//	e1.setNumber(number);
	
	int successful = 0;
	successful = e1.createAccount();
	return successful;
}
void operator << (ostream &out, Saving_Acc &s1)
{
	cout<<"Account Number: "<<s1.getAcc_Num()<<endl;
	cout<<"Name: "<<s1.getName()<<endl;
	cout<<"Age: "<<s1.getAge()<<endl;
	cout<<"Address: "<<s1.getAddress()<<endl;
	cout<<"Number: "<<s1.getNumber()<<endl;
	cout<<"CNIC Number: "<<s1.getCNIC()<<endl;
	cout<<"Account Type: Saving Account\n";
	cout<<"Balance: "<<s1.getBalance()<<endl;
}

//int main()
//{
////	Saving_Acc s1, s2, s3;
////	cout<<s1.getAcc_Num()<<endl;
////	cout<<s1.getBalance()<<endl;
////	
////	cout<<s2.getAcc_Num()<<endl;
////	cout<<s2.getBalance()<<endl;
////	
////	cout<<s3.getAcc_Num()<<endl;
////	cout<<s3.getBalance()<<endl;
//	
//	int login_option = 0;
//	do
//	{
//		cout<<"\t\t\t\t\tWelcome to HASH Bank\t\t\t\n";
//		cout<<"Please select from the following option: \n\t1. Login\n\t2. Create a new Account\n";
//		cin>>login_option;
//		
//		if (login_option == 1)
//		{
//			int account_option = 0;
//			do
//			{
//				cout<<"Please select your Account type: \n\t1. Current Account\n\t2. Saving Account\n";
//				cin>>account_option;
//				
//				if (account_option == 1)
//				{
//					
//					break;
//				}
//				else if (account_option == 2)
//				{
//					break;
//				}
//				else
//				{
//					cout<<"Please select a valid option...\n";
//					Sleep(1500);
//					system("cls");
//				}
//			}
//			while (true);
//		}
//		else if (login_option == 2)
//		{
//			int account_option = 0;
//			cout<<"Please select the desired Account type to create: \n\t1. Current Account\n\t2. Saving Account\n";
//			cin>>account_option;
//			
//			if (account_option == 1)
//			{
//				
//				break;
//			}
//			else if (account_option == 2)
//			{
//				int retry = 0;
//				Saving_Acc temp;
//				retry = cin>>temp;
//				if (retry == 0)
//					cout<<"Account not created. Please try again later...\n";
//				
//				//saving into unique file	
//				if (retry == 1)
//				{
//					char *filename = generate_filename (temp);
//					
//					fstream file;
//					file.open(filename, ios::out | ios::binary );
//					file.write((char*)&temp, sizeof(temp));
//					file.close();
//					
//					Saving_Acc dis;
//					file.open(filename, ios::in | ios::binary);
//					file.read((char*)&dis, sizeof(temp));
//					cout<<dis;
//				}
//				break;
//			}
//			else
//			{
//				cout<<"Please select a valid option...\n";
//				Sleep(1500);
//				system("cls");
//			}
//			while (true);
//		}
//		else
//		{
//			cout<<"Please select a valid option...\n";
//			Sleep(1500);
//			
//		}
//		system ("cls");
//	}
//	while (login_option != 1 && login_option != 2);
//	
//}


char * generate_filename (Saving_Acc s1)
{
	string temp = s1.getFilename();
	int len = stringlen (temp);
	
	int i;
	char arr[len+1];
	//copying elements of string into array
	for (i=0; i<len; i++)
	{
		arr[i] = temp[i];
	}
	arr[i] = '\0';
	char *filename = arr;
	return filename;
}
