#include<bits/stdc++.h> 
using namespace std;

class SegTree {
public:
    vector<long long> seg;
    SegTree(int n) {
        seg.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<long long>& nums) {
        if (low == high) {
            seg[ind] = nums[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, nums);
        build(2 * ind + 2, mid + 1, high, nums);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    long long query(int ind, int low, int high, int l, int r) {
        if (low > r || high < l) return 0;
        if (low >= l && high <= r) return seg[ind];
        int mid = low + (high - low) / 2;
        long long left = query(2 * ind + 1, low, mid, l, r);
        long long right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int ind, int low, int high, int i, long long val) {
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
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> nums(n);
    SegTree seg(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    seg.build(0, 0, n - 1, nums);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k;
            long long u;
            cin >> k >> u;
            k--;
            nums[k] = u;
            seg.update(0, 0, n - 1, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << seg.query(0, 0, n - 1, a, b) << endl;
        }
    }
    return 0;
}
