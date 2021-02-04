// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	map<int, map<int, double>> matrix;
	map<int, map<int, double>> matrix_1;
	map<int, double> buffer_stolbetc_1;
	map<int, double> buffer_stolbetc_2;
	map<int, double> buffer_stolbetc_3;
	map<int, double> decision;
	fstream f("1.txt", ios::in);
	int size = 0;
	double buffer = 0;
	double buffer_1 = 0;
	double buffer_2 = 0;
	f >> size;
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size + 1; j++)
		{
			f >> matrix[i][j];
		}

	}

	matrix_1 = matrix;

	for (int i = 0; i < size - 1; i++)
	{

		for (int j = i + 1; j < size; j++)
		{
			buffer_1 = (matrix[i][i]) / (sqrt(pow(matrix[i][i], 2) + pow(matrix[j][i], 2)));
			buffer_2 = (matrix[j][i]) / (sqrt(pow(matrix[i][i], 2) + pow(matrix[j][i], 2)));

			for (auto a : matrix[i])
			{
				buffer_stolbetc_1[a.first] = a.second * buffer_1;
			}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 

			for (auto a : matrix[j])
			{
				buffer_stolbetc_2[a.first] = a.second * buffer_2;
				buffer_stolbetc_3[a.first] = buffer_stolbetc_1[a.first] + buffer_stolbetc_2[a.first];
			}

			for (auto a : matrix[i])
			{
				buffer_stolbetc_1[a.first] = a.second * (-buffer_2);
			}

			for (auto &a : matrix[i])
			{
				a.second = buffer_stolbetc_3[a.first];
			}

			for (auto a : matrix[j])
			{
				buffer_stolbetc_2[a.first] = a.second * buffer_1;
				buffer_stolbetc_3[a.first] = buffer_stolbetc_1[a.first] + buffer_stolbetc_2[a.first];
			}

			for (auto& a : matrix[j])
			{
				a.second = buffer_stolbetc_3[a.first];
			}

		}

	}

	for (int i = size - 1; i != -1; i--)
	{
		int j, k;
		for (j = size, k = size; j != i - 1; j--, k--)
		{

			if (size == j)
				decision[i] += matrix[i][j];

			if (i != j && size != j)
				decision[i] += -matrix[i][j] * decision[k];

			if (i == j)
				decision[i] /= matrix[i][j];
		}

	}

	for (auto a : matrix)
	{
		for (auto b : a.second)
		{
			cout << left << setw(12) << b.second;
		}

		cout << endl;
	}

	cout << endl;

	for (auto a : decision)
	{
		cout << left << setw(4) << a.second << endl;
	}

	int i = 0;

	buffer = 0;

	decision[size] = -1;

	cout << endl;

	for (auto a : matrix_1)
	{
		for (auto b : a.second)
		{
			buffer += b.second * decision[i];
			i++;
		}

		i = 0;
		cout << buffer << endl;

		buffer = 0;
	}
}
