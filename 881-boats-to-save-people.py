class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        # greedy

        people.sort()
        ans, i, j = 0, 0, len(people) - 1

        while i <= j:
            if i == j:
                ans += 1
                i += 1
                j -= 1
            else:
                if people[i] + people[j] <= limit:
                    ans += 1
                    i += 1
                    j -= 1
                else:
                    ans += 1
                    j -= 1
        return ans
