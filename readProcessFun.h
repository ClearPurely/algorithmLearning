/*************
���ߣ�ClearPurely
˵��������ļ��ķ�����Ϊ��Ӧ��ACM������Ŀ�����Ĵ����д
�������ڣ�2025.1.13
���������ڣ�2025.1.13
****************/
#pragma once
#include <functional>
#include<iostream>		//	���������ӡ
#include<vector>		//����

using namespace std;

//����һ�� �ɴ���һ������������ֵvoid�ĺ��� ����
typedef std::function<void(int)> MyIntProcessFun;

//����һ�� �ɴ���һ�����飬����ֵvoid�ĺ��� ����
typedef std::function<void(std::vector<int>&)> MyArrayProcessFun;

//����һ�� �ɴ���һ����ά�������������ֵvoid�ĺ��� ����
typedef std::function<void(std::vector<std::vector<int>>&)> MyMatrixProcessFun;

//��ȡһ�������ļ����ݣ����ô���ĺ���������д���
//���ļ���ʽӦ��������ʾ����һ��2��2�еľ���Ԫ�طֱ���9��10��13��14
//2 2
//9 10
//13 14
void processInputMatrix(const MyMatrixProcessFun& func);

//����һ��һ�е����룬�Ե����������д���
//������룬���ļ������У�
//10 11 12
//13 50 60
void processInputLineNum(const MyIntProcessFun& func);

//�����������飬���������һ������5�����飬�ֱ���4 2 4 5 1
//5
//4 2 4 5 1
void processInputArray(const MyArrayProcessFun& func);