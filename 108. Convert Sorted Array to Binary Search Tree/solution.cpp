/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return insertNode(nums, 0, nums.size() - 1);
    }

    TreeNode *insertNode(vector<int> &nums, int start, int end)
    {
        // base case 1 - one node
        if (start == end)
            return new TreeNode(nums[start]);
        // base case 2 - two nodes
        if (end == start + 1)
        {
            TreeNode *root = new TreeNode(nums[start]);
            root->right = new TreeNode(nums[end]);
            return root;
        }

        // recursive code
        int mid = floor((start + end) / 2);
        TreeNode *root = new TreeNode(nums[mid]);

        // go left
        root->left = insertNode(nums, start, mid - 1);
        // go right
        root->right = insertNode(nums, mid + 1, end);

        return root;
    }
};