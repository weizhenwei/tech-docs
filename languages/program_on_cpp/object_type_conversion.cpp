// TypeSwitch.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

using namespace std;

class Complex
{
public:
	Complex():real(0),imag(0){};
	Complex(double r, double i):real(r),imag(i){};
	Complex(double r):real(r),imag(0){};  // 定义转换构造函数

	void Print(){
		cout<<"real = " << real <<" image = "<<imag<<endl;
	}

	operator double(){ // 定义类型转换函数
		return real;
	}

private:
	double real;
	double imag;
};

int main(int argc, char* argv[])
{
	Complex c1(1.2, 2.3);
	double d;
	d = c1 + 1.1; // 调用类型转换函数将c1转换为double
	cout<<d<<endl;
	
	return 0;
}

