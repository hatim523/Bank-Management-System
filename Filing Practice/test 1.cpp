#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream out;
	out.open("passwords.txt", ios::app);
	
	while (out.eof() != 0)
	{
		out<<endl;
	}
	out<<endl;
	string s;
	cin>>s;
	out<<s;
}
