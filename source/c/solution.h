#ifndef SOLUTION_H
#define SOLUTION_H

/*
🧾 File Description:

This header file implements a brute force solution for the
"Container With Most Water" problem using C.

It evaluates all possible pairs of vertical lines to compute
the maximum water that can be stored between them.

🎯 Purpose:
- Provide a simple baseline implementation in C
- Demonstrate low-level array handling
- Useful for performance comparison with Python/C++ versions

⚠️ Note:
Time Complexity: O(n^2)
Space Complexity: O(1)
*/


// 🔒 Safe macros with proper parentheses (avoid precedence bugs)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))


// ⚙️ Function to compute maximum container area
int maxArea(int* height, int heightSize) {

    // 🪣 Stores maximum water container capacity
    int max_Container_Capacity = 0;

    // 📏 Total number of vertical lines
    int total_Lines = heightSize;

    // 🔁 Loop variables
    int start_Line;
    int end_Line;

    // 📦 Temporary variables for calculation
    int container_Width;
    int container_Height;
    int container_Capacity;

    // 🔁 Iterate over all possible starting lines
    for (start_Line = 0; start_Line < total_Lines - 1; ++start_Line) {

        // 🔁 For each start line, check all lines to its right
        for (end_Line = start_Line + 1; end_Line < total_Lines; ++end_Line) {

            // 📐 Calculate width (distance between lines)
            container_Width = end_Line - start_Line;

            // 📏 Height limited by shorter line
            container_Height = MIN(height[start_Line], height[end_Line]);

            // 💧 Calculate container capacity
            container_Capacity = container_Width * container_Height;

            // 🏆 Update maximum capacity
            max_Container_Capacity = MAX(max_Container_Capacity, container_Capacity);
        }
    }

    // ✅ Return maximum water stored
    return max_Container_Capacity;
}

#endif