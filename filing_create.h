#include<iostream>
#include<fstream>
#include "main.cpp"
using namespace std;


void filing_create (const Saving_Acc &s1, char *filename)
{
	ofstream write2(filename, ios::app);
	
	write2<<s1.getAcc_Num()<<endl;
	write2<<s1.getName()<<endl;
	write2<<s1.getAge()<<endl;
	write2<<s1.getSex()<<endl;
	write2<<s1.getAddress()<<endl;
	write2<<s1.getCNIC()<<endl;
	write2<<s1.getNumber()<<endl;
	write2<<s1.getBalance()<<endl;
	
	write2.close();
}
//int operator >> (istream &in, Saving_Acc &e1)
//{
//	//Person details
//	string name, cnic, address, number;
//	int age;
//	char sex;
//	
//	cout<<"Name: ";
//	in>>name;
//	e1.setName(name);
//	
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
//	
//	//filing variable by variable
//	
//	int successful = 0;
//	successful = e1.createAccount();
//	return successful;
//}
