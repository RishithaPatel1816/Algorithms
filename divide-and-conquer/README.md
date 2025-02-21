# Divide and Conquer Algorithms

## Kth Smallest Element using Median of Medians (MoM)

### Problem Statement
Given an unsorted array of `n` elements, find the **kth smallest element** efficiently in **O(n) worst-case time complexity** using the **Median of Medians (MoM) Algorithm**.

### Approach: Median of Medians (Divide and Conquer)
The **MoM algorithm** improves upon QuickSelect by ensuring a good pivot selection, reducing the chances of worst-case behavior. It guarantees **O(n) worst-case time complexity** by selecting the pivot more deterministically.

### Steps:
1. **Divide the array into groups of 5 elements.**
2. **Find the median of each group** by sorting and selecting the middle element.
3. **Find the median of these medians (MoM)** recursively.
4. **Partition the array** around the MoM pivot.
5. **Recursive case:**
   - If `k` matches the pivot position, return the pivot.
   - If `k` is smaller, search in the left partition.
   - If `k` is larger, search in the right partition.

### Recurrence Relation
\[
T(n) = T(n/5) + T(7n/10) + O(n)
\]
This simplifies to **O(n) worst-case time complexity**.

## Example Execution
### Input:
```
n = 10
arr = [12, 3, 5, 7, 19, 26, 23, 8, 15, 2]
k = 4
```
### Steps:
```
1. Divide into groups of 5: [12, 3, 5, 7, 19] and [26, 23, 8, 15, 2]
2. Find medians: [7, 15]
3. Find median of medians: 7
4. Partition around 7 → Left: [3, 5, 2], Right: [12, 19, 26, 23, 8, 15]
5. Recursively find the 4th smallest in the right partition.
6. Output: 8
```
### Output:
```
4-th smallest number in the array is 8
```

## Time Complexity Analysis
| Approach        | Time Complexity |
|----------------|---------------|
| Naive Sorting  | \( O(n \log n) \) |
| QuickSelect (Worst) | \( O(n^2) \) |
| QuickSelect (Average) | \( O(n) \) |
| Median of Medians | \( O(n) \) |

## Number of Inversions in an Array (Using Merge Sort)

### Problem Statement
Given an array of `n` integers, count the **number of inversions**, where an inversion is a pair `(i, j)` such that `i < j` and `arr[i] > arr[j]`. This measures ranking similarity between two orderings.

### Approach: Merge Sort (Divide and Conquer)
Instead of using a brute-force `O(n^2)` approach, we can efficiently count inversions while sorting the array using **Merge Sort**.

### Steps:
1. **Divide**: Split the array into two halves.
2. **Conquer**: Recursively count inversions in both halves.
3. **Combine**: Count cross-inversions while merging the two halves.
   - If `arr[i] > arr[j]`, all remaining elements in the left half after `i` are also greater than `arr[j]`, contributing to inversions.
4. **Base Case Optimization**: If the subarray size is small (e.g., <10 elements), use a brute-force method for efficiency.

### Recurrence Relation
\[
T(n) = 2T(n/2) + O(n)
\]
This results in a **time complexity** of **O(n log n)**.

## Example Execution
### Input:
```
n = 5
arr = [5, 3, 2, 4, 1]
```
### Steps:
```
Splitting: [5, 3, 2] and [4, 1]
Splitting further: [5, 3] [2] and [4] [1]
Merging:
  [5] and [3] → Inversion Count = 1
  [3, 5] and [2] → Inversion Count = 2
  [4] and [1] → Inversion Count = 1
  [2, 3, 5] and [1, 4] → Inversion Count = 4
Total Inversions = 8
```
### Output:
```
Number of inversions: 8
```

## Time Complexity Analysis
| Approach        | Time Complexity |
|----------------|---------------|
| Brute Force  | \( O(n^2) \) |
| Merge Sort Approach | \( O(n \log n) \) |

# Closest Pair of Points (Divide and Conquer)

## Problem Statement  
Given `n` points on a 2D plane, find the smallest Euclidean distance between any two points.  

### Example  
**Input:**  
```plaintext
5  
2 3  
12 30  
40 50  
5 1  
12 10  
```
**Output:**  
```plaintext
Smallest distance is 1.41421
```
This means the closest two points are at a distance of **1.41421** (sqrt(2)).

## Approach  

### Brute Force Method (O(n²))  
- When `n` is small (≤5), we calculate distances for all pairs using a nested loop.  

### Divide and Conquer Method (O(n log n))  
- The set of points is sorted by x-coordinates.
- The midpoint is chosen, and we recursively find the smallest distance in the left and right halves.
- A strip region is considered to check for closer pairs across the dividing line.
- The final answer is the minimum of:
  1. The closest pair in the left half.
  2. The closest pair in the right half.
  3. The closest pair in the strip.

## Complexity Analysis  
- **Sorting** takes `O(n log n)`.
- **Divide and conquer recursion** works in `T(n) = 2T(n/2) + O(n)`, which solves to **O(n log n)**.
- The strip checking step runs in **O(n)**.

