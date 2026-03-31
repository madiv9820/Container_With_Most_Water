# 🪣 Container With Most Water — Two Pointers Approach 💧

### 🧠 Intuition

Instead of checking all possible pairs (O(n²)) ❌, we can **optimize** the solution using the **Two Pointers technique**.

#### 👉 Key idea:

- Start with the **maximum possible width**
- Gradually **shrink the window**
- Always try to **improve the limiting factor (height)**

#### 📦 Formula

```
water = (right_index - left_index) * min(height[left], height[right])
```

#### 🔥 One-Line Intuition

“Start with maximum width and move the pointer at the smaller height to improve the limiting factor.”

### 🚀 Approach: Two Pointers
- Initialize two pointers:
    - **`left = 0`**
    - **`right = n - 1`**
- At each step:
    1. Calculate current container area
    2. Update maximum if needed
    3. Move the pointer pointing to the **shorter height**

### 🔥 Core Logic

👉 Why move the smaller height?

- Water is limited by the **shorter wall**
- Moving the taller wall ❌ won’t help (height still limited)
- Moving the shorter wall ✅ may increase height

### 🧩 Algorithm Steps

1. Initialize **`maxWater = 0`**
2. Set **`left = 0`**, **`right = n - 1`**
3. While **`left < right`**:
    - width = **`right - left`**
    - height = **`min(height[left], height[right])`**
    - water = **`width * height`**
    - Update **`maxWater`**
    - Move:
        - If **`height[left] < height[right]`** → **`left++`**
        - Else → **`right--`**
4. Return **`maxWater`**

### 🧾 Pseudocode

```
FUNCTION maxArea(height):

    left ← 0
    right ← length(height) - 1
    maxWater ← 0

    WHILE left < right:

        width ← right - left
        minHeight ← MIN(height[left], height[right])

        currentWater ← width * minHeight
        maxWater ← MAX(maxWater, currentWater)

        IF height[left] < height[right]:
            left ← left + 1
        ELSE:
            right ← right - 1

    RETURN maxWater
```

#### 💡 Key Observations

- 📏 Start with maximum width
- 📉 Width decreases over time
- 📈 Try to increase minimum height
- 🎯 Greedy decision at each step

### 📊 Complexity Analysis

| **Metric**              | **Value**    |
| ------------------- | -------- |
| ⏱️ Time Complexity  | **O(n)** |
| 📦 Space Complexity | **O(1)** |

### ⚠️ Common Mistakes

- ❌ Moving the taller pointer
- ❌ Moving both pointers at once
- ❌ Forgetting **`min(height[left], height[right])`**

### 🏁 Summary

- ⚡ Optimized approach using Two Pointers
- 🎯 Focus on improving limiting height
- 🚀 Linear time complexity
- 💯 Interview favorite solution

---