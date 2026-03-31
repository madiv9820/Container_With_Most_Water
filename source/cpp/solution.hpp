#ifndef SOLUTION_HPP
#define SOLUTION_HPP

/*
🧾 File Description:

This header file implements a brute force solution for the
"Container With Most Water" problem using C++.

It evaluates all possible pairs of vertical lines to compute
the maximum water that can be stored between them.

🎯 Purpose:
- Provide a simple baseline approach
- Help understand problem fundamentals before optimization
- Useful for comparison with optimized solutions

⚠️ Note:
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <vector>
#include <algorithm>   // 📌 Required for min() and max()

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        // 🪣 Stores maximum water container capacity
        int max_Container_Capacity = 0;

        // 📏 Total number of vertical lines
        int total_Lines = height.size();

        // 🔁 Iterate over all possible starting lines
        for (int start_Line = 0; start_Line < total_Lines - 1; ++start_Line) {

            // 🔁 For each start line, check all lines to its right
            for (int end_Line = start_Line + 1; end_Line < total_Lines; ++end_Line) {

                // 📐 Calculate width between two lines
                int container_Width = end_Line - start_Line;

                // 📏 Height limited by shorter line
                int container_Height = min(height[start_Line], height[end_Line]);

                // 💧 Calculate container capacity (area)
                int container_Capacity = container_Height * container_Width;

                // 🏆 Update maximum capacity if needed
                max_Container_Capacity = max(max_Container_Capacity, container_Capacity);
            }
        }

        // ✅ Return maximum water stored
        return max_Container_Capacity;
    }
};

#endif