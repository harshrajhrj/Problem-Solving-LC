class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // use big array for binary search
        if (n1 > n2) {
            sort(nums1.begin(), nums1.end());
            return solve(nums1, nums2);
        } else {
            sort(nums2.begin(), nums2.end());
            return solve(nums2, nums1);
        }
    }

    vector<int> solve(vector<int>& big, vector<int>& small) {
        set<int> store; // to eliminate duplicates

        // traverse smaller array
        int n = small.size();
        int i = 0;
        while (i < n) {
            if (binary_search(big.begin(), big.end(), small[i]))
                store.insert(small[i]);
            i++;
        }

        // copy the elements to array and return
        vector<int> ans;
        for (auto v : store) {
            ans.push_back(v);
        }
        return ans;
    }
};