class Solution {
public:


    // use a single array ret to store the value
    // first we store the start time of updates with inc value
    // next we store the end+1 time of updates with -inc value
    // we later are going to interate through the array
    // and add the current position with the previous(ret[i] + ret[i-1])
    // this is why we put -inc value in the array
    // when we iterate until end+1, means the current position(end+1)
    // is not going to add the value inc, so we decrease it
    // after iterate it, we can get the result

    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
        vector<int> ret(length+1, 0);

        for(auto op : updates) {

            ret[op[0]] += op[2];
            ret[op[1]+1] -= op[2];
        }

        for(int i = 1 ; i < length ; i++) {

            ret[i] += ret[i-1];
        }

        ret.pop_back();
        return ret;
    }
};