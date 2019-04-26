#include<iostream>
#include "Person.h"
#include "Authentication.h"
#ifndef Employee_H
#define Employee_H
using namespace std;


class Employee : public Person, public Authentication
{
	private:
		string department, qualification;
		double work_Hours, days, salary, experience;
	//	static long int IDnumber;
	protected:
		string position;
	public:
		int success; 
		Employee ()
		{
			success = 0;
		//	IDnumber++;
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
		friend void operator >> (istream &, Employee &);
};

//static long int IDnumber = 1238560001;

void operator >> (istream &in, Employee &e1)
{
	//Person details
	string name, cnic, address, number;
	int age;
	char sex;
	
	cout<<"Name: ";
	in>>name;
	e1.setName(name);
	
	cout<<"Age: ";
	in>>age;
	fflush(stdin);
	e1.setAge(age);
	
	cout<<"Gender (M/F): ";
	in>>sex;
	e1.setSex(sex);
	
	cout<<"CNIC: ";
	in>>cnic;
	fflush(stdin);
	e1.setCNIC(cnic);
	
	cout<<"Address: ";
	getline(in, address);
	e1.setAddress(address);
	fflush(stdin);
	cout<<"Number: ";
	in>>number;
	e1.setNumber(number);
	
	//Employee details
	string department, qualification, position;
	double work_Hours, salary, experience;
	
	cout<<"Qualification: ";
	getline(in, qualification);
	e1.setQualification(qualification);
	fflush(stdin);
	cout<<"Experience: ";
	in>>experience;
	e1.setExp(experience);
	fflush(stdin);
	cout<<"Work-Hours: ";
	in>>work_Hours;
	e1.setWorkHrs(work_Hours);
	
	cout<<"Department: ";
	getline(in, department);
	e1.setDepartment(department);
	fflush(stdin);
	cout<<"Salary: ";
	in>>salary;
	e1.setSal(salary);
	fflush(stdin);
	cout<<"Position: ";
	getline(in, position);
	fflush(stdin);
	e1.setPosition(position);
	fflush(stdin);
	
//	int successful = 0;
	e1.success = e1.createAccount();
	//return successful;
}
#endif
