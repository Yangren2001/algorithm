#pragma once
/**
* ���Ա�ʵ�ֶ���ʽ
*/
#include "DataStruct.h"

class Polinomial {
public:
	Polinomial();
	int Create();    // �������Ա�
	// ��������
	int insert();
	int Delete();
	~Polinomial();
private:
	plls::pll* data_table;
};