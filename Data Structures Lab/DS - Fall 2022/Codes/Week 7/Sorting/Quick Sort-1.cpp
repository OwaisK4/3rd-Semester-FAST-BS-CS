# include <iostream>
using namespace std;
// quick sort sorting algorithm
int Partition(int arr[], int s, int e)
{
 cout <<"value of start is start "<<s<<" and value of end is "<<e<<endl;
 int pivot = arr[e];
 int pIndex = s;
 cout<<"value of pivot is "<<pivot<<endl;
 
 for(int i = s;i<e;i++)
 {
 if(arr[i]<pivot)
 {
 int temp = arr[i];
 arr[i] = arr[pIndex];
 arr[pIndex] = temp;
 
 pIndex++;
 }
 }
 
 int temp = arr[e];
 arr[e] = arr[pIndex];
 arr[pIndex] = temp;
 cout<<endl<<"partition"<<endl;
 for(int i=s;i<=e;i++)
 {
 cout<<arr[i]<<" ";
 }
 cout<<endl;
 cout<<pIndex<<endl;
 return pIndex;
}
 
void QuickSort(int arr[], int s, int e)
{
 if(s<e)
 {
 int p = Partition(arr,s, e);
 QuickSort(arr, s, (p-1));  // recursive QS call for left partition
 QuickSort(arr, (p+1), e);  // recursive QS call for right partition
 }
}
 
int main()
{
 
 
 int size=6;
 int myarray[size]={56,33,21,59,20,30};
 QuickSort(myarray,0,(size-1));  // quick sort called
 cout<<"After Sorting"<<endl;
 for(int i=0;i<size;i++)
 {
 cout<<myarray[i]<<" ";
 }
 return 0;
}
