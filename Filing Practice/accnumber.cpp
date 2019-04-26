#include<iostream>
#include<fstream>

using namespace std;

static int times=0;
void accnumbr(long int acc_num)
{
	ifstream infile;
	ofstream outfile("Accholder.txt",ios::app);
	if(times==0)    // one time entry of acc number next time it would read previous and add it
	{
		outfile<<acc_num<<endl;
		times++;
	}
	infile.open("Accholder.txt",ios::app);
	long int getter=0;
	infile>>getter;
	
	
	int saver=0;
	if(getter!=0)
	saver=getter;  
	if(getter!=0)
		getter++;
	

	if(getter!=0&&getter!=saver) 
		outfile<<"\n"<<getter;
	
		
	
	infile.close();
	outfile.close();
}

int main()
{
	accnumbr (42000);
}
