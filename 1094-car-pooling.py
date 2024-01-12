class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        person = [0] * 1002
        for passenger, start, end in trips:
            person[start] += passenger
            person[end] -= passenger

        s = 0
        for a in person:
            s += a
            if s > capacity:
                return False
        return True

