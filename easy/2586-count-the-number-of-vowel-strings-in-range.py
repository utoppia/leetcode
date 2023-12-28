# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-12-29 01:06:16
# filename    : 2586-count-the-number-of-vowel-strings-in-range.py
# language    : Python
# editor      : Emacs 27.1
# -----------------------------------------


class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        ans = 0

        for i in range(left, right + 1):
            if words[i][0] in "aeiou" and words[i][-1] in "aeiou":
                ans += 1
        return ans
