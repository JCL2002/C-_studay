#include<iostream>
using namespace std;
#define PI 3.14159265
int main(){
	long long y,i=1,k=1,JC;//i����ѭ����y��ԭ���е�y��JC������׳�
	cout << "������һ���Ƕ�:"<<endl;
	cin >> y;
	double x;
	double current,M,sinx=0;
	x=y*PI/180;
	while(1){
		//����׳ˡ��ݴη�
		if(i!=1){
			k++;
			JC*=k;
			k++;
			JC*=k;
			M*=(x*x);
		}
		else {
			JC=i;
			M=x;
		}
		current=M/JC;
		if(current<0.0000001){
			break;
		}
		else{
			if(i%2){//������
				sinx+=current;
			}
			else{
				sinx-=current;
			}
		}
		i++;
	}
	cout << sinx;
	return 0;
}