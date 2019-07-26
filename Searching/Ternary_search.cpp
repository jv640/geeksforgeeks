#include<iostream>
using namespace std;

void TS(int arr[],int num,int l,int h);

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

    TS(array,num,l,size);
}

void TS(int arr[],int num,int l,int h)
{
    if(l>h)
        cout<<"NOT FOUND";
    else
    {
        int mid1= l+(h-l)/3;
        int mid2= h-(h-l)/3;

        if(num==arr[mid1])
            cout<<"Number found at "<<mid1 + 1 << " index of array";
        else if(num==arr[mid2])
            cout<<"Number found at "<<mid2 + 1 << " index of array";
        else if(num<arr[mid1])
            TS(arr,num,l,mid1-1);
        else if(num>arr[mid2])
            TS(arr,num,mid2+1,h);
        else
            TS(arr,num,mid1+1,mid2-1);
    }
    
}