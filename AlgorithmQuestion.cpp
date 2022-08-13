#include <iostream>
#include "AlgorithmQuestion.h"

using namespace std;

template <class T>
AlgorithmQuestion<T>::AlgorithmQuestion() {

}

template <class T>
T AlgorithmQuestion<T>::MaxSubseqSum1(T* squences, int left, int right) {
	if (left == right) return squences[left];
	int mid = (left + right) / 2;  // 记录终点索引
	T left_sum = this->MaxSubseqSum1(squences, left, mid);
	T right_sum = this->MaxSubseqSum1(squences, mid + 1, right);
	T sum1 = 0;
	T this_sum = 0;
	for (int i = mid; i >= left; i--) {
		this_sum += squences[i];
		if (this_sum > sum1) sum1 = this_sum;
	}
	T sum2 = 0;
	this_sum = 0;
	for (int i = mid + 1; i <= right; i++) {
		this_sum += squences[i];
		if (this_sum > sum2) sum2 = this_sum;
	}
	sum1 += sum2;
	if (sum1 < left_sum) {
		sum1 = left_sum;
	}
	else if (sum1 < right_sum){
		sum1 = right_sum;
	}
	return sum1;
}

template <class T>
void AlgorithmQuestion<T>::test() {
	cout << "输入序列长度：" << endl;
	int m;				 
	cin >> m;
	cout << "输入序列: ";
	T* n = new T[200];
	for (int i = 0; i < m; i++) {
		cin >> n[i];
	}
	T sum = this->MaxSubseqSum1(n, 0, m - 1);
	cout << "最大子序列和为: " << sum << endl;

}