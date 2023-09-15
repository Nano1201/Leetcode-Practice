# solution 1: normal dp
# Time: O(n^2)
# Space: O(n^2)
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = [[0]*n for _ in range(n)]

        for idx, num in enumerate(piles):
            dp[idx][idx] = num

        for d in range(1,n):
            for i in range(0, n-d):
                j = i+d
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])

        return dp[0][n-1] > 0


# solution 2: 2-d dp
# Time: O(n^2)
# Space: O(n)
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        n = len(piles)
        dp = piles.copy()

        for d in range(1,n):
            for j in range(n-1, d-1, -1):
                i = j-d
                dp[j] = max(piles[j] - dp[j-1],  piles[i] - dp[j])
        return dp[n-1] > 0

# solution 3:
class Solution:
    def stoneGame(self, piles: List[int]) -> bool:
        return True
