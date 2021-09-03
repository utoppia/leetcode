class Solution:
  def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
    # Disjoint Set

    fa = [i for i in range(len(accounts))]

    def find(x: int) -> int:
      nonlocal fa
      if fa[x] != x:
        fa[x] = find(fa[x])
      return fa[x]

    mails = {}

    for index, emails in enumerate(accounts):
      u = find(index)
      for mail in emails[1:]:
        if mail in mails:
          v = find(mails[mail])
          fa[v] = u
        else:
          mails[mail] = index

    ans = {}

    for i in range(len(accounts)):
      v = find(i)
      if v not in ans:
        ans[v] = set([])
      for mail in accounts[i][1:]:
        ans[v].add(mail)

    return [[accounts[k][0]] + sorted(list(v)) for k, v in ans.items()]
