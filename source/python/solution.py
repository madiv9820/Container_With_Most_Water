"""
🧾 File Description:

Optimized Two Pointer solution for "Container With Most Water".

🎯 Idea:
Start with maximum width and move the pointer at the shorter line
to try improving the limiting height.

⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
"""

from typing import List

class pySolution:
    def py_maxArea(self, height: List[int]) -> int:

        # 🪣 Stores maximum water container capacity
        max_Container_Capacity: int = 0

        # 📍 Initialize two pointers
        start_Line: int = 0
        end_Line: int = len(height) - 1

        # 🔁 Process until pointers meet
        while start_Line < end_Line:

            # 📐 Calculate width
            container_Width: int = end_Line - start_Line

            # 📏 Height limited by shorter line
            container_Height: int = min(
                height[start_Line], 
                height[end_Line]
            )

            # 💧 Calculate area
            container_Capacity: int = container_Height * container_Width

            # 🏆 Update max capacity
            max_Container_Capacity = max(
                max_Container_Capacity, 
                container_Capacity
            )

            # 🚀 Move pointer at smaller height (core logic)
            if height[start_Line] < height[end_Line]: 
                start_Line += 1     # ➡️ try taller left wall
            else: 
                end_Line -= 1       # ⬅️ try taller right wall

        # ✅ Return maximum water stored
        return max_Container_Capacity