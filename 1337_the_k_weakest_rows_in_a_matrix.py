class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        forces = [(sum(a), i) for i, a in enumerate(mat)]
        forces.sort()
        return [forces[i][1] for i in range(0, k)]

