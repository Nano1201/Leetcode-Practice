class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        // impossible to make two array equal
        // if min sum of bigger size array if greater than max sum of smaller size array
        // it is impossible to make it equal

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(min(n1,n2)*6 < max(n1,n2)*1)
            return -1; 

        // possible to make two array equal
        // Let nums1 be the smaller sum array
        // the answer should be in the range s1 < ans < s2
        // for s1 array, we only increase it and vice versa
        // sort two array, smaller in increase order
        // lager in decrease order
        // use two pointer i, j to iterate two array
        // check the different between two sum
        // check the different in two array with position i, j
        // for the smaller array, we check the different 6-nums[i]
        // for the larger we check nums[i]-1
        // pick the different that is larger and check it is smaller than the sum diff
        // or we just have to change the number to num - diff;
        // repeat it until s1 = s2

        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);

        if(s1 > s2) {

            swap(nums1, nums2);
            swap(s1, s2);
            swap(n1, n2);
        }
        else if(s1 == s2) {

            return 0;
        }


        sort(nums1.begin(), nums1.end());
        sort(nums2.rbegin(), nums2.rend());

        int i = 0;
        int j = 0;
        int ret = 0;

        int diff = 0;
        int d1 = 0;
        int d2 = 0;
        int d = 0;
        while(s1 != s2) {

            diff = s2-s1;

            d1 = (i == n1 ? 0: 6-nums1[i]);
            d2 = (j == n2 ? 0: nums2[j]-1);
            d = min(diff, max(d1, d2));

            if(d1 >= d2) {

                s1 += d;
                i++;
            }
            else {

                s2 -=d;
                j++;
            }
            ret++;
        }

        return ret;
    }
};