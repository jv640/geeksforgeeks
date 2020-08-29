/*
  Given k sorted arrays of size n each, merge them and print the sorted output.
*/

// Approach 1 is to use copy all element to new array and sort that shit
// Approach 2 is to merge 2 arrays and keep merging until left one
// O(n*k*logk) both time and space
// code
  void mergeKArrays(int arr[][n],int i,int j, int output[]) 
{ 
    //if one array is in range 
    if(i==j) 
    { 
        for(int p=0; p < n; p++) 
        output[p]=arr[i][p]; 
        return; 
    } 
      
    //if only two arrays are left them merge them  
    if(j-i==1) 
    { 
        mergeArrays(arr[i],arr[j],n,n,output); 
        return; 
    } 
      
    //output arrays  
    int out1[n*(((i+j)/2)-i+1)],out2[n*(j-((i+j)/2))]; 
      
    //divide the array into halves 
    mergeKArrays(arr,i,(i+j)/2,out1); 
    mergeKArrays(arr,(i+j)/2+1,j,out2); 
      
    //merge the output array 
    mergeArrays(out1,out2,n*(((i+j)/2)-i+1),n*(j-((i+j)/2)),output); 
      
} 
void mergeArrays(int arr1[], int arr2[], int n1,  
                             int n2, int arr3[])  
{  
    int i = 0, j = 0, k = 0;  
    
    // Traverse both array  
    while (i<n1 && j <n2)  
    {  
        // Check if current element of first  
        // array is smaller than current element  
        // of second array. If yes, store first  
        // array element and increment first array  
        // index. Otherwise do same with second array  
        if (arr1[i] < arr2[j])  
            arr3[k++] = arr1[i++];  
        else
            arr3[k++] = arr2[j++];  
    }  
    
    // Store remaining elements of first array  
    while (i < n1)  
        arr3[k++] = arr1[i++];  
    
    // Store remaining elements of second array  
    while (j < n2)  
        arr3[k++] = arr2[j++];  
} 
// other approach is to use heap 
/*
  The process must start with creating a MinHeap and inserting the first element of all the k arrays. 
  Remove the root element of Minheap and put it in the output array and insert the next element from the array of removed element. 
  To get the result the step must continue until there is no element in the MinHeap left.
  O(n*k*logk) O(k)
*/
// code
  int *mergeKArrays(int arr[][N], int k){
    int *res=new int[k*k];
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
    for(int i = 0; i<k; i++){
        q.push(make_pair(arr[i][0], make_pair(i,0)));
    }
    int x = 0;
    while(!q.empty()){
        pair<int, pair<int, int>> p1 = q.top();
        q.pop();
        res[x++] = p1.first;
        if(p1.second.second < k-1)
            q.push(make_pair(arr[p1.second.first][p1.second.second+1], 
                make_pair(p1.second.first, p1.second.second+1)));
        
    }
    return res;
}
