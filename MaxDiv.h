#pragma once

#define SPACE_SIZE 100

void Div(int n, int& amount);

namespace Prime {
	class Prime {
	public:
		Prime();
		// ������������
		void AddSpace(int size);
		// �ж�����
		bool IsPrime(int var);
		~Prime();

	private:
		bool* num_arr;
		int size;
		int ulen;
		
	};

}