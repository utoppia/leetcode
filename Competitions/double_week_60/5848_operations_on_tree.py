class LockingTree:

    def __init__(self, parent: List[int]):
      n = len(parent)
      self.parent = parent
      self.isLock = [0] * n
      self.childlock = [[] for _ in range(n)]


    def lock(self, num: int, user: int) -> bool:
      if self.isLock[num]:
        return False
      self.isLock[num] = user
      parent = self.parent[num]
      while parent != -1:
        self.childlock[parent].append(num)
        parent = self.parent[parent]
      return True


    def unlock(self, num: int, user: int) -> bool:
      if self.isLock[num] != user and user != 0:
        return False
      # user 0 can unlock any node
      self.isLock[num] = 0
      parent = self.parent[num]
      while parent != -1:
        self.childlock[parent].remove(num)
        parent = self.parent[parent]
      return True

    def upgrade(self, num: int, user: int) -> bool:
      if self.isLock[num]:
        return False
      if not self.childlock[num]:
        return False
      parent = self.parent[num]
      while parent != -1:
        if self.isLock[parent]:
          return False
        parent = self.parent[parent]
      self.lock(num, user)
      for child in self.childlock[num].copy():
        self.unlock(child, 0)
      return True


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
