#include<stdio.h>
int main(){
    void hanoi(int n,char from,char help,char target);
    int m;
    printf("input the number of diskes:");
    scanf("%d",&m);
    hanoi(m,'A','B','C');
    return 0;
    }
void hanoi(int n,char from,char help,char target){
    void move(char from,char target);
    if (n==1) move(from,target);
    else{
        hanoi(n-1,from,target,help);
        move(from,target);
        hanoi(n-1,help,from,target);
        }
    }
void move(char from,char target){
printf("%c-->%c\n",from,target);}
