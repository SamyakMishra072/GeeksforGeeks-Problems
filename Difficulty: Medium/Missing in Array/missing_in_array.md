# Missing in Array: Find the missing element in a permutation

## 🔗 Problem Statement

You are given an array `arr[]` of size $n-1$ that contains **distinct integers** in the range from $1$ to $n$ (inclusive). This array represents a permutation of the integers from $1$ to $n$ with **exactly one element missing**.

Your task is to identify and return the missing element.

### Examples

| Input Array (`arr[]`) | Range ($1$ to $n$) | Output | Explanation |
| :--- | :--- | :--- | :--- |
| `[1, 2, 3, 5]` | $1$ to $5$ | $4$ | All numbers from $1$ to $5$ are present except $4$. |
| `[8, 2, 4, 5, 3, 7, 1]` | $1$ to $8$ | $6$ | All numbers from $1$ to $8$ are present except $6$. |
| `[1]` | $1$ to $2$ | $2$ | Only $1$ is present, so the missing element is $2$. |

### Constraints

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le \text{arr}[i] \le \text{arr.size()} + 1$
* **Expected Complexity:** An efficient solution ($O(N)$ time complexity) is required for large inputs.

---

## 💡 Solution: Summation Method (Optimal $O(N)$)

The most efficient way to solve this is by using the mathematical properties of the numbers in the sequence.

### Method Overview

We can find the missing number by comparing the **expected sum** of all numbers from $1$ to $n$ with the **actual sum** of the elements present in the array.

1.  **Calculate $n$**: The full range of numbers is $1$ to $n$, where $n = \text{arr.size()} + 1$.
2.  **Calculate Expected Sum**: Use the formula for the sum of the first $n$ natural numbers:
    $$\text{Expected Sum} = \frac{n \times (n+1)}{2}$$
3.  **Calculate Actual Sum**: Sum all elements present in the input array.
4.  **Find Missing Element**: The missing element is the difference between the two sums:
    $$\text{Missing Element} = \text{Expected Sum} - \text{Actual Sum}$$

### ⚠️ Data Type Consideration

Since the array size can be up to $10^6$, the expected sum can exceed the capacity of a standard 32-bit integer (`int`). To prevent **integer overflow**, we must use the **`long long`** data type in C++ for storing and calculating the sums.


Time Complexity,O(N);
Space Complexity,O(1);