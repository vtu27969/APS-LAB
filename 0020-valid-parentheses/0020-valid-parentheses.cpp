#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // For closing brackets, check if stack is empty or top doesn't match
            else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                
                st.pop(); // Matching pair found
            }
        }
        
        // If stack is empty, all brackets were validly closed
        return st.empty();
    }
};