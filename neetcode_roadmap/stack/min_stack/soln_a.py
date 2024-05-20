class MinimumStack:

    def __init__(self):
        """
        Initializes the MinimumStack object.
        """
        self.stack = []  # Regular stack to store data
        self.min_stack = []  # Stack to store minimum elements

    def push(self, val: int) -> None:
        """
        Pushes a new value onto the stack.

        Args:
            val: The value to be pushed.
        """
        self.stack.append(val)
        # Update minimum stack only if the new value is less than or equal to the current minimum
        self.min_stack.append(min(val, self.min_stack[-1] if self.min_stack else val))

    def pop(self) -> None:
        """
        Pops the top element from the stack.
        """
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        """
        Returns the top element of the stack.

        Returns:
            The top element of the stack.
        """
        return self.stack[-1] if self.stack else None

    def get_minimum(self) -> int:
        """
        Returns the minimum element in the stack in constant time.

        Returns:
            The minimum element in the stack.
        """
        return self.min_stack[-1]

# Example usage
stack = MinimumStack()
stack.push(2)
stack.push(0)
stack.push(1)
print(stack.get_minimum())  # Output: 1
stack.pop()
print(stack.get_minimum())  # Output: 1
stack.pop()
print(stack.get_minimum())  # Output: 3