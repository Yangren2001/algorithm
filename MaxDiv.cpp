#include <iostream>
#include <math.h>
#include <vcruntime.h>
#include "MaxDiv.h"
using namespace std;

Prime::Prime::Prime() {
	/*
	* ���캯��
	*/
	this->num_arr = new bool[SPACE_SIZE];  // ��ʼ����С
	if (this->num_arr == NULL) {
		cout << "��������ռ䶯̬����ʧ��";
	}
	this->size = SPACE_SIZE;
	this->ulen = 0;
}

bool Prime::Prime::IsPrime(int var) {
	/*
	* �ж��Ƿ�Ϊ����
	*/
	/*if (var == 1) return true;
	for (int i = 2; i <= (int)ceil(sqrt(var)); i++)
	{
		if (var % i == 0) return false;
	}
	return true;*/
	if (var > this->size) this->AddSpace(var); // �ж�����ռ��Ƿ��������󣬲��������ӿռ�
	// �ж��Ƿ����var�Ƿ�������������
	if (this->num_arr[var - 1] == true) return true;
	else if (this->num_arr[var - 1] == false) return false;
	else if (this->ulen == 0) {
		if (var == 1) {
			this->num_arr[0] = true;
			return true;
		}
		for (int i = 2; i <= var; i++) {
			if (this->num_arr[i - 1] != true && this->num_arr[i - 1] != false) this->num_arr[i - 1] = true;
			if (this->num_arr[i - 1] == true) {
					for (int j = i * 2; j <= var; j += i) {
						this->num_arr[j - 1] = false;
					}
			}
		}
	}
	else {
		for (int i = 2; i <= var; i++) {
			if (this->num_arr[i - 1] != true && this->num_arr[i - 1] != false) this->num_arr[i - 1] = true;
			if (this->num_arr[i - 1] == true) {
				int t = (int)(this->ulen / i) * 2 + 2;
				for (int j = t; j <= var; j += i) {
					this->num_arr[j - 1] = false;
				}
			}
		}
	}
	return this->num_arr[var - 1];
}	

void Prime::Prime::AddSpace(int size) {
	/*
	* ���ӿռ�
	* param size: �����С
	*/
	bool* t = new bool[this->size + size];
	if (t == NULL) {
		cout << "��������ռ䶯̬����ʧ��";
	}
	// ������������
	for (int i = 0; i < this->size; i++) {
		t[i] = this->num_arr[i];
	}
	// �ͷ�ԭ�д���Ƭ�Σ�ָ���µ����ݴ����ַ
	delete[] this->num_arr;
	this->num_arr = t;
	this->size += size;
}

Prime::Prime::~Prime() {
	/*
	* ��������
	*/
	delete[] this->num_arr;
}

void Div(int n, int& amount) {
	/*
	* ���Լ��
	*
	* param n:��ֵ
	* param amount: ����ֵԼ������
	*/
	amount = 0;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) amount++;
	}
	amount = amount * 2 + 2;
}