<h2><a href="https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps">2106. Maximum Fruits Harvested After at Most K Steps</a></h2><h3>Hard</h3><hr><p>Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array <code>fruits</code> where <code>fruits[i] = [position<sub>i</sub>, amount<sub>i</sub>]</code> depicts <code>amount<sub>i</sub></code> fruits at the position <code>position<sub>i</sub></code>. <code>fruits</code> is already <strong>sorted</strong> by <code>position<sub>i</sub></code> in <strong>ascending order</strong>, and each <code>position<sub>i</sub></code> is <strong>unique</strong>.</p>

<p>You are also given an integer <code>startPos</code> and an integer <code>k</code>. Initially, you are at the position <code>startPos</code>. From any position, you can either walk to the <strong>left or right</strong>. It takes <strong>one step</strong> to move <strong>one unit</strong> on the x-axis, and you can walk <strong>at most</strong> <code>k</code> steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.</p>

<p>Return <em>the <strong>maximum total number</strong> of fruits you can harvest</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/21/1.png" style="width: 472px; height: 115px;" />
<pre>
<strong>Input:</strong> fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
<strong>Output:</strong> 9
<strong>Explanation:</strong> 
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/21/2.png" style="width: 512px; height: 129px;" />
<pre>
<strong>Input:</strong> fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
<strong>Output:</strong> 14
<strong>Explanation:</strong> 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/21/3.png" style="width: 476px; height: 100px;" />
<pre>
<strong>Input:</strong> fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
<strong>Output:</strong> 0
<strong>Explanation:</strong>
You can move at most k = 2 steps and cannot reach any position with fruits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>fruits[i].length == 2</code></li>
	<li><code>0 &lt;= startPos, position<sub>i</sub> &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>position<sub>i-1</sub> &lt; position<sub>i</sub></code> for any <code>i &gt; 0</code>&nbsp;(<strong>0-indexed</strong>)</li>
	<li><code>1 &lt;= amount<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>5</sup></code></li>
</ul>



// EXPLANATION
/*Step-by-Step Pointwise Explanation
 1. Understand the Problem
You're placed on a number line at position startPos.

There are fruits available at certain sorted positions, each with a quantity.

You can take up to k total steps, moving left or right.

Wherever you land, you collect all fruits at that location.

Goal: Maximize the total number of fruits collected within the step limit.

✅ 2. Preprocessing the Data
Extract all fruit positions into a separate array.

Compute a prefix sum array, where each entry at index i tells you the total fruits from index 0 to i.

This helps in quickly computing the total number of fruits in any range of positions using subtraction.

✅ 3. Optimal Movement Strategy
Only two types of movement patterns are optimal:

Move left first, then right.

Move right first, then left.

Key insight:
🚫 Avoid more than one U-turn (e.g., left → right → left), as it wastes steps unnecessarily.

So we only need to consider one U-turn maximum, and for every possible value of d (distance turned in one direction), we explore these two patterns.

✅ 4. Loop Over All Valid Turn Distances (d)
Try every possible d from 0 to k / 2.

Why up to k/2?
Because moving d units out and returning takes 2d steps — the rest can be used in the opposite direction.

➤ Case 1: Go d steps left, then go right with remaining steps:
The total covered interval will be from startPos - d to startPos + (k - 2d).

➤ Case 2: Go d steps right, then go left with remaining steps:
The interval will be from startPos - (k - 2d) to startPos + d.

✅ 5. Get the Valid Interval of Fruit Positions
For each case, determine which fruit positions fall inside the current interval.

Since fruit positions are sorted, use binary search to quickly find:

The first fruit position that lies within or after the left end of the interval.

The last fruit position that lies within or before the right end of the interval.

✅ 6. Use Prefix Sum to Calculate Fruits in Interval
Using the indices found via binary search, compute total fruits in that interval in constant time:

Subtract prefix sums to get total fruits between two indices.

Keep updating the maximum total fruits collected so far.

✅ 7. Return the Final Answer
After checking both movement patterns for every valid d, return the highest amount of fruits collected.

💡 Key Concepts Used
Prefix Sum: Fast summing of fruit counts over ranges.

Binary Search (lower_bound, upper_bound): Quickly locate relevant indices in sorted positions.

Greedy-like Optimization: Only try the two efficient movement patterns, avoiding unnecessary paths.

⏱️ Time & Space Complexity
Time Complexity:

O(K log N) — You try up to K/2 values of d, and for each you perform log N binary search.

Space Complexity:

O(N) — for storing positions and prefix sums. */

