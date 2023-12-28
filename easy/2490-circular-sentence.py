# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-12-29 00:20:48
# filename    : 2490-circular-sentence.py
# language    : py
# -----------------------------------------


class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        s = sentence.split()
        if s[0][0] != s[-1][-1]:
            return False

        for i in range(len(s) - 1):
            if s[i][-1] != s[i + 1][0]:
                return False

        return True
