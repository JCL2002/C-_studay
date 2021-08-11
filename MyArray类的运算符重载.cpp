#include<bits/stdc++.h>
using namespace std;

class MyArray {
private:
	int size;
	int* ptr;
	friend ostream& operator<<(ostream& out, const MyArray& A);
public:
	MyArray(int n) :size{ n } {
		ptr = new int[size];
	}
	MyArray(const MyArray& o1) {
		size = o1.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			*(ptr + i) = *(o1.ptr + i);
		}
	}
	MyArray() {
		size = 1;
		ptr = new int[1];
	}
	~MyArray() {
		delete[]ptr;
	}
	int getSize() {
		return size;
	}
	int& operator[](int i) {
		return *(ptr + i);
	}
	void operator=(const MyArray& o1) {
		size = o1.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			*(ptr + i) = *(o1.ptr + i);
		}
	}
	MyArray operator+(const MyArray& o1) {
		MyArray o2(o1.size);
		for (int i = 0; i < size; i++) {
			*(o2.ptr + i) = *(o1.ptr + i) + *(ptr + i);
		}
		return o2;
	}
	MyArray operator-(const MyArray& o1) {
		MyArray o2(o1.size);
		for (int i = 0; i < size; i++) {
			*(o2.ptr + i) = *(ptr + i) - *(o1.ptr + i);
		}
		return o2;
	}
	int operator*(const MyArray& o1) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += *(o1.ptr + i) * *(ptr + i);
		}
		return sum;
	}
};
ostream& operator<<(ostream& out, const MyArray& A) {
	cout << A.ptr[0];
	for (int i = 1; i < A.size; i++) {
		cout << "," << *(A.ptr + i);
	}
	cout << endl;
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
