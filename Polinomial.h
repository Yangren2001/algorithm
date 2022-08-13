#pragma once
/**
* 线性表实现多项式
*/
#include "DataStruct.h"

class Polinomial {
public:
	Polinomial();
	int Create();    // 创建线性表
	// 插入数据
	int insert();
	int Delete();
	~Polinomial();
private:
	plls::pll* data_table;
};