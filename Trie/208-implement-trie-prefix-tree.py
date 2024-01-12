class Trie:

  def __init__(self):
    """
    Initialize your data structure here.
    """
    self.children = [None] * 26
    self.isNode = False


  def insert(self, word: str) -> None:
    """
    Inserts a word into the trie.
    """
    if not word:
      self.isNode = True
      return
    pos = ord(word[0]) - ord('a')
    if self.children[pos]:
      self.children[pos].insert(word[1:])
    else:
      self.children[pos] = Trie()
      self.children[pos].insert(word[1:])


  def search(self, word: str) -> bool:
    """
    Returns if the word is in the trie.
    """
    if not word:
      return self.isNode

    pos = ord(word[0]) - ord('a')
    if not self.children[pos]:
      return False
    return self.children[pos].search(word[1:])
    


  def startsWith(self, prefix: str) -> bool:
    """
    Returns if there is any word in the trie that starts with the given prefix.
    """
    if not prefix:
      return True

    pos = ord(prefix[0]) - ord('a')
    if not self.children[pos]:
      return False
    return self.children[pos].startsWith(prefix[1:])


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
