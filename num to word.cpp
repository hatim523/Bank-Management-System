#include<iostream>
using namespace std;
int main()
{
	

    int money,i=0,j=0,temp;
    cout<<"Enter money upto 10 lac :";
    cin>>money;
    temp=money;
    while(temp!=0)
    {
    	i++;
    	temp=temp/10;
	}
	
	int array[i];
	
	while(money!=0)
    {
    	array[j]=money%10;
    	money=money/10;
    	j++;
	}
	
	if(i==7)
	{
		if(array[j-1]==1)
		{
			cout<<" Ten lakh ,";
			i--;
			i--;
			j--;
			j--;
		}
	}
	if(i==6)
	{
	if(array[j-1]==1)
		{
			cout<<" one lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==2)
		{
			cout<<" two lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==3)
		{
			cout<<" three lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==4)
		{
			cout<<" four lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==5)
		{
			cout<<" five lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==6)
		{
			cout<<" six lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==7)
		{
			cout<<" seven lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==8)
		{
			cout<<" eight lakh ";
			i--;
			j--;
		}
	else if(array[j-1]==9)
		{
			cout<<" nine lakh ";
			i--;
			j--;
		}
		
	}
if(i==5)
	{
	   if(array[j-1]==1 && array[j-2]==1)
	   {
	   	cout<<" eleven thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	else if(array[j-1]==1 && array[j-2]==2)
	   {
	   	cout<<" twelve thosand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==3)
	   {
	   	cout<<" thirteen thosusand";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==4)
	   {
	   	cout<<" fourteen thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==5)
	   {
	   	cout<<" fifteen thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==6)
	   {
	   	cout<<" sixteen thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==7)
	   {
	   	cout<<" seventeen thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==8)
	   {
	   	cout<<" eighteen thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   	
	   }
	   else if(array[j-1]==1 && array[j-2]==9)
	   {
	   	cout<<" nineteen thosand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==1 && array[j-2]==0)
	   {
	   	cout<<" ten thousand ";
	   	i--;
	   	i--;
	   	j--;
	   	j--;
	   }
	   else if(array[j-1]==2)
	   {
	   	cout<<" twenty ";
	   	i--;
	   	j--;
	   	
	   }
	   else if(array[j-1]==3)
	   {
	   	cout<<" thirty ";
	   	i--;
	   	j--;
	   }
	    else if(array[j-1]==4)
	   {
	   	cout<<" fourty ";
	   	i--;
	   	j--;
	   }
	    else if(array[j-1]==5)
	   {
	   	cout<<" fifty ";
	   	i--;
	   	j--;
	   }
	    else if(array[j-1]==6)
	   {
	   	cout<<" sixty ";
	   	i--;
	   	j--;
	   }
	    else if(array[j-1]==7)
	   {
	   	cout<<" seventy ";
	   	i--;
	   	j--;
	   }
	    else if(array[j-1]==8)
	   {
	   	cout<<" eighty ";
	   	i--;
	   	j--;
	   }
	    else if(array[j-1]==9)
	   {
	   	cout<<" ninety ";
	   	i--;
	   	j--;
	   }
		
	}
if(i==4)
	{
	if(array[j-1]==1)
		{
			cout<<" one thousand,";
			i--;
			j--;
		}
	else if(array[j-1]==2)
		{
			cout<<" two thousand, ";
			i--;
			j--;
		}
		else if(array[j-1]==3)
		{
			cout<<" three thousand,";
			i--;
			j--;
		}
		else if(array[j-1]==4)
		{
			cout<<" four thousand ,";
			i--;
			j--;
		}
		else if(array[j-1]==5)
		{
			cout<<" five thousand,";
			i--;
			j--;
		}
		else if(array[j-1]==6)
		{
			cout<<" six thousand,";
			i--;
			j--;
		}
		else if(array[j-1]==7)
		{
			cout<<" seven thousand ,";
			i--;
			j--;
		}
		else if(array[j-1]==8)
		{
			cout<<" eight thousand,";
			i--;
			j--;
		}
		else if(array[j-1]==9)
		{
			cout<<" nine thousand ,";
			i--;
			j--;
		}
		else if(array[j-1]==0)
		{
			cout<<" thousand ,";
			i--;
			j--;
		}
	}
if(i==3)
   {
	 if(array[j-1]==1)
	 {
	 	cout<<" one hundred and";
	 	i--;
	 	j--;
	 }
	else if(array[j-1]==2)
	 {
	 	cout<<" two hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==3)
	 {
	 	cout<<" three hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==4)
	 {
	 	cout<<" four hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==5)
	 {
	 	cout<<" five hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==6)
	 {
	 	cout<<" six hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==7)
	 {
	 	cout<<" seven hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==8)
	 {
	 	cout<<" eight hundred and";
	 	i--;
	 	j--;
	 }
	 	else if(array[j-1]==9)
	 {
	 	cout<<" nine hundred and";
	 	i--;
	 	j--;
	 }
   }
   
if(i==2)
   {
   	if(array[j-1]==1 && array[j-2]==1)
   	{
   		cout<<" eleven rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	else if(array[j-1]==1 && array[j-2]==2)
   	{
   		cout<<" twelve rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==3)
   	{
   		cout<<" thirteen rs ";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==4)
   	{
   		cout<<" fourteen rs ";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==5)
   	{
   		cout<<" fifteen rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==6)
   	{
   		cout<<" sixteen rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==7)
   	{
   		cout<<" seventeen rs ";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==8)
   	{
   		cout<<" eighteen rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==9)
   	{
   		cout<<" nineteen rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==1 && array[j-2]==0)
   	{
   		cout<<" ten rs";
   		i--;
   		i--;
   		j--;
   		j--;
   		
	   }
	   else if(array[j-1]==2)
   	{
   		cout<<" twenty ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==3)
   	{
   		cout<<" thirty ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==4)
   	{
   		cout<<" forty ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==5)
   	{
   		cout<<" fifty ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==6)
   	{
   		cout<<" sixty ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==7)
   	{
   		cout<<" seventy ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==8)
   	{
   		cout<<" eighty ";
   		i--;
   		j--;
	   }
	   else if(array[j-1]==9)
   	{
   		cout<<" ninety ";
   		i--;
   		j--;
	   }
   }
   if(i==1)
   {
   	  if(array[j-i]==1)
   	  {
   	  	cout<<" one rs";
		 }
else  if(array[j-i]==2)
   	  {
   	  	cout<<" two rs ";
		 }
		else if(array[j-i]==3)
   	  {
   	  	cout<<" three rs";
		 }
		else if(array[j-i]==4)
   	  {
   	  	cout<<" four rs ";
		 }
	else	 if(array[j-i]==5)
   	  {
   	  	cout<<" five rs";
		 }
	else	 if(array[j-i]==6)
   	  {
   	  	cout<<" six rs ";
		 }
		else if(array[j-i]==7)
   	  {
   	  	cout<<" seven rs";
		 }
		else if(array[j-i]==8)
   	  {
   	  	cout<<" eight rs ";
		 }
		else if(array[j-i]==9)
   	  {
   	  	cout<<" nine rs ";
		 }
	else  if(array[j-i]==0)
   	  {
   	  	cout<<" rs";
		 }
   }
   	


}

