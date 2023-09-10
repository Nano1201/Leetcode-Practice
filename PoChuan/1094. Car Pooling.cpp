class Solution {
public:

    // Store the start pos and end pos of the trips
    // the start pos will label as numPassengers
    // the end pos will label as -numPassengers
    // this means at the start pos there is numPassengers on the car
    // at the end pos, numPassengers will left the car

    // sort the stored array
    // iterate from the begining and maintain a counter to count the # passengers
    // once the counter is latger than the capacity we return false 
    // if we fininsh iterating the array means it doesn't exceed the capacity

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<pair<int, int>> drive;
        for(auto trip : trips) {

            drive.push_back(make_pair(trip[1], trip[0]));
            drive.push_back(make_pair(trip[2], -trip[0]));
        }

        sort(drive.begin(), drive.end());
        int numPassengers = 0;
        for(auto [pos, num] : drive) {

            numPassengers += num;
            if(numPassengers > capacity)
                return false;
        }

        return true;
    }
};