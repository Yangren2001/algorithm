#include <iostream>
#include <vcruntime.h>
#include "GreatestCommonsiDvisor.h"
using namespace std;

GreatestCommonDisvisor::GreatestCommonDisvisor()
{
	// ���캯��
}

void GreatestCommonDisvisor::temp(int& var1, int& var2) {
	/*
	* ����var1, var2��ֵ
	* param var1:����
	* param var2: ����
	*/
	int t;
	t = var1;
	var1 = var2;
	var2 = t;
}

void GreatestCommonDisvisor::Test() {
	/*
	* �������Լ�������㷨
	*/
	int x, y;
	cout << "���Լ������" << "\n������x=";;
	cin >> x;
	if (x == -1) return;
	if (x <= 0)
	{
		cout << "�������x Ϊ����" << endl;
	}
	cout << "������y=";
	cin >> y;
	cout << endl;
	if (y <= 0)
	{
		cout << "�������y Ϊ����" << endl;
	}
	int s;
	this->GetResult(x, y, s);
	cout << x << "��" << y << "���Լ��Ϊ:" << s << "\n��С������Ϊ��" << (x * y) / s << endl;
	this->Test();
}


void GreatestCommonDisvisor::GetResult(int var1, int var2, int& result)
{
	/*
	* ��ȡ���Լ��
	* 
	* param var1:
	* param var2:
	* param result: ���ñ���, �������Լ��
	* return :
	*/ 
	this->remainder = var1 % var2;	 // ��ʼ������
	while (this->remainder != 0) {
		// ��������ֵ
		var1 = var2;
		var2 = this->remainder;
		this->remainder = var1 % var2;
	}
	result = var2;
}

GreatestCommonDisvisor::~GreatestCommonDisvisor()
{
	// ��������
}