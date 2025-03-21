/***题目介绍***
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
将数组和减半的最少操作次数
给你一个正整数数组 nums 。每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。（注意，在后续操作中你可以对减半过的数继续执行操作）
请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
*/
#pragma once
#include "../Solution.h"


class _2208_HalveArray : public Solution {
private:
    long heap[100001];         // 定义堆数组
    int size;                // 定义堆的大小
public:
	int halveArray(vector<int>& nums) {
        // 放大倍数（左移 20 位）
        const int shift = 20;
        // 计算放大后的总和
        long long sum = 0;

        // 使用最大堆（优先队列）存储放大后的元素
        priority_queue<long long> maxHeap;
        for (int num : nums) {
            long long temp = static_cast<long long>(num) << shift;
            sum += temp;
            maxHeap.push(temp);
        }

        // 目标减半值
        long long target = sum / 2;

        int ans = 0; // 操作次数
        long long reducedSum = 0; // 已减少的总和

        // 每次操作将堆顶元素减半，直到减少的总和达到目标
        while (reducedSum < target) {
            long long maxElement = maxHeap.top();
            maxHeap.pop();
            long long halfElement = maxElement / 2;
            reducedSum += halfElement;
            maxHeap.push(halfElement);
            ans++;
        }

        return ans;
	}

    // 堆化函数
    void heapify(int i) {
        int l = i * 2 + 1; // 左孩子索引
        while (l < size) {
            // 选择左右孩子中较大的一个
            int best = (l + 1 < size && heap[l + 1] > heap[l]) ? l + 1 : l;
            // 如果当前节点比孩子小，则交换
            best = (heap[best] > heap[i]) ? best : i;
            if (best == i) {
                break; // 如果当前节点已经是最大值，则退出
            }
            std::swap(heap[best], heap[i]); // 交换节点
            i = best;                       // 更新当前节点索引
            l = i * 2 + 1;                  // 更新左孩子索引
        }
    }

    // 主函数：将数组和减半的最少操作次数
    int halveArray2(vector<int>& nums) {
        size = (int)nums.size(); // 初始化堆的大小
        long sum = 0;       // 初始化总和

        // 将数组元素放入堆中，并计算总和
        for (int i = size - 1; i >= 0; i--) {
            heap[i] = (long)nums[i] << 20; // 将元素放大
            sum += heap[i];                // 累加总和
            heapify(i);                   // 堆化
        }

        sum /= 2; // 目标减半值
        int ans = 0; // 操作次数
        long minus = 0; // 已减少的总和

        // 每次操作将堆顶元素减半，直到减少的总和达到目标
        while (minus < sum) {
            heap[0] /= 2;       // 将堆顶元素减半
            minus += heap[0];   // 累加减少的总和
            heapify(0);         // 重新堆化
            ans++;              // 增加操作次数
        }

        return ans; // 返回操作次数
    }

	void testDemo() override {
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;



	}
};