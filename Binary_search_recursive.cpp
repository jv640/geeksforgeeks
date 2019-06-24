#include <iostream>
using namespace std;

void BS(int arr[], int num, int l, int h);

int main()
{
    cout << "Enter the size of Array you want to search in : ";
    int size;
    cin >> size;
    int array[size];
    cout << "Enter the input to the Array " << endl;
    for (int i = 0; i < size; i++)
        cin >> array[i];

    cout << "Enter the number you want to search : ";
    int num;
    cin >> num;
    int low = 0, high = size;

    BS(array, num, low, high);
    return 0;
}

void BS(int arr[], int num, int l, int h)
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