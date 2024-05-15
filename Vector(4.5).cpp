#include "Vector.h"

Vector::Vector()
{
    array = new int[maxsize];
}
Vector::Vector(int size)
{
    this->size = size;
    array = new int[size];
}

Vector::Vector(const Vector& vec)
{
    this->size = vec.size;

    this->array = new int[this->size];

    for (auto i = 0; i < this->size; i++)
    {
        this->array[i] = vec.array[i];
    }
}

Vector::Vector(Vector&& other)
{
    this->size = other.size;
    this->array = new int[this->size];

    for (int i = 0; i < this->size; i++)
    {
        this->array[i] = other.array[i];
        other.array[i] = 0;
    }
}

Vector :: ~Vector()
{
    delete[] array;
    array = nullptr;
}
void Vector::fillVector()
{
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}
void Vector::fillVectorRandom()
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 6 + 1;
    }
}
void Vector::outVector()
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
void Vector::setVectorSize(int size)
{
    this->size = size;
}
int Vector::getVectorSize()
{
    return this->size;
}
int Vector::getVectorElement(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Некорректный индекс!";
        return 0;
    }
    else {
        return this->array[index];
    }
}


void Vector::setVectorElement(int index, int data)
{
    if (index < 0 || index >= size)
    {
        return;
    }

    this->array[index] = data;
}

void Vector::replaceVectorElement(int index, int temp)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    array[index] = temp;
}

void Vector::sumWithScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        array[i] += scalar;
    }
}
void Vector::subWithScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        array[i] -= scalar;
    }
}
void Vector::multiWithScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        array[i] *= scalar;
    }
}
void Vector::divWithScalar(int scalar)
{
    for (int i = 0; i < size; i++)
    {
        array[i] /= scalar;
    }
}

void Vector::findingLenght()
{
    double lenght, sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += (pow(array[i], 2));
    }
    lenght = sqrt(sum);
    cout << "Длина вектора  = " << lenght << endl;
}

void Vector::multiWithOtherVector(Vector& vec, Vector& FinalVec)
{
    for (int i = 0; i < size; i++)
    {
        FinalVec.array[i] = array[i] * vec.array[i];
    }
}
void Vector::divWithOtherVector(Vector& vec, Vector& FinalVec)
{
    for (int i = 0; i < size; i++)
    {
        FinalVec.array[i] = array[i] / vec.array[i];
    }
}
void Vector::sumWithOtherVector(Vector& vec, Vector& FinalVec)
{
    for (int i = 0; i < size; i++)
    {
        FinalVec.array[i] = array[i] + vec.array[i];
    }
}
void Vector::subWithOtherVector(Vector& vec, Vector& FinalVec)
{
    for (int i = 0; i < size; i++)
    {
        FinalVec.array[i] = array[i] - vec.array[i];
    }
}
Vector Vector :: operator * (const Vector& vec)
{
    for (int i = 0; i < this->size; i++)
    {
        array[i] *= vec.array[i];
    }
    return *this;
}


