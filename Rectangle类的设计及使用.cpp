#include<bits/stdc++.h>
using namespace std;

class Rectangle{
	private:
		int top,right,bottom,left;
	public:
		Rectangle(int top,int right,int bottom,int left){
			if(top-bottom>0&&right-left>0){
				this->top=top;
				this->left=left;
				this->bottom=bottom;
				this->right=right;
			}
			else{
				this->top=0;this->bottom=0;this->left=0;this->right=0;
			}
		}
		void showLeftTop(){
			cout << left << ',' << top <<endl;
		}
		void showRightTop(){
			cout << right << ',' << top <<endl;
		}
		void showLeftBottom(){
			cout << left << ',' << bottom <<endl;
		}
		void showRightBottom(){
			cout << right << ',' << bottom <<endl;
		}
		int getHeight(){
			return top-bottom;
		}
		int getWidth(){
			return right-left;
		}
		int getArea(){
			return Rectangle::getHeight()*Rectangle::getWidth();
		}
		int getPerimeter(){
			return Rectangle::getHeight()*2+Rectangle::getWidth()*2;
		}
};

int main(){
	int top,bottom,left,right;
	cin>>top>>right>>bottom>>left;
	Rectangle r(top,right,bottom,left);
	r.showLeftTop();   //输出左上顶点的坐标 
	r.showRightTop();  //输出右上顶点的坐标 
	r.showLeftBottom();  //输出左下顶点的坐标 
	r.showRightBottom();  //输出右下顶点的坐标 
	cout<<r.getHeight()<<" "<<r.getWidth()<<endl;  //输出高和宽 
	cout<<r.getArea()<<" "<<r.getPerimeter()<<endl;  //输出面积和周长 
	return 0;
}
