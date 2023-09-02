class Solution {
public:

    // Use & operation to check if the bit is 1
    vector<int> countBits(int n) {
        
        vector<int> ret(n+1);
        for(int i = 0 ; i <= n ; i++) {

            int cnt = 0;
            for(int j = 0 ; j < 32 ; j++) {

                if(i & (1 << j)) {

                    cnt++;
                }
            }
            ret[i] = cnt;
        }
        return ret;
    }
};