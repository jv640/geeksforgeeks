#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

void BS(int arr[],int num,int l,int h);
void Expo_search(int arr[],int size,int num);

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

    Expo_search(array,size,num);

}

void Expo_search(int arr[],int size,int num)
{
    for(int i=0; i<size; i=i*2+2)
    {
        if(arr[i]>=num)
            BS(arr,num,i/2,i);
        
    }
}

void BS(int arr[],int num,int l,int h)

{
    if (l > h)                  // BASE CASE
        cout << "NOT FOUND " << endl;
    else
    {
        int mid = (l + h) / 2;

        if (arr[mid] == num)
            cout << "Number found on " << mid + 1 << " index of array ";
        
        else if (num > arr[mid])
            BS(arr, num, mid + 1, h);
        
        else
            BS(arr, num, l, mid - 1);
    }
}