#include "Bitset.h"

Bitset::Bitset(int n) {
	saveSet = vector<int>((n + 31) / 32, 0);
	size = n;
	zeros = n;
	ones = 0;
	reverse = false;
}

void Bitset::fix(int i)
{
	int index = i / 32;
	int bit = i % 32;
	if (!reverse) {
		// 位图所有位的状态，维持原始含义
		// 0 : 不存在
		// 1 : 存在
		if ((saveSet[index] & (1 << bit)) == 0) {
			zeros--;
			ones++;
			saveSet[index] |= (1 << bit);
		}
	}
	else {
		// 位图所有位的状态，翻转了
		// 0 : 存在
		// 1 : 不存在
		if ((saveSet[index] & (1 << bit)) != 0) {
			zeros--;
			ones++;
			saveSet[index] ^= (1 << bit);
		}
	}
}

void Bitset::unfix(int i)
{
	int index = i / 32;
	int bit = i % 32;
	if (!reverse) {
		if ((saveSet[index] & (1 << bit)) != 0) {
			ones--;
			zeros++;
			saveSet[index] ^= (1 << bit);
		}
	}
	else {
		if ((saveSet[index] & (1 << bit)) == 0) {
			ones--;
			zeros++;
			saveSet[index] |= (1 << bit);
		}
	}
}

void Bitset::flip() {
	reverse = !reverse;
	int tmp = zeros;
	zeros = ones;
	ones = tmp;
}

bool Bitset::all() {
	return ones == size;
}

bool Bitset::one() {
	return ones > 0;
}

int Bitset::count() {
	return ones;
}

string Bitset::toString() {
	string builder(size, '0');
	for (int i = 0, k = 0; i < size; k++) {
		int number = saveSet[k];
		for (int j = 0; j < 32 && i < size; j++, i++) {
			int status = (number >> j) & 1;
			status ^= reverse ? 1 : 0;
			builder[i] = static_cast<char>(status + '0');
		}
	}
	return builder;
}

void Bitset::reverseNum(int i)
{
	int index = i / 32;
	int bit = i % 32;
	saveSet[index] ^= (1 << bit);

	bool originalBit = (saveSet[index] & (1 << bit)) != 0;
	originalBit = reverse ? !originalBit : originalBit;
	if (originalBit) {
		ones--;
		zeros++;
	}
	else {
		ones++;
		zeros--;
	}

}

bool Bitset::contains(int i)
{
	int index = i / 32;
	int bit = i % 32;
	bool contained = ((saveSet[index] >> bit) & 1) == 1;
	return reverse ? !contained : contained;
}