#include<iostream>
#include "Employee class.h"

using namespace std;

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


