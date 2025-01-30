from typing import List, Dict


class Node:
    def __init__(self, val: chr):
        self.val = val
        self.visited = False
        self.left = None
        self.right = None
        self.up = None
        self.down = None


class TrieNode:
    def __init__(self, val: chr = None):
        self.val = val
        self.children: Dict[chr, TrieNode] = {}
        self.endofword = False


class Solution:

    def buildTrie(self, words: List[str]):
        for word in words:
            current: TrieNode = self.root
            for i, c in enumerate(word):
                if c not in current.children:
                    current.children[c] = TrieNode(c)
                current = current.children[c]
                if i == len(word) - 1:
                    current.endofword = True

    def buildNodeBoard(self, board: List[List[str]]):
        for i in range(len(board)):
            for j in range(len(board[0])):
                self.nodeBoard[i][j] = Node(board[i][j])
                if i > 0:
                    self.nodeBoard[i - 1][j].down = self.nodeBoard[i][j]
                    self.nodeBoard[i][j].up = self.nodeBoard[i - 1][j]
                if j > 0:
                    self.nodeBoard[i][j - 1].right = self.nodeBoard[i][j]
                    self.nodeBoard[i][j].left = self.nodeBoard[i][j - 1]

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.nodeBoard: List[List[Node]] = [
            [Node("X") for _ in range(len(board[0]))] for _ in range(len(board))
        ]
        self.buildNodeBoard(board)
        self.root: TrieNode = TrieNode()
        self.buildTrie(words)
        results = set()

        def dfs(node: Node, strsofar: str, trieNode: TrieNode):
            if node is None or node.visited is True:
                return
            if node.val not in trieNode.children:
                return
            # Base case
            current_str = strsofar + node.val
            if trieNode.children[node.val].endofword:
                results.add(current_str)
            node.visited = True
            dfs(node.right, current_str, trieNode.children[node.val])
            dfs(node.left, current_str, trieNode.children[node.val])
            dfs(node.up, current_str, trieNode.children[node.val])
            dfs(node.down, current_str, trieNode.children[node.val])
            node.visited = False

        for i in range(len(self.nodeBoard)):
            for j in range(len(self.nodeBoard[0])):
                dfs(self.nodeBoard[i][j], "", self.root)
        return list(results)


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
board = [
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
    ["a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a", "a"],
]
words = [
    "a",
    "aa",
    "aaa",
    "aaaa",
    "aaaaa",
    "aaaaaa",
    "aaaaaaa",
    "aaaaaaaa",
    "aaaaaaaaa",
    "aaaaaaaaaa",
]
print(soln.findWords(board, words))
