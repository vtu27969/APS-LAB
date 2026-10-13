class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result = prices;
        stack<int> st; // Stores indices

        for (int i = 0; i < prices.size(); ++i) {
            // Apply discount to previous elements if current price is <= previous price
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                result[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};