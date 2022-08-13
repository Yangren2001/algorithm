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
	int  m;    // 输入元素长度
	int* n = new int[200];
	cout << "输入元素长度：";
	cin >> m;
	cout << "输入元素: ";
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
	cout << "输入需要判断是否为质数的值:";
	while (cin >> v)
	{
		if (prime->IsPrime(v) == true) {
			cout << v << "是质数" << endl;
		}
		else if (prime->IsPrime(v) == false)
		{
			s++;
			cout << v << "不是是质数" << endl;
		}
		else  cout << "代码错误" << endl;
		cout << "合数个数:" << s << endl;
		cout << "输入需要判断是否为质数的值:";
	}*/

	// test();
	
	return 0;
}