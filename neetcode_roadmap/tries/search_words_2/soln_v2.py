from typing import List


class TrieNode:
    def __init__(self, val=None):
        self.val = val
        self.endOfWord = False
        self.children = {}


class Node:
    def __init__(self, val: chr):
        self.val = val
        self.neighbors = {}
        self.visited = False

    def __str__(self):
        return f"{self.val} l:{self.neighbors.get('l').val if self.neighbors.get('l') else None} r:{self.neighbors.get('r').val if self.neighbors.get('r') else None} u:{self.neighbors.get('u').val if self.neighbors.get('u') else None} d:{self.neighbors.get('d').val if self.neighbors.get('d') else None}"

    def __repr__(self):
        return f"{self.val} l:{self.neighbors.get('l').val if self.neighbors.get('l') else None} r:{self.neighbors.get('r').val if self.neighbors.get('r') else None} u:{self.neighbors.get('u').val if self.neighbors.get('u') else None} d:{self.neighbors.get('d').val if self.neighbors.get('d') else None}"

    def __eq__(self, other):
        if isinstance(other, Node):
            return self.val == other.val
        if isinstance(other, chr):
            return self.val == other
        return False


class Solution:
    def buildNodeBoard(self, board: List[List[str]]):
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.nodeBoardBuiltAlready:
                    self.nodeBoard[i][j].visited = False
                    continue
                self.nodeBoard[i][j].val = board[i][j]
                if i > 0:
                    self.nodeBoard[i - 1][j].neighbors["d"] = self.nodeBoard[i][j]
                    self.nodeBoard[i][j].neighbors["u"] = self.nodeBoard[i - 1][j]
                if j > 0:
                    self.nodeBoard[i][j - 1].neighbors["r"] = self.nodeBoard[i][j]
                    self.nodeBoard[i][j].neighbors["l"] = self.nodeBoard[i][j - 1]

    def buildTrie(self, words):
        self.root = TrieNode()
        for word in words:
            current = self.root
            for chr in word:
                if chr not in current.children:
                    current.children[chr] = TrieNode(chr)
                current = current.children[chr]
            current.endOfWord = True    

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.nodeTrie = Node("X")
        self.nodeBoard: List[List["Node"]] = [
            [Node("X") for _ in range(len(board[0]))] for _ in range(len(board))
        ]
        self.nodeBoardBuiltAlready = False
        self.buildNodeBoard(board)
        self.nodeBoardBuiltAlready = True
        self.buildTrie(words)
        out_arr = []
        
        def dfs(root, )
        
        for i in range(len(self.nodeBoard)):
            for j in range(len(self.nodeBoard[i])):
                self.buildNodeBoard()
                dfs(self.root, self.nodeBoard[i][j])


soln = Solution()
board = [
    ["o", "a", "a", "n"],
    ["e", "t", "a", "e"],
    ["i", "h", "k", "r"],
    ["i", "f", "l", "v"],
]
words = ["oath", "pea", "eat", "rain"]
print(soln.findWords(board, words))
board = [["a", "b"], ["c", "d"]]
words = ["abcb"]
print(soln.findWords(board, words))
