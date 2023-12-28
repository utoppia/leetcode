# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-12-29 00:36:37
# filename    : 2506-count-pairs-of-similar-strings.py
# language    : Python
# editor      : Emacs 27.1
# -----------------------------------------


class Solution:
    def toBase(self, word: str) -> str:
        return "".join(sorted(set([x for x in word])))

    def similarPairs(self, words: List[str]) -> int:
        ans = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if self.toBase(words[i]) == self.toBase(words[j]):
                    ans += 1
        return ans
