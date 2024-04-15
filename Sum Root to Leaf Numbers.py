# You are given the root of a binary tree containing digits from 0 to 9 only.

# Each root-to-leaf path in the tree represents a number.

# For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
# Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

# A leaf node is a node with no children.

 

# Example 1:
#      1
#    /   \
#  2       3

# Input: root = [1,2,3]
# Output: 25
# Explanation:
# The root-to-leaf path 1->2 represents the number 12.
# The root-to-leaf path 1->3 represents the number 13.
# Therefore, sum = 12 + 13 = 25.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, currSum):
        if root is None:
            return 0

        currSum = currSum * 10 + root.val
        if root.left is None and root.right is None:
            return currSum

        leftSum = self.dfs(root.left, currSum)
        rightSum = self.dfs(root.right, currSum)

        return leftSum + rightSum

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, 0)
