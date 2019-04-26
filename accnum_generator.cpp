#include<iostream>
#include<fstream>

using namespace std;

long long int generate_accnum ();

int main()
{
	cout<<generate_accnum();
}

long long int generate_accnum ()
{
	long long int acc_num;
	ifstream read("customer_acc.txt");
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
