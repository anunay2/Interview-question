#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left , *right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};

struct TreeNode *root = new TreeNode(15);
TreeNode *asc = root,*desc = root;
stack<TreeNode*> inorder,inorderRev;
TreeNode *getNextNodeInOrder(){
    while(asc != NULL || inorder.empty() == false){
        while(asc != NULL){
            inorder.push(asc);
            asc = asc->left;
        }
        TreeNode *next = inorder.top();
        inorder.pop();
        //we have the next inorder element
        asc = next->right;
        return next;
    }
    return NULL;
}

TreeNode *getNextNodeinReverseOfInorder(){
    while(desc != NULL || inorderRev.empty() == false){
        while(desc != NULL){
            inorderRev.push(desc);
            desc = desc->right;
        }
        TreeNode *next = inorderRev.top();
        inorderRev.pop();
        desc = next->left;
        return next;
    }
    return NULL;
}

vector<pair<int,int>> twoSum(TreeNode *root, int k){

    vector<pair<int,int>> allPairs;
    TreeNode *x = getNextNodeInOrder(), *y = getNextNodeinReverseOfInorder();
    while( x!=y){
        if(x->val + y->val == k){
            allPairs.push_back(make_pair(x->val,y->val));
            x = getNextNodeInOrder();
            y = getNextNodeinReverseOfInorder();
        }
        else if(x->val+y->val<k){
            x = getNextNodeInOrder();
        }
        else{
            y = getNextNodeinReverseOfInorder();
        }
    }
    return allPairs;
}

int main(){

    /* same tree as in Interview 
    
                            15
                           /  \
                        10     20
                        /      / \
                        5      17 25
                        /         /  \
                        1         23  27
                         \              \
                           3             30*/
        
                    

    root->left = new TreeNode(10);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(13);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);

    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(7);
    root->right->right->left = new TreeNode(23);
    root->right->right->right = new TreeNode(27);

    root->left->left->left->right = new TreeNode(3);
    root->right->right->right->right = new TreeNode(30);

    vector<pair<int,int>> ans = twoSum(root, 30);

    for(auto pair :ans){
         cout<<pair.first<<"\t"<<pair.second<<"\n";
    }

    //TimeComplexity : O(n)  Space Complexity : O(log n)

    return 0;

}

