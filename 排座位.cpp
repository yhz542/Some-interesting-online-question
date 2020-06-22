#include <iostream>//排座位 要安排：3个A国人，3个B国人，3个C国人坐成一排。 要求不能使连续的3个人是同一个国籍。 求所有不同方案的总数？
#include <string>
using namespace std;
unsigned int cnt = 0 ;
void calculate( int [], int ) ;
bool check ( int *, int ) ;
int main()
{
	int data[ 9 ] ;
	calculate( data , 1 ) ;
	cout << cnt << endl ;
	return 0 ;
}
void calculate( int data[] , int layer )
{
	for ( int i = 0 ; i < 9 ; ++i )
	{
		data[ layer - 1 ] = i ;
		if ( !check( data , layer ) ) //如果两个数重复了，则直接丢弃，将当前位置赋给另一个人
			continue ;
		if ( layer >= 3 )
		{
			if ( (data[ layer-1 ]/3 == data[ layer - 2 ]/3) && (data[ layer - 3 ]/3 == data[ layer - 2 ]/3) )
				continue ;
			else if ( 9 == layer )//满足条件 计数+1
			{
				++cnt ;
				return ;
			}	
		}
		calculate( data , layer + 1 ) ;
	}
}
bool check ( int data[] , int layer )//判断是否重复
{
	for( int i = 0 ; i < layer - 1 ; ++i )
		if ( data[ i ] == data[ layer - 1 ] )
			return false ;
	return true ;
}
