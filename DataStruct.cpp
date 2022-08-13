#include "DataStruct.h"

namespace plls {

	// ����ռ�
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
	// ��ʼ��
	int Init(pll* data) {
		int i = sizeof(data) * SIZE;
		data = (pll*)malloc(i);
		if (data == NULL) return ERROR;
		data->len = 0;
		data->size = SIZE;
		return OK;
	}
	// �ж����Ա��Ƿ�����
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

	// �ж����Ա��Ƿ�Ϊ��
	bool IsLTEmpty(pll* lt) {
		if (lt->len <= 0) {
			return false;
		}
		return true;
	}

	// ��������
	int Insert(pll* linetable, pll* data) {
		// �ж��Ƿ��ڴ治��,��������ռ�
		IsLTFull(linetable);
		// ִ�����ݲ���
		(linetable + linetable->len)->coef = data->coef;
		(linetable + linetable->len)->exp = data->exp;
		(linetable + linetable->len)->len += 1;
		return OK;
	}
}