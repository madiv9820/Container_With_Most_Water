"""
🧾 File Description:

This module provides a Cython wrapper to interface Python with a C-based
implementation of the "Container With Most Water" problem.

It converts a Python list into a C-style integer array and calls the
`maxArea` function defined in `solution.h`.

🎯 Purpose:
- Leverage fast C execution for computation
- Provide a simple Python-accessible interface
- Handle manual memory management safely
"""

from libc.stdlib cimport calloc, free

# 🔗 Link with C header file
cdef extern from 'solution.h':
    int maxArea(int* height, int heightSize)


# 🐍➡️⚙️ Python wrapper class for C function
cdef class cSolution:

    def c_maxArea(self, height):
        """
        📌 Wrapper function to call C maxArea from Python

        Args:
            height (list[int]): Python list of heights

        Returns:
            int: Maximum water container area
        """

        # 📏 Get size of input list
        cdef int c_heightSize = len(height)

        # 🧱 Allocate memory for C array (zero-initialized)
        cdef int* c_height = <int*> calloc(c_heightSize, sizeof(int))

        # 📦 Variable to store result
        cdef int result = 0

        # ✅ Ensure memory allocation succeeded
        if c_height is not NULL:

            # 🔄 Copy Python list → C array
            # Required because C functions cannot directly use Python lists
            for i in range(c_heightSize):
                c_height[i] = height[i]

            # ⚙️ Call C implementation
            result = maxArea(c_height, c_heightSize)

            # 🧹 Free allocated memory (important to avoid leaks)
            free(c_height)

        return result