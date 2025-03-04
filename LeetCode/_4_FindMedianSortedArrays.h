/*
寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数。

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
*/
#pragma once
#include "../Solution.h"

class _4_FindMedianSortedArrays : public Solution{
public:
    //无法处理一个元素的情况
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        double ret = 0;
        double num1 = 0, num2 = 0;
        int size = nums1.size() + nums2.size();
        if (size < 1 || size > 2000) {
            return false;
        }

        int index = (size + 1) / 2;
        if (size % 2 == 0) {
            int L = 0, R = 0;
            for (int i = 0; i < index; i++) {
                if (nums1[L] < nums2[R]) {
                    num1 = nums1[L];
                    if (L < nums1.size() - 1)
                    {
                        ++L;
                    }
                }
                else {
                    num1 = nums2[R];
                    if (R < nums2.size()-1)
                    {
                        ++R;
                    }
                }
                cout << L << " " << R << endl << endl;
            }
            int L2 = nums1.size()-1, R2 = nums2.size() - 1;
            for (int i = 0; i < index; i++) {
                if (nums1[L2] > nums2[R2]) {
                    num2 = nums1[L2];
                    if (L2 > 0)
                    {
                        --L2;
                    }
                }
                else {
                    num2 = nums2[R2];
                    if (R2 > 0)
                    {
                        --R2;
                    }
                }
                cout << L2 << " " << R2 << endl << endl;
            }


            cout << num1 << " " << num2 << endl;
            ret = (num1 + num2) / 2;

        }
        else {
            cout << index << endl << endl;
            int L = 0, R = 0;
            for (int i = 0; i < index; i++) {
                if (nums1[L] < nums2[R]) {
                    num2 = nums1[L];
                    ++L;
                }
                else {
                    num2 = nums2[R];
                    ++R;
                }
            }
            ret = num2;
        }

        return ret;
    }



    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ret = 0;
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int size = nums1.size();
        cout << size << endl << endl;
        int index = (size + 1) / 2;
        cout << index << endl << endl;
        if (size < 1 || size > 2000)
        {
            return false;
        }
        if (size % 2 == 0)
        {
            cout << nums1[index-1] << " " << nums1[index] << endl << endl;
            ret = (nums1[index - 1] + nums1[index]) / 2.0;
        }   
        else
        {
            ret = nums1[index-1];
        }
        return ret;
    }




    //测试代码
    void testDemo() override {
        vector<int> v1;
        vector<int> v2;
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
        v2.push_back(4);

        double an = findMedianSortedArrays(v1, v2);
        cout <<  an << endl;
    }
};