// Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

// Nodes x and y will always be present in the input of a BST, and x != y.

// Example 1:

// Input: 
// -------------------- Input tree--------------------------
//                     30
//                 /       \ 
//                20        50
//                       /      \ 
//                      40      60

// k = 2, x = 40, y = 60 
// Output:
// 30
// Explanation:
// Their 2nd common ancestor is 30.
// Example 2:

// Input: 
// Input tree

// k = 2, x = 40, y = 60
// Output:
// -1
// Explanation:
// LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.

class Solution
{
    public:
    void solve(Node *root, int k, int x, int y, vector<int> &ans){
        // preOrder Traversal 
        if(!root) return;
        
        ans.push_back(root->data);
        if(root->data < x && root->data < y){
            solve(root->right, k, x, y, ans);
        }
        else if(root->data > x && root->data > y){
            solve(root->left, k, x, y, ans);
        }
    }
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int> ans;
        solve(root, k, x, y, ans);
        
        int n = ans.size();
        
        if(n < k) return -1;
        
        return ans[n-k];
    }
};
