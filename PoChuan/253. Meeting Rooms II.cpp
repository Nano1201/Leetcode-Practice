class Solution {
public:

    // Store the start/end time in a table and label it with 1 & -1
    // means when ecounter the start time we should assign a room,
    // if we reach the end time a free the room
    // after builing the table, we sort the table
    // the sorted table make sure we do not miss any intervals that is overlap
    // iterate through the table and count the label

    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<pair<int, int>> times;
        for(auto time : intervals) {

            times.push_back(make_pair(time[0], 1));
            times.push_back(make_pair(time[1], -1));
        }

        sort(times.begin(), times.end());
        int ret = 0;
        int currentCnt = 0;
        for(auto [time, cnt] : times) {

            currentCnt += cnt;
            ret = max(ret, currentCnt);
        } 

        return ret;
    }
};