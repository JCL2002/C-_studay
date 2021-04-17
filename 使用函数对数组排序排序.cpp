#include<stdio.h>
void sort( int a[], int n ){
	int tmp; 
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];a[j]=a[j+1];a[j+1]=tmp;
			}
		}
	}
}
int main()
{
    int i, n;
    scanf("%d",&n);
    int a[n];

    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);

    sort(a, n);

    printf("After sorted the array is:");
    for( i = 0; i < n; i++ )
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}
