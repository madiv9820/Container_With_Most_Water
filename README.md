# 🪣 Container With Most Water — Brute Force Approach 💧

### 🧠 Intuition

We are given an array where each element represents the height of a vertical line.
We need to pick **two lines** such that together with the x-axis, they form a container that holds the **maximum water**.

👉 The amount of water a container can store depends on:

- **📏 Width** → distance between two lines
- **📐 Height** → minimum of the two heights (shorter wall limits water)

#### 📦 Formula

```
water = (right_index - left_index) * min(height[left], height[right])
```

### 🔁 Approach: Brute Force (Exhaustive Search)

- Try **all possible pairs** of lines **`(i, j)`** where **`i < j`**
- For each pair:
    - Calculate width
    - Calculate height (minimum of two lines)
    - Compute water stored
- Keep track of the **maximum value**

### 🧩 Algorithm Steps

1. Initialize **`maxWater = 0`**
2. Loop through each index **`i`**
3. For each **`i`**, loop through all **`j > i`**
4. Compute:
    - width = **`j - i`**
    - height = **`min(height[i], height[j])`**
    - water = **`width * height`**
5. Update **`maxWater`**
6. Return **`maxWater`**

### 🧾 Pseudocode

```
FUNCTION maxArea(height):

    maxWater ← 0
    n ← length of height

    FOR i FROM 0 TO n - 2:
        FOR j FROM i + 1 TO n - 1:

            width ← j - i
            minHeight ← MIN(height[i], height[j])

            currentWater ← width * minHeight

            maxWater ← MAX(maxWater, currentWater)

    RETURN maxWater
```

#### 💡 Key Observations from Pseudocode

- 🔁 Two nested loops → all pairs are checked
- 📐 Width depends on index difference
- 📏 Height depends on shorter line
- 🏆 Track maximum continuously

#### 💻 Implementations

This approach is implemented in multiple languages:
- 🐍 Python (simple and readable)
- ⚙️ C++ (using vector)
- 🧱 C (using raw arrays + macros)

### 📊 Complexity Analysis

| **Metric**              | **Value**     |
| ------------------- | --------- |
| ⏱️ Time Complexity  | **O(n²)** |
| 📦 Space Complexity | **O(1)**  |

### ⚠️ Limitations

- ❌ Not efficient for large inputs
- ❌ Evaluates all possible pairs unnecessarily
- ❌ Can lead to **TLE (Time Limit Exceeded)** in interviews

### 💡 When to Use This Approach?

- ✅ When starting to understand the problem
- ✅ For explaining logic in interviews
- ✅ As a baseline before optimization

### 🚀 What’s Next?

This brute force approach helps build intuition, but it can be optimized.

👉 Next step: **Two Pointer Approach (O(n))** — avoids unnecessary checks and improves performance significantly.

---