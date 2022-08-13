#include <iostream>
#include "DataStruct.h"

using namespace std;

namespace plls {

	// 分配空间
	int AddSpace(pll* data, int size) {
		pll* a;
		a = (pll*)realloc(data, sizeof(data) * size);
		if (a == NULL) {
			return ERROR;
		}
		data = a;
		data->len = data->len;
		data->size += SIZE;
		return OK;
	}
	// 初始化
	int Init(pll* data) {
		int i = sizeof(data) * SIZE;
		data = (pll*)malloc(i);
		if (data == NULL) return ERROR;
		data->len = 0;
		data->size = SIZE;
		return OK;
	}
	// 判断线性表是否已满,分配空间与否
	bool IsLTFull(pll* lt, bool flag=true) {
		if(lt->len >= lt->size){
			if (flag) {
				int a = SIZE;
				int ok = OK;
				if(AddSpace(lt, a) == ok) return true;
				else
				{
					return false;
				}
			}
			return false;
		}
		return true;
	}

	// 判断线性表是否为空
	bool IsLTEmpty(pll* lt) {
		if (lt->len <= 0) {
			return false;
		}
		return true;
	}

	// 线性表元素赋值
	int SetLTValues(pll* old, pll* n_data) {
		n_data->coef = old->coef;
		n_data->exp = old->exp;
		n_data->len = old->len;
		n_data->size = old->len;
		return OK;
	}

	// 获取线性表数据
	/*
	* 
	*/
	int GetLT(pll* lt, int index, pll* data) {
		if (index >= lt->len) {
			return ERROR;
		}
		if(SetLTValues(lt + index, data) != 1) return ERROR;
		return OK;
	}

	// 插入数据
	int Insert(pll* linetable, pll* data, int index=-1) {
		// 判断是否内存不足,是则扩大空间
		if(IsLTFull(linetable)) return ERROR;
		// 执行数据插入
		if (index < 0) {
			SetLTValues(data, linetable + linetable->len);	
		}
		else {
			if (index <= linetable->len) {
				for (int i = linetable->len; i > index; i--) {
					SetLTValues(linetable + i, linetable + i - 1);
				}
			}
		}
		linetable->len += 1;
		return OK;
	}

	// 

	// 遍历线性表
	void printPLL(pll* lt) {
		for (int i = 0; i < lt->len; i++) {
			cout << lt->coef << "x^" << lt->exp;
			if (i < lt->len - 1) {
				cout << "+";
			}
		}
		cout << endl;
	}
}