# time: O(n)
# space: O(1)
class Solution:
    def minPartitions(self, n: str) -> int:
        return int(max(n))
        """
        max_num = 0
        for i in n:
            if int(i) > max_num:
                max_num = int(i)
        return max_num
        """