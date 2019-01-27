#include <iostream>
#include <stack>
#include <string>//总思路：先去乘除，再算没有乘除的括号，再算括号前的乘除，最后算没有括号的加减
using namespace std ;
enum objType { LP , RP , ADD , SUB , VAL , MUL , DIV } ;
class Type
{
public:
        objType type = VAL;
        double value = 0 ;
};
double Compute( string &calculation );
void CalculInPar(stack<Type> &store );
void CalCulVal( stack<Type> &store ) ;
void FinalCalcul( stack<Type> &store );
int main()
{
        string source ;
        getline(cin , source ) ;
        cout << Compute( source ) ;
}
double Compute( string &calculation )
{
        double result = 0 ;
        stack<Type> store ;
        size_t len = calculation.size() ;
        for( size_t index = 0 ; index < len ; )
        {
                Type obj ;
                //忽略无用的空格
                while( ' ' == calculation[ index ] )
                        ++index ;
                switch( calculation[ index ] )//根据当前字符串位置内容决定元素类型
                {
                        case '(':
                                obj.type = LP ;
                                break ;
                        case '+':
                                obj.type = ADD ;
                                break ;
                        case '-':
                                obj.type = SUB ;
                                break ;
                        case '*':
                                obj.type = MUL ;
                                break ;
                        case '/':
                                obj.type = DIV ;
                                break ;
                        case ')':
                                obj.type = RP ;
                                break ;
                        default://数值类型 特殊处理
                                size_t pos ;
                                obj.type = VAL ;
                                obj.value = stod( calculation.substr( index ) , &pos ) ;
                                index += pos ;
                                --index ;//配合++index使用,保证index正确性
                                break ;
                }
                store.push( obj ) ;//将解析出的元素压入栈中
                ++index ;//将字符串光标后移一个单位
                //如果栈顶是右括号(因为会出现例如1*(2+3) 这种情况，所以去除括号后要探测生成的数值是否需要处理乘除法，所以CalCulVal函数放在处理括号
                if ( store.top().type == RP )//的函数之后。
                {
                        CalculInPar( store ) ;
                }
                //如果栈顶是数值
                if ( store.top().type == VAL )
                {
                        CalCulVal( store ) ;
                }
        }
        //读完整个字符串开始做没有括号的加减法
        if( store.size() > 1 )
        {
                FinalCalcul( store );
        }
        return store.top().value ;
}
void CalculInPar(stack<Type> &store )//括号只处理加减法，乘除法交给数值函数去处理
{
        store.pop();//弹出右括号;
        double sum = 0 ;
        double tem = 0 ;
        while( store.top().type != LP )
        {
                if( store.top().type == VAL )//如果是数值
                {
                        tem = store.top().value ;
                        store.pop() ;
                        if( store.top().type == LP )
                        {
                                sum += tem ;
                        }
                }
                else if( store.top().type == SUB )//如果为减号，将之前读入的值变为负值加入总值
                {//1-2 等同于 1+(-2)
                        tem *= -1 ;
                        sum += tem ;
                        store.pop() ;
                }
                else//如果是加号 不改变tem符号 直接将其加入总值
                {
                        sum += tem ;
                        store.pop();
                }
        }
        store.pop();//弹出左括号
        Type obj ;//将获得的结果压入栈中 交给针对数值的函数处理
        obj.type = VAL ;
        obj.value = sum ;
        store.push( obj ) ;
}
void CalCulVal( stack<Type> &store )
{
        Type obj;
        obj.type = VAL ;
        double result = 0 ;
        double val = store.top().value ;
        store.pop() ;//弹出数值;
        if( store.empty() )//如果为空,不能再次取栈顶元素.
        {
                obj.value = val ;
                store.push( obj ) ;
                return ;
        }
        else
        {
                auto symbol = store.top().type ;
                if( symbol == MUL )
                {
                        store.pop() ;//弹出乘号
                        result = store.top().value * val ;//计算乘积
                        store.pop() ;//弹出乘数
                }
                else if ( symbol == DIV )
                {
                        store.pop() ;//弹出除号
                        result = store.top().value / val ;//计算商
                        store.pop();//弹出被除数
                }
                else//如果为加减法,不做计算再把弹出的数值压入栈中
                {
                        result = val ;
                }
        }
        obj.value = result ;
        store.push( obj ) ;//将结果压入栈中
}
void FinalCalcul( stack<Type> &store )
{
        double sum = 0 ;
        double tem = 0 ;
        while( !store.empty() )
        {
                if( store.top().type == VAL )
                {
                        tem = store.top().value ;
                        store.pop() ;//数值出栈
                        if( store.empty() )
                                sum += tem ;
                }
                else if( store.top().type == SUB )//如果为减号，将之前读入的值变为负值加入总值
                {//1-2 等同于 1+(-2)
                        tem *= -1 ;
                        sum += tem ;
                        store.pop() ;
                }
                else//如果是加号 不改变tem符号 直接将其加入总值
                {
                        sum += tem ;
                        store.pop();
                }
        }
        Type obj ;
        obj.type = VAL ;
        obj.value = sum ;
        store.push( obj ) ;
}
//对于一个运算式，优先处理括号和乘除法，遇到一个数值就要看一下它前一个位置是符号还是括号，如果是左括号或者加减都不处理，如果是乘除就处理。
