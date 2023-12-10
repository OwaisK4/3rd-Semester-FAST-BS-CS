#include<iostream>
#include<stdlib.h>
using namespace std;
class Sort
{
	public:
		void bubblesort(int arr[],int s)
		{
			for(int i=0;i<s;i++)
			{
				for(int j=0;j<s;j++)
				{
					int temp;
					if(arr[i]<arr[j])
					{
						temp=arr[j];
						arr[j]=arr[i];
						arr[i]=temp;
					}
				}
			}
		}
		void insertionsort(int arr[],int s)
		{
			for(int i=1;i<s;i++)
			{
				int key=arr[i];
				int j=i-1;
				while( j>=0 && key<arr[j])
				{
					arr[j+1]=arr[j];
					j--;
				}
				arr[j+1]=key;
			}
		}
		void selectionsort(int arr[],int s)
		{
			for(int i=1;i<s-1;i++)
			{
				for(int j=0;j<s;j++)
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
		void merge(int arr[],int l,int m,int r,int size)
		{
			int i=l;
			int j=m+1;
			int k=l;
			int temp[size];
			while(i<=m && j<=r)
			{
				if(arr[i]<=arr[j])
				{
					temp[k]=arr[i];
					i++;
					k++;
				}
				else
				{
					temp[k]=arr[j];
					j++;
					k++;
				}
			}
			while(i<=m)
			{
					temp[k]=arr[i];
					i++;
					k++;
		    }
		    while(j<=r)
		    {
		    	    temp[k]=arr[j];
					j++;
					k++;
			}
			for(int i=l;i<=r;i++)
			{
				arr[i]=temp[i];
			}
		
		}
		void mergesort(int arr[],int l,int r,int s)
		{
			if(l<r)
			{
				int m=(l+r)/2;
				mergesort(arr,l,m,s);
				mergesort(arr,m+1,r,s);
				merge(arr,l,m,r,s);
			}
		}
		int part(int arr[],int l,int r,int s)
		{
				int pivot=arr[r];
				int index=l;
				for(int j=l;j<r;j++)
				{
						if (arr[j]<pivot)
						{
							 int temp = arr[j];
							 arr[j] = arr[index];
							 arr[index] = temp;
							 index++;
						}
			    }
				 int temp = arr[r];
				 arr[r] = arr[index];
				 arr[index] = temp;
				 return index;
		}
		void quicksort(int arr[],int l,int r,int s)
		{
			if(l<r)
			{
				int pi=part(arr,l,r,s);
				quicksort(arr,l,pi-1,s);
				quicksort(arr,pi+1,r,s);
			}
		}
		void print(int arr[],int s)
		{
			for(int i=0;i<s;i++)
			{
				cout<<"-->"<<arr[i];
			}
			
		}
			
};
int main()
{
	system("color 70");
	int size,choice;
	cout<<"\n\n\n\n\t\t\t\t\t\t-->-->-->-->-->-->-->-->-->";
	cout<<"\n\n\n\n\n\t\t\t\t\t\tSorting Algorithim in One!";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t-->-->-->-->-->-->-->-->-->";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t";system("pause");
	system("cls");
	cout<<"\n\n\n\n\t\t\t\t\t\t-->-->-->-->-->-->-->-->-->";
	cout<<"\n\n\n\n\n\t\t\t\t\t\tEnter asked Information!";
	cout<<"\n\n\n\n\n\n\t\t\t\t\t\t-->-->-->-->-->-->-->-->-->";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t";system("pause");
	block:
	cout<<"\nEnter size of the array: ";
	cin>>size;	
	int arr[size];
	Sort s1;  //object of class
	cout<<"\n\nRandomly generated array: ";
	for(int i=0;i<size;i++)
	{
		arr[i]=rand()%100;
		cout<<" "<<arr[i];
	}
	cout<<endl<<"\n\n\n\n\n\t\t\t\t\t\t1. Bubble Sort"<<endl<<"\n\t\t\t\t\t\t2. Insertion Sort"<<endl<<"\n\t\t\t\t\t\t3. Selection Sort"<<endl<<"\n\t\t\t\t\t\t4. Merge Sort"<<endl<<"\n\t\t\t\t\t\t5. Quick Sort"<<endl<<"\n\t\t\t\t\t\t7. End";
	cout<<endl<<"\n\n\n\n\n\t\t\t\t\t\tEnter your sorting choice: ";
	cin>>choice;
	if(choice==1)
	{
		system("cls");
		system("pause");
		s1.bubblesort(arr,size);
		s1.print(arr,size);
		goto block;
	}
	if(choice==2)
	{
		system("cls");
		system("pause");
		s1.insertionsort(arr,size);
		s1.print(arr,size);	
		goto block;
	}
	if(choice==3)
	{
		system("cls");
		system("pause");
		s1.selectionsort(arr,size);
		s1.print(arr,size);
		goto block;
	}
	if(choice==4)
	{
		system("cls");
		system("pause");
		s1.mergesort(arr,0,(size-1),size);
		s1.print(arr,size);
		goto block;	
	}
	if(choice==5)
	{
		system("cls");
		system("pause");
		s1.quicksort(arr,0,(size-1),size);
		s1.print(arr,size);
		goto block;		
	}
	if(choice==6)
	{
		return 0;
	}
}

