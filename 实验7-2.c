#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum EntryType {Legitimate, Empty, Deleted};

struct HashEntry
{
    int Data;
    enum EntryType Info;
};

struct HashTable
{
    int TableSize;
    struct HashEntry * Cells; /* 存放条目的数组 */
};

void Insert(struct HashTable t,int x)//插入函数
{
    int i=x%t.TableSize;
    while(t.Cells[i].Info==Legitimate) i=(i+1)%t.TableSize;//寻找插入位置
    t.Cells[i].Data=x;
    t.Cells[i].Info=Legitimate;
}

int Find(struct HashTable t,int x)//查找函数-返回下标
{
    int i=x%t.TableSize;
    int times=0;
    while( (t.Cells[i].Info==Legitimate || t.Cells[i].Info==Deleted) && t.Cells[i].Data!=x && ++times!=t.TableSize ) i=(i+1)%t.TableSize;//线性探测
    if(t.Cells[i].Data==x && t.Cells[i].Info==Legitimate) return i;//成功查找
    return -1;//查找失败
}

int find_times(struct HashTable t,int x)
{
    int i=x%t.TableSize;
    int times=0;
    while( (t.Cells[i].Info==Legitimate || t.Cells[i].Info==Deleted) && t.Cells[i].Data!=x && ++times!=t.TableSize ) i=(i+1)%t.TableSize;//线性探测
    if(t.Cells[i].Data==x && t.Cells[i].Info==Legitimate) return times+1;//成功查找
    return -1;//查找失败
}

float ASL(struct HashTable t)
{
    int num=0,sum=0;
    for(int i=0; i<t.TableSize; i++)
    {
        if(t.Cells[i].Info==Legitimate)
        {
            num++;
            sum+=find_times(t,t.Cells[i].Data);
        }
    }
    return (float) sum / num;
}

int main()
{
    srand(time(NULL));//设置随机数种子
    struct HashTable ht;
    //初始化hash表
    ht.TableSize=50;
    ht.Cells=(struct HashEntry*) malloc(50*sizeof(struct HashEntry));
    for(int i=0; i<50; i++)
    {
        ht.Cells[i].Data=0;
        ht.Cells[i].Info=Empty;
    }
    //插入数据
    for(int i=0; i<30; i++) Insert(ht,rand()%1001);
    printf("表中元素\n");
    for(int i=0; i<ht.TableSize; i++)
    {
        if(ht.Cells[i].Info == Legitimate ) printf ("%d ",ht.Cells[i].Data);
    }
    printf("\n");
    //查找
    int n;
    scanf("%d",&n);
    int res=Find(ht,n);
    if(res>0 )printf("%d 在表中的位置： %d\n",n,res);
    else printf("no find\n");

    //计算ASL
    printf("ASL: %f",ASL(ht));
    return 0;
}
