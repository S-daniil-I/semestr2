
#include "Vector.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

void maxDiff(Vector& vec1, Vector& vec2, Vector& FinalVec)
{
    double avgVec1 = 0;
    for (int i = 0; i < vec1.getVectorSize(); i++)
    {
        avgVec1 += vec1.getVectorElement(i);
        
    }
    avgVec1 /= vec1.getVectorSize();
    
    double maxVec1 = 0;
    for (int i = 0; i < vec1.getVectorSize(); i++)
    {
        double diffVec1 = vec1.getVectorElement(i) - avgVec1;
        
        maxVec1 = max(maxVec1,abs(diffVec1));
        
    }
    cout <<"Среднее значение:" << round(avgVec1)<<endl;
    cout<<"Максимальное отличие:" << round(maxVec1) << endl;

    FinalVec.setVectorSize(vec1.getVectorSize());
    for (int i = 0; i < vec1.getVectorSize(); i++)
    {
        double sum = vec1.getVectorElement(i) + maxVec1;
        FinalVec.setVectorElement(i, sum);
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    Vector vec1; 
    Vector vec2; 
    Vector FinalVec(5);
    
    vec1.setVectorSize(5);
    vec2.setVectorSize(5);
    vec1.fillVectorRandom();
    vec2.fillVectorRandom();
    vec1.findingScalarLenght();
    vec2.findingScalarLenght();
    cout << "Вектор 1: ";
    vec1.outVector();
    cout << endl;
    cout << "Вектор 2: ";
    vec2.outVector();
    cout << endl;
    vec1.actionsWithScalar(2);
    vec2.actionsWithScalar(3);
    cout << "Вектор 1 после преобразования с 2: ";
    vec1.outVector();
    cout << endl;
    cout << "Вектор 2 после преобразования с 3: ";
    vec2.outVector();
    cout << endl;
    maxDiff(vec1, vec2, FinalVec);
    cout << "Вектор FinalVec после выполнения функции Func: ";
    FinalVec.outVector();
    cout << endl;
    cout << "Работа с первым вектором";
    vec1.actionsWithOtherVector(vec2, FinalVec);
    cout << "Преобразования первого вектора и второго: ";
    FinalVec.outVector();
    cout << endl;
    int element = vec1.getVectorElement(2);
    cout << "Элемент под вторым индексом первого вектора: " << element << endl;
    vec1.replaceVectorElement(2, 4);
    cout << "Заменяем элемент со 2-ым индексом на 4: ";
    vec1.outVector();
    
    return 0;
}
