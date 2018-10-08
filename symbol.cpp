#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ancsii[256] = {}; 

	cout << "������� ������ ���� � ����� � ������� Enter. �������� D:\\���������\\text.txt" << endl;
	string file;
	getline(cin, file); 

	fstream fs(file, fstream::in); 
	if (!fs.is_open()) 
	{
		cout << "���� �� ����� ���� ������ " << file << endl;
		return 0;
	}

	for (;; )
	{
		int p = (int)fs.get();
		if (p == EOF)
			break;

		ancsii[p] += 1; 
	}

	int pos = 0;
	int max = ancsii[0];
	for (int i = 1; i < 256; ++i) 
		if (ancsii[i] > max)
		{
			max = ancsii[i];
			pos = i;
		}

	cout << "���������� : " << max << " ������ : " << char(pos) << endl;
	getchar();

	return 0;
}