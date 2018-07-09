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
	
ofstream fout("file.txt");

string name[10] = { "Иван","Рустам","Максим","Алина","Наталья", 
"Ольга","Павел","Мария","Алексей","Евгения" }; 

int age[10] = { 23, 21, 22, 19, 20, 22, 18, 24, 22, 21 }; 

for (int i = 0; i<10; i++) 
{ 
fout << name[i] << "	" << age[i] << endl; 
} 

fout.close();
}