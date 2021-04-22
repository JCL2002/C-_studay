#include<bits/stdc++.h>
using namespace std;
class Test{
	public:
		void Swap(int a,int b){
			return;
		}
		void Swap(int* a,int* b){
			int c;
			c=*a;
			*a=*b;
			*b=c;
			return;
		}
		void Swap(float &e,float &f){
			float c;
			c=e;
			e=f;
			f=c;
			return;
		}
		void Swap(int *p){
			int i;
			for(i=0;i<5;i++){
				p[i]++;
			}
		}
		void Print(int *p){
			int i;
			for(i=0;i<5;i++){
				cout << p[i]<<endl;
			}
		}
};

int main()
{
	int a, b;
	int c, d;
	float e, f;
	int ints[5];
	Test* o = new Test();


	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;
	for (int i = 0; i < 5; i++)
	{
		cin >> ints[i];
	}
	o->Swap(a, b);
	o->Swap(&c, &d);
	o->Swap(e, f);
	o->Swap(ints);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << fixed << setprecision(2) << e << endl;
	cout << fixed << setprecision(2) << f << endl;
	o->Print(ints);

	return 0;
}