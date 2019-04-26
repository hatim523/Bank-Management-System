#include<iostream>
#include "Person.h"

using namespace std;

class Employee : public Person
{
	private:
		string department, position, qualification;
		double work_Hours, days, salary, experience;
		long int IDnumber;
	public:
		Employee ()
		{
			
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
		void setID (long int pID)
		{
			//8-digit id
			if (pID <= 99999999)
				IDnumber = pID;
			else
			{
				cout<<"Invalid ID-Number...\nID set to: 11111111\n";
				IDnumber = 11111111;
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
		long int getID () const
		{
			return IDnumber;
		}
		double getExp () const
		{
			return experience;
		}
};

int main()
{
	
}
