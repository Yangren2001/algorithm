#include <iostream>
#include "GreatestCommonsiDvisor.h"
#include "MaxDiv.h"
#include "IntagerPartition.h"
#include "AlgorithmQuestion.cpp"
#include "Perm.cpp"
using namespace std;

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

void perm(int* ls, int k, int m) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << ls[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = k; i < m; i++) {
			swap(ls[k], ls[i]);
			perm(ls, k + 1, m);
			swap(ls[k], ls[i]);
			cout << "aaa=" << i << endl;
		}
	}

}

void test() {
	int  m;    // ����Ԫ�س���
	int* n = new int[200];
	cout << "����Ԫ�س��ȣ�";
	cin >> m;
	cout << "����Ԫ��: ";
	for (int i = 0; i < m; i++) {
		cin >> n[i];
	}
	perm(n, 0, m);
}

int main() {
	AlgorithmQuestion<int>* test = new AlgorithmQuestion<int>();
	test->test();
	/*Prime::Prime* prime = new Prime::Prime();
	int v;
	int s = 0;
	cout << "������Ҫ�ж��Ƿ�Ϊ������ֵ:";
	while (cin >> v)
	{
		if (prime->IsPrime(v) == true) {
			cout << v << "������" << endl;
		}
		else if (prime->IsPrime(v) == false)
		{
			s++;
			cout << v << "����������" << endl;
		}
		else  cout << "�������" << endl;
		cout << "��������:" << s << endl;
		cout << "������Ҫ�ж��Ƿ�Ϊ������ֵ:";
	}*/

	// test();
	
	return 0;
}