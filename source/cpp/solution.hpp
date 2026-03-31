#ifndef SOLUTION_HPP
#define SOLUTION_HPP

/*
🧾 File Description:

This header file implements an optimized Two Pointer solution for the
"Container With Most Water" problem using C++.

🎯 Idea:
Start with maximum width and move the pointer at the smaller height
to try improving the limiting factor (height).

⚡ Complexity:
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        // 🪣 Stores maximum water container capacity
        int max_Container_Capacity = 0;

        // 📍 Initialize two pointers
        int start_Line = 0;
        int end_Line = height.size() - 1;

        // 🔁 Process until pointers meet
        while (start_Line < end_Line) {

            // 📐 Calculate width
            int container_Width = end_Line - start_Line;

            // 📏 Height limited by shorter line
            int container_Height = min(
                height[start_Line],
                height[end_Line]
            );

            // 💧 Calculate container capacity
            int container_Capacity = container_Width * container_Height;

            // 🏆 Update maximum capacity
            max_Container_Capacity = max(
                max_Container_Capacity,
                container_Capacity
            );

            // 🚀 Move pointer at smaller height (core logic)
            if (height[start_Line] < height[end_Line]){
                ++start_Line;   // ➡️ try better left wall
            }
            else{ 
                --end_Line;     // ⬅️ try better right wall
            }
        }

        // ✅ Return maximum water stored
        return max_Container_Capacity;
    }
};

#endif