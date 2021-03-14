//将num个方块从source经由transfer放到target上面
void Hanoi(int num,char source,char transfer,char target)
{
        //printf("src = %c  trans = %c tar = %c num = %d\n",source,transfer,target,num);
        if(num == 1)//如果只有一个方块,那么直接把source的方块放到target上
        {
                printf("%c->%c\n",source,target);
                return;
        }
        //把source上面的num-1个方块经由target放到transfer上。
        Hanoi(num-1,source,target,transfer);
        //把source上面最后的一个方块放到target上
        printf("%c->%c\n",source,target);
        //把transfer上面的num-1个方块经由source放到target上面。
        Hanoi(num-1,transfer,source,target);
}
