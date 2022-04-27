/*
华为机试题(od)
n个人分m个月饼
每个人至少分一个月饼
且每个人分的月饼排序后，相邻分的月饼数差值不能大于3
问总共有多少种方法
同时同样的分配数量分给不同的人,只记一次方法。
举例 2个人分3个月饼。只有1种方法,因为1 3 和 3 1认为是同一种分法。
类八皇后问题
*/
#include<stdio.h>
#include<stdlib.h>
#define DifferBiggerThan3(cur,last) ((personID != 1)&&((cur)-(last) > 3))
#define curAllocateCakeNum personCakeNum[personID]
#define lastAllocateCakeNum personCakeNum[personID - 1]
#define remainCakeNum (curCakeNum - curAllocateCakeNum)
int cakeNum,personNum;
int cnt = 0;
int *personCakeNum;
//函数含义:给第personID个人分配月饼
//参数含义:personID 人的ID号 curCakeNum:当前可分配的月饼数
//函数思想:依次给第1,第2,第3……个人分配月饼,同时分配的月饼数依次递增
//设第1个人分配的月饼为n1,第二个人分配的月饼为n2…… 则n1<=n2<=n3……
//函数每次递归后,确保本次分配的月饼至少要大于上一次
//另注意涉及到的剪枝方法,按照递增分配月饼的设计,对于每次分配月饼,至多只能分配当前剩余月饼数/剩余人数.
//所以每次分配月饼遍历的范围为 上次分配的月饼数——>当前剩余月饼数/剩余人数
//本函数采用的是逆向遍历,即当前剩余月饼数/剩余人数——>上次分配的月饼数。
void allocateCake(int personID,int curCakeNum)
{
        //printf("cur person = %d curCakeNum = %d lastAllocateCakeNum = %d\n",personID,curCakeNum,lastAllocateCakeNum);
        if(personID == personNum )
        {
                if(!DifferBiggerThan3(curCakeNum,personCakeNum[personID-1]))
                {
                        ++cnt;
                        curAllocateCakeNum = curCakeNum;
                        for(int i = 1 ; i <= personNum ; ++i)
                                printf("%d ",personCakeNum[i]);
                        puts("\nfind a way");
                }
                return;
        }
        int remainPerson = personNum - personID + 1;//计算剩余人数
        int curAllocateCakeNumMax = curCakeNum / remainPerson;//计算本轮可分配月饼的上限值。
        for( curAllocateCakeNum = curAllocateCakeNumMax ; curAllocateCakeNum >= lastAllocateCakeNum ;--curAllocateCakeNum)
        {
                if(DifferBiggerThan3(curAllocateCakeNum,lastAllocateCakeNum))//如果差值大于3 则跳过
                        continue;
                //printf("curAllocateCakeNum = %d remainCakeNum = %d curAllocateCakeNumMax = %d\n",curAllocateCakeNum,remainCakeNum,curAllocateCakeNumMax);
                allocateCake(personID + 1 , remainCakeNum);
        }
}

int main(void)
{

    scanf("%d %d",&personNum,&cakeNum);
    personCakeNum = (int *)malloc(sizeof(int)*(personNum + 1));
    if(personNum)
        personCakeNum[0] = 1;//设为1,在第一个人取月饼时确保至少取一个
    allocateCake(1,cakeNum);
    printf("%d",cnt);
    return 0;
}
