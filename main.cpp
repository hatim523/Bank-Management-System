#include<iostream>
#include<fstream>
#include<windows.h>
#include "Bank.h"
#include "Authentication.h"
#include "Person.h"
#include "hash.h"
using namespace std;

class Employee : public Person, public Authentication
{
	private:
		string department, qualification;
		double work_Hours, days, salary, experience;
		long long int IDnumber;
	protected:
		string position;
	public:
		int success;
		Employee ()
		{
			success = 0;
			IDnumber = generate_idnum();
		}
		long long int generate_idnum ()
		{
			long long int acc_num;
			ifstream read("employee_acc.txt");
			if (read)
			{
				read>>acc_num;
				read.close();
			}
			else
				cout<<"Failed to open\n";
			
			ofstream write("customer_acc.txt");
			write<<++acc_num;
			write.close();
			
			return acc_num;
		}
		void setDepartment (string pDepart)
		{
			//foreign exchange, treasury management, inspection, IT
			if (pDepart == "Customer Service" || pDepart == "customer service" ||pDepart == "Foreign Exchange" || pDepart == "foreign exchange" || pDepart == "Treasury Management" || pDepart == "treasury management" || pDepart == "IT" || pDepart == "Inspection" || pDepart == "inspection")
				department = pDepart;
			else
			{
				cout<<"Department does not exist...\nSetting Department to Default: Customer Service Department\n";
				department = "Customer Service Department";
			}
		}
		virtual void setPosition (string pPos)
		{
			//input by getline()
			//financial analyst, bank teller, loan officer, internal auditor
			if (pPos == "Financial Analyst" || pPos == "financial analyst" || pPos == "Bank Teller" || pPos == "bank teller" || pPos == "Loan Officer" || pPos == "loan officer" || pPos == "Internal Auditor" || pPos == "internal auditor")
				position = pPos;
			else
			{
				cout<<"The entered Position does not exist...\nSetting Default Position: Financial Analyst\n";
				position = "Financial Analyst";
			}
		}
		void setQualification (string pQual)
		{
			//BCOM, MBA, CA
			if (pQual == "BCOM" || pQual == "MBA" || pQual == "CA")
				qualification = pQual;
			else
			{
				cout<<"Invalid Qualification...\nSetting Qualification to Default: CA\n";
				qualification = "CA";
			}
		}
		void setWorkHrs (double pHours)
		{
			if (pHours > 0 && pHours < 240)
				work_Hours = pHours;
			else
			{
				cout<<"Invalid input\nSetting to Default: 200 Hrs\n";
				work_Hours = 200.0;
			}
			CalculateDays();
		}
		void setExp (double pExp)
		{
			if (pExp >= 1)
				experience = pExp;
			else
			{
				cout<<"Not enough experience\nSetting to Default: 1 Yr\n";
				experience = 1.0;
			}
		}
		void setSal (double pSal)
		{
			if (pSal >= 25000)
				salary = pSal;
			else
			{
				cout<<"Invalid amount...\nSetting to Default: Rs.25000/\n";
				salary = 25000;
			}
		}
		void CalculateDays ()
		{
			days = getHrs() / 8.0;
		}
		double getHrs () const
		{
			return work_Hours;
		}
		string getQual () const
		{
			return qualification;
		}
		string getDepart() const
		{
			return department;
		}
		string getPos() const
		{
			return position;
		}
		double getDays () const
		{
			return days;
		}
		double getSal () const
		{
			return salary;
		}
//		long int getID () const
//		{
//			return IDnumber;
//		}
		double getExp () const
		{
			return experience;
		}
		friend int operator >> (istream &, Employee &);
};

//static long int IDnumber = 1238560001;

