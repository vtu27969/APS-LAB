#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> answer(n, 0);
        std::stack<int> st; // Stores indices of temperatures

        for (int i = 0; i < n; ++i) {
            // While the current temperature is warmer than the temperature at the index on top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex; // Distance to the warmer day
            }
            st.push(i);
        }

        return answer;
    }
};