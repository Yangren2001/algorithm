#pragma once
/*
* ���ݽṹ ��̬����
*/

class DynArray {
	/*
	* ��̬������
	*/
public:

private:

	// ����ṹ
	typedef struct 
	{
		int* base_address;
		int offset;
		int length;
		int size;
	}DyArray;
};