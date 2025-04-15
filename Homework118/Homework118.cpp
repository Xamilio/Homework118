#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* removeGreaterThan100(int* arr, int& size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] <= 100) count++;
    int* newArr = new int[count];
    int index = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] <= 100)  newArr[index++] = arr[i];
    size = count;
    delete[] arr;
    return newArr;
}

void task1() 
{
    int size;
    cout << "Task 1 - Enter array size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++) cin >> arr[i];
    arr = removeGreaterThan100(arr, size);
    cout << "Result: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
}

int* removeByIndex(int* arr, int& size, int indexToRemove)
{
    if (indexToRemove < 0 || indexToRemove >= size) return arr;
    int* newArr = new int[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (i != indexToRemove)
            newArr[j++] = arr[i];
    }
    size--;
    delete[] arr;
    return newArr;
}

void task2() 
{
    int size, index;
    cout << "Task 2 - Enter array size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter array elements:\n";
    for (int i = 0; i < size; i++) cin >> arr[i];
    cout << "Enter index to remove: ";
    cin >> index;
    arr = removeByIndex(arr, size, index);
    cout << "Result: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
}

void modifyArrayBasedOnSum(int* arr, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    if (sum > 100) 
    {
        for (int i = 0; i < size; i++) arr[i] *= 10;
    }
    else 
    {
        for (int i = 0; i < size; i++) arr[i] /= 10;
    }
}

void task3()
{
    int size;
    cout << "Task 3 - Enter array size: ";
    cin >> size;
    int* arr = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++) arr[i] = rand() % 50;
    modifyArrayBasedOnSum(arr, size);
    cout << "Result: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
}

int main()
{
    task1();
    task2();
    task3();
}
