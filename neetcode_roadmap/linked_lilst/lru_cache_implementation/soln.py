class Node:
    def __init__(self, key=-1,value=-1, next_=None, previous= None, hit=0):
        self.key = key
        self.value = value
        self.next = next_
        self.previous = previous
        
    def __str__(self):
        return f"{self.key} == {self.value}"

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.left = Node()
        self.right = Node(-1, -1, None, self.left)
        self.left.next = self.right
        
    def delete_node(self, node: Node):
        previous_node = node.previous
        next_node = node.next
        previous_node.next, next_node.previous = next_node, previous_node
        
    def add_new_node(self, node: Node):
        prev_node = self.right.previous
        node.previous = prev_node
        node.next = self.right
        self.right.previous = node
        prev_node.next = node

    def get(self, key: int) -> int:
        if not self.cache.get(key):
            # self.print_cache()
            # print()
            return -1
        else:
            self.delete_node(self.cache[key])
            self.add_new_node(self.cache[key])
            # self.print_cache()
            # print()
            return self.cache[key].value
        
        
    def put(self, key: int, value: int) -> None:        
        if key in self.cache:
            self.delete_node(self.cache[key])
            self.cache[key].value = value
            self.add_new_node(self.cache[key])
        else:
            node = Node(key, value)
            self.add_new_node(node)
            self.cache[key] = node
        if len(self.cache) > self.capacity:
            del self.cache[self.left.next.key]
            self.delete_node(self.left.next)
        # self.print_cache()
        # print()

    def print_cache(self):
        head = self.left
        while head:
            print(head)
            head=head.next

def main():
    # Instantiate LRUCache object
    lRUCache = LRUCache(2)

    # Perform operations and print results
    lRUCache.put(1, 1)
    lRUCache.put(2, 2)
    print("Output 1: ", lRUCache.get(1))  # Should print 1
    lRUCache.put(3, 3)
    print("Output 2: ", lRUCache.get(2))  # Should print -1

    lRUCache.put(4, 4)
    print("Output 3: ", lRUCache.get(1))  # Should print -1
    print("Output 4: ", lRUCache.get(3))  # Should print 3
    print("Output 5: ", lRUCache.get(4))  # Should print 4

if __name__ == "__main__":
    main()