class StockSpanner:

    def __init__(self):
        self.st = [(float('inf'), 0)]
        self.pos = 0

    def next(self, price: int) -> int:
        self.pos += 1

        while self.st and self.st[-1][0] <= price:
            self.st.pop()

        ans = self.pos - self.st[-1][1]
        
        self.st.append((price, self.pos))
        
        return ans


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
