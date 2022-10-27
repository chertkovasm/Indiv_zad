#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	int data; //информационный элемент
	Node* Next; //указатель на следующий элемент
};
typedef Node* PNode;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string komanda; //
	int n, size = 0; //n - число, которое нужно добавить в очередь, size - размер очереди
	bool flag = true; //flag - переменная, которое позволяет выйти из программы
	PNode Head, LastNode; //Head - голова, LastNode - последний элемент
	Head = LastNode = NULL;
	cout << "Структура данных \"очередь\".";
	cout << "\n\nСписок реализованных программ:\npush n - Добавить в очередь число n. Вывести ok.\npop - Удалить из очереди первый элемент. Вывести его значение. \
	\nfront - Вывести значение первого элемента, не удаляя его из очереди.\nsize - Вывести количество элементов в очереди. \nclear - Очистить очередь и вывести ok. \
    \nexit - Вывести bye и завершить работу.\n";
	cout << "\nПротокол работы очереди: \n\n";
	while (flag)
	{
		cin >> komanda; //ввод команды, которую необходимо выполнить
		cout << "\033[F"; //удаление строки ввода
		if (komanda == "push")
		{
			cin >> n; //ввод числа, которое необходимо добавить
			PNode Temp; //Temp - новый элемент, LastNode - последний элемент
			if (Head == NULL) //если очередь пустая, добавляем новый элемент в начало очереди 
			{
				Head = new Node; 
				LastNode = Head;
				Head->Next = NULL;
			}
			else //если очередь не пустая, добавляем новый элемент после последнего (конец очереди)
			{
				Temp = new Node;
				LastNode->Next = Temp;
				LastNode = Temp;
				LastNode->Next = NULL;
			}
			LastNode->data = n; //присвоение новому элементу значения n
			cout << "push " << n << setw(5) << "ok\n";
			size++; //увеличение размера очереди
		}
		if (komanda == "pop")
		{
			if (Head == NULL) cout << "pop" << setw(11) << "error\n"; //если очередь пустая, то ошибка
			else
			{
				cout << "pop" << setw(7) << Head->data << endl; //вывод первого элемента очереди
				PNode OldNode = Head;
				Head = OldNode->Next;
				delete OldNode; //освобождение памяти первого элемента 
				size--; //уменьшение размера очереди
			}
		}
		if (komanda == "front")
		{
			if (Head == NULL) cout << "front" << setw(9) << "error\n"; //если очередь пустая, то ошибка
			else cout << "front " << setw(4) << Head->data << endl; //вывод первого элемента очереди
		}
		if (komanda == "size")
		{
			cout << "size" << setw(6) << size << endl; //размер очереди
		}
		if (komanda == "clear")
		{
			PNode MyNode = Head;
			while (Head != NULL) //проход по очереди
			{
				MyNode = Head;
				Head = Head->Next;
				delete MyNode; //освобождение памяти
			}
			cout << "clear" << setw(6) << "ok\n";
			size = 0; //обнуление размера очереди
		}
		if (komanda == "exit")
		{
			cout << "exit" << setw(8) << "bye\n"; //выход из программы
			flag = false; //позволяет завершить работу программы
		}
	}
}