# solution dp
# time: O(log(n)) ?
# space: O(log(n)) ?
"""
class Solution:
    def integerReplacement(self, n: int) -> int:
        @cache

        def rec(k):

            if k == 1:
                return 0
            if k%2 == 0:
                return 1+rec(k//2)
            else:
                return 1+min(rec(k-1), rec(k+1))
        
        return rec(n)
"""
# solution greedy
# time: O(log(n)) ?
# space: O(1) ?

class Solution:
    def integerReplacement(self, n: int) -> int:
        cnt = 0
        while n > 1:
            cnt+=1
            if n%2 == 0:
                n/=2
            elif (n-1)%4 == 0 or n == 3: 
                n-=1                    
            else: 
                n+=1
        return cnt