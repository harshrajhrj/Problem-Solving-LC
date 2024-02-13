class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seenIndex;
        int n = s.size();
        int l = 0, r = 0;
        int res = 0;

        while (r < n) {
            if (seenIndex.count(s[r]) == 0 || seenIndex[s[r]] < l) {
                seenIndex[s[r]] = r;
                res = max(res, r - l + 1);
            } else {
                l = seenIndex[s[r]] + 1;
                seenIndex[s[r]] = r;
            }
            r++;
        }
        return res;
    }
};