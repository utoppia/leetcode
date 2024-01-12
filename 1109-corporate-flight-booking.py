class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        s = [0] * (n + 1)
        for l, r, seats in bookings:
            s[l-1] += seats
            s[r] -= seats

        ans = []
        tmp = 0
        for i in range(n):
            tmp += s[i]
            ans.append(tmp)
        return ans
