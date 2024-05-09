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

	void setVectorElement(int index, int data);
	void setVectorSize(int size);
	void fillVector();
	void fillVectorRandom();
	void outVector();
	int getVectorSize();
	int getVectorElement(int index);
	void replaceVectorElement(int index, int temp);
	void actionsWithScalar(int scalar);
	void findingScalarLenght();
	void actionsWithOtherVector(Vector& vec, Vector& FinalVec);

	~Vector();
};
