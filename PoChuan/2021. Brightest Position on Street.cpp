class Solution {
public:

    // Maintain an array the store the start pos and end pos+1 of each light
    // every start pos we label it as 1 that represented it is coverd by a light
    // every end pos+1 we label it as -1 which represented it is end covered by a light
    // walk through the array and maintain a current bright and maxBright
    // once current bright is larger the maxBright
    // update maxBright and store the pos
    // when finish iterating, the pos would be the answer

    int brightestPosition(vector<vector<int>>& lights) {
        
        vector<pair<int, int>> street;
        for(auto l : lights) {

            street.push_back(make_pair(l[0]-l[1], 1));
            street.push_back(make_pair(l[0]+l[1]+1, -1));
        }

        sort(street.begin(), street.end());
        int bright = 0;
        int maxBright = INT_MIN;
        int retPos = 0;
        for(auto [pos, light]: street) {

            bright += light;
            if(bright > maxBright) {
                
                maxBright = bright;
                retPos = pos; 
            }
        }

        return retPos;
    }
};