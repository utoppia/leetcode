class Solution:
  def getNumberOfBacklogOrders(self, orders: List[List[int]]) -> int:
    # heap
    buy_backlog = []
    sell_backlog = []

    for price, amount, order_type in orders:
      if order_type: # current order's type is sell
        while amount:
          if not buy_backlog: # Buy Backlog is empty
            break
          
          if -buy_backlog[0][0] < price:
            # largest price in buy order is less than current price
            break

          p, cnt = heapq.heappop(buy_backlog)
          if amount >= cnt:
            amount -= cnt
          else:
            heapq.heappush(buy_backlog, (p, cnt - amount))
            amount = 0

        if amount:
          heapq.heappush(sell_backlog, (price, amount))
      else: # current order's type is buy 
        while amount:
          if not sell_backlog:
            break

          if sell_backlog[0][0] > price:
            # samllest price in sell order is larger than current price
            break

          p, cnt = heapq.heappop(sell_backlog)
          if amount >= cnt:
            amount -= cnt
          else:
            heapq.heappush(sell_backlog, (p, cnt - amount))
            amount = 0

        if amount:
          heapq.heappush(buy_backlog, (-price, amount))

    return sum([item[1] for item in sell_backlog + buy_backlog]) % (10 ** 9 + 7)
