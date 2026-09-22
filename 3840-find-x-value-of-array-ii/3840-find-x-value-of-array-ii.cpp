class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        struct Node {
            int prod = 1;
            long long cnt[5] = {};
        };

        vector<Node> st(4 * n);

        auto merge = [&](const Node& a, const Node& b) {
            Node res;

            res.prod = (1LL * a.prod * b.prod) % k;

            // Prefixes completely inside left
            for (int i = 0; i < k; i++)
                res.cnt[i] = a.cnt[i];

            // Prefixes = whole left + prefix of right
            for (int i = 0; i < k; i++) {
                int rem = (1LL * a.prod * i) % k;
                res.cnt[rem] += b.cnt[i];
            }

            return res;
        };

        auto build = [&](auto&& self, int p, int l, int r) -> void {
            if (l == r) {
                int x = nums[l] % k;
                st[p].prod = x;
                st[p].cnt[x] = 1;
                return;
            }

            int m = (l + r) >> 1;

            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);

            st[p] = merge(st[p << 1], st[p << 1 | 1]);
        };

        auto update = [&](auto&& self, int p, int l, int r, int idx) -> void {
            if (l == r) {
                st[p] = Node();

                int x = nums[idx] % k;
                st[p].prod = x;
                st[p].cnt[x] = 1;

                return;
            }

            int m = (l + r) >> 1;

            if (idx <= m)
                self(self, p << 1, l, m, idx);
            else
                self(self, p << 1 | 1, m + 1, r, idx);

            st[p] = merge(st[p << 1], st[p << 1 | 1]);
        };

        auto query = [&](auto&& self, int p, int l, int r, int ql, int qr) -> Node {
            if (ql <= l && r <= qr)
                return st[p];

            int m = (l + r) >> 1;

            if (qr <= m)
                return self(self, p << 1, l, m, ql, qr);

            if (ql > m)
                return self(self, p << 1 | 1, m + 1, r, ql, qr);

            Node left = self(self, p << 1, l, m, ql, qr);
            Node right = self(self, p << 1 | 1, m + 1, r, ql, qr);

            return merge(left, right);
        };

        build(build, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            nums[index] = value;

            update(update, 1, 0, n - 1, index);

            Node res = query(query, 1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};