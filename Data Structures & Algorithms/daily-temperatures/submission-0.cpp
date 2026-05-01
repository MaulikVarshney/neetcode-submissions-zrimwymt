class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);
        stack<int> st; // stores indices

        for(int i = n - 1; i >= 0; i--) {

            // pop all smaller or equal temperatures
            while(!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }

            // if stack not empty → next warmer exists
            if(!st.empty()) {
                res[i] = st.top() - i;
            }

            st.push(i);
        }

        return res;
    }
};