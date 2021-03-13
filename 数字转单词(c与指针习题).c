#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdarg.h>
void commonWrite(unsigned int num,char *buffer,const char *attach)
{
        if(!num)
                return;
        switch(num)
        {
        case 1:
                strcat(buffer," ONE");
                break;
        case 2:
                strcat(buffer," TWO");
                break;
        case 3:
                strcat(buffer," THREE");
                break;
        case 4:
                strcat(buffer," FOUR");
                break;
        case 5:
                strcat(buffer," FIVE");
                break;
        case 6:
                strcat(buffer," SIX");
                break;
        case 7:
                strcat(buffer," SEVEN");
                break;
        case 8:
                strcat(buffer," EIGHT");
                break;
        case 9:
                strcat(buffer," NINE");
                break;
        default:
                break;
        }
        strcat(buffer,attach);
}
void convert_amount(unsigned int amount ,char *buffer,int Nthousands)
{
        if(!amount)
        {
                return;
        }
        printf("Nthousands = %d amount = %d\n",Nthousands,amount);
        convert_amount(amount/1000,buffer,Nthousands+1);
        int partNum;
        int threeNum;
        switch(Nthousands)
        {
        case 0:
                partNum = amount % 1000;
                printf("part = %d\n",partNum%10);
                commonWrite(partNum/100,buffer," HUNDRED");
                commonWrite(partNum/10%10,buffer,"");
                commonWrite(partNum%10,buffer,"");
                break;
        case 1:
                partNum = amount % 1000;
                commonWrite(partNum/100,buffer," HUNDRED");
                commonWrite(partNum/10%10,buffer,"");
                commonWrite(partNum%10,buffer,"");
                strcat(buffer," THOUSAND");
                break;
        }
}
//半成品,把amount的值转换成单词形式，并存储于buffer中 例如如果amount的值是16 312,那么buffer中存储的字符串应该是
//SIXTEEN THOUSAND THREE HUNDRED TWELVE
void written_amount(unsigned int amount,char *buffer)
{
        if(!amount)
                strcpy(buffer,"ZERO");
        convert_amount(amount,buffer,0);
}
int main(void)
{
        char buffer[1000];
        memset(buffer,0,sizeof(buffer));
        written_amount(134144,buffer);
        puts(buffer);
}
