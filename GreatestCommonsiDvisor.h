#pragma once

// ���Լ��

class GreatestCommonDisvisor
{
public:
	GreatestCommonDisvisor();
	// ��ȡ���
   	void GetResult(int var1, int var2, int& result);
	// ����ֵ
	void temp(int& var1, int& var2);
	void Test();

	~GreatestCommonDisvisor();

private:
	int remainder;

};

