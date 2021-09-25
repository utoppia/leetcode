class Solution:
  def isValid(self, s: str) -> bool:
    pairs = {"]": "[", ")": "(", "}": "{"}

    st = []
    for ch in s:

      if ch in pairs:
        if st and pairs[ch] == st[-1]:
          st.pop(-1)
        else:
          return False
      else:
        st.append(ch)

    return len(st) == 0
