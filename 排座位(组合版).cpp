//设0代表为A国人 1代表B国人 2代表C国人，则可以用一个长度为9的数组来代表这9个人。
//设数为3进制，逢3进1，
//则从000 000 000遍历到 222 222 222则包括了 3国人共9人的所有组合情况。然后对每一组进行判断，满足条件则数目加1。
#include < iostream > // 构造一个长度为9的3进制数组，初始为000 000 000 最高为 222 222 222 每次加一对其进行改变 保证组合的唯一性。
#include < vector > //缺点 会产生大量的不符合条件的组合，例如000 000 000 ，111 111 111 根本不满足题目条件的组合。这些组合其实没有判断价值 
using namespace std;
void plusOne( vector< int > & ) ;//每次加一，对元素进行改变
bool isEnd( const vector< int > & ) ;//是否是结尾
bool check( const vector< int > & ) ;//检查所得结果是否符合要求
int main()
{
	unsigned cnt = 0 ;
	vector < int > data( 9 , 0 ) ;
	while( !isEnd( data ) )
	{
		plusOne(data) ;
		if ( check( data ) )
			++cnt ;
	}
	cout<<cnt*6*6*6<<endl;//由于计算的是组合，最后还要针对排列进行扩充，A33 * A33 *A33才是最终结果，因为A国人和A国人是不一样的。
	return 0 ;
}
void plusOne( vector< int >&data ) //每次加一，按理来说应该是从末位开始往前加，但考虑到size_t的非负性 ，还是决定从前往后加。结果没影响，因为产生
{                                  //的组合数量和内容是一致的  
	auto length = data.size() ;
	for ( decltype( length ) i = 0 ; i < length ; ++i )
	{
		++data[ i ] ;
		if ( 3 == data[ i ] )//满3就进位 当前位置0
			data[ i ] = 0 ;
		else//否则就只加1 并返回
			return ;
	}
}
bool isEnd( const vector< int > &data )//当容器元素为 222 222 222时说明已经达到末尾了。
{
	for ( auto begin = data.cbegin() ; begin != data.cend() ; ++begin )
	{
		if ( *begin != 2 )
			return false ;
	}
	return  true ;
}
bool check( const vector< int > &data )//检查是否满足条件， 总共两个条件 1. 0 1 2每个元素分别要出现3次 2.连续三个元素不能一致
{
	int cnt0 = 0 , cnt1 = 0 , cnt2 = 0 ;
	for ( decltype( data.size() ) i = 0 ; i < data.size() ; ++i )
	{
		if ( i >=2 )
		{
			if ( data[ i ] == data[ i - 1 ] && data[ i - 1 ] == data[ i - 2 ] )
				return false ;
		}
		if ( data[ i ] == 0 )
			++cnt0 ;
		else if ( data[ i ] == 1 )
			++cnt1 ;
		else if ( data[ i ] == 2 )
			++cnt2 ;
	}
	if ( cnt0 == 3 && cnt1 == 3 && cnt2 == 3 )
		return true ;
	else
		return false ;
}
