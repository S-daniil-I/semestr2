#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

using namespace std;

class Vector
{
	const int maxsize = 100;
	int size = 0;
	int* array;

public:
	Vector();
	Vector(int size);
	Vector(const Vector& vec);
	Vector(Vector&& other);
	Vector operator * (const Vector& vec);

	
	void setVectorElement(int index, int data);
	void setVectorSize(int size);
	void fillVector();
	void fillVectorRandom();
	void outVector();
	int getVectorSize();
	int getVectorElement(int index);
	void replaceVectorElement(int index, int temp);
	void findingLenght();
	void sumWithScalar(int scalar);
	void multiWithScalar(int scalar);
	void divWithScalar(int scalar);
	void subWithScalar(int scalar);
	void multiWithOtherVector(Vector& vec, Vector& FinalVec);
	void divWithOtherVector(Vector& vec, Vector& FinalVec);
	void sumWithOtherVector(Vector& vec, Vector& FinalVec);
	void subWithOtherVector(Vector& vec, Vector& FinalVec);

	~Vector();
};



