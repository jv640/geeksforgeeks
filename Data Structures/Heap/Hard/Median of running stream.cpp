// Basic approaches are to save element in vector then sort and find median O(n*nlogn) or use quicksort to sort dynamically and then return median O(n2) 
// other is using heap make 2 heaps one minheap and other maxheap 
// code (nlogn)
  #include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;    
    int med;
    cin>>med;
    cout<<med<<endl;
    left.push(med);
    t--;
    while(t--){
        int n;
        cin>>n;
        
        if(left.size() == right.size()){
            if(n < med){
                left.push(n);
                med = left.top();
            }
            else{
                right.push(n);
                med = right.top();
            }
            cout<<med<<endl;
        }
        else if(left.size()>right.size()){
            if(n<med){
                right.push(left.top());
                left.pop();
                left.push(n);
            }
            else
                right.push(n);
            med = (left.top() + right.top())/2;
            cout<<med<<endl;
        }
        else{
            if(n>med){
                left.push(right.top());
                right.pop();
                right.push(n);
            }
            else
                left.push(n);
            med = (left.top() + right.top())/2;
            cout<<med<<endl;
        }
        // code
    }
	
	return 0;
}
