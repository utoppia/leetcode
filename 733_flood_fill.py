class Solution:
  def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
    n, m = len(image), 0
    if n > 0:
      m = len(image[0])
    
    def inImage(x, y):
      return x>=0 and x<n and y>=0 and y<m

    def dfs(image, sr, sc, newColor):
      dx = [1, -1, 0, 0]
      dy = [0, 0, 1, -1]
      p = image[sr][sc]
      if p == newColor:
        return False
      image[sr][sc] = newColor
      for i in range(0, 4):
        x = sr + dx[i]
        y = sc + dy[i]
        if inImage(x, y) and image[x][y] == p:
          dfs(image, x, y, newColor)
    
    dfs(image, sr, sc, newColor)
    return image
