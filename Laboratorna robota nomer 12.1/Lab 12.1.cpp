// Lab 12.1

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Імена файлів
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";

    // Введення даних у файл
    ofstream inputFile(inputFileName);
    if (!inputFile) 
    {
        cerr << "Не вдалося створити вхідний файл!" << endl;
        return 1;
    }

    // Запис чисел у файл (приклад)
    inputFile << "4.5 -1 16 9 -3 25 -8 0 5.6";
    inputFile.close();

    // Зчитування чисел із файлу
    ifstream inputFileRead(inputFileName);
    if (!inputFileRead) 
    {
        cerr << "Не вдалося відкрити вхідний файл для читання!" << endl;
        return 1;
    }

    vector<double> numbers;
    double number;
    while (inputFileRead >> number) 
    {
        numbers.push_back(number);
    }
    inputFileRead.close();

    // Перевірка чисел і запис у вихідний файл
    ofstream outputFile(outputFileName);
    if (!outputFile) 
    {
        cerr << "Не вдалося створити вихідний файл!" << endl;
        return 1;
    }

    for (double num : numbers) 
    {
        if (num < 0) 
        {
            outputFile << num << " ";
        }
    }
    outputFile.close();

    // Виведення вмісту результуючого файлу на екран
    ifstream outputFileRead(outputFileName);
    if (!outputFileRead) 
    {
        cerr << "Не вдалося відкрити вихідний файл для читання!" << endl;
        return 1;
    }

    cout << "Вміст результуючого файлу: ";
    while (outputFileRead >> number) 
    {
        cout << number << " ";
    }
    cout << endl;

    outputFileRead.close();

    return 0;
}
