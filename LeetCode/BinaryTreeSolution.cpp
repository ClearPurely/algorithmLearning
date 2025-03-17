#include "BinaryTreeSolution.h"

BinaryTreeSolution::BinaryTreeSolution()
{
}

void BinaryTreeSolution::ClearAns()
{
	ans.clear();
}

vector<int> BinaryTreeSolution::preorderTraversal1(TreeNode* root)
{
	if (!root) {
		return ans;
	}
	ans.push_back(root->val);
	preorderTraversal1(root->left);
	preorderTraversal1(root->right);
	return ans;
}

vector<int> BinaryTreeSolution::preorderTraversal(TreeNode* root)
{
	vector<int> ret = vector<int>();
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		st.pop();
		ret.push_back(cur->val);
		if (cur->right != NULL)
		{
			st.push(cur->right);
		}
		if (cur->left != NULL)
		{
			st.push(cur->left);
		}
	}
	return ret;
}

vector<int> BinaryTreeSolution::inorderTraversal1(TreeNode* root)
{
	if (!root) {
		return ans;
	}
	inorderTraversal1(root->left);
	ans.push_back(root->val);
	inorderTraversal1(root->right);
	return ans;
}

vector<int> BinaryTreeSolution::inorderTraversal(TreeNode* root)
{
	vector<int> ret = vector<int>();
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	while (!st.empty() || root != NULL)
	{
		if (root != NULL)
		{
			st.push(root);
			root = root->left;
		}
		else
		{
			root = st.top();
			st.pop();
			ret.push_back(root->val);
			root = root->right;
		}
	}
	return ret;
}

vector<int> BinaryTreeSolution::postorderTraversal1(TreeNode* root)
{
	if (!root) {
		return ans;
	}
	postorderTraversal1(root->left);
	postorderTraversal1(root->right);
	ans.push_back(root->val);
	return ans;
}

vector<int> BinaryTreeSolution::postorderTraversal(TreeNode* root)
{
	vector<int> ret = vector<int>();
	if (root == NULL)
		return ret;
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* cur = st.top();
		if (cur->left != NULL && root != cur->left && root!= cur->right)
		{
			st.push(cur->left);
		}
		else if (cur->right != NULL && root != cur->right)
		{
			st.push(cur->right);
		}
		else
		{
			ret.push_back(cur->val);
			root = st.top();
			st.pop();
		}
	}
	return ret;
}

vector<vector<int>> BinaryTreeSolution::levelOrder(TreeNode* root)
{
	vector<vector<int>> ans;
	if (!root) return ans;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int level_size = (int)q.size();
		vector<int> currentLevel;
		currentLevel.reserve(level_size); // 预分配空间

		for (int i = 0; i < level_size; ++i) {
			TreeNode* node = q.front();
			q.pop();
			currentLevel.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		ans.push_back(move(currentLevel)); // 使用移动语义减少拷贝
	}
	return ans;
}

vector<vector<int>> BinaryTreeSolution::zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> ans;
	if (!root) return ans;
	queue<TreeNode*> q;
	q.push(root);
	bool reverse = false;

	while (!q.empty()) {
		int level_size = (int)q.size();
		vector<int> currentLevel;
		currentLevel.reserve(level_size); // 预分配空间

		for (int i = 0; i < level_size; ++i) {
			TreeNode* node = q.front();
			q.pop();
			currentLevel.push_back(node->val);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		// 根据标记决定是否反转
		if (reverse) {
			std::reverse(currentLevel.begin(), currentLevel.end());
		}
		reverse = !reverse;
		ans.push_back(move(currentLevel)); // 使用移动语义减少拷贝
	}

	return ans;
}

vector<vector<int>> BinaryTreeSolution::zigzagLevelOrder1(TreeNode* root) {
	vector<vector<int>> ans;
	if (root != nullptr) {
		const int MAXN = 2001;
		TreeNode* queue[MAXN];
		int l = 0, r = 0;
		queue[r++] = root;
		bool reverse = false;
		while (l < r) {
			int size = r - l;
			vector<int> list;
			for (int i = reverse ? r - 1 : l, j = reverse ? -1 : 1, k = 0; k < size; i += j, k++) {
				TreeNode* cur = queue[i];
				list.push_back(cur->val);
			}
			for (int i = 0; i < size; ++i) {
				TreeNode* cur = queue[l++];
				if (cur->left != nullptr) {
					queue[r++] = cur->left;
				}
				if (cur->right != nullptr) {
					queue[r++] = cur->right;
				}
			}
			ans.push_back(list);
			reverse = !reverse;
		}
	}
	return ans;
}

