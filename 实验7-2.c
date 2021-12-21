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
    struct HashEntry * Cells; /* �����Ŀ������ */
};

void Insert(struct HashTable t,int x)//���뺯��
{
    int i=x%t.TableSize;
    while(t.Cells[i].Info==Legitimate) i=(i+1)%t.TableSize;//Ѱ�Ҳ���λ��
    t.Cells[i].Data=x;
    t.Cells[i].Info=Legitimate;
}

int Find(struct HashTable t,int x)//���Һ���-�����±�
{
    int i=x%t.TableSize;
    int times=0;
    while( (t.Cells[i].Info==Legitimate || t.Cells[i].Info==Deleted) && t.Cells[i].Data!=x && ++times!=t.TableSize ) i=(i+1)%t.TableSize;//����̽��
    if(t.Cells[i].Data==x && t.Cells[i].Info==Legitimate) return i;//�ɹ�����
    return -1;//����ʧ��
}

int find_times(struct HashTable t,int x)
{
    int i=x%t.TableSize;
    int times=0;
    while( (t.Cells[i].Info==Legitimate || t.Cells[i].Info==Deleted) && t.Cells[i].Data!=x && ++times!=t.TableSize ) i=(i+1)%t.TableSize;//����̽��
    if(t.Cells[i].Data==x && t.Cells[i].Info==Legitimate) return times+1;//�ɹ�����
    return -1;//����ʧ��
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
    srand(time(NULL));//�������������
    struct HashTable ht;
    //��ʼ��hash��
    ht.TableSize=50;
    ht.Cells=(struct HashEntry*) malloc(50*sizeof(struct HashEntry));
    for(int i=0; i<50; i++)
    {
        ht.Cells[i].Data=0;
        ht.Cells[i].Info=Empty;
    }
    //��������
    for(int i=0; i<30; i++) Insert(ht,rand()%1001);
    printf("����Ԫ��\n");
    for(int i=0; i<ht.TableSize; i++)
    {
        if(ht.Cells[i].Info == Legitimate ) printf ("%d ",ht.Cells[i].Data);
    }
    printf("\n");
    //����
    int n;
    scanf("%d",&n);
    int res=Find(ht,n);
    if(res>0 )printf("%d �ڱ��е�λ�ã� %d\n",n,res);
    else printf("no find\n");

    //����ASL
    printf("ASL: %f",ASL(ht));
    return 0;
}
