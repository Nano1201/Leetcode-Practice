class Solution {
public:

    // We label the first and last position as seats and -seats
    // which represent the number of seats in range[first~last]
    // after labeling, we sum up the array with ret[i] += ret[i-1]

    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        vector<int> ret(n+1, 0);
        for(auto books : bookings) {

            ret[books[0]-1] += books[2];
            ret[books[1]-1+1] -= books[2];
        }

        for(int i = 1 ; i < ret.size() ; i++) {

            ret[i] += ret[i-1];
        }

        ret.pop_back();

        return ret;
    }
};