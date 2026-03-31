#ifndef SOLUTION_H
#define SOLUTION_H

/*
🧾 File Description:

This header file implements an optimized Two Pointer solution for the
"Container With Most Water" problem using C.

🎯 Idea:
Start with maximum width and move the pointer at the smaller height
to try improving the limiting factor.

⚡ Complexity:
Time Complexity: O(n)
Space Complexity: O(1)
*/


// 🔒 Safe macros (avoid precedence bugs)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


// ⚙️ Function to compute maximum container area
int maxArea(int* height, int heightSize) {

    // 🪣 Stores maximum water container capacity
    int max_Container_Capacity = 0;

    // 📍 Initialize two pointers
    int start_Line = 0;
    int end_Line = heightSize - 1;

    // 📦 Temporary variables
    int container_Width;
    int container_Height;
    int container_Capacity;

    // 🔁 Process until pointers meet
    while (start_Line < end_Line) {

        // 📐 Calculate width
        container_Width = end_Line - start_Line;

        // 📏 Height limited by shorter line
        container_Height = MIN(
            height[start_Line],
            height[end_Line]
        );

        // 💧 Calculate container capacity
        container_Capacity = container_Width * container_Height;

        // 🏆 Update maximum capacity
        max_Container_Capacity = MAX(
            max_Container_Capacity,
            container_Capacity
        );

        // 🚀 Move pointer at smaller height (core logic)
        if (height[start_Line] < height[end_Line]) {
            ++start_Line;   // ➡️ move left pointer
        } else {
            --end_Line;     // ⬅️ move right pointer
        }
    }

    // ✅ Return maximum water stored
    return max_Container_Capacity;
}

#endif