int operator >> (istream &in, Employee &e1)
{
	//Person details
	string name, cnic, address, number, position;
	int age;
	char sex;
	
	cout<<"Name: ";
	in>>name;
	e1.setName(name);
	
	cout<<"Age: ";
	in>>age;
	e1.setAge(age);
	
	cout<<"Gender (M/F): ";
	in>>sex;
	e1.setSex(sex);
	
	cout<<"CNIC: ";
	in>>cnic;
	e1.setCNIC(cnic);
	fflush(stdin);
	cout<<"Address: ";
	getline(cin, address);
	fflush(stdin);
	e1.setAddress(address);
	
	cout<<"Number: ";
	in>>number;
	e1.setNumber(number);
	fflush(stdin);
//	Employee details
	string department, qualification;
	double work_Hours, salary, experience;
	
	cout<<"Qualification: ";
	getline(cin, qualification);
	fflush(stdin);
	e1.setQualification(qualification);
	
	cout<<"Experience: ";
	in>>experience;
	e1.setExp(experience);
	fflush(stdin);
	cout<<"Work-Hours: ";
	in>>work_Hours;
	e1.setWorkHrs(work_Hours);
	fflush(stdin);
	cout<<"Department: ";
	getline(cin, department);
	fflush(stdin);
	e1.setDepartment(department);
	fflush(stdin);
	cout<<"Salary: ";
	in>>salary;
	e1.setSal(salary);
	fflush(stdin);
	cout<<"Position: ";
	in>>position;
	e1.setPosition(position);
	
	int successful = 0;
	successful = e1.createAccount();
	return successful;
	
}

class Manager : public Employee
{
	public:
		void setPosition (string pPos)
		{
			if (pPos == "Finance Manager" || pPos == "finance manager" || pPos == "Branch Manager" || pPos == "branch manager")
				position = pPos;
			else
			{
				cout<<"Invalid input...Setting to default: Finance Manager\n";
				position = "Finance Manager";
			}
		}
		Employee addEmployee ()
		{
			Employee e1;
			cin>>e1;
			return e1;
		}
		
};


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
//		void login_Saving ()
//		{
//			Authentication::login();
//		}
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
		double deposit (double amount)
		{
			double file_balance = 0;
			if (amount >= 500 && amount < 50000)
			{
				cout<<"Requesting Trasaction. Please wait.\n";
				Sleep (2000);
				cout<<"Depositing Amount Rs."<<amount<<"/\n";
				Sleep (1500);
				file_balance = UpdateBalance (amount);
				cout<<"Amount successfully deposited...\n";
				//writing updated amount in file
			//	cout<<filename<<endl;
				
			}
			else if (amount >= 50000)
			{
				cout<<"Requesting Trasaction. Please wait.\n";
				Sleep (2000);
				cout<<"WithHolding Tax for amount Rs."<<amount<<"/ will be Rs."<<amount * 0.003<<"/\n";
				Sleep (1000);
				cout<<"Depositing Amount Rs."<<amount - (amount * 0.003)<<"/\n";
				Sleep (1500);
				file_balance = UpdateBalance ((amount - (amount * 0.003)));
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
			
			return file_balance;
		}
		double withdraw (double amount)
		{
			double file_balance = 0;
			double bal = getBalance ();
			cout<<"Requesting Trasaction. Please wait.\n";
			Sleep (2000);
			cout<<"Checking for current Account Balance...\n";
			Sleep (1000);
			if (bal >= amount)
			{
				cout<<"Balance confirmed...\nWithdrawing amount...\n";
				Sleep (1000);
				file_balance = UpdateBalance (-amount);
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
			return file_balance;
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
		double deposit (double amount)
		{
			double file_balance = 0;
			if (amount > 500 && amount < 50000)
			{
				cout<<"Requesting Trasaction. Please wait.\n";
				Sleep (2000);
				cout<<"Depositing Amount Rs."<<amount<<"/\n";
				Sleep (1500);
				file_balance = UpdateBalance (amount);
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
				file_balance = UpdateBalance ((amount - (amount * 0.003)));
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
			return file_balance;
		}
		double withdraw (double amount)
		{
			double file_balance=0;
			double bal = getBalance ();
			cout<<"Requesting Trasaction. Please wait.\n";
			Sleep (2000);
			cout<<"Checking for current Account Balance...\n";
			Sleep (1000);
			if (bal >= amount)
			{
				cout<<"Balance confirmed...\nWithdrawing amount...\n";
				Sleep (1000);
				file_balance = UpdateBalance (-amount);
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
			return file_balance;
		}
		friend int operator >> (istream &, Current_Acc &);
		friend void operator << (ostream &, Current_Acc &);
};


int operator >> (istream &in, Saving_Acc &e1)
{
	//Person details
	string name, cnic, address, number;
	int age;
	char sex;
	
	cout<<"Name: ";
	in>>name;
	e1.setName(name);
	fflush(stdin);
	cout<<"Age: ";
	in>>age;
	e1.setAge(age);
	fflush(stdin);
	cout<<"Gender (M/F): ";
	in>>sex;
	e1.setSex(sex);
	fflush(stdin);
	cout<<"CNIC: ";
	in>>cnic;
	e1.setCNIC(cnic);
	fflush(stdin);
	cout<<"Address: ";
	getline(cin, address);
	e1.setAddress(address);
	fflush(stdin);
	cout<<"Number: ";
	in>>number;
	e1.setNumber(number);
	fflush(stdin);
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

int operator >> (istream &in, Current_Acc &e1)
{
	//Person details
	string name, cnic, address, number;
	int age;
	char sex;
	
	cout<<"Name: ";
	in>>name;
	e1.setName(name);
	fflush(stdin);
	cout<<"Age: ";
	in>>age;
	e1.setAge(age);
	fflush(stdin);
	cout<<"Gender (M/F): ";
	in>>sex;
	e1.setSex(sex);
	fflush(stdin);
	cout<<"CNIC: ";
	in>>cnic;
	e1.setCNIC(cnic);
	fflush(stdin);
	cout<<"Address: ";
	getline(cin, address);
	e1.setAddress(address);
	fflush(stdin);
	cout<<"Number: ";
	in>>number;
	e1.setNumber(number);
	fflush(stdin);
	int successful = 0;
	successful = e1.createAccount();
	return successful;
}

void operator << (ostream &out, Current_Acc &s1)
{
	cout<<"Account Number: "<<s1.getAcc_Num()<<endl;
	cout<<"Name: "<<s1.getName()<<endl;
	cout<<"Age: "<<s1.getAge()<<endl;
	cout<<"Address: "<<s1.getAddress()<<endl;
	cout<<"Number: "<<s1.getNumber()<<endl;
	cout<<"CNIC Number: "<<s1.getCNIC()<<endl;
	cout<<"Account Type: Current Account\n";
	cout<<"Balance: "<<s1.getBalance()<<endl;
}

int main()
{
	welcome();
	system("color 09");
	Sleep(2000);
	system("cls");
	int interface_option = 0;
	cout<<"\t\t\t\t\tWelcome to HASH Bank\t\t\t\n";
	cout<<"Please select your interface.\n\t1. Customer Interface\n\t2. Employee Interface\n\t";
	cin>>interface_option;
	
	if (interface_option == 1)
	{
		
		int login_option = 0;
		do
		{
			cout<<"Please select from the following option: \n\t1. Login\n\t2. Create a new Account\n";
			cin>>login_option;
			
			if (login_option == 1)
			{
				int account_option = 0;
				do
				{
					cout<<"Please select your Account type: \n\t1. Current Account\n\t2. Saving Account\n";
					cin>>account_option;
					
					if (account_option == 1)
					{
						bool flag = false;
						Current_Acc temp;
						flag = temp.login();
						
						if (flag == true)
						{
							//reading data from file of username and saving it in object
							Current_Acc data;
							//declaring temporary variables
							string name, address, cnic, number, type;
							int age;
							char sex;
							long int accnum;
							double balance;
							ifstream read(temp.getFilename().c_str());
							//complete data set to variable
							read>>type;
							if (type == "Current_Account")
							{
								read>>accnum;
								data.setAcc_Num(accnum);
								read>>name;
								data.setName(name);
								read>>age;
								data.setAge(age);
								read>>sex;
								data.setSex(sex);
								read>>address;
								data.setAddress(address);
								read>>cnic;
								data.setCNIC(cnic);
								read>>number;
								data.setNumber(number);
								read>>balance;
								data.setBalance(balance);
								
								read.close();
								int service_option = 0;
								cout<<"\n\t\t\tCurrent Account Dashboard\n\n";
								cout<<"\n\t\t1. Deposit Amount\n\t\t2. Withdraw Amount\n\t\t3. Display all Information\nPlease enter your choice: ";
								cin>>service_option;
								
								if (service_option == 1)
								{
									double pAmount;
									cout<<"Enter amount to deposit (>500): ";
									cin>>pAmount;
									double file_balance = data.deposit(pAmount);
									//updating balance in file
									ofstream write2(temp.getFilename().c_str());
									write2<<"Current_Account"<<endl;
									write2<<data.getAcc_Num()<<endl; //check for suspended accounts
									write2<<data.getName()<<endl;
									write2<<data.getAge()<<endl;
									write2<<data.getSex()<<endl;
									write2<<data.getAddress()<<endl;
									write2<<data.getCNIC()<<endl;
									write2<<data.getNumber()<<endl;
									write2<<file_balance<<endl;
								}
								else if (service_option == 2)
								{
									double pAmount;
									cout<<"Enter amount to withdraw: ";
									cin>>pAmount;
									double file_balance = data.withdraw(pAmount);
									//updating balance in file
									ofstream write2(temp.getFilename().c_str());
									write2<<"Current_Account"<<endl;
									write2<<data.getAcc_Num()<<endl; //check for suspended accounts
									write2<<data.getName()<<endl;
									write2<<data.getAge()<<endl;
									write2<<data.getSex()<<endl;
									write2<<data.getAddress()<<endl;
									write2<<data.getCNIC()<<endl;
									write2<<data.getNumber()<<endl;
									write2<<file_balance<<endl;
								}
								else if (service_option == 3)
								{
									cout<<data;
								}
							}
							else
							{
								cout<<"Invalid Account type selected\nOperation failed\n\tPlease try again later\n";
								cout<<"Exiting...\n";
							}
							system("pause");
						}
						break;
					}
					else if (account_option == 2)
					{
						bool flag = false;
						Saving_Acc temp;
						flag = temp.login();
						
						if (flag == true)
						{
							//reading data from file of username and saving it in object
							Saving_Acc data;
							//declaring temporary variables
							string name, address, cnic, number, type;
							int age;
							char sex;
							long int accnum;
							double balance;
							ifstream read(temp.getFilename().c_str());
							//complete data set to variable
							read>>type;
							if (type == "Saving_Account")
							{
								read>>accnum;
								data.setAcc_Num(accnum);
								read>>name;
								data.setName(name);
								read>>age;
								data.setAge(age);
								read>>sex;
								data.setSex(sex);
								read>>address;
								data.setAddress(address);
								read>>cnic;
								data.setCNIC(cnic);
								read>>number;
								data.setNumber(number);
								read>>balance;
								data.setBalance(balance);
								
								read.close();
								int service_option = 0;
								cout<<"\n\t\t\tSaving Account Dashboard\n\n";
								cout<<"\n\t\t1. Deposit Amount\n\t\t2. Withdraw Amount\n\t\t3. Display all Information\n\t\t4. Simulate Months for adding interest.\nPlease enter your choice: ";
								cin>>service_option;
								
								if (service_option == 1)
								{
									double pAmount;
									cout<<"Enter amount to deposit (>500): ";
									cin>>pAmount;
									double file_balance = data.deposit(pAmount);
									//updating balance in file
									ofstream write2(temp.getFilename().c_str());
									write2<<"Saving_Account"<<endl;
									write2<<data.getAcc_Num()<<endl; //check for suspended accounts
									write2<<data.getName()<<endl;
									write2<<data.getAge()<<endl;
									write2<<data.getSex()<<endl;
									write2<<data.getAddress()<<endl;
									write2<<data.getCNIC()<<endl;
									write2<<data.getNumber()<<endl;
									write2<<file_balance<<endl;
									
									write2.close();
								}
								else if (service_option == 2)
								{
									double pAmount;
									cout<<"Enter amount to withdraw: ";
									cin>>pAmount;
									double file_balance = data.withdraw(pAmount);
									//updating balance in file
									ofstream write2(temp.getFilename().c_str());
									write2<<"Saving_Account"<<endl;
									write2<<data.getAcc_Num()<<endl; //check for suspended accounts
									write2<<data.getName()<<endl;
									write2<<data.getAge()<<endl;
									write2<<data.getSex()<<endl;
									write2<<data.getAddress()<<endl;
									write2<<data.getCNIC()<<endl;
									write2<<data.getNumber()<<endl;
									write2<<file_balance<<endl;
									
									write2.close();
								}
								else if (service_option == 3)
								{
									cout<<data;
								}
								else if (service_option == 4)
								{
									data.stimulateDays();
									
									//re-saving data in file
									ofstream write2(temp.getFilename().c_str());
									write2<<"Saving_Account"<<endl;
									write2<<data.getAcc_Num()<<endl; //check for suspended accounts
									write2<<data.getName()<<endl;
									write2<<data.getAge()<<endl;
									write2<<data.getSex()<<endl;
									write2<<data.getAddress()<<endl;
									write2<<data.getCNIC()<<endl;
									write2<<data.getNumber()<<endl;
									write2<<data.getBalance()<<endl;
									
									cout<<"Updating Balance...\n";
									Sleep(800);
									cout<<"Updated Balance is Rs. "<<data.getBalance()<<endl;
								}
							}
							else
							{
								cout<<"Invalid Account type selected\nOperation failed\n\tPlease try again later\n";
								cout<<"Exiting...\n";
							}
								
						}
						system("pause");
						break;
					}
					else
					{
						cout<<"Please select a valid option...\n";
						Sleep(1500);
						system("cls");
					}
				}
				while (true);
			}
			else if (login_option == 2)
			{
				int account_option = 0;
				cout<<"Please select the desired Account type to create: \n\t1. Current Account\n\t2. Saving Account\n";
				cin>>account_option;
				
				if (account_option == 1)
				{
					int retry = 0;
					Current_Acc temp;
					retry = cin>>temp;
					if (retry == 0)
						cout<<"Account not created. Please try again later...\n";
					
					//saving into unique file	
					if (retry == 1)
					{
					//	char *filename = generate_filename (temp);
						double bal;
						cout<<"\n\t\t\tThank You for choosing Hash Bank.\nPlease enter amount >= 500 to activate your Account: ";
						cin>>bal;
						cout<<"Please Wait...\n";
						Sleep (1500);
						if (bal >= 500)
						{
							cout<<"Amount successfully deposited.\nAccount Activated\n";
							temp.setBalance(bal);
							ofstream write2(temp.getFilename().c_str(), ios::app);
							write2<<"Current_Account"<<endl;
							write2<<temp.getAcc_Num()<<endl; //check for suspended accounts left
							write2<<temp.getName()<<endl;
							write2<<temp.getAge()<<endl;
							write2<<temp.getSex()<<endl;
							write2<<temp.getAddress()<<endl;
							write2<<temp.getCNIC()<<endl;
							write2<<temp.getNumber()<<endl;
							write2<<temp.getBalance()<<endl;
							
						}
						else
							cout<<"Account suspended for current time\n";
						
					}
					break;
				}
				else if (account_option == 2)
				{
					int retry = 0;
					Saving_Acc temp;
					retry = cin>>temp;
					if (retry == 0)
						cout<<"Account not created. Please try again later...\n";
					
					//saving into unique file	
					if (retry == 1)
					{
					//	char *filename = generate_filename (temp);
						double bal;
						cout<<"\n\t\t\tThank You for choosing Hash Bank.\nPlease enter amount >= 500 to activate your Account: ";
						cin>>bal;
						cout<<"Please Wait...\n";
						Sleep (1500);
						if (bal >= 500)
						{
							cout<<"Amount successfully deposited.\nAccount Activated\n";
							temp.setBalance(bal);
							ofstream write2(temp.getFilename().c_str(), ios::app);
							write2<<"Saving_Account"<<endl;
							write2<<temp.getAcc_Num()<<endl; //check for suspended accounts left
							write2<<temp.getName()<<endl;
							write2<<temp.getAge()<<endl;
							write2<<temp.getSex()<<endl;
							write2<<temp.getAddress()<<endl;
							write2<<temp.getCNIC()<<endl;
							write2<<temp.getNumber()<<endl;
							write2<<temp.getBalance()<<endl;
							
						}
						else
							cout<<"Account suspended for current time\n";
						
					}
					break;
				}
				else
				{
					cout<<"Please select a valid option...\n";
					Sleep(1500);
					system("cls");
				}
				while (true);
			}
			else
			{
				cout<<"Please select a valid option...\n";
				Sleep(1500);
				
			}
			system ("cls");
		}
		while (login_option != 1 && login_option != 2);
	}
	else if (interface_option == 2)
	{
		do
		{
			int login_option = 0;
			cout<<"\n\t1. Manager Login\n\t2. Employee Login\n\t";
			cin>>login_option;
			
			int successful = 0;
			if (login_option == 1)
			{
				Manager temp;
				successful = temp.login();
				
				if (successful == 1)
				{
					string type;
					ifstream read("manager.txt");
					read>>type;
					
					if (type == "Manager")
					{
						int manager_option = 0;
						cout<<"\n\n\t\t\tManager Dashboard\n";
						cout<<"\n\t1. Add employee\n\t2. Fire Employee\n\tPlease select your option: ";
						cin>>manager_option;
						
						if (manager_option == 1)
						{
							cout<<"\n\tEnter employee Details: ";
							Employee e1;
						//	Employee e1;
							int success = cin>>e1;
						//	e1 = temp.addEmployee();
							
						//	cout<<success<<endl;
							
							if (success == 1)
							{
							ofstream write(e1.getFilename().c_str());
							write<<"Employee"<<endl;
							write<<e1.getName()<<endl;
							write<<e1.getAge()<<endl;
							write<<e1.getAddress()<<endl;
							write<<e1.getCNIC()<<endl;
							write<<e1.getDepart()<<endl;
							write<<e1.getExp()<<endl;
							write<<e1.getDays()<<endl;
							write<<e1.getQual()<<endl;
							write<<e1.getPos()<<endl;
							write<<e1.getNumber()<<endl;
							write<<e1.getSal()<<endl;
							
							write.close();
							cout<<"Employee Details successfully added.\n";
								
							}
							else if (success != 1)
								cout<<"Account not created...\n";
						}
						else if (manager_option == 2)
						{
							string username;
							cout<<"Enter username of the employee to remove: ";
							cin>>username;
							
							Sleep(1500);
							ifstream read(username.c_str());
							if (read)
							{
								string type;
								read>>type;
								cout<<type;
								if (type == "Employee")
								{
									ofstream write(username.c_str());
									write<<"Removed"<<endl;
									cout<<"Employee Successfully removed\n";
								}
								else
									cout<<"The entered username is not employee\n";
							}
							else
								cout<<"No employee of entered username exists.\n";
						}
						
					}
				}
				break;
			}
			else if (login_option == 2)
			{
				Employee temp;
				successful = temp.login();
				
				if (successful == 1)
				{
					string type;
					ifstream read(temp.getFilename().c_str());
					read>>type;
					read.close();
					if (type == "Employee")
					{
						int employee_option = 0;
						cout<<"\n\n\t\tEmployee Dashboard\n\n\t1. View Details of user\n\t2. Edit Details of user\nPlease enter your choice: ";
						cin>>employee_option;
						if (employee_option == 1)
						{
							string username;
							cout<<"Enter username of the User to view Details: ";
							cin>>username;
							
							ifstream read(username.c_str());
							if (read)
							{
								string acc_type;
								read>>acc_type;
								if (acc_type == "Saving_Account")
								{
									string name, address, number, cnic;
									long int acc_num;
									char sex;
									int age;
									double balance;
									
									Saving_Acc data;
									read>>acc_num;
									data.setAcc_Num(acc_num);
									read>>name;
									data.setName(name);
									read>>age;
									data.setAge(age);
									read>>sex;
									data.setSex(sex);
									read>>address;
									data.setAddress(address);
									read>>cnic;
									data.setCNIC(cnic);
									read>>number;
									data.setNumber(number);
									read>>balance;
									data.setBalance(balance);
									
									cout<<data;
								}
								else if (acc_type == "Current_Account")
								{
									string name, address, number, cnic;
									char sex;
									long int acc_num;
									int age;
									double balance;
									
									Current_Acc data;
									read>>acc_num;
									data.setAcc_Num(acc_num);
									read>>name;
									data.setName(name);
									read>>age;
									data.setAge(age);
									read>>sex;
									data.setSex(sex);
									read>>address;
									data.setAddress(address);
									read>>cnic;
									data.setCNIC(cnic);
									read>>number;
									data.setNumber(number);
									read>>balance;
									data.setBalance(balance);
									
									read.close();
									cout<<data;
								}
								else
									cout<<"Username is not a customer type.\n";
							}
							else
								cout<<"No account of current username exists.\n";
						}
						else if (employee_option == 2)
						{
							string username;
							cout<<"Enter username of the customer to edit details: ";
							cin>>username;
							
							ifstream read(username.c_str());
							if (read)
							{
								string acc_type;
								read>>acc_type;
								if (acc_type == "Saving_Account")
								{
									string name, address, number, cnic;
									long int acc_num;
									char sex;
									int age;
									double balance;
									Saving_Acc data;
									read>>acc_num;
									data.setAcc_Num(acc_num);
									read>>name;
									data.setName(name);
									read>>age;
									data.setAge(age);
									read>>sex;
									data.setSex(sex);
									read>>address;
									data.setAddress(address);
									read>>cnic;
									data.setCNIC(cnic);
									read>>number;
									data.setNumber(number);
									read>>balance;
									data.setBalance(balance);
									
									read.close();
									ofstream write(username.c_str());
									int edit_option = 0;
									cout<<"Please select the data you want to edit: \n\t1. Name\n\t2. Address\n\t3. Number\n\t4. Age\n\t5. CNIC number\nEnter your option: ";
									cin>>edit_option;
									if (edit_option == 1)
									{
										string name_c;
										cout<<"Enter name: ";
										cin>>name_c;
										
										write<<"Saving_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<name_c<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<data.getCNIC()<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 2)
									{
										
										string address_c;
										cout<<"Enter changed address: ";
										cin>>address_c;
										
										write<<"Saving_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<address_c<<endl;
										write<<data.getCNIC()<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 3)
									{
										string number_c;
										cout<<"Enter changed number: ";
										cin>>number_c;
										
										write<<"Saving_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<data.getCNIC()<<endl;
										write<<number_c<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 4)
									{
										int number_c;
										cout<<"Enter Age: ";
										cin>>number_c;
										
										write<<"Saving_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<number_c<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<data.getCNIC()<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 5)
									{
										string number_c;
										cout<<"Enter changed CNIC: ";
										cin>>number_c;
										
										write<<"Saving_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<number_c<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else
										cout<<"Not a valid option.\nPlease try Again.\n";
								}
								else if (acc_type == "Current_Account")
								{
									string name, address, number, cnic;
									char sex;
									long int acc_num;
									int age;
									double balance;
									
									Current_Acc data;
									read>>acc_num;
									data.setAcc_Num(acc_num);
									read>>name;
									data.setName(name);
									read>>age;
									data.setAge(age);
									read>>sex;
									data.setSex(sex);
									read>>address;
									data.setAddress(address);
									read>>cnic;
									data.setCNIC(cnic);
									read>>number;
									data.setNumber(number);
									read>>balance;
									data.setBalance(balance);
									
									read.close();
									ofstream write(username.c_str());
									cout<<data;
									
									int edit_option = 0;
									cout<<"Please select the data you want to edit: \n\t1. Name\n\t2. Address\n\t3. Number\n\t4. Age\n\t5. CNIC number\nEnter your option: ";
									cin>>edit_option;
									if (edit_option == 1)
									{
										string name_c;
										cout<<"Enter name: ";
										cin>>name_c;
										
										write<<"Current_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<name_c<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<data.getCNIC()<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 2)
									{
										
										string address_c;
										cout<<"Enter changed address: ";
										cin>>address_c;
										
										write<<"Current_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<address_c<<endl;
										write<<data.getCNIC()<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 3)
									{
										string number_c;
										cout<<"Enter changed number: ";
										cin>>number_c;
										
										write<<"Current_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<data.getCNIC()<<endl;
										write<<number_c<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 4)
									{
										int number_c;
										cout<<"Enter Age: ";
										cin>>number_c;
										
										write<<"Current_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<number_c<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<data.getCNIC()<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else if (edit_option == 5)
									{
										string number_c;
										cout<<"Enter changed CNIC: ";
										cin>>number_c;
										
										write<<"Current_Account"<<endl;
										write<<data.getAcc_Num()<<endl;
										write<<data.getName()<<endl;
										write<<data.getAge()<<endl;
										write<<data.getSex()<<endl;
										write<<data.getAddress()<<endl;
										write<<number_c<<endl;
										write<<data.getNumber()<<endl;
										write<<data.getBalance()<<endl;
											
										cout<<"Showing details after edit:\n\n";
										cout<<data;
										write.close();
									}
									else
										cout<<"Not a valid option.\nPlease try again.\n";
								}
								else
									cout<<"Username is not a customer type.\n";
							}
							else
								cout<<"No account of current username exists.\n";
							}
						}
					}
					else
						cout<<"The current username is of not Employee type.\n";
				break;
				}
			else
				cout<<"\nNot a valid option...\nPlease try Again\n\n";
	
		}
		while (true);
	
	}
	else
		cout<<"Not a valid option...Please try again later\n\n";
	
}



