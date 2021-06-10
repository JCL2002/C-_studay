#include<bits/stdc++.h>
using namespace std;
class MyString{
	char *ptr;
public:
	int size()const{
		return strlen(ptr);
	}
	MyString(){
		ptr=new char[1];
		ptr[0]='\0';
	}
	MyString(const char *p){
		ptr=new char[strlen(p)+1];
		strcpy(ptr,p);
	}
	MyString(const MyString &str){
		ptr=new char[str.size()+1];
		strcpy(ptr,str.ptr);
	}
	~MyString(){
		delete []ptr;
	}
	friend ostream& operator<<(ostream & out,const MyString &str); 
	friend MyString operator+(const MyString &s1,const MyString &s2); 
	friend int operator==(const MyString &s1,const MyString &s2);
	friend int operator!=(const MyString &s1,const MyString &s2);
	friend int operator<(const MyString &s1,const MyString &s2);
	friend int operator<=(const MyString &s1,const MyString &s2);
	friend int operator>(const MyString &s1,const MyString &s2);
	friend int operator>=(const MyString &s1,const MyString &s2);
	MyString & operator=(const MyString &s);
	MyString & operator+=(const MyString &s);
	char operator[](int i);
}; 
ostream& operator<<(ostream& out,const MyString& str){
	for(int i=0;i<(int)strlen(str.ptr);i++){
		out << str.ptr[i];
	}
	return out;
}
MyString operator+(const MyString& s1,const MyString& s2){
	char cache[32];
	int i=0;
	for(int j=0;j<(int)strlen(s1.ptr);j++,i++){
		cache[i]=s1.ptr[j];
		}
	for(int j=0;j<(int)strlen(s2.ptr);j++,i++){
		cache[i]=s2.ptr[j];
		}
	cache[i]='\0';
	MyString c(cache);
	return c;
}
int operator==(const MyString& s1,const MyString& s2){
	if(strcmp(s1.ptr,s2.ptr)){
		return 0;
		}
	return 1;
}
int operator!=(const MyString& s1,const MyString& s2){
	if(strcmp(s1.ptr,s2.ptr)){
		return 1;
		}
	return 0;
}
int operator<(const MyString& s1,const MyString& s2){
	if(strcmp(s1.ptr,s2.ptr)<0){
		return 1;
		}
	return 0;
}
int operator<=(const MyString& s1,const MyString& s2){
	if(strcmp(s1.ptr,s2.ptr)<=0){
		return 1;
		}
	return 0;
}
int operator>(const MyString& s1,const MyString& s2){
	if(strcmp(s1.ptr,s2.ptr)>0){
		return 1;
		}
	return 0;
}
int operator>=(const MyString& s1,const MyString& s2){
	if(strcmp(s1.ptr,s2.ptr)>=0){
		return 1;
		}
	return 0;
}
MyString& MyString::operator=(const MyString& s1){
	strcpy(this->ptr,s1.ptr);
	return *this;
}
MyString& MyString::operator+=(const MyString& s1){
	char cache[32];
	int i=0;
	for(int j=0;j<(int)strlen(this->ptr);j++,i++){
		cache[i]=this->ptr[j];
		}
	for(int j=0;j<(int)strlen(s1.ptr);j++,i++){
		cache[i]=s1.ptr[j];
		}
	cache[i]='\0';
	strcpy(this->ptr,cache);
	return *this;
}
char MyString::operator[](int i){
	return this->ptr[i];
}

int main(){
	
	MyString s1("Hello"),s2("World"),s3("China");
	cout<<(s1>s2)<<" "<<(s1>=s2)<<" "<<(s1<=s2)<<" "<<(s2<s3)<<endl;
	cout<<(s1==s2)<<" "<<(s1!=s3)<<endl;
	MyString s4=s1+s2;
	cout<<s4<<endl;
	s1=s2=s3;
	cout<<s1<<" "<<s2<<" "<<s3<<endl;
	s4+=s3;
	cout<<s4<<endl;
	for(int i=s4.size()-1;i>=0;i--)
		cout<<s4[i];
	cout<<endl;
	return 0; 
}
