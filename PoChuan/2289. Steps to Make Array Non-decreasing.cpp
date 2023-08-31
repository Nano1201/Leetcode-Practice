class Solution {
public:

    // dp[i] means at element i, max round for i to eat the element it can eat
    // iterate from the back
    // use a stack to store those element that cannot been eat
    // if the current element i is suppose to eat the element on the top of the stack
    // the round should be max(dp[i]+1, dp[st.top()])
    // dp[i] + 1 means current eat the top
    // dp[st.top()] means the number of the top element has eaten
    // suppose current i already eat 3 element and the top element has only 1
    // this mean in the first round they both eat 1 element and the top element has no element to eat
    // then current element eat to 3 element then eat the top element so the result is 3 + 1
    // if current i eats 3 element and top element eat 5
    // this means after 3 round when the current element are going to eat the top element
    // there is still have two element left behind the top element hasen't been eat
    // note that top element is suppose to eat the left over element and the current can eat the top element
    // which means the current element > top element > left over element, so the result of current element
    // finish eating is dp[st.top()]. It finish itself's three element, and while it eat the top element
    // the top element eat an element too, after that it still have 1 left, the current element will finish it.

    int totalSteps(vector<int>& nums) {
        
        stack<int> st;
        vector<int> dp(nums.size());
        int cnt = 0;

        for(int i = nums.size()-1 ; i >= 0 ; i--){

            while(!st.empty() && nums[i] > nums[st.top()]) {

                dp[i] = max(dp[i]+1, dp[st.top()]);
                st.pop();
            }
            st.push(i);
            cnt = max(cnt, dp[i]);
        } 

        return cnt;
    }
};