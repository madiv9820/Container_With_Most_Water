"""
🧾 File Description:

This module implements a brute force solution for the
"Container With Most Water" problem using Python.

It evaluates all possible pairs of lines to calculate
the maximum water that can be stored between them.

🎯 Purpose:
- Provide a simple and intuitive baseline approach
- Help understand the problem before optimization
- Useful for learning and interview explanation

⚠️ Note:
This approach is not optimal due to its O(n²) time complexity.
"""

from typing import List

class pySolution:
    def py_maxArea(self, height: List[int]) -> int:
        
        # 🪣 Stores the maximum water container capacity found so far
        max_Container_Capacity: int = 0

        # 📏 Total number of vertical lines
        total_Lines: int = len(height)

        # 🔁 Iterate over all possible starting lines
        for start_Line in range(total_Lines - 1):

            # 🔁 For each start line, check all lines to its right
            for end_Line in range(start_Line + 1, total_Lines):

                # 📐 Calculate width (distance between two lines)
                container_Width: int = end_Line - start_Line

                # 📏 Height is limited by the shorter line (water overflow logic)
                container_Height: int = min(height[start_Line], height[end_Line])

                # 💧 Calculate container capacity (area)
                container_Capacity: int = container_Height * container_Width

                # 🏆 Update maximum capacity if current is greater
                max_Container_Capacity = max(max_Container_Capacity, container_Capacity)

        # ✅ Return the maximum water that can be stored
        return max_Container_Capacity