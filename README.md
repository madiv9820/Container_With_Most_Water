# [🪣 Container With Most Water](https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150)

Imagine you’re given an array called **`height`** with **`n`** numbers. Each number represents the height of a vertical line drawn on a graph 📊.

The position of each line is its index 📍
So the line at index **`i`** goes from **(i, 0)** up to **(i, height[i])**

Now here’s the interesting part 👇

### 🎯 Your Goal

Pick **any two lines** such that together with the x-axis, they form a container that can hold water 💧

But wait… there’s a catch ⚠️
- The container **cannot be tilted** (no slanting allowed 🚫)

### 📏 How is water stored?

The amount of water the container can hold depends on:
- The **distance between the two lines** (width) ↔️
- The **shorter of the two heights** (since water spills over the shorter wall) ⬇️

### 🎯 What You Need to Do

Find the **maximum amount of water** that can be stored by choosing the best possible pair of lines 🏆

### 🧪 Example 1
```
Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

💡 In this case, selecting the right pair of lines forms a container that can hold **49 units of water**

### 🧪 Example 2
```
Input:  height = [1,1]
Output: 1
```

### 📌 Constraints
- **`2 <= n <= 100000`**
- **`0 <= height[i] <= 10000`**

## 🚴🏽‍♂️ Approaches

| **Feature**             | 🐌 [**Brute Force**](https://github.com/madiv9820/Container_With_Most_Water/tree/Approach_01-Brute_Force)                       | 🚀 [**Two Pointers**](https://github.com/madiv9820/Container_With_Most_Water/tree/Approach_02-Two_Pointers)                      |
| ------------------- | ------------------------------------ | ------------------------------------ |
| 🧠 Idea             | Check all possible pairs             | Greedy elimination of useless pairs  |
| 🔁 Approach         | Nested loops (i, j)                  | Start from both ends and move inward |
| ⏱️ Time Complexity  | **O(n²)** ❌                          | **O(n)** ✅                           |
| 📦 Space Complexity | **O(1)**                             | **O(1)**                             |
| 📏 Width Handling   | Explicitly calculated for every pair | Starts maximum, then shrinks         |
| 📐 Height Handling  | Uses `min(height[i], height[j])`     | Same, but optimized selection        |
| ⚡ Efficiency        | Slow for large inputs                | Very fast 🚀                         |
| 🧩 Implementation   | Simple                               | Slightly tricky (requires intuition) |
| 🎯 Optimality       | ❌ Not optimal                        | ✅ Optimal solution                   |
| 🧪 Use Case         | Learning / baseline                  | Production / interviews              |

#### 💡 Key Takeaway

- 🐌 Brute Force → Try everything
- 🚀 Two Pointers → Think smart, skip useless work

#### 🧠 One-Line Difference

“Brute force checks all pairs, while two pointers intelligently eliminate pairs that cannot give a better result.”

---