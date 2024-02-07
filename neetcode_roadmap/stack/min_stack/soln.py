class MinStack:

    def __init__(self):
        self.stack=[]
        self.min_stack=[]

    def push(self, val: int) -> None:
        self.stack.append(val)
        if (not self.min_stack) or self.min_stack[-1] >= val:
            self.min_stack.append(val)

    def pop(self) -> None:
        if(self.min_stack[-1] == self.stack[-1]):
            self.min_stack.pop()
        self.stack.pop()

    def top(self) -> int:
        return  self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


def main():
    obj = MinStack()
    obj.push(-2)
    obj.push(0)
    obj.push(-3)
    min1 = obj.getMin()  # Should print -3
    print("Min1: ", min1)
    obj.pop()
    top = obj.top()  # Should print 0
    print("Top: ", top)
    min2 = obj.getMin()  # Should print -2
    print("Min2: ", min2)

if __name__ == "__main__":
    main()