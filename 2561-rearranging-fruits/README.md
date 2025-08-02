<h2><a href="https://leetcode.com/problems/rearranging-fruits">2561. Rearranging Fruits</a></h2><h3>Hard</h3><hr><p>You have two fruit baskets containing <code>n</code> fruits each. You are given two <strong>0-indexed</strong> integer arrays <code>basket1</code> and <code>basket2</code> representing the cost of fruit in each basket. You want to make both baskets <strong>equal</strong>. To do so, you can use the following operation as many times as you want:</p>

<ul>
	<li>Chose two indices <code>i</code> and <code>j</code>, and swap the <code>i<font size="1">th</font>&nbsp;</code>fruit of <code>basket1</code> with the <code>j<font size="1">th</font></code>&nbsp;fruit of <code>basket2</code>.</li>
	<li>The cost of the swap is <code>min(basket1[i],basket2[j])</code>.</li>
</ul>

<p>Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.</p>

<p>Return <em>the minimum cost to make both the baskets equal or </em><code>-1</code><em> if impossible.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> basket1 = [4,2,2,2], basket2 = [1,4,1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> basket1 = [2,3,4,1], basket2 = [3,2,5,1]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be shown that it is impossible to make both the baskets equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>basket1.length == basket2.length</code></li>
	<li><code>1 &lt;= basket1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= basket1[i],basket2[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


/*
We use an unordered map to efficiently track the frequency difference of elements between the two baskets. Unordered maps provide fast average time complexity for insertions and lookups, and we don’t care about the order of elements, so this choice is optimal.

We keep a variable to store the minimum element across both baskets, because it plays an important role later in minimizing the swap cost. This is based on the idea that sometimes using the smallest value to perform two indirect swaps is cheaper than a direct swap between large values.

We iterate over the first basket and for each item, we increase its count in the map and update the minimum element if it's smaller than the current minimum. This builds the first half of the frequency difference.

Then we iterate over the second basket, decreasing the count of each item in the map. This finalizes the net difference in frequency for each item, while also updating the minimum element again if needed.

After both baskets are processed, each key in the map has a net frequency difference. If the difference is zero for a key, that item is already balanced between the baskets and needs no action.

If any item has an odd frequency difference, it's impossible to pair all extra items evenly for swapping, so the function immediately returns -1.

For items with non-zero and even frequency difference, we take half of the absolute difference (since each swap corrects two mismatches) and collect those many instances of the item in a list. This forms the list of elements that need to be swapped.

Since only half the items in that list will be swapped with their counterparts, we use an efficient algorithm (nth_element internally) to quickly identify the smallest half of the list without sorting the entire list. This is done to save time and only focus on the part that affects the final cost. */

