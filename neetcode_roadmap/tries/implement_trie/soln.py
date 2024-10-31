import typing


class Trie:

    def __init__(self, chr=""):
        self.chr = chr
        self.nodes: typing.List["Trie"] = []
        self.end = False

    def __eq__(self, other):
        if isinstance(other, str):
            return self.chr == other
        return False

    def __str__(self):
        return self.chr

    def insert(self, word: str) -> None:
        if word[0] not in self.nodes:
            node = Trie(word[0])
            self.nodes.append(node)
            if len(word) > 1:
                node.insert(word[1:])
            else:
                node.end = True
        else:
            index = self.nodes.index(word[0])
            if len(word) > 1:
                self.nodes[index].insert(word[1:])
            else:
                self.nodes[index].end = True

    # def print_nodes(self):
    #     for node in self.nodes:
    #         node.print_nodes()

    # def print_tree(self):
    #     print(self.chr)
    #     for node

    def search(self, word: str) -> bool:
        if len(word) == 1:
            return word[0] in self.nodes and self.nodes[self.nodes.index(word[0])].end
        if word[0] in self.nodes:
            return self.nodes[self.nodes.index(word[0])].search(word[1:])
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        if len(prefix) == 1:
            return prefix[0] in self.nodes
        if prefix[0] in self.nodes:
            return self.nodes[self.nodes.index(prefix[0])].startsWith(prefix[1:])
        else:
            return False


trie = Trie()
trie.insert("apple")
print(trie.search("apple"))  # return True
print(trie.search("app"))  # return False
print(trie.startsWith("app"))  # return True
trie.insert("app")
print(trie.search("app"))  # return True
