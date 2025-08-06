class SegmentTree {
 public:
  explicit SegmentTree(const vector<int>& nums) : n(nums.size()), tree(n * 4) {
    build(nums, 0, 0, n - 1);
  }

  // Updates basket capacity at index i to new value.
  void update(int i, int val) {
    update(0, 0, n - 1, i, val);
  }

  // Finds the first index i where basket[i] >= target, or -1 if none.
  int queryFirst(int target) {
    return queryFirst(0, 0, n - 1, target);
  }

 private:
  const int n;
  vector<int> tree;

  void build(const vector<int>& nums, int idx, int lo, int hi) {
    if (lo == hi) {
      tree[idx] = nums[lo];
      return;
    }
    int mid = (lo + hi) / 2;
    build(nums, 2*idx + 1, lo, mid);
    build(nums, 2*idx + 2, mid + 1, hi);
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
  }

  void update(int idx, int lo, int hi, int i, int val) {
    if (lo == hi) {
      tree[idx] = val;
      return;
    }
    int mid = (lo + hi) / 2;
    if (i <= mid) update(2*idx + 1, lo, mid, i, val);
    else          update(2*idx + 2, mid + 1, hi, i, val);
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
  }

  int queryFirst(int idx, int lo, int hi, int target) {
    if (tree[idx] < target) return -1;
    if (lo == hi) {
      update(lo, -1); // Mark basket as used
      return lo;
    }
    int mid = (lo + hi) / 2;
    if (tree[2*idx+1] >= target)
      return queryFirst(2*idx + 1, lo, mid, target);
    else
      return queryFirst(2*idx + 2, mid + 1, hi, target);
  }

  int merge(int a, int b) const {
    return max(a, b);
  }
};

class Solution {
 public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    SegmentTree st(baskets);
    int unplaced = 0;
    for (int f : fruits)
      if (st.queryFirst(f) == -1)
        ++unplaced;
    return unplaced;
  }
};
