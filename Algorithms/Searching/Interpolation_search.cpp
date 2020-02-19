#include<iostream>
using namespace std;

void ITP_search(int arr[],int num,int low,int high);

int main()
{
    cout<<"Enter the size of Array you want to search in : "<<endl;
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter the input to the array "<<endl;
    for(int i =0; i< size; i++)
        cin>>array[i];
    cout<<"Enter the number you want to search : ";
    int num;
    cin>>num;
    int l=0;

    ITP_search(array,num,l,size);
}

void ITP_search(int arr[],int num,int low,int high)
{
    if(low>high)
        cout<<"NOT FOUND";
    else
    {
        int pos = low +((high-low)/(arr[high]-arr[low]*(num-arr[low])));

        if (arr[pos] == num)
            cout << "Number found on " << pos + 1 << " index of array ";
        
        else if (num > arr[pos])
            ITP_search(arr, num, pos + 1, high);
        
        else
            ITP_search(arr, num, low, pos - 1);
    }
    
}