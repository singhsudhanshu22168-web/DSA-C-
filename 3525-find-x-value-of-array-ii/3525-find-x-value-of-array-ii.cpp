class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) {
                pref[i] = 0;
            }
        }
    };

    int n, k;
    vector<Node> seg;

    Node merge(const Node& left, const Node& right) {
        Node res;

        // Product of the combined segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes entirely inside the left segment
        for (int r = 0; r < k; r++) {
            res.pref[r] = left.pref[r];
        }

        // Prefixes that include the entire left segment
        // and a non-empty prefix of the right segment
        for (int r = 0; r < k; r++) {
            int newRem = (left.prod * r) % k;
            res.pref[newRem] += right.pref[r];
        }

        return res;
    }

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            seg[idx].prod = rem;
            seg[idx].pref[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, nums);
        build(idx * 2 + 1, mid + 1, r, nums);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            int rem = val % k;

            seg[idx] = Node();
            seg[idx].prod = rem;
            seg[idx].pref[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(idx * 2, l, mid, pos, val);
        } else {
            update(idx * 2 + 1, mid + 1, r, pos, val);
        }

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        // No overlap: identity node
        if (qr < l || r < ql) {
            return Node();
        }

        // Complete overlap
        if (ql <= l && r <= qr) {
            return seg[idx];
        }

        int mid = (l + r) / 2;

        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {
        n = nums.size();
        k = K;

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> result;

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent point update
            nums[index] = value;

            update(1, 0, n - 1, index, value);

            // Get prefix-product frequencies in [start, n-1]
            Node ans = query(1, 0, n - 1, start, n - 1);

            result.push_back(ans.pref[x]);
        }

        return result;
    }
};