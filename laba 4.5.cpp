#include "Vector.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>

void maxDiff(Vector& vec1, Vector& vec2, Vector& FinalVec);

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int choice_,size=5;
    Vector vec;
    Vector vec1;
    Vector vec2;
    Vector FinalVec(5);
    vec1.setVectorSize(5);
    vec2.setVectorSize(5);
    cout << "1-заполнение с консоли\n2-заполнение случайными числами" << endl;
    cin >> choice_;
    switch (choice_)
    {
    case 1:
        cout << "Введите значения вектора 1: ";
        vec1.fillVector();
        cout << "Введите значения вектора 2: ";
        vec2.fillVector();
        break;
    case 2:
        vec1.fillVectorRandom();
        vec2.fillVectorRandom();
        break;
    }
    vec1.findingLenght();
    vec2.findingLenght();

    cout << "Вектор 1: ";
    vec1.outVector();
    cout << endl;
    cout << "Вектор 2: ";
    vec2.outVector();
    cout << endl;
    int choice = 0;
        cout << " Выберите операцию: \n 1 : * \n 2 : / \n 3 : + \n 4 : -" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            vec1.multiWithScalar(2);
            vec2.multiWithScalar(3);
            break;
    
        case 2:
            vec1.divWithScalar(2);
            vec2.divWithScalar(3);
            break;
        case 3:
            vec1.sumWithScalar(2);
            vec2.sumWithScalar(3);
            break;
        case 4:
            vec1.subWithScalar(2);
            vec2.subWithScalar(3);
            break;
        default:
            cout << "Некорректный выбор!";
            
        }
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
    cout << "Работа с первым вектором"<<endl;
        int choice1 = 0;
        cout << " Выберите операцию: \n 1 : * \n 2 : / \n 3 : + \n 4 : -" << endl;
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            vec1.multiWithOtherVector(vec2, FinalVec);
            break;
        case 2:
            vec1.divWithOtherVector(vec2, FinalVec);
            break;
        case 3:
            vec1.sumWithOtherVector(vec2, FinalVec);
            break;
        case 4:
            vec1.subWithOtherVector(vec2, FinalVec);
            break;
        default:
            cout << "Некорректный выбор!";
        }
    /*cout << "Преобразования первого вектора и второго: ";
    FinalVec.outVector();
    cout << endl;
    int element = vec1.getVectorElement(2);
    cout << endl;
    cout << "Элемент под вторым индексом первого вектора: " << element << endl;
    vec1.replaceVectorElement(2, 4);
    cout << "Заменяем элемент со 2-ым индексом на 4: ";
    vec1.outVector();
    cout << endl;*/
    cout << "Результат умножения: ";
    Vector result=vec1 * vec2;
    result.outVector();
    return 0;
}
void maxDiff(Vector& vec1, Vector& vec2, Vector& FinalVec)
{
    double avgVec1 = 0;
    int vectorSize = vec1.getVectorSize();
    for (int i = 0; i < vectorSize; i++)
    {
        avgVec1 += vec1.getVectorElement(i);

    }
    avgVec1 /= vectorSize;

    double maxVec1 = 0;
    for (int i = 0; i < vectorSize; i++)
    {
        double diffVec1 = vec1.getVectorElement(i) - avgVec1;

        maxVec1 = max(maxVec1, abs(diffVec1));

    }
    cout << "Среднее значение:" << round(avgVec1) << endl;
    cout << "Максимальное отличие:" << round(maxVec1) << endl;

    FinalVec.setVectorSize(vec1.getVectorSize());
    for (int i = 0; i < vectorSize; i++)
    {
        double sum = vec1.getVectorElement(i) + round(maxVec1);
        FinalVec.setVectorElement(i, sum);
    }
}
Vector operator * (const Vector& vec1, const Vector& vec2)
{
    Vector result(vec1.size);
    for (int i = 0; i < vec1.size; i++)
    {
        result.array[i] = vec1.array[i] * vec2.array[i];
    }
    return result;
}
