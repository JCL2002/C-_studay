#include<bits/stdc++.h>
using namespace std;
void strlow(char * t){//ת����Сд
	int len=(int)strlen(t);
	for(int j=0;j<len;j++){
		if(t[j]>='A'&&t[j]<='Z'){
			t[j]+=32;
		}
	}
}
bool test(char *text,int i,char *target,int len_text,int len_tar){
	for(int j=0;j<len_tar;j++,i++){
		if(i==len_text){//ƥ�䲻��
			return false;
		}
		if(text[i]!=target[j]){//��ƥ��
			return false;
		}
	}
	if(text[i]=='\0'||text[i]==' '){
		return true;	
	}
	return false;
}
int main(){
	char text[1000001];
	char target[11];
	int location=-1;//��һ��λ��
	int times=0;//���ִ���
	
	gets(target);
	gets(text);
	strlow(text);
	strlow(target);
	int len_text=strlen(text),len_tar=strlen(target);
	bool _new=false;//��־�ǲ���һ���µĵ���
	bool empty=true;//�ո��־
	for(int i=0;i<len_text;i++){
		if(text[i]!=' '){
			if(empty){
				_new=true;
			}
			else{
				_new=false;
			}
			if(_new){//�µĵ���
				if(test(text,i,target,len_text,len_tar)){
					if(!times){
						times++;
						location=i;
					}
					else{
						times++;
					}
				}
			}
			empty=false;	
		}
		else{
			empty=true;
		}	
	}
	if(location>=0){
		cout <<times<<' ' <<location;
	}
	else{
		cout <<location;
	}
	return 0;
}