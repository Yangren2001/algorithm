#include "DataStruct.h"

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
	// 判断线性表是否已满
	bool IsLTFull(pll* lt, bool flag=true) {
		if(lt->len >= lt->size){
			if (flag) {
				int a = SIZE;
				AddSpace(lt, a);
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

	// 插入数据
	int Insert(pll* linetable, pll* data) {
		// 判断是否内存不足,是则扩大空间
		IsLTFull(linetable);
		// 执行数据插入
		(linetable + linetable->len)->coef = data->coef;
		(linetable + linetable->len)->exp = data->exp;
		(linetable + linetable->len)->len += 1;
		return OK;
	}
}