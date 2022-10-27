#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;
void DFS(int n, int** matrix_sm, bool* matrix_log, int a) { //����� � �������
	matrix_log[a] = true; //�������� �������, ��� �������������
	for (int i = 0; i < n; i++) //�������� �� ���� ��������� ��������
		if (!matrix_log[i] and matrix_sm[a][i] != 0) //������� �������, ������� �������, ������� ��� �� ��������
			DFS(n, matrix_sm, matrix_log, i); // ��������� ��� ��� ����� � �������
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	unsigned int start_time = clock(); // ������ ���������� ���������
	ifstream f1; ofstream f2;
	int i;
	f1.open("input.txt");
	if (f1) { //�������� ���������� �����
		cout << "���� input.txt ������� �������.\n";
		int n, k = 0; //k - ���������� ��������� ���������, n - ���������� ������ � �����
		f1 >> n;
		int** matrix_sm = new int* [n]; //������������ ��������� ������ ��� ������� ���������
		bool* matrix_log = new bool[n]; //������������ ��������� ������ ��� ���������� ������
		for (i = 0; i < n; i++) matrix_log[i] = false; //���������� ����������� �������: ������� ��������, ��� �� �������������
		for (i = 0; i < n; i++) { //���������� ������� ���������
			matrix_sm[i] = new int[n];
			for (int j = 0; j < n; j++) f1 >> matrix_sm[i][j];
		}
		for (i = 0; i < n; i++) { //���������� ��� ������� �����
			if (!matrix_log[i]) { //������� �� ��������
				DFS(n, matrix_sm, matrix_log, i); //����� � �������
				k++; //����������� ����� ��������� ��������� ���������
			}
		}
		f2.open("output.txt");
		if (f2) {
			f2 << k;
			cout << "���������� ��������� ��������� �������� � output.txt."; //������ � ���� ���������� ��������� ���������
		}
		else cout << "�� ������� �������� ������ � ���� output.txt";
		for (i = 0; i < n; i++) delete[] matrix_sm[i]; //������� ������ ����������� ������� � ������� ���������
		delete[]matrix_sm;
		delete[]matrix_log;
	}
	else cout << "�� ������� �������� ���� input.txt";
	f1.close(); //�������� ������
	f2.close();
	unsigned int end_time = clock(); // ����� ���������� ���������
	unsigned int time = end_time - start_time; // �������� ����� ���������� ���������
	cout << "\n����� ���������� ���������: " << time << " ��.";
}