#pragma once

#include <iostream>
	template<class T> class Permutation {
	public:
		Permutation();
		void swap(T& a, T& b);
		void perm(T* ls, int k, int m);
		void test();

	private:
		T* n;
	};
