#include<iostream>
#ifndef Person_H
#define Person_H

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
		string getName () const;
		string getCNIC () const;
		int getAge () const;
		string getAddress () const;
		string getNumber () const;
		char getSex () const;
		
};

void Person::setName (string n)
{
	name = n;
}
void Person::setAge (int a)
{
	if (a >= 18)
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
	if (a == 'M' || a == 'F' || a == 'O' || a == 'm' || a == 'f' || a == 'o')
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
string Person::getName(void) const
{
	return name;
}
int Person::getAge (void) const
{
	return age;
}
string Person:: getCNIC (void) const
{
	return CNIC;
}
char Person:: getSex (void) const
{
	return sex;
}
string Person::getAddress (void) const
{
	return address;
}
string Person::getNumber (void) const
{
	return number;
}

#endif

