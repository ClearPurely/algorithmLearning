#include "TrieArray.h"


TrieArray::TrieArray() : cnt(1), treeArr(MAXN, std::vector<int>(26, 0)), endArr(MAXN, 0), passArr(MAXN, 0)
{
}

void TrieArray::insert(const string& word) {
	int cur = 1;
	int path = 0;
	passArr[cur]++;
	for (char ch : word) {
		path = ch - 'a';
		if (treeArr[cur][path] == 0) {
			treeArr[cur][path] = ++cnt;		//确定连接的下一个节点
		}
		cur = treeArr[cur][path];		//进入下一个节点
		passArr[cur]++;
	}
	endArr[cur]++;
}

int TrieArray::search(const string& word) {
	int cur = 1;
	int path = 0;
	for (char ch : word) {
		path = ch - 'a';
		if (treeArr[cur][path] == 0) {
			return 0;
		}
		cur = treeArr[cur][path];
	}
	return endArr[cur];
}

int TrieArray::startsWith(const string& pre) {
	int cur = 1;
	int path = 0;
	for (char ch : pre) {
		path = ch - 'a';
		if (treeArr[cur][path] == 0) {
			return 0;
		}
		cur = treeArr[cur][path];
	}
	return passArr[cur];
}

void TrieArray::erase(const string& word) {
	if (search(word) > 0) {
		int cur = 1;
		for (int i = 0, path; i < word.length(); i++) {
			path = word[i] - 'a';
			// 判断下一个节点的引用计数在减 1 之后是否为 0。若为 0，就意味着没有其他字符串经过这个节点。
			if (--passArr[treeArr[cur][path]] == 0) {
				treeArr[cur][path] = 0;
				return;
			}
			cur = treeArr[cur][path];
		}
		endArr[cur]--;
	}
}

void TrieArray::clear() {
	for (int i = 1; i <= cnt; i++) {
		std::fill_n(treeArr[i].begin(), 26, 0);
		endArr[i] = 0;
		passArr[i] = 0;
	}
	cnt = 1;
}