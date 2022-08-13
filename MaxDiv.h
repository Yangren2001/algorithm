#pragma once

#define SPACE_SIZE 100

void Div(int n, int& amount);

namespace Prime {
	class Prime {
	public:
		Prime();
		// 创建质数数组
		void AddSpace(int size);
		// 判断质数
		bool IsPrime(int var);
		~Prime();

	private:
		bool* num_arr;
		int size;
		int ulen;
		
	};

}