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

 Input: root = [2,1,3]
 Output: 1

        2
      /   \
     1     3 

     so bottom left is 1
 */
class Solution {
    private int max_depth;
    private int bottom_left_val;

    private void dfs(TreeNode current, int depth){
        if(current == null) return;

        if(depth > max_depth){
            max_depth = depth;
            bottom_left_val = current.val;
        }
        dfs(current.left, depth + 1);
        dfs(current.right, depth + 1);
    }
    public int findBottomLeftValue(TreeNode root) {
       if(root == null) return 0;
        max_depth = -1;
        bottom_left_val = 0;
        dfs(root, 0);
        return bottom_left_val;
    }
}
