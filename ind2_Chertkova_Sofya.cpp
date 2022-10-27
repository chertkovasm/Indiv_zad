#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
	int data; //�������������� �������
	Node* Next; //��������� �� ��������� �������
};
typedef Node* PNode;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string komanda; //
	int n, size = 0; //n - �����, ������� ����� �������� � �������, size - ������ �������
	bool flag = true; //flag - ����������, ������� ��������� ����� �� ���������
	PNode Head, LastNode; //Head - ������, LastNode - ��������� �������
	Head = LastNode = NULL;
	cout << "��������� ������ \"�������\".";
	cout << "\n\n������ ������������� ��������:\npush n - �������� � ������� ����� n. ������� ok.\npop - ������� �� ������� ������ �������. ������� ��� ��������. \
	\nfront - ������� �������� ������� ��������, �� ������ ��� �� �������.\nsize - ������� ���������� ��������� � �������. \nclear - �������� ������� � ������� ok. \
    \nexit - ������� bye � ��������� ������.\n";
	cout << "\n�������� ������ �������: \n\n";
	while (flag)
	{
		cin >> komanda; //���� �������, ������� ���������� ���������
		cout << "\033[F"; //�������� ������ �����
		if (komanda == "push")
		{
			cin >> n; //���� �����, ������� ���������� ��������
			PNode Temp; //Temp - ����� �������, LastNode - ��������� �������
			if (Head == NULL) //���� ������� ������, ��������� ����� ������� � ������ ������� 
			{
				Head = new Node; 
				LastNode = Head;
				Head->Next = NULL;
			}
			else //���� ������� �� ������, ��������� ����� ������� ����� ���������� (����� �������)
			{
				Temp = new Node;
				LastNode->Next = Temp;
				LastNode = Temp;
				LastNode->Next = NULL;
			}
			LastNode->data = n; //���������� ������ �������� �������� n
			cout << "push " << n << setw(5) << "ok\n";
			size++; //���������� ������� �������
		}
		if (komanda == "pop")
		{
			if (Head == NULL) cout << "pop" << setw(11) << "error\n"; //���� ������� ������, �� ������
			else
			{
				cout << "pop" << setw(7) << Head->data << endl; //����� ������� �������� �������
				PNode OldNode = Head;
				Head = OldNode->Next;
				delete OldNode; //������������ ������ ������� �������� 
				size--; //���������� ������� �������
			}
		}
		if (komanda == "front")
		{
			if (Head == NULL) cout << "front" << setw(9) << "error\n"; //���� ������� ������, �� ������
			else cout << "front " << setw(4) << Head->data << endl; //����� ������� �������� �������
		}
		if (komanda == "size")
		{
			cout << "size" << setw(6) << size << endl; //������ �������
		}
		if (komanda == "clear")
		{
			PNode MyNode = Head;
			while (Head != NULL) //������ �� �������
			{
				MyNode = Head;
				Head = Head->Next;
				delete MyNode; //������������ ������
			}
			cout << "clear" << setw(6) << "ok\n";
			size = 0; //��������� ������� �������
		}
		if (komanda == "exit")
		{
			cout << "exit" << setw(8) << "bye\n"; //����� �� ���������
			flag = false; //��������� ��������� ������ ���������
		}
	}
}