/*
 * @lc app=leetcode.cn id=109 lang=cpp
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//@lc code=start
class Solution
{
private:
	TreeNode *buildT(vector<int> &v, int s, int e)
	{
		if (e == s)
			return nullptr;
		int mid = (e + s) / 2;
		TreeNode *root = new TreeNode(v[mid]);
		root->left = buildT(v, s, mid);
		root->right = buildT(v, mid + 1, e);
		return root;
	}

public:
	TreeNode *sortedListToBST(ListNode *head)
	{
		vector<int> v;
		while (head)
		{
			//cout << 2;
			v.emplace_back(head->val);
			head = head->next;
		}
		return buildT(v, 0, v.size());
	}
};
