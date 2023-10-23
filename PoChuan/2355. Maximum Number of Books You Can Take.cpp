class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        
        long long res = 0;
        vector<long long> dp(books.size(), 0);
        stack<int> st;

        auto sum = [](long long n) -> long long{

            if(n < 0)
                return 0;

            long long res = n * (n+1) / (long long)2;
            return res;
        };


        for(int i = 0 ; i < books.size() ; i++) {

            while(!st.empty() && books[st.top()] >= books[i] - i + st.top())
                st.pop();    
            
            long long s1;
            long long s2;

            s1 = st.empty()? 0 : dp[st.top()];
            s2 = sum(books[i]) - sum(books[i] - i + (st.empty()? -1 : st.top()));

            dp[i] = s1 + s2;

            res = max(res, dp[i]);
            st.push(i);
        }

        return res;
    }
};