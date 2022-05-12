#pragma once
#include "TVector.h"
#include <assert.h>
template <class T>
class ChildVector : public TVector<TVector<T>>
{
public:
	ChildVector(int _m, int _n) : TVector<TVector<T>>(_m) {
		for (int i = 0; i < _m; i++) {
			this->array[i] = TVector<T>(_n);
		}
	}

	~ChildVector() {
		for (int i = 0; i < this->size; i++) {
			this->array[i].~TVector();
		}
	}

	int GetSize2() const {
		return this->array[0].GetSize();
	}

	ChildVector Trans() {
		ChildVector tmp(GetSize2(), this->GetSize());
		for (int i = 0; i < this->GetSize(); i++) {
			for (int j = 0; j < GetSize2(); j++) {
				tmp[j][i] = this->array[i][j];
			}
		}
		return tmp;
	}

	template <class T1>
	ChildVector operator*(const ChildVector <T1> & m) const {
		assert(GetSize2() == m.GetSize());
		ChildVector tmp(this->GetSize(), m.GetSize2());
		for (int i = 0; i < this->GetSize(); i++) {
			for (int j = 0; j < m.GetSize2(); j++) {
				for (int k = 0; k < GetSize2(); k++) {
					tmp[i][j] += this->array[i][k] * m[k][j];
				}
			}
		}
		return tmp;
	}

	//T Det() const {
	//	assert(this->GetSize() == GetSize2());
	//	assert(this->GetSize() == 2);
	//}
};

