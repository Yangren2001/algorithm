#pragma once
/*
* 数据结构 动态数组
*/

class DynArray {
	/*
	* 动态数组类
	*/
public:

private:

	// 数组结构
	typedef struct 
	{
		int* base_address;
		int offset;
		int length;
		int size;
	}DyArray;
};