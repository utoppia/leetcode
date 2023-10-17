# -----------------------------------------
# author      : utoppia
# description : solution for leetcode
# updated at  : 2023-10-18 00:47:55
# filename    : 504-base-7.py
# language    : py
# -----------------------------------------


class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"
        ret = ""
        n = abs(num)
        while n > 0:
            ret = str(n % 7) + ret
            n //= 7
        if num < 0:
            ret = "-" + ret
        return ret
