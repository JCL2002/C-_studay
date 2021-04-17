#include<iostream>
using namespace std;
class fun{
	public:
		inline int GetMax(int a,int b){
			if (a>b){
				return a;
			}
			else{
				return b;
			}
		}
		inline char GetMax(char a,char b){
			if (a>b){
				return a;
			}
			else{
				return b;
			}
		}
};
int main(){
	fun function;
	cout << function.GetMax('a','c') << endl;
	cout << function.GetMax(2,3) <<endl;
	return 0;
}