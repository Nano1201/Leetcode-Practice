class Solution {
public:

    #define ll long long

    // Greedy: Sort the array in increase order, start eating from the smallest
    // If there is one that cannot eat, means can't finish all of them
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        ll sum = mass;

        for(auto e : asteroids) {

            if(sum >= e) {

                sum += e;
            }
            else {

                return false;
            }
        }

        return true;
    }
};