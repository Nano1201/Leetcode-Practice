class Solution {
public:

    // Since we only have to return the earliest year
    // We do not have to maintain a list to count all the range
    // We only have to conisder the birth year and death year
    // when we meet a birth day, we store it into a new array
    // and label it with number as 1 means there is 1 person alive
    // when we meet a death day, we store it and label it as -1
    // this is conisder as a person died
    // after stroring and label all the birth/death year
    // we sorted the array in increase order
    // and we itereate from the begining
    // We add the number we store, and update the max alive people
    // if current alive people is bigger


    int maximumPopulation(vector<vector<int>>& logs) {

        vector<pair<int, int>> l;
        for(auto e : logs) {

            l.push_back(make_pair(e[0], 1));
            l.push_back(make_pair(e[1], -1));
        }

        sort(l.begin(), l.end());
        int alive = 0;
        int maxAlive = INT_MIN;
        int yearRet = 0;

        for(auto [year, num] : l) {

            alive += num;
            if(alive > maxAlive) {

                maxAlive = alive;
                yearRet = year;
            }
        }
        return yearRet;
    }
};