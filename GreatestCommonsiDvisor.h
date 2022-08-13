#pragma once

// 最大公约数

class GreatestCommonDisvisor
{
public:
	GreatestCommonDisvisor();
	// 获取结果
   	void GetResult(int var1, int var2, int& result);
	// 交换值
	void temp(int& var1, int& var2);
	void Test();

	~GreatestCommonDisvisor();

private:
	int remainder;

};

