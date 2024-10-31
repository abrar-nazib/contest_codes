import typing


class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        current_node = self.root
        for chr in word:
            if chr not in current_node.children:
                current_node.children[chr] = TrieNode()
            current_node = current_node.children[chr]
        current_node.endOfWord = True

    def search(self, word: str) -> bool:
        current_node = self.root
        for chr in word:
            if chr not in current_node.children:
                return False
            current_node = current_node.children[chr]
        return current_node.endOfWord

    def startsWith(self, prefix: str) -> bool:
        current_node = self.root
        for chr in prefix:
            if chr not in current_node.children:
                return False
            current_node = current_node.children[chr]
        return True


trie = Trie()
trie.insert("apple")
print(trie.search("apple"))  # return True
print(trie.search("app"))  # return False
print(trie.startsWith("app"))  # return True
trie.insert("app")
print(trie.search("app"))  # return True
