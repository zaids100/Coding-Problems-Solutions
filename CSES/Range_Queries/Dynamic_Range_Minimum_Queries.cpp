#include<bits/stdc++.h>
using namespace std;

class SegTree {
public:
    vector<int> seg;
    SegTree(int n) {
        seg.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[ind] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (low > r || high < l) return INT_MAX;
        if (low >= l && high <= r) return seg[ind];
        int mid = low + (high - low) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val);
        } else {
            update(2 * ind + 2, mid + 1, high, i, val);
        }
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    SegTree seg(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    seg.build(0, 0, n - 1, nums);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;
            k--;  // Convert to 0-based index for internal use
            nums[k] = u;
            seg.update(0, 0, n - 1, k, u);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            a--; b--;  // Convert to 0-based index for internal use
            cout << seg.query(0, 0, n - 1, a, b) << endl;
        }
    }
    return 0;
}
