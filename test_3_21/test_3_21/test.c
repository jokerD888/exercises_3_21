#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写函数代码找出那个缺失的整数。你有办法在O(n)时间内完成吗?
//示例1:
//输入: [3, 0, 1] 输出 : 2
//若要在O(n)时间内完成，那么常规的排序法就无法满足题吗要求

//法一：加减法，将0到n的数累加，再减去缺了一个数的数组nums的所有元素，结果即为所得
int MissingNumber1(int* a, int n)
{
	int num = 0;
	int i = 0;
	for (i = 0; i <= n; i++)
	{
		num += i;
	}
	for (i = 0; i < n; i++)
	{
		num -= *(a+i);
	}
	return num;
}

//法二：异或法
int MissingNumber2(int* a, int n)
{
	int num = 0;
	int i = 0;
	for (i = 0; i <= n; i++)
	{
		num ^= i;
	}
	for (i = 0; i <n; i++)
	{
		num ^= *(a+i);
	}
	return num;
}


//int main(void)
//{
//	int nums[7] = { 3,0,1,2,5,6,7};
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int ret = MissingNumber1(nums, sz);
//	printf("%d\n", ret);
//	ret = MissingNumber2(nums, sz);
//	printf("%d\n", ret);
//	return 0;
//}


//剑指 Offer 56 - II.数组中数字出现的次数 II
//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
//示例 1：
//输入：nums = [3, 4, 3, 3]
//输出：4
//示例 2：
//输入：nums = [9, 1, 7, 9, 7, 9, 7]
//输出：1
int singleNumber1(int* a, int sz)
{
	//冒泡排序，从小到大排
	int i = 0;
	int k = 0;
	for (i = 0; i < sz-1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1-i; j++)
		{

			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}

	//查找
	k = 0;
	while (k+2 < sz)//k+2<sz 防止越界访问,如3,3,3,4,当k=3时，再进行if条件句的判断时就会非法访问
	{
		if ((a[k] == a[k + 1]) && (a[k + 1] == a[k + 2]))
			k += 3;
		else
			return a[k];
	}
	//当程序走到这里时，说明被查找的数排在最后，直接return 即可
	return a[k];
	
}


int singleNumber2(int* a, int sz)
{
	//创建一个记录32个比特位的数组counter[32],记录所有数字的各二进制位的1的出现次数
	//如  3   0 0 1 1
	//    4   0 1 0 0
	//    3   0 0 1 1
	//    3   0 0 1 1
//各个位相加   0 1 3 3
//各个位%3	  0 1 0 0   =  4
//各个位%3后一定是0或1
	int counter[32] = { 0 };
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int j = 0;
		int m = 0;
		for (j = 0; j < 32; j++)
		{
			counter[j] += (a[i] & (1<<m));
			m++;
		}
	}

	//还原各个二进制位
	int res = 0;
	for (i = 0; i < 32; i++)
	{
		res <<= 1;//通过左移操作，从高位到底位依次还原
		res |= counter[31 - i] % 3;//按位与（有1就为1）
	}
	return res;
}
int main(void)
{
	int nums[7] = { 9, 1, 7, 9, 7, 9, 7 };
	int sz = sizeof(nums) / sizeof(nums[0]);
	int ret = singleNumber1(nums, sz);
	printf("%d\n", ret);
	ret = singleNumber2(nums, sz);
	printf("%d\n", ret);
	return 0;
}