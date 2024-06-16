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

def dfs_recur(root):
    if root == None:
        return []
    output = []
    left_values = dfs_recur(root.left)
    right_values = dfs_recur(root.right)
    output.append(root.value)
    output = [root.value] + [val for val in left_values] + [val for val in right_values]
    return output
    
    
        



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

print(dfs_recur(root))
