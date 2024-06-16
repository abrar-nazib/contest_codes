class Node:
    def __init__(self,value=-1, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right
        

def bfs(root):
    if root == None:
        return []
    output = []
    queue = [root]
    maxDepth = -1
    it=0
    while len(queue) > 0:
        it+=1
        val = queue[0]
        del queue[0]
        output.append(val.value)
        if val.left:
            queue.append(val.left)
        if val.right:
            queue.append(val.right)
            
    return output

def dfs_recur(root):
    if root == None:
        return []
    output = []
    left_values = dfs_recur(root.left)
    right_values = dfs_recur(root.right)
    output.append(root.value)
    for val in left_values:
        if val:
            output.append(val)
    for val in right_values:
        if val:
            output.append(val)
        
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

print(bfs(root))
