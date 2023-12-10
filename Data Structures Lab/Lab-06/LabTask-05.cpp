#include<iostream>
using namespace std;
int main()
{
	system("color 70");
	int n,k,count=0,i=0;
	cout<<endl<<"Enter Total Number of Toys: ";
	cin>>n;
	int *arr=new int[n];
	cout<<endl<<"Enter Price of "<<n<<" Toy: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int *temp=new int[count];
	cout<<endl<<"Price Set of Toys: ";
	for(int i=0;i<n;i++)
	{
		cout<<"["<<arr[i]<<"]-";
	}
	cout<<endl<<"Enter you amount of Money: ";
	cin>>k;
	while(i<n && k>0)
	{
		if(arr[i]<=k && k>0)
		{
			if(k>0)
			{
			   temp[i]=arr[i];
			   cout<<"["<<temp[i]<<"]->";
			   k=k-arr[i];
			}
			count++;
		}
		i++;
	}
	cout<<endl<<"You can buy Maximum "<<count<<" toys";
}

