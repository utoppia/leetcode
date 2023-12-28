# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-12-29 00:42:56
# filename    : 2515-shortest-distance-to-target-string-in-a-circular-arra.py
# language    : Python
# editor      : Emacs 27.1
# -----------------------------------------


class Solution:
    def closetTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if target not in words:
            return -1

        n = len(words)

        step = 0
        cur = startIndex
        while words[cur] != target:
            step += 1
            cur = (cur + 1) % n

        steq = 0
        cur = startIndex
        while words[cur] != target:
            steq += 1
            cur = (cur - 1 + n) % n

        return min(step, steq)
