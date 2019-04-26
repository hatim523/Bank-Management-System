#include<iostream>

using namespace std;

class Person
{
	private:
		string name;
		int age;
		string CNIC;
		char sex;
		string address;
		string number;
	public:
		void setName (string);
		void setAge (int);
		void setCNIC (string);
		void setSex (char);
		void setAddress (string);
		void setNumber (string n);
		
};

void Person::setName (string n)
{
	name = n;
}
void Person::setAge (int a)
{
	if (age >= 18)
		age = a;
	else
		cout<<"Not old enough"<<endl;
}
void Person::setCNIC (string c)
{
	CNIC = c;
}
void Person::setSex (char a)
{
	if (a == 'M' || a == 'F' || a == 'O')
		sex = a;
	else
		cout<<"Invalid Input"<<endl;
}
void Person::setAddress (string a)
{
	address = a;
}
void Person::setNumber (string n)
{
	//check for any input other than digits
	int i=0, flag = 0;
	while (n[i] != '\0')
	{
		if (n[i] != '1' && n[i] != '2' && n[i] != '3' && n[i] != '4' && n[i] != '5' && n[i] != '6' && n[i] != '7' && n[i] != '8' && n[i] != '9' && n[i] != '0')
		{
			flag = 1;
		}
		i++;
	}
	
	if (flag == 0)
	{
		number = n;
	}
	else
		cout<<"Invalid number"<<endl;
}


