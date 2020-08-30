/*
  Given a number, in the form of an array a[] containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome larger than this number.
  Input : The first line is number of test cases T. Every testcase contains two lines. 
          The first line contains the size of the array, second line contains the digits of the number separated by space.
  Output: In each separate line print the digits of palindrome with spaces in between.
  Constraints:
          1<=T<=100
          1<=n<=1000
          1<=a[i]<=9
  Example:
    Input:
          1
          11
          9 4 1 8 7 9 7 8 3 2 2
    Output:
          9 4 1 8 8 0 8 8 1 4 9
*/

// code
  #include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> num;
        for(int i = 0; i<n; i++){
            int v;
            cin>>v;
            num.push_back(v);
        }
        int mid = n/2; 
      
        // A bool variable to check if copy of left side to right is sufficient or not 
        bool leftsmaller = false; 
      
        // end of left side is always 'mid -1' 
        int i = mid - 1; 
      
        // Beginning of right side depends if n is odd or even 
        int j = (n % 2)? mid + 1 : mid; 
      
       // Initially, ignore the middle same digits  
        while (i >= 0 && num[i] == num[j]) 
            i--,j++; 
      
        // Find if the middle digit(s) need to be incremented or not (or copying left  
        // side is not sufficient) 
        if ( i < 0 || num[i] < num[j]) 
            leftsmaller = true; 
      
        // Copy the mirror of left to tight 
        while (i >= 0) 
        { 
            num[j] = num[i]; 
            j++; 
            i--; 
        } 
      
        // Handle the case where middle digit(s) must be incremented.  
        // This part of code is for CASE 1 and CASE 2.2 
        if (leftsmaller == true){ 
            int carry = 1; 
            i = mid - 1; 
      
            // If there are odd digits, then increment 
            // the middle digit and store the carry 
            if (n%2 == 1){ 
                num[mid] += carry; 
                carry = num[mid] / 10; 
                num[mid] %= 10; 
                j = mid + 1; 
            } 
            else
                j = mid; 
      
            // Add 1 to the rightmost digit of the left side, propagate the carry  
            // towards MSB digit and simultaneously copying mirror of the left side  
            // to the right side. 
            while (i >= 0){ 
                num[i] += carry; 
                carry = num[i] / 10; 
                num[i] %= 10; 
                num[j++] = num[i--]; // copy mirror to right 
            }
        }
        for(int i = 0; i<n; i++)
            cout<<num[i]<<" ";
        cout<<endl;
        // code
    }
	
	return 0;
}
