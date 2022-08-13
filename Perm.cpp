/*
* 全排列问题
*/

#include <iostream>
#include "Perm.h"

using namespace std;

template<class T> Permutation<T>::Permutation() {
	this->n = new T[200];

}

template<class T> void Permutation<T>::swap(T& a, T& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

template<class T> void Permutation<T>::perm(T* ls, int k, int m) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << ls[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = k + 1; i < m; i++) {
			this->swap(ls[k], ls[i]);
			this->perm(ls, k + 1, m);
		}
	}

}

template<class T> void Permutation<T>::test() {
	int  m;    // 输入元素长度
	cout << "输入元素长度：";
	cin >> m;
	cout << "输入元素: ";
	for (int i = 0; i < m; i++) {
		cin >> this->n[i];
	}
	this->perm(this->n, 0, m);
}

