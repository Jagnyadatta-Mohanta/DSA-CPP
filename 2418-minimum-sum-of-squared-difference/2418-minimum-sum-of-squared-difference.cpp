class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> diff(nums1.size());

        long long sum = 0, mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
            mx = max(mx, diff[i]);
        }

        if (sum <= k) return 0;

        long long l = 0, r = mx;

        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long need = 0;

            for (long long d : diff)
                need += max(0LL, d - mid);

            if (need <= k)
                r = mid;
            else
                l = mid + 1;
        }

        long long ans = 0;

        for (long long d : diff) {
            d = min(d, l);
            ans += d * d;
        }

        long long used = 0;
        for (long long d : diff)
            used += max(0LL, d - l);

        long long remaining = k - used;

        for (long long& d : diff) {
            if (d > l) d = l;
            if (remaining > 0 && d == l && d > 0) {
                ans -= d * d;
                ans += (d - 1) * (d - 1);
                remaining--;
            }
        }

        return ans;
    }
};