#pragma once
#include <initializer_list>
#include <iostream>
#include <cmath>
#define pi  3.14159265358979323846


template <class T>
class TVector
{
protected:
	size_t size;
	T* array;
public:

	TVector(std::initializer_list<T> list) {
		size = list.size();
		array = new T[list.size()];
		int curIndex = 0;
		for (const T* i = list.begin(); i < list.end(); i++) {
			array[curIndex] = *i;
			curIndex++;
		}
	}


	TVector(size_t s = 1) : size(s) {
		array = new T[size];
		for (int i = 0; i < size; i++) {
			array[i] = T();
		}
	}


	TVector(const TVector& sec) {
		size = sec.size;
		array = new T[sec.size];
		for (int i = 0; i < sec.size; i++) {
			array[i] = sec.array[i];
		}
	}

	~TVector() {
		if (!size) {
			size = 0;
			delete[] array;
		}
	}

	TVector operator+(const TVector& v) const {
		int nSize = (size > v.size) ? size : v.size;
		TVector tmp(nSize);
		for (int i = 0; i < nSize; i++) {
			if (i >= size) {
				tmp[i] = v[i];
			}
			else if (i >= v.size) {
				tmp[i] = array[i];
			}
			else {
				tmp[i] = array[i] + v[i];
			}
		}
		return tmp;
	}

	TVector operator-(const TVector& v) const {
		int nSize = (size > v.size) ? size : v.size;
		TVector tmp(nSize);
		for (int i = 0; i < nSize; i++) {
			if (i >= size) {
				tmp[i] = -v[i];
			}
			else if (i >= v.size) {
				tmp[i] = array[i];
			}
			else {
				tmp[i] = array[i] - v[i];
			}
		}
		return tmp;
	}

	TVector operator*(const TVector& v) const {
		int nSize = (size > v.size) ? size : v.size;
		TVector tmp(nSize);
		for (int i = 0; i < nSize; i++) {
			if (i >= size) {
				tmp[i] = 0;
			}
			else if (i >= v.size) {
				tmp[i] = 0;
			}
			else {
				tmp[i] = array[i] * v[i];
			}
		}
		return tmp;
	}


	TVector operator*(int a) const{
		TVector tmp(size);
		for (int i = 0; i < size; i++) {
			tmp[i] = array[i] * a;
		}
		return tmp;
	}

	T & operator[](int i){
		return array[i];
	}

	T operator[](int i) const { // —сылка?
		return array[i];
	}

	int GetSize() const {
		return size;
	}

	TVector VecMulti(const TVector& v) const {
		if (size == 3 && v.size == 3) {
			TVector tmp(size);
			tmp[0] = array[1] * v[2] - array[2] * v[1];
			tmp[1] = array[2] * v[0] - array[0] * v[2];
			tmp[2] = array[0] * v[1] - array[1] * v[0];
			return tmp;
		}
		else {
			std::cout << "Cannot do vector multipliation!" << std::endl;
			return 0;
		}
	}

	double Angle(const TVector & v) {
		TVector tmp = *this * v;
		double sum = 0;
		for (int i = 0; i < tmp.size; i++) {
			sum += tmp[i];
		}
		double CosAngle = (sum) / (sqrt(pow(array[0], 2) + pow(array[1], 2) + pow(array[2], 2)) * sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2)));
		return acos(CosAngle) * pi / 180 ;
	}

	double VecLen() {
		return (sqrt(pow(this->array[0], 2) + pow(this->array[1], 2) + pow(this->array[2], 2)));
	}

	friend std::istream& operator>>(std::istream & in, const TVector & v) {
		for (int i = 0; i < v.size; i++) {
			in >> *(v.array + i);
		}
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const TVector& v) {
		for (int i = 0; i < v.size; i++) {
			out << *(v.array + i) << std::endl;
		}
		return out;
	}

	friend TVector operator*(int a,const TVector& v) {
		return v * a;
	}
};

