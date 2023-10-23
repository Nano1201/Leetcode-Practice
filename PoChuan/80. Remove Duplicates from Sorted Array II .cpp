class Solution {
public:

    // Use two pointer, once we met an element that is dupicate, then we
    // set a pointer to the position and wait for another pointer to find
    // a larger element then swap it.
    int removeDuplicates(vector<int>& nums) {
        
        int dup = 0;
        for(auto e : nums) {

            if(dup < 2 || e > nums[dup-2])
                nums[dup++] = e;
        }

        return dup;
    }
};