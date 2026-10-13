#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::deque<int> dq; // Stores indices of elements
        std::vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove indices that are out of the current window bound
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // 2. Remove elements smaller than the current element from the back
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add current element's index
            dq.push_back(i);
            
            // 4. Append maximum element for the current window (starts at i >= k - 1)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};