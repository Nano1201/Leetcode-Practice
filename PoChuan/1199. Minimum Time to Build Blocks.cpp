class Solution {
public:

    // Greedy
    // put blocks into a priority queue in increase order
    // pick the smallest two element
    // add the bigger with split and push it back to the queue
    // repeat it until only one element in the queue
    int minBuildTime(vector<int>& blocks, int split) {

        priority_queue<int, vector<int>, greater<int>> pq(blocks.begin(), blocks.end());

        while(pq.size() > 1) {

            auto top = pq.top();
            pq.pop();
            auto next = pq.top();
            pq.pop();
            pq.push(split+max(top, next));
        }
        return pq.top();
    }
};