/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
        //    3
        //   / \   
        // 9    20
        //      /\
        //     15 7
class Solution {
    int sum = 0;
    void solve(TreeNode root){
        if(root == null) return;
        
        if(root.left != null && root.left.left == null && root.left.right == null){
            sum += root.left.val;
        }
        solve(root.left);
        solve(root.right);
    }
    public int sumOfLeftLeaves(TreeNode root) {
        solve(root);
        return sum;
    }
}
