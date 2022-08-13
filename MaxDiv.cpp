#include <iostream>
#include <math.h>
#include <vcruntime.h>
#include "MaxDiv.h"
using namespace std;

Prime::Prime::Prime() {
	/*
	* 构造函数
	*/
	this->num_arr = new bool[SPACE_SIZE];  // 初始化大小
	if (this->num_arr == NULL) {
		cout << "储存数组空间动态分配失败";
	}
	this->size = SPACE_SIZE;
	this->ulen = 0;
}

bool Prime::Prime::IsPrime(int var) {
	/*
	* 判断是否为素数
	*/
	/*if (var == 1) return true;
	for (int i = 2; i <= (int)ceil(sqrt(var)); i++)
	{
		if (var % i == 0) return false;
	}
	return true;*/
	if (var > this->size) this->AddSpace(var); // 判断数组空间是否满足需求，不足则增加空间
	// 判断是否存在var是否是素数的数据
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
	* 增加空间
	* param size: 数组大小
	*/
	bool* t = new bool[this->size + size];
	if (t == NULL) {
		cout << "储存数组空间动态分配失败";
	}
	// 复制数组数据
	for (int i = 0; i < this->size; i++) {
		t[i] = this->num_arr[i];
	}
	// 释放原有储存片段，指向新的数据储存地址
	delete[] this->num_arr;
	this->num_arr = t;
	this->size += size;
}

Prime::Prime::~Prime() {
	/*
	* 析构函数
	*/
	delete[] this->num_arr;
}

void Div(int n, int& amount) {
	/*
	* 最大约数
	*
	* param n:数值
	* param amount: 该数值约数个数
	*/
	amount = 0;
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) amount++;
	}
	amount = amount * 2 + 2;
}