int BinaryTreeSolution::widthOfBinaryTree(TreeNode* root) {
	if (!root) return 0;

	typedef pair<TreeNode*, uint64_t> NodePair;
	queue<NodePair> q;
	q.push(NodePair(root, 0));

	uint64_t max_width = 0;

	while (!q.empty()) {
		const int level_size = static_cast<int>(q.size());
		uint64_t level_start = q.front().second;
		uint64_t level_end = level_start;

		//遍历这一层的所有节点
		for (int i = 0; i < level_size; ++i) {
			const NodePair& current = q.front();
			TreeNode* node = current.first;
			uint64_t pos = current.second;
			q.pop();

			level_end = pos;  // 更新当前层最后一个位置

			// 计算相对位置并推入子节点
			const uint64_t adjusted_pos = pos - level_start;
			if (node->left) {
				q.push(NodePair(node->left, 2 * adjusted_pos));
			}
			if (node->right) {
				q.push(NodePair(node->right, 2 * adjusted_pos + 1));
			}
		}

		if (level_end >= level_start) { // 防止空层
			max_width = std::max(max_width, level_end - level_start + 1);
		}
	}

	return static_cast<int>(max_width);
}

int BinaryTreeSolution::maxDepth(TreeNode* root) {
	return root == nullptr ? 0 : std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int BinaryTreeSolution::minDepth(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	if (root->left == nullptr) {
		return minDepth(root->right) + 1;
	}
	if (root->right == nullptr) {
		return minDepth(root->left) + 1;
	}
	return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

TreeNode* BinaryTreeSolution::buildTree(vector<int>& pre, vector<int>& in) {
	if (pre.empty() || in.empty() || (int)pre.size() != (int)in.size()) {
		return nullptr;
	}
	unordered_map<int, int> map = unordered_map<int, int>();
	for (int i = 0; i < (int)in.size(); i++)
		map[in[i]] = i;
	return buildTreeF(pre, 0, (int)pre.size() - 1, in, 0, (int)in.size() - 1, map);
}
TreeNode* BinaryTreeSolution::buildTreeF(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2, unordered_map<int, int>& map) {
	if (l1 > r1) {
		return nullptr;
	}
	TreeNode* head = new TreeNode(pre[l1]);
	if (l1 == r1) {
		return head;
	}
	int k = map[pre[l1]];
	// pre : l1(........)[.......r1]
	// in  : (l2......)k[........r2]
	// (...)是左树对应，[...]是右树的对应
	head->left = buildTreeF(pre, l1 + 1, l1 + k - l2, in, l2, k - 1, map);
	head->right = buildTreeF(pre, l1 + k - l2 + 1, r1, in, k + 1, r2, map);
	return head;
}

bool BinaryTreeSolution::isCompleteTree(TreeNode* root) {
	if (!root) return true;
	queue<TreeNode*> q;
	q.push(root);
	bool leaf = false;

	while (!q.empty()) {
		int level_size = (int)q.size();

		for (int i = 0; i < level_size; ++i) {
			TreeNode* node = q.front();
			q.pop();
			//一个节点只有右节点  或者  该节点不是叶节点，就进入条件二
			if ((node->left == nullptr && node->right != nullptr) || (leaf && (node->left != nullptr || node->right != nullptr))) {
				return false;
			}

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);

			//条件二：检查每个节点都是叶节点
			if (node->left == nullptr || node->right == nullptr) {
				leaf = true;
			}
		}
	}
	return true;
}

int BinaryTreeSolution::countNodes(TreeNode* root) {
	if (root == nullptr) {
		return 0;
	}
	return countNodesF(root, 1, mostLeft(root, 1));
}
int BinaryTreeSolution::countNodesF(TreeNode* cur, int level, int h) {
	if (level == h) {
		return 1;
	}
	if (mostLeft(cur->right, level + 1) == h) {
		// cur右树上的最左节点，扎到了最深层
		return (1 << (h - level)) + countNodesF(cur->right, level + 1, h);
	}
	else {
		// cur右树上的最左节点，没扎到最深层
		return (1 << (h - level - 1)) + countNodesF(cur->left, level + 1, h);
	}
}
int BinaryTreeSolution::mostLeft(TreeNode* cur, int level) {
	while (cur != nullptr) {
		level++;
		cur = cur->left;
	}
	return level - 1;
}