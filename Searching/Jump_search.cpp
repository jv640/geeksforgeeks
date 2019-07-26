#include<math.h>
#include<iostream>
using namespace std;

void jump_search(int arr[],int size, int num);

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
    jump_search(array,size,num);

}
void jump_search(int arr[],int size,int num)
{
    int flag=0;
    int n = sqrt(size);
    for(int i=0;i<size;i+=n)
    {
        if(num==arr[i])
        {
            cout<<"Number found on "<<i+1<<" Index"<<endl;
            flag=1;
            break;
        }
        else if(num<arr[i])
        {
            for(int j=i-n+1;j<i;j++)
            {
                if(num==arr[i])
                {
                    cout<<"Number found on "<<i+1<<" Index of array"<<endl;
                    flag=1;
                    break;
                }
            }
        }
    }
    if(!flag)
        cout<<"NOT FOUND";

}
