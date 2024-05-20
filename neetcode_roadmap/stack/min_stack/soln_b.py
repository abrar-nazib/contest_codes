class MinimumStack:
    def __init__(self):
        self.stack = []  # Main stack to store elements
        self.min_stack = []  # Auxiliary stack to track minimums

    def push(self, val):
        self.stack.append(val)
        # Update min_stack only if val is less than or equal to the current minimum
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)

    def pop(self):
        if not self.stack:  # Empty stack
            return None
        popped_val = self.stack.pop()
        # If the popped value is the current minimum, also pop from min_stack
        if popped_val == self.min_stack[-1]:
            self.min_stack.pop()
        return popped_val

    def top(self):
        if not self.stack:
            return None
        return self.stack[-1]  

    def get_minimum(self):
        if not self.min_stack:
            return None
        return self.min_stack[-1]  # Top of min_stack is always the minimum

# Example Usage
min_stack = MinimumStack()
min_stack.push(5)
min_stack.push(10)
min_stack.push(2)
min_stack.push(8)

print(min_stack.get_minimum())  # Output: 2
print(min_stack.top())          # Output: 8
min_stack.pop()
print(min_stack.get_minimum())  # Output: 5