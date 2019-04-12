#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode *root,int n) {
	if (n > root->val) {
		if (!root->right) {
			TreeNode *t = new TreeNode(n);
			root->right = t;
			return;
		}
		else {
			insert(root->right, n);
		}
	}
	else {
		if (!root->left) {
			TreeNode *t = new TreeNode(n);
			root->left = t;
			return;
		}
		else {
			insert(root->left, n);
		}
	}
}

void inorder(TreeNode* root) {
	if (root->left) {
		inorder(root->left);
	}
	cout << root->val << endl;

	if (root->right) {
		inorder(root->right);
	}
}

int main() {
	srand(int(time(0)));
	TreeNode *root = new TreeNode(rand() % 1000);
	vector<int> myvec;
	for (int i = 0; i < 9; i++) {
		myvec.push_back(rand() % 1000);
	}
	while (myvec.size() > 0) {
		insert(root, myvec[myvec.size() - 1]);
		myvec.pop_back();
	}
	inorder(root);
	system("pause");
	return 0;
}