/********************
题目：一组数中有若干个数，只有2个数出现奇数次，其他的全部出现偶数次
求2个出现奇数次的数
算法思想:
对于任何一个数X而言，X异或它本身都等于0，而0异或X则等于X.
所以说对于出现偶数次的数而言，我们可以通过异或将其变为0。
所以对于题目而言，将这一组数全部进行异或，则最后的答案ans就是两个出现奇数次的数的异或值。
设这两个数为A和B;
因为A!=B
所以对于A和B的二进制表示而言，至少有一位不同，也就是说A的二进制表示Binary(A)和B的二进制表示Binary(B)
存在一位一个是0，另一个是1.因为0^1=1，所以这一位就在ans中。
通过找到ans中二进制表示中为1的最高位。
然后根据这一位将数组分为两部分，一部分是这一位为0，另一部分这一位全为1.
然后将所有这一位为1的数进行异或，求出的就是其中一个数。
然后将这个数与ans进行异或求出的就是另外一个数

********************/

#include<iostream>
#include<vector>
using namespace std;
int divide2(int num)//求出最高为1的二进制位
{
	int cnt = 0;
	while (num /= 2)
	{
		cnt++;
	}
	return cnt;
}
int main()
{
	vector<int> data;
	int tem;
	int cur = 0;
	while (cin >> tem)
	{
		data.push_back(tem);
		cur ^= tem;//求出 两个目标值的异或值
	}
	int n = 1 << divide2(cur);
	int one = 0, other = 0;
	for (auto elem : data)
	{
		if (elem & n)//对所有目标二进制位为1的数进行异或
			one ^= elem;//求出的值即为其中一个数
	}
	other = cur ^ one;
	cout << one << ' ' << other << endl;
}
