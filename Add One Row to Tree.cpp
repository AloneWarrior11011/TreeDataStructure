
// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:

// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

// Example 1:


// Input: root = [4,2,6,3,1,5], val = 1, depth = 2
// Output: [4,1,1,2,null,null,6,3,1,5]
// Example 2:

    //        4
    //      /     \
    //     2       6
    //  /   \      /
    // 3     1    5

// Input: root = [4,2,null,3,1], val = 1, depth = 3
// Output: [4,2,null,1,1,3,null,null,1]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int currDepth){
        if(!root) return NULL;

        if(currDepth == depth - 1) // on what level we have to insert a new row
        {
            TreeNode *exLeftChild = root->left;
            TreeNode *exRightChild = root->right;
            //
            TreeNode* newLeftChild = new TreeNode(val);
            TreeNode* newRightChild = new TreeNode(val);
            // connecting val wala node to the exsisting left and right node of a tree
            root->left = newLeftChild;
            newLeftChild->left = exLeftChild;

            root->right = newRightChild;
            newRightChild->right = exRightChild;
        }
        if(currDepth < depth - 1){
             solve(root->left, val, depth, currDepth + 1);
             solve(root->right, val, depth, currDepth + 1);
        }
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Try to resolve edge cases
        // If depth == 1 that means there is no depth depth - 1 at all, 
        // then create a tree node with value val as the new 
        // root of the whole original tree, and the original 
        // tree is the new root's left subtree.

        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }
       return solve(root, val, depth, 1);
    }
};
