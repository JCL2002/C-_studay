#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[103];
int Find(int x)//���ֲ���
{
    int l=0,r=99;int mid=(l+r)/2;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr[mid]==x) return mid;
        else if(arr[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return -1;
}
int main()
{
    srand(time(NULL));
    for(int i=0;i<100;i++) arr[i]=rand()%130;
    //����
    for(int i=0;i<99;i++)//��С��������
    {
        for(int j=i+1;j<100;j++)
        {
            if(arr[i]>arr[j])
            {
                //������򽻻���������
                arr[i]^=arr[j];
                arr[j]^=arr[i];
                arr[i]^=arr[j];
            }
        }
    }
    int n;
    printf("������Ҫ���в��ҵĴ���\n");
    scanf("%d",&n);
    int tar;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tar);
        printf("%d �������е�λ�ã� %d \n",tar,Find(tar));
    }
    return 0;
}
