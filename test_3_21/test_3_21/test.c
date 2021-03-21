#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ʧ������
//����nums������0��n������������������ȱ��һ�������д���������ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������?
//ʾ��1:
//����: [3, 0, 1] ��� : 2
//��Ҫ��O(n)ʱ������ɣ���ô��������򷨾��޷���������Ҫ��

//��һ���Ӽ�������0��n�����ۼӣ��ټ�ȥȱ��һ����������nums������Ԫ�أ������Ϊ����
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

//���������
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


//��ָ Offer 56 - II.���������ֳ��ֵĴ��� II
//��һ������ nums �г�һ������ֻ����һ��֮�⣬�������ֶ����������Ρ����ҳ��Ǹ�ֻ����һ�ε����֡�
//ʾ�� 1��
//���룺nums = [3, 4, 3, 3]
//�����4
//ʾ�� 2��
//���룺nums = [9, 1, 7, 9, 7, 9, 7]
//�����1
int singleNumber1(int* a, int sz)
{
	//ð�����򣬴�С������
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

	//����
	k = 0;
	while (k+2 < sz)//k+2<sz ��ֹԽ�����,��3,3,3,4,��k=3ʱ���ٽ���if��������ж�ʱ�ͻ�Ƿ�����
	{
		if ((a[k] == a[k + 1]) && (a[k + 1] == a[k + 2]))
			k += 3;
		else
			return a[k];
	}
	//�������ߵ�����ʱ��˵�������ҵ����������ֱ��return ����
	return a[k];
	
}


int singleNumber2(int* a, int sz)
{
	//����һ����¼32������λ������counter[32],��¼�������ֵĸ�������λ��1�ĳ��ִ���
	//��  3   0 0 1 1
	//    4   0 1 0 0
	//    3   0 0 1 1
	//    3   0 0 1 1
//����λ���   0 1 3 3
//����λ%3	  0 1 0 0   =  4
//����λ%3��һ����0��1
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

	//��ԭ����������λ
	int res = 0;
	for (i = 0; i < 32; i++)
	{
		res <<= 1;//ͨ�����Ʋ������Ӹ�λ����λ���λ�ԭ
		res |= counter[31 - i] % 3;//��λ�루��1��Ϊ1��
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