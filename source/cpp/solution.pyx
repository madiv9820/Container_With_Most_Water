"""
🧾 File Description:

This module acts as a Cython wrapper to bridge Python and C++ for solving
the "Container With Most Water" problem efficiently.

It interfaces with the C++ `Solution` class defined in `solution.hpp`
and exposes the `maxArea` method to Python.

Key Responsibilities:
- 🔁 Converts Python list → C++ vector[int]
- ⚙️ Invokes high-performance C++ logic
- 🧹 Manages memory for C++ object lifecycle

🎯 Purpose:
Leverage C++ speed for computation while keeping a clean Python interface
for testing and integration.
"""

from libcpp.vector cimport vector

# 🔗 Link Cython with C++ header file
cdef extern from 'solution.hpp':
    
    # 🧠 C++ Solution class declaration
    cdef cppclass Solution:
        Solution() except +                 # Constructor (handles C++ exceptions)
        int maxArea(vector[int]& height)   # Function to compute max water


# 🐍➡️⚙️ Python wrapper class for C++ Solution
cdef class cppSolution:
    
    cdef Solution *ptr   # Pointer to C++ Solution object

    def __init__(self):
        # 🚀 Allocate memory for C++ Solution object
        self.ptr = new Solution()

    def __dealloc__(self):
        # 🧹 Free allocated memory to prevent memory leaks
        if self.ptr:
            del self.ptr

    def cpp_maxArea(self, height):
        """
        📌 Wrapper function to call C++ maxArea from Python

        Args:
            height (list[int]): Python list of heights

        Returns:
            int: Maximum water container area
        """

        # 📦 Create a C++ vector to store heights
        cdef vector[int] cpp_height

        # 🔄 Convert Python list → C++ vector
        for i in range(len(height)):
            cpp_height.push_back(height[i])

        # ⚙️ Call C++ function and return result
        return self.ptr.maxArea(cpp_height)