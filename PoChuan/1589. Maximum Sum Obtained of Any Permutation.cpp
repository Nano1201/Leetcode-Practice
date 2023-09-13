class Solution {
public:

    // Calculate the frequency of which pos appears
    // assign the bigger number to the position with more frequency

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        
        long long mod = 1e9+7;

        // Calculate the frequency
        vector<int> freq(nums.size());

        for(auto req : requests) {

            freq[req[0]] += 1;
            if(req[1]+1 < nums.size())
                freq[req[1]+1] -= 1;
        }

        // build the frequency table
        for(int i = 1 ; i < freq.size() ; i++) {

            freq[i] += freq[i-1];
        }

        sort(nums.begin(), nums.end());
        sort(freq.begin(), freq.end());

        long long ret = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            
            ret += (long long)nums[i] * freq[i];
        }  

        return ret % mod;
    }
};