#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <cstring>
using namespace std;
struct info
{
    std::string name;
    int year;
};
 
int main() {
  SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	

info users[100];
for (int i = 0; i !=10; ++i) {
    cout << "Введите имя студента #" << i+1 << endl;
	ofstream fout("file.txt");
    cin >> users[i].name;
	fout << users[0].name << ' ' ;
    cout << "Введите возраст студента #" << i+1 << endl;
    cin >> users[i].year;
	fout << users[0].year << endl  ;
	fout << users[1].name << ' ' ;
	fout << users[1].year << endl  ;
	fout << users[2].name << ' ' ;
	fout << users[2].year << endl  ;
	fout << users[3].name << ' ' ;
	fout << users[3].year << endl  ;
	fout << users[4].name << ' ' ;
	fout << users[4].year << endl  ;
	fout << users[5].name << ' ' ;
	fout << users[5].year << endl  ;
	fout << users[6].name << ' ' ;
	fout << users[6].year << endl  ;
	fout << users[7].name << ' ' ;
	fout << users[7].year << endl  ;
	fout << users[8].name << ' ' ;
	fout << users[8].year << endl  ;
	fout << users[9].name << ' ' ;
	fout << users[9].year << endl  ;
	std::cout << "Имя: " << users[i].name << "\nВозраст: " << users[i].year << std::endl;
	}
    system("pause");
	
return 0;
}