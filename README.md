# DSA-Leetcode-and-POTD
#Explanation step by step
We use an unordered map to efficiently track the frequency difference of elements between the two baskets. Unordered maps provide fast average time complexity for insertions and lookups, and we don’t care about the order of elements, so this choice is optimal.

We keep a variable to store the minimum element across both baskets, because it plays an important role later in minimizing the swap cost. This is based on the idea that sometimes using the smallest value to perform two indirect swaps is cheaper than a direct swap between large values.

We iterate over the first basket and for each item, we increase its count in the map and update the minimum element if it's smaller than the current minimum. This builds the first half of the frequency difference.

Then we iterate over the second basket, decreasing the count of each item in the map. This finalizes the net difference in frequency for each item, while also updating the minimum element again if needed.

After both baskets are processed, each key in the map has a net frequency difference. If the difference is zero for a key, that item is already balanced between the baskets and needs no action.

If any item has an odd frequency difference, it's impossible to pair all extra items evenly for swapping, so the function immediately returns -1.

For items with non-zero and even frequency difference, we take half of the absolute difference (since each swap corrects two mismatches) and collect those many instances of the item in a list. This forms the list of elements that need to be swapped.

Since only half the items in that list will be swapped with their counterparts, we use an efficient algorithm (nth_element internally) to quickly identify the smallest half of the list without sorting the entire list. This is done to save time and only focus on the part that affects the final cost.

For each of these smallest values, we compute the cost of swapping. We compare the item's value with twice the minimum value seen in both baskets and pick whichever is smaller. This is because sometimes it's cheaper to do two swaps using the smallest element than one direct swap with a large value.

Finally, we sum all the minimum swap costs and return the result, which is the minimum total cost to make both baskets identical through allowed swaps.