Overall, the time complexity is **O(n log n)**, which is much faster than brute force (`O(n²)`) for large `n`.

## Example  
### Input  
```plaintext
6  
2 3  
12 30  
40 50  
5 1  
12 10  
3 4  
```
### Output  
```plaintext
Smallest distance is 1.00000
```
 
# Tower of Hanoi (Divide and Conquer Approach)
## Problem Statement
The **Tower of Hanoi** is a classic mathematical problem that involves moving a set of disks from one rod to another following specific rules. It demonstrates the power of recursion and is a perfect example of the **Divide and Conquer** approach.

## Rules
1. Only one disk can be moved at a time.
2. A disk can only be placed on top of a larger disk or an empty rod.
3. All disks must be moved from the source rod to the destination rod using the helper rod.

## Approach: Divide and Conquer
The problem is solved recursively using the **Divide and Conquer** strategy:

1. **Divide:**  
   - Move the top `n-1` disks from the **source** rod to the **helper** rod using the **destination** rod.

2. **Conquer:**  
   - Move the largest `nth` disk directly from the **source** rod to the **destination** rod.

3. **Combine:**  
   - Move the `n-1` disks from the **helper** rod to the **destination** rod using the **source** rod.

### Recurrence Relation
\[
T(n) = 2T(n-1) + 1
\]
The number of moves required to solve the problem for `n` disks is:
\[
2^n - 1
\]

## Example Execution
### Input:
```
n = 3
```
### Steps:
```
Move disk 1 from r1 to r3
Move disk 2 from r1 to r2
Move disk 1 from r3 to r2
Move disk 3 from r1 to r3
Move disk 1 from r2 to r1
Move disk 2 from r2 to r3
Move disk 1 from r1 to r3
```
### Output:
```
Steps taken is 7
```

## Time Complexity Analysis
| Approach        | Time Complexity |
|----------------|---------------|
| Recursive Method | \( O(2^n) \) |

This exponential complexity makes the problem infeasible for large values of `n`.


## Efficient Exponentiation using Divide and Conquer
### Problem Statement
Given two integers, `a` (the base) and `k` (the exponent), compute \( a^k \) efficiently using a **Divide and Conquer** approach.

### Approach: Exponentiation by Squaring
Instead of multiplying `a` by itself `k` times (which would take \( O(k) \) time), we use a recursive method that reduces the problem size at each step. The approach follows these rules:

1. **Divide:**  
   - Compute \( a^{k/2} \) recursively.

2. **Conquer:**  
   - If `k` is even, then \( a^k = (a^{k/2})^2 \).
   - If `k` is odd, then \( a^k = (a^{k/2})^2 \times a \).

3. **Combine:**  
   - Return the computed result.

### Recurrence Relation
\[
T(k) = T(k/2) + O(1)
\]
This results in a **time complexity of** \( O(\log k) \).

### Example Execution
#### Input:
```
2 10
```
#### Steps (Recursive Calls):
1. `findexponent(2, 10)`  
   - `findexponent(2, 5)`  
     - `findexponent(2, 2)`  
       - `findexponent(2, 1) \to 2`
       - Compute \( 2^2 = 4 \)  
     - Compute \( 4^2 \times 2 = 32 \)  
   - Compute \( 32^2 = 1024 \)  

#### Output:
```
2 power 10 is 1024
```

### Time Complexity Analysis
| Approach        | Time Complexity |
|----------------|---------------|
| Naive Method (Loop) | \( O(k) \) |
| Recursive Method (Exponentiation by Squaring) | \( O(\log k) \) |


## Efficient Exponentiation using Divide and Conquer

### Problem Statement
Given two integers, `a` (the base) and `k` (the exponent), compute \( a^k \) efficiently using a **Divide and Conquer** approach.

### Approach: Exponentiation by Squaring
Instead of multiplying `a` by itself `k` times (which would take \( O(k) \) time), we use a recursive method that reduces the problem size at each step. The approach follows these rules:

1. **Divide:**  
   - Compute \( a^{k/2} \) recursively.

2. **Conquer:**  
   - If `k` is even, then \( a^k = (a^{k/2})^2 \).
   - If `k` is odd, then \( a^k = (a^{k/2})^2 \times a \).

3. **Combine:**  
   - Return the computed result.

### Recurrence Relation
\[
T(k) = T(k/2) + O(1)
\]
This results in a **time complexity of** \( O(\log k) \).

### Example Execution
#### Input:
```
2 10
```
#### Steps (Recursive Calls):
1. `findexponent(2, 10)`  
   - `findexponent(2, 5)`  
     - `findexponent(2, 2)`  
       - `findexponent(2, 1) \to 2`
       - Compute \( 2^2 = 4 \)  
     - Compute \( 4^2 \times 2 = 32 \)  
   - Compute \( 32^2 = 1024 \)  

#### Output:
```
2 power 10 is 1024
```

### Time Complexity Analysis
| Approach        | Time Complexity |
|----------------|---------------|
| Naive Method (Loop) | \( O(k) \) |
| Recursive Method (Exponentiation by Squaring) | \( O(log k) \) |

