#include<iostream>
using namespace std;
class Person
{
	public:
		void sort(int dob[],int mob[],int yob[],string fname[],string lname[])
		{
			for(int i=1;i<5;i++)
			{
				for(int j=0;j<4;j++)
				{
					if(yob[j]>=yob[i])
					{
						int temp=yob[j];
						yob[j]=yob[i];
						yob[i]=temp;
						
						int temp2=mob[j];
						mob[j]=mob[i];
						mob[i]=temp2;
						
						int temp3=dob[j];
						dob[j]=dob[i];
						dob[i]=temp3;
						
						string temp4=fname[j];
						fname[j]=fname[i];
						fname[i]=temp4;
						
						string temp5=lname[j];
						lname[j]=lname[i];
						lname[i]=temp5;
					}
					if(yob[j]==yob[i])
					{
						int temp2=mob[j];
						mob[j]=mob[i];
						mob[i]=temp2;
						
						int temp3=dob[j];
						dob[j]=dob[i];
						dob[i]=temp3;
						
						string temp4=fname[j];
						fname[j]=fname[i];
						fname[i]=temp4;
						
						string temp5=lname[j];
						lname[j]=lname[i];
						lname[i]=temp5;
					}
					if(mob[j]==mob[i] && yob[j]==yob[i])
					{
						if(dob[j]>=dob[i])
						{
							int temp3=dob[j];
							dob[j]=dob[i];
							dob[i]=temp3;
							
							string temp4=fname[j];
							fname[j]=fname[i];
							fname[i]=temp4;
							
							string temp5=lname[j];
							lname[j]=lname[i];
							lname[i]=temp5;
						}
					}
				}
			}
		}
		void display(int dob[],int mob[],int yob[],string fname[],string lname[])
		{
			for(int i=0;i<5;i++)
			{
				cout<<endl<<"FirstName: "<<fname[i]<<endl<<"LastName: "<<lname[i];
				cout<<endl<<"Date of Birth: "<<" "<<dob[i]<<"-"<<mob[i]<<"-"<<yob[i];
			}
			
		}
};
int main()
{
	system("color 70");
	Person p1;
	int dob[5];
	int mob[5];
	int yob[5];
	string fname[5];
	string lname[5];
	cout<<"Enter First name of 5 Peoples: ";
	for(int i=0;i<5;i++)
	{
		cin>>fname[i];
	}
	cout<<endl<<"Enter Last Name of 5 Peoples: ";
	for(int i=0;i<5;i++)
	{
		cin>>lname[i];
	}
	cout<<endl<<"Enter Date in the Format dd/mm/yy: ";cout<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>dob[i];
		cin>>mob[i];
		cin>>yob[i];
		
	}
	p1.sort(dob,mob,yob,fname,lname);
	p1.display(dob,mob,yob,fname,lname);
}

