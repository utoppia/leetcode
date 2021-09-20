class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # monotonic stack

        # stack 'st' stores the answer
        st = []

        # n is the length of nums
        n = len(nums)

        # update k means that the length of 'st' is k
        k = n - k

        for i in range(n):
            digit = nums[i]
            while st and len(st) + n - i - 1 >= k and ord(st[-1]) > ord(digit):
                st.pop()

            if len(st) < k:
                st.append(digit)

        return str(int(''.join(st))) if st else "0"

