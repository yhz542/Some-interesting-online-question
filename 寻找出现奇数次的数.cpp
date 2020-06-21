#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#define NotExisted (1<<31)
using namespace std;
//题目：有一个数组，数组中有很多元素，除了一个数只出现过奇数次以外，其他的数都出现过偶数次。
//要求找出这个只出现过奇数次的数
class FindOddNumber
{
	vector<int> data;
	int target;
public:
	FindOddNumber(istream& in):target(NotExisted)
	{
		int num;
		int tem = 0 ;
		while (in >> num)
		{
			data.push_back(num);
			tem ^= num;//利用异或的性质，任何数异或本身都等于0，也就是说出现了偶数次的数会全部异或成0，对所有的数进行异或，留下了就是出现了奇数词的数。
		}
		target = tem;
	}
	void Solve()
	{
		
	}
	void Print()
	{
		cout << target << endl;
	}
};
int main()
{
	FindOddNumber test(cin);
	test.Solve();
	test.Print();
}
