#include <iostream>
#include <vcruntime.h>
#include "GreatestCommonsiDvisor.h"
using namespace std;

GreatestCommonDisvisor::GreatestCommonDisvisor()
{
	// 构造函数
}

void GreatestCommonDisvisor::temp(int& var1, int& var2) {
	/*
	* 交换var1, var2的值
	* param var1:变量
	* param var2: 变量
	*/
	int t;
	t = var1;
	var1 = var2;
	var2 = t;
}

void GreatestCommonDisvisor::Test() {
	/*
	* 测试最大公约数计算算法
	*/
	int x, y;
	cout << "最大公约数计算" << "\n请输入x=";;
	cin >> x;
	if (x == -1) return;
	if (x <= 0)
	{
		cout << "输入错误，x 为整数" << endl;
	}
	cout << "请输入y=";
	cin >> y;
	cout << endl;
	if (y <= 0)
	{
		cout << "输入错误，y 为整数" << endl;
	}
	int s;
	this->GetResult(x, y, s);
	cout << x << "与" << y << "最大公约数为:" << s << "\n最小公倍数为：" << (x * y) / s << endl;
	this->Test();
}


void GreatestCommonDisvisor::GetResult(int var1, int var2, int& result)
{
	/*
	* 获取最大公约数
	* 
	* param var1:
	* param var2:
	* param result: 引用变量, 返回最大公约数
	* return :
	*/ 
	this->remainder = var1 % var2;	 // 初始化余数
	while (this->remainder != 0) {
		// 交换变量值
		var1 = var2;
		var2 = this->remainder;
		this->remainder = var1 % var2;
	}
	result = var2;
}

GreatestCommonDisvisor::~GreatestCommonDisvisor()
{
	// 析构函数
}