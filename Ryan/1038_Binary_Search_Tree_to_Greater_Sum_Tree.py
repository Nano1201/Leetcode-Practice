# rec version
# Time complexity: O(n)
# Space complexity: O(n)
"""
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        
        def rec(accu, curr):
            if not curr:
                return accu
            curr.val += rec(accu, curr.right)
            left = rec(curr.val, curr.left)
            return left
        rec(0, root)
        return root
"""


# stack version
# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        stack = []
        curr = root
        accu = 0

        while curr:
            stack.append(curr)
            curr = curr.right
        
        while stack:
            curr = stack.pop()
            curr.val += accu
            accu = curr.val
            if curr.left:
                stack.append(curr.left)
                temp = curr.left.right
                while temp:
                    stack.append(temp)
                    temp = temp.right
        return root
