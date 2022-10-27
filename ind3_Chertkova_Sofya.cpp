#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;
void DFS(int n, int** matrix_sm, bool* matrix_log, int a) { //обход в глубину
	matrix_log[a] = true; //помечаем вершину, как просмотренную
	for (int i = 0; i < n; i++) //проходим по всем остальным вершинам
		if (!matrix_log[i] and matrix_sm[a][i] != 0) //находим вершины, смежные текущей, которые еще не помечены
			DFS(n, matrix_sm, matrix_log, i); // выполняем для них обход в глубину
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	unsigned int start_time = clock(); // начало выполнения программы
	ifstream f1; ofstream f2;
	int i;
	f1.open("input.txt");
	if (f1) { //проверка читаемости файла
		cout << "Файл input.txt прочтен успешно.\n";
		int n, k = 0; //k - количество компонент связности, n - количество вершин в графе
		f1 >> n;
		int** matrix_sm = new int* [n]; //динамическое выделение памяти под матрицу смежности
		bool* matrix_log = new bool[n]; //динамическое выделение памяти под логический массив
		for (i = 0; i < n; i++) matrix_log[i] = false; //заполнение логического массива: вершины помечаем, как не просмотренные
		for (i = 0; i < n; i++) { //заполнение матрицы смежности
			matrix_sm[i] = new int[n];
			for (int j = 0; j < n; j++) f1 >> matrix_sm[i][j];
		}
		for (i = 0; i < n; i++) { //перебираем все вершины графа
			if (!matrix_log[i]) { //вершина не помечена
				DFS(n, matrix_sm, matrix_log, i); //обход в глубину
				k++; //увеличиваем число найденных компонент связности
			}
		}
		f2.open("output.txt");
		if (f2) {
			f2 << k;
			cout << "Количество компонент связности записано в output.txt."; //запись в файл количества компонент связности
		}
		else cout << "Не удалось записать данные в файл output.txt";
		for (i = 0; i < n; i++) delete[] matrix_sm[i]; //очистка памяти логического массива и матрицы смежности
		delete[]matrix_sm;
		delete[]matrix_log;
	}
	else cout << "Не удалось прочесть файл input.txt";
	f1.close(); //закрытие файлов
	f2.close();
	unsigned int end_time = clock(); // конец выполнения программы
	unsigned int time = end_time - start_time; // итоговое время выполнения программы
	cout << "\nВремя выполнения программы: " << time << " мс.";
}