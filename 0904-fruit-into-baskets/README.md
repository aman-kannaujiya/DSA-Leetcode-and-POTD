<h2><a href="https://leetcode.com/problems/fruit-into-baskets">904. Fruit Into Baskets</a></h2><h3>Medium</h3><hr><p>You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array <code>fruits</code> where <code>fruits[i]</code> is the <strong>type</strong> of fruit the <code>i<sup>th</sup></code> tree produces.</p>

<p>You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:</p>

<ul>
	<li>You only have <strong>two</strong> baskets, and each basket can only hold a <strong>single type</strong> of fruit. There is no limit on the amount of fruit each basket can hold.</li>
	<li>Starting from any tree of your choice, you must pick <strong>exactly one fruit</strong> from <strong>every</strong> tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.</li>
	<li>Once you reach a tree with fruit that cannot fit in your baskets, you must stop.</li>
</ul>

<p>Given the integer array <code>fruits</code>, return <em>the <strong>maximum</strong> number of fruits you can pick</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> fruits = [<u>1,2,1</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from all 3 trees.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> fruits = [0,<u>1,2,2</u>]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> fruits = [1,<u>2,3,2,2</u>]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fruits[i] &lt; fruits.length</code></li>
</ul>

/*
What is Sliding Window?
Sliding Window is a technique to process a contiguous segment (window) of an array by maintaining two pointers (start and end of the window).

As we move along the array, we dynamically adjust the size and position of the window to satisfy given constraints (here: “at most 2 fruit types in the window”).

It works efficiently in subarray problems where we want to find the largest/smallest window that meets certain criteria.

Why Use Sliding Window for This Problem?
The problem asks for the longest contiguous sequence of trees from which you can collect fruit, with at most two types of fruit.

Instead of checking every possible subarray (inefficient), sliding window allows us to scan the array once and adjust the window when the two-type limit is broken.

This method uses extra memory (map/dictionary) to track fruit types and counts inside the window.

Step-by-Step Approach (Point-wise)
Initialize window pointers: Start with both the left and right pointers of the window at the beginning of the array.

Track fruit types:

Use a map/hash table/dictionary to remember how many of each fruit type are currently in the window.

Expand the window:

Move the right pointer forward to include more fruits into your window, adding the fruit type to your tracking map.

Check the basket constraint:

If your window now includes more than 2 types of fruit, you have broken the rule (only 2 baskets allowed).

Shrink the window:

Move the left pointer forward, removing fruits from the map. If the count for a fruit type drops to zero, remove it entirely from the tracking map.

Keep shrinking the window from the left until you are back down to at most 2 fruit types in your window.

Track the maximum window:

Every time the window is valid (no more than 2 fruit types inside), check if this window is the largest seen so far. Remember its length.

Continue scanning:

Repeat expanding and shrinking as you move the right pointer across the full array.

Result:

The largest valid window found is the answer: the maximum number of fruits you can collect under the rules.

How Sliding Window Works Visually
Expand: Grow the window to the right as long as adding a fruit doesn't violate the two-type limit.

Contract: If the limit is violated, move the left side of the window right, one by one, until the window is valid again.

Update: Track the biggest window size you encounter throughout the process.

This approach is efficient (O(n) time), easy to follow, and fits this kind of “maximum in a constrained subarray” problem perfectly */
