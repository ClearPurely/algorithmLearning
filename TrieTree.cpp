#include "TrieTree.h"

void TrieTree::destroy(TrieNode* node) {
	if (!node) return;
	for (auto& pair : node->nexts) {
		destroy(pair.second);
	}
	delete node;
}

TrieTree::TrieTree() {
	root = new TrieNode();
}

TrieTree::~TrieTree() {
	destroy(root);
}

void TrieTree::insert(const string& word) {
	TrieNode* node = root;
	node->pass++;
	for (int i = 0, path; i < word.length(); i++) { // 从左往右遍历字符
		path = word[i];
		TrieNode*& next = node->nexts[path];
		if (!next) {
			next = new TrieNode();
		}
		node = next;
		node->pass++;
	}
	node->end++;
}

void TrieTree::erase(const string& word) {
	if (countWordsEqualTo(word) == 0) return;

	// 记录节点路径用于回溯 (父节点, 字符)
	vector<pair<TrieNode*, int>> node_path;
	node_path.reserve(word.length());

	TrieNode* node = root;
	node->pass--;  // 先减少根节点的pass

	// 遍历路径并减少pass计数
	for (int c : word) {
		auto it = node->nexts.find(c);
		if (it == node->nexts.end())
			return;  // 防御性保护

		node_path.emplace_back(node, c);  // 记录当前节点和字符
		node = it->second;
		node->pass--;  // 提前减少pass计数
	}
	node->end--;  // 最后减少结束计数

	// 逆向检查需要删除的空节点
	for (int i = (int)node_path.size() - 1; i >= 0; --i) {
		if (node->pass != 0) break;  // 遇到仍有其他路径的节点则停止

		// 获取父节点和对应字符
		TrieNode* parent = node_path[i].first;
		int char_key = node_path[i].second;

		parent->nexts.erase(char_key);  // 移除子节点
		delete node;          // 删除当前空节点
		node = parent;        // 回溯到父节点继续检查
	}
}

int TrieTree::countWordsEqualTo(const string& word) {
	TrieNode* node = root;
	for (int c : word) {
		auto it = node->nexts.find(c);
		if (it == node->nexts.end())
			return 0;
		node = it->second;
	}
	return node->end;
}

int TrieTree::countWordsStartingWith(const string& pre) {
	TrieNode* node = root;
	for (int c : pre) {
		auto it = node->nexts.find(c);
		if (it == node->nexts.end())
			return 0;
		node = it->second;
	}
	return node->pass;
}