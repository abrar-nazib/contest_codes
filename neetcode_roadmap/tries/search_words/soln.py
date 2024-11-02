class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False


class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        current = self.root
        for chr in word:
            if chr not in current.children:
                current.children[chr] = TrieNode()
            current = current.children[chr]
        current.endOfWord = True

    def search(self, word: str, node=None) -> bool:
        if node is None:
            node = self.root
        if len(word) < 2:
            if word[0] in node.children:
                return node.children[word[0]].endOfWord
            elif word[0] == ".":
                for key, value in node.children.items():
                    if node.children[key].endOfWord:
                        return True
                return False
            return False

        if word[0] in node.children:
            return self.search(word[1:], node.children[word[0]])
        elif word[0] == ".":
            for key, value in node.children.items():
                available = self.search(word[1:], node.children[key])
                if available:
                    return True
            return False
        else:
            return False


# Example usage:
wordDictionary = WordDictionary()
wordDictionary.addWord("bad")
wordDictionary.addWord("dad")
wordDictionary.addWord("mad")
print(wordDictionary.search("pad"))  # return False
print(wordDictionary.search("bad"))  # return True
print(wordDictionary.search(".ad"))  # return True
print(wordDictionary.search("b.."))  # return True
