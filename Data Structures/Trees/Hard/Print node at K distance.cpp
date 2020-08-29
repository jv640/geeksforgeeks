    void printDownK(Node* node, int k, vector<int> &res){
        if(!node)return;
        if(k == 0)res.push_back(node->data);
        if(node->left != NULL)
            printDownK(node->left, k-1, res);
        if(node->right != NULL)
            printDownK(node->right, k-1, res);
    }
    
    int kdutil(Node* root, int target , int k, vector<int> &res){
        if(!root)
            return -1;
        if(root->data == target){
            printDownK(root, k, res);
            return 0;
        }
        int left = kdutil(root->left, target, k, res);
        if(left != -1){
            if (left + 1 == k) 
                res.push_back(root->data); 
      
             // Else go to right subtree and print all k-dl-2 distant nodes 
             // Note that the right child is 2 edges away from left child 
            else
                printDownK(root->right, k-left-2, res); 
      
             // Add 1 to the distance and return value for parent calls 
            return 1 + left;
        }
        
        int right = kdutil(root->right, target, k, res);
        if(right != -1){
            if (right + 1 == k) 
                res.push_back(root->data); 
      
             // Else go to right subtree and print all k-dl-2 distant nodes 
             // Note that the right child is 2 edges away from left child 
            else
                printDownK(root->left, k-right-2, res); 
      
             // Add 1 to the distance and return value for parent calls 
             return 1 + right;
        }
}
