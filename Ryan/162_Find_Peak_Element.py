# solution 1 - linear scan
# Time: O(n)
# Space: O(1)

# solution 2 - binary search
# Time: O(logn)
# Space: O(1)
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)-1
        while l<r:
            m = (l+r)//2
            if nums[m]>nums[m+1]:
                r = m
            else:
                l = m+1
        return l
        