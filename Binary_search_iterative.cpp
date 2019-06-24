#include <iostream>
using namespace std;

int main()
{
    //taking input from user
    cout << "Enter the size of Array you want to search in"<< endl;
    int size;
    cin >> size;
    cout << "Enter the Input Array in which you want to search" << endl; 
    int array[size];
    for ( int i=0; i<size; i++)
    {
        cin >> array[i];
    }
    cout << "Enter the number you want to search : ";
    int num;
    cin >> num;

    int low = 0, high = size,flag=1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if( num == array[mid])
        {
            cout << "Number found on " << mid + 1 << " Index of array";
            flag = 0;
            break;
        }
        else if( num > array[mid] )
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(flag)
        cout<<"NOT FOUND";
}