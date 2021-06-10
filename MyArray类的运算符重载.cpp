#include<bits/stdc++.h>
using namespace std;
class MyArray{
	private:
		int size;
		int *ptr;
	public:
		MyArray(){
			
		}
		MyArray(int n){
			ptr=new int[n];
			size=n;
		}
		int& operator[](int a){
			return ptr[a];
		}
		int getSize(){
			return size;
		}
		MyArray(MyArray& b){
			size=b.size;
			ptr=(int*)malloc(sizeof(int)*b.size);
			for(int i=0;i<size;i++){
				ptr[i]=b[i];
			}
		}
		friend ostream& operator<<(ostream& out,const MyArray &a);
		MyArray operator+(MyArray& b){
			MyArray c(b.size);
			for(int i=0;i<b.size;i++){
				c[i]=ptr[i]+b[i];
			}
			return c;
		}
		MyArray operator-(MyArray& b){
			MyArray c(b.size);
			for(int i=0;i<b.size;i++){
				c[i]=ptr[i]-b[i];
			}
			return c;
		}
		int operator*(MyArray& b){
			int sum=0;
			for(int i=0;i<b.size;i++){
				sum+=(ptr[i]*b[i]);
			}
			return sum;
		}
		~MyArray(){
			free(ptr);//释放内存
		}
};
ostream& operator<<(ostream& out,MyArray &a){//<<的重载
	for(int i=0;i<5;i++){
		out << a[i];
		if(i<4){
			out <<',';
		}
	}
	out <<endl;
	return out;
}

int main(){
	int n;
	cin>>n;
	MyArray arr1(n);
	for(int i=0;i<arr1.getSize();i++)
		cin>>arr1[i];
	cout<<arr1;
	
	MyArray arr2(arr1);
	for(int i=0;i<arr2.getSize();i++)
		arr2[i]+=1;
	cout<<arr2;
	MyArray arr3,arr4;
	arr3=arr2+arr1;
	cout<<arr3;
	arr4=arr2-arr1;
	cout<<arr4;
	
	cout<<arr1*arr2<<endl;
	
	return 0;
}
