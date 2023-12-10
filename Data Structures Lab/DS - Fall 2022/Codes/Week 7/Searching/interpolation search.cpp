#include<iostream>
using namespace std;

void interpolationSearch(int arr[], int n, int key)
{
    int Low = 0, High = n-1;
    bool flag = true;
    //Checking the corner cases
    while(Low <= High && key >= arr[Low] && key <= arr[High])
    {
        if(Low == High)
        {
            cout<<"Element found at position "<<Low<<endl;
        }
        int q = (key - arr[Low])/(arr[High] - arr[Low]);
        int pos = Low + (High - Low) * q;
        if(arr[pos] == key)
        {
            cout<<"Element found at position "<<pos<<endl;
            flag = false;
        }
        //If the element is greater than the value at that position
        if(arr[pos] < key)
        {
            Low = pos + 1;
        }
        //If the element is lesser than the value at that position
        else
        {
            High = pos - 1;
        }
    }
    //If the element is not found after traversing the whole array
    if(flag == true)
    {
     cout<<"Element not found"<<endl;
    }
}

//Main function to take in the inputs from the user
int main()
{
    int n,i,x;
    cout<<"Enter the number of elements\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>x;
    interpolationSearch(arr, n, x);
    return 0;
}
