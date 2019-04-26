#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;

int stringlen (string);
string app_string (string, char);

class Authentication
{
	private:
		string username, password, forfile;
		unsigned int data_line;
	public:
		void setUserName (string pUser)
		{
			if (stringlen(pUser) >= 5)
			{
				username = app_string(pUser, '$');
				forfile = pUser;
			}
			else
				username = "NULL";
		}
		string getFilename () const
		{
			return forfile;
		}
		void setPassword (string pPass)
		{
			if (stringlen(pPass) >= 8)
				password = app_string(pPass, '*');
			else
				password = "NULL";
		}
		int createAccount ()
		{
			int successful_creation = 1;
			fflush(stdin);
			string name, pass;
			cout<<"Please enter username: ";
			cin>>name;
			cout<<"Please enter password: ";
			cin>>pass;
			
			setUserName(name);
			setPassword(pass);
			
			int length_check = 1;
			//checking for length of username or password
			if (getUserName() == "NULL" || getPassword() == "NULL")
				length_check = 0;
			//checking for duplicate username or password
			bool duplicate = false;
			fstream read;
			read.open("data.txt", ios::in | ios::app);
			string line;
			int Line = 0;
			while(getline(read, line)) 
			{
    			Line++;
    			if (line.find(getUserName(), 0) != string::npos) 
				{
        			duplicate = true;
        			break;
    			}
			}
			read.close();
			cout<<"Creating Account...\n";
			Sleep(1500);
			if (duplicate == true)
			{
				cout<<"Username taken\nPlease try again...\n";
				successful_creation = 0;
			}
			if (length_check == 0)
			{
				cout<<"Invalid username or Password\nPlease try again...\n";
				successful_creation = 0;
			}
			//writing data in file
			if (duplicate == false && length_check == 1)
			{
				ofstream out;
				out.open("data.txt", ios::app);
				
				while (out.eof() != 0)
					out<<endl;
				out<<endl;
				
				
				
				out<<getUserName()<<"\t"<<out<<getPassword();
				cout<<"Account successfully created\n";
				system ("color 9f");
			}
			
			return successful_creation;
		}
		int login ()
		{
			static int flag = false;
			
			fstream read;
			read.open("data.txt", ios::in);
			//reading username and password from user
			string pUser, pPass, new_user, new_pass;
			cout<<"\tUsername: ";
			cin>>pUser;
			new_user = app_string(pUser, '$');
			
			cout<<"\tPassword: ";
			cin>>pPass;
			new_pass = app_string(pPass, '*');
			
			
			cout<<"\tPlease Wait...\n";
			Sleep(1500);
			
			//searching mechanism
			static int attempt = 0;
			string line;
			int Line = 0;
			while(getline(read, line)) 
			{
    			Line++;
    			if (line.find(new_user, 0) != string::npos && line.find(new_pass, 0) != string::npos) 
				{
					data_line = Line;  //check statement for issues (currently not checked)
        			flag = true;
        			break;
    			}
			}
			
			if (flag == true)
			{
				username = pUser;
				password = pPass;
				cout<<"\t\tLogin Successful!\n";
				flag = 1;
				setUserName (username);
				setPassword (password);
				system("color 9f");
			}
			else
				cout<<"\t\tIncorrect Username or Password!\n";
				
			int option = 0;	
			if (flag == 0 && attempt < 2)
			{
				cout<<"Press 1 to try again: ";
				cin>>option;
			}
			else
			{
				if (flag == 0 && attempt >= 2)
				{
					system("color 4f");
					cout<<"Too many failed attempts...\nAccess Denied\n";
					cout<<"Exiting...";
					Sleep(2500);
				}
			}
				
			if (option == 1 && attempt < 2 && flag == 0)
			{
				attempt++;
				login();
			}
			return flag;
		}
		string getUserName () const
		{
			return username;
		}
		string getPassword () const
		{
			return password;
		}
		int getLine () const
		{
			return data_line;
		}
};


int stringlen (string s)
{
	int i=0;
	while (s[i] != '\0')
		i++;
	return i;
}

string app_string (string s, char special)
{
	int i, j=0, len = stringlen(s);
	char c[len + 2];
	
	for (i=0; i<len+2; i++)
	{
		if (i == 0 || i == len+1)
		{
			c[i] = special;
		}
		else
		{
			c[i] = s[j];
			j++;
		}
	}
	c[i] = '\0';
	string new_string = c;
	return new_string;
}
