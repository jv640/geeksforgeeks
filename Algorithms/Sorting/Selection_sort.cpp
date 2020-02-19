#include<iostream>
using namespace std;


void S_S(int arr[],int n);
void swap(int *a,int *b);
void Disp(int arr[],int n);
int main()
{
    cout<<"Enter the size of array you want to sort : "<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements to the array "<<endl;

    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    S_S(arr,size);
    Disp(arr,size);
}

void S_S(int arr[],int n)
{
    
for(int i=0;i<n;i++)
    {
        int small=arr[i];
        int k=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<small)
            {
                small=arr[j];
                k=j;
            }
        }
        if(k!=i)
            swap(&arr[i],&arr[k]);
    }

    
}

void Disp(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"  ";
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
