# solution 1: dp
# time : O(nlogn + n^2)
# space: O(n^2)

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:

# solution 2: greedy
# time: O(nlogn + n)
# space: O(1)
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x:x[1])
        cur, ans = float('-inf'), 0
        for pair in pairs:
            if cur < pair[0]:
                cur = pair[1]
                ans += 1
        return ans