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
    // ����� �����
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";

    // �������� ����� � ����
    ofstream inputFile(inputFileName);
    if (!inputFile) 
    {
        cerr << "�� ������� �������� ������� ����!" << endl;
        return 1;
    }

    // ����� ����� � ���� (�������)
    inputFile << "4.5 -1 16 9 -3 25 -8 0 5.6";
    inputFile.close();

    // ���������� ����� �� �����
    ifstream inputFileRead(inputFileName);
    if (!inputFileRead) 
    {
        cerr << "�� ������� ������� ������� ���� ��� �������!" << endl;
        return 1;
    }

    vector<double> numbers;
    double number;
    while (inputFileRead >> number) 
    {
        numbers.push_back(number);
    }
    inputFileRead.close();

    // �������� ����� � ����� � �������� ����
    ofstream outputFile(outputFileName);
    if (!outputFile) 
    {
        cerr << "�� ������� �������� �������� ����!" << endl;
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

    // ��������� ����� ������������� ����� �� �����
    ifstream outputFileRead(outputFileName);
    if (!outputFileRead) 
    {
        cerr << "�� ������� ������� �������� ���� ��� �������!" << endl;
        return 1;
    }

    cout << "���� ������������� �����: ";
    while (outputFileRead >> number) 
    {
        cout << number << " ";
    }
    cout << endl;

    outputFileRead.close();

    return 0;
}
