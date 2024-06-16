class Node:
    def __init__(self,value=-1, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
        

def dfs(root):
    if root == None:
        return []
    output = []
    stack = [root]
    while len(stack) > 0:
        val = stack.pop()
        output.append(val.value)
        if val.right:
            stack.append(val.right)
        if val.left:
            stack.append(val.left)
            
    return output

def dfs_recur(root, val):
    if root == None:
        return False
    if root.value == val:
        return True
    return dfs_recur(root.left, val) or dfs_recur(root.right, val)

    
    
        



# Ceate a binary tree
#     1
#    / \
#   2   5
#  / \   \
# 3   4   6

root = Node(1)
root.left = Node(2)
root.right = Node(5)
root.right.right=Node(6)
root.left.left = Node(3)
root.left.right = Node(4)

print(dfs_recur(root, 12))
