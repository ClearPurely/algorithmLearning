#pragma once
#include "../Solution.h"

/// <summary>
/// 86. �ָ�����
/// ����һ�������ͷ�ڵ�head��һ���ض�ֵx�������������зָ���ʹ������С��x�Ľڵ㶼�����ڴ��ڻ����x�Ľڵ�֮ǰ��
/// ��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�
/// </summary>
class _86_Partition : public Solution
{
    /// <summary>
    /// ���񽲵ģ����ŷ���
    /// </summary>
    /// <param name="head">�����ͷ�ڵ�</param>
    /// <param name="x">�ָ�ֵ</param>
    /// <returns>�ָ���������ͷ�ڵ�</returns>
	ListNode* partition(ListNode* head, int x);

};

