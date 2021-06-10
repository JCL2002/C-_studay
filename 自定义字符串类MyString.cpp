#include<bits/stdc++.h>
using namespace std;
class MyString{
	private:
		char *sptr;
	public:
		MyString(){//默认构造函数
			sptr=NULL;//指针指空
			cout <<"Object Constructed. No Memory Allocated."<<endl;
			}
		MyString(string p){//构造函数
			sptr=(char*)malloc(p.length()+1);//就是不用new
			int i;
			for(i=0;i<(int)p.length();i++){
				sptr[i]=p[i];
				}
			sptr[i]='\0';
			cout <<"Object Constructed. "<<(int)strlen(sptr)+1<<" Bytes Allocated."<<endl;
			}
		MyString(const MyString& s){//拷贝构造
			sptr=(char*)malloc((int)strlen(s.sptr)+1);
			strcpy(sptr,s.sptr);
			cout <<"Object Constructed. "<<(int)strlen(sptr)+1<<" Bytes Allocated."<<endl;
			}
		int getSize(){
			if(sptr==NULL) return 0;
			return (int)strlen(sptr);
			}
		void printString(){//打印函数
			if(sptr==NULL){
				cout <<"No Memory Allocated In This Object."<<endl;
				}
			else{
				cout <<sptr<<endl;
				}
			}
		void stringCopy(const MyString& s){
			int ori=(int)strlen(sptr)+1;//记录原来的长度
			sptr=(char*)realloc((void*)sptr,(int)strlen(s.sptr)+1);//重新分配内存空间
			strcpy(sptr,s.sptr);
			cout <<"String Copy, "<<(int)strlen(sptr)+1<<" Bytes Reallocated And "<<ori<<" Bytes Freed."<<endl;
			}
		void stringCat(const MyString& s){
			int ori=(int)strlen(sptr);int j=ori;
			sptr=(char*)realloc((void*)sptr,ori+(int)strlen(s.sptr)+1);//空间扩容
			for(int i=0;i<(int)strlen(s.sptr);i++){
				sptr[ori++]=s.sptr[i];
				}
			sptr[ori]='\0';
			cout <<"String Connection, "<<ori+1<<" Bytes Reallocated And "<<j+1<<" Bytes Freed."<<endl;
			}
		~MyString(){
			if(sptr!=NULL){
				cout <<"Object Destructed. "<<(int)strlen(sptr)+1<<" Bytes Freed."<<endl;
				free(sptr);
				}
			else{
				cout <<"Object Destructed. No Memory Freed."<<endl;
				}
			}
};

int main(){
	MyString s1;
	MyString s2("Hello");
	MyString s3(s2);
	
	s1.printString();
	s2.printString();
	s3.printString();
	
	cout<<s1.getSize()<<" "<<s2.getSize()<<" "<<s3.getSize()<<endl;
	
	MyString s4("HiChina"); 
	
	s2.stringCopy(s4);
	s2.printString();
	
	s3.stringCat(s4);
	s3.printString(); 
	
	return 0;
}