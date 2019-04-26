#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream in;
	in.open("passwords.txt", ios::app);
	
	string s;
	in>>s;
	
	cout<<s;
	
	in.close();
}
