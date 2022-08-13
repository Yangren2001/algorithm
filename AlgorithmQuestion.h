#pragma once

/**
* 算法问题类
*/

template <class T>
class AlgorithmQuestion {
public:
	AlgorithmQuestion();
	// 分治法实现最大子序列和
	T MaxSubseqSum1(T *squences, int left, int right);
	void test();
	
};