# time: O(nlogn)
# space: O(1)

class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()

        cnt = 0
        for i in range(0, len(nums)-1):
            pick_num = i+1
            if nums[i] < pick_num < nums[i+1] : # nums[i] < pick_num: make sure happy
                cnt+=1                          # nums[i+1] > pick_num: make sure unhappy

        if min(nums) > 0: # select no one
            cnt += 1 
        if max(nums) < len(nums): # select everyone
            cnt += 1
        return cnt
        #0 2 3 3 6 6 7 7 
        #1 2 3 4 5 6 7 8

        #0 1 1 1
        #1 2 3 4