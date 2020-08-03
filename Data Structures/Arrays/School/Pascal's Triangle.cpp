// Geeks Link : https://practice.geeksforgeeks.org/problems/pascal-triangle/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int numRows;
        cin>> numRows;
        vector<vector<int>> triangle;
        vector<int> temp;
        temp.push_back(1);
        triangle.push_back(temp);
        // if(numRows == 1) cout<<1<<" ";
        for(int row = 1; row<numRows; row++){
            vector<int> r;
            for(int i = 0; i<triangle[row-1].size()+1; i++){
                if(i == 0 || i == triangle[row-1].size())
                    r.push_back(1);
                else{
                    r.push_back(triangle[row-1][i-1] + triangle[row-1][i]);
                }
            }
            triangle.push_back(r);
        }
        for(int i = 0; i<numRows; i++)
            cout<<triangle[numRows-1][i]<<" ";
    	cout<<endl;
    }

	return 0;
}
