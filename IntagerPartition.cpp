#include "IntagerPartition.h"
#include <iostream>

using namespace std;

IntegerPartition::IntegerPartition() {

}

bool IntegerPartition::partition(int n, int m, int& result) {
	/*
	* param n: ����
	* param m: ��󻮷�
	* param result: ���㻮�ִ���
	*/
	if (n < 1 || m < 1) { result = 0; return false; }
	else if (n == 1 || m == 1) {
		result = 1;
		return true;
	}
	else if (n == m) {
		int r0 = 0;
		this->partition(n, m - 1, r0);
		result += r0 + 1;
		return true;
		
	}
	else if (n < m) {
		
		int r3 = 0;
		this->partition(n, n, r3);
		result += r3;
		return true;
	}
	else
	{
		int r1=0, r2=0;
		this->partition(n - m, m, r1);
		this->partition(n, m - 1, r2);
		result += r1 + r2;
		return true;
	}
}

void IntegerPartition::test() {
	// ���Է���
	int n, r = 0;
	cout << "���뻮����ֵ:";
	cin >> n;
	this->partition(n, n, r);
	cout << "�������������:" << r << endl;
}