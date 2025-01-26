#pragma once
#include "../Solution.h"

/// <summary>
/// 86. 分隔链表
/// 给你一个链表的头节点head和一个特定值x，请你对链表进行分隔，使得所有小于x的节点都出现在大于或等于x的节点之前。
/// 你应当 保留 两个分区中每个节点的初始相对位置。
/// </summary>
class _86_Partition : public Solution
{
    /// <summary>
    /// 左神讲的，最优方法
    /// </summary>
    /// <param name="head">链表的头节点</param>
    /// <param name="x">分隔值</param>
    /// <returns>分隔后的链表的头节点</returns>
	ListNode* partition(ListNode* head, int x);

};

