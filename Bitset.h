// 2166 λͼ��ʵ��
// λͼ�ǿ��Դ洢һ���������������ݽṹ
// Bitset��һ�����Խ�����ʽ�洢λ�����ݽṹ
// �������� : https://leetcode-cn.com/problems/design-bitset/
#pragma once
#include<vector>		//����
#include <string>
using namespace std;

class Bitset
{
private:
	vector<int> saveSet;
	int size;
	int zeros;
	int ones;
	bool reverse;

public:
	// �� size ��λ��ʼ�� Bitset ������λ���� 0
	Bitset(int n);

	// ���±�Ϊidx��λ�ϵ�ֵ����Ϊ1�����ֵ�Ѿ���1���򲻻ᷢ���κθı䡣
	void fix(int i);

	// ���±�Ϊidx��λ�ϵ�ֵ����Ϊ0�����ֵ�Ѿ���0���򲻻ᷢ���κθı䡣
	void unfix(int i);

	//��ת Bitset ��ÿһλ�ϵ�ֵ�����仰˵������ֵΪ 0 ��λ������ 1 ����֮��Ȼ��
	void flip();

	//��� Bitset �� ÿһλ ��ֵ�Ƿ��� 1 �������������������� true �����򣬷��� false ��
	bool all();

	//��� Bitset �� �Ƿ� ����һλ ��ֵ�� 1 �������������������� true �����򣬷��� false ��
	bool one();

	//���� Bitset ��ֵΪ 1 ��λ�� ���� ��
	int count();

	//���� Bitset �ĵ�ǰ��������ע�⣬�ڽ���ַ����У��� i ���±괦���ַ�Ӧ���� Bitset �еĵ� i λһ�¡�
	string toString();

	//��תһ������λͼ�е�״̬
	void reverseNum(int i);

	//�ж�λͼ���Ƿ���������
	bool contains(int i);
};

