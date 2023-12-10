#include<iostream>
using namespace std;
class DSA
{ 
   public:
   	    bool checksort(int arr[],int size)
   	    {
   	    	for(int i=0;i<size;i++)
   	    	{
   	    		for(int j=0;j<size;j++)
   	    		{
   	    			if(arr[i]>arr[j])
	   	    		{
	   	    			return true;
					}
				}
			}
			cout<<endl<<"SORTED";
			return false;
		}
		void bubblesort(int arr[],int size)
		{
			for(int i=0;i<size;i++)
			{
				for(int j=0;j<size;j++)
				{
					if(arr[i]<arr[j])
					{
						int temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					}
				}
			}
		}
		void print(int arr[],int size)
		{
			for(int i=0;i<size;i++)
			{
				cout<<"|--<"<<arr[i]<<">--|";
			}
		}
		bool safearray(int *arr[],int pos,int size)
		{
			if(pos<0 || pos>=size)
			{
			   cout<<"Array out of Bound!";
			   return false;
			}
			else 
			{
				return true;
			}
			
		}
};
int main()
{
	system("color 70");
	int size,pos,val,choice;
	DSA obj1;
	cout<<"21K-3323 LAB TASK-01"<<endl;
	cout<<endl<<"Enter Credentials on an Array First!";
	cout<<endl<<"Enter Size of array: ";
	cin>>size;
	int *arr=new int[size];
	cout<<endl<<"Enter Elements of array: ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	block:
	system("pause");
	system("cls");
	cout<<endl<<"Menu"<<endl<<"1. Alter Value"<<endl<<"2. Bubble Sort"<<endl<<"3. Print array"<<endl<<"4. Exit";
	cin>>choice;
	if(choice==1)
	{
		system("cls");
		system("pause");
			cout<<endl<<"Enter Position: ";
			cin>>pos;
			cout<<endl<<"Enter New Value: ";
			cin>>val;
				if(obj1.safearray(&arr,pos,size))
				{
					arr[pos]=val;
					cout<<endl<<"Operation Success!";
				}
			cout<<endl;	
			obj1.print(arr,size);
		goto block;
	}
	if(choice==2)
	{
		system("cls");
		system("pause");
		if(obj1.checksort(arr,size)==true)
		{
			obj1.bubblesort(arr,size);
			obj1.print(arr,size);
		    cout<<endl;
		    goto block;
		}
	    if(obj1.checksort(arr,size)==false)
		{
			cout<<endl<<"already sorted";
		}
	}
	if(choice==3)
	{
		system("cls");
		system("pause");
		obj1.print(arr,size);
		cout<<endl;
		goto block;
	}
    if(choice==4)
    {
    	return 0;
	}
}

