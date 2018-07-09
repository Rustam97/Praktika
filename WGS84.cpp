#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <math.h>

using namespace std;


int main()
{  SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	
	float re; // �������������� ������(������� �������)
double e; // ��������������
double Gwgs0; // ��������� ���������� ������� �� �������� ������
double Gwgs1; //  �������������� ���������� �����
double Rmer; // ������ ���������
double Rnorm; // ���������� ������ 
double Reqviv; //��������� ������ �����
double G; //���������� � ������� ���������
int Lat; // ������� ������ � ��������

cout << "������� ������� ������ � ��������"  << endl;
cin >> Lat;
ofstream fout("result.txt");


re = 6378137;
e = 0.081819190842622;
Gwgs0 = 9.7803253359;
Gwgs1 = 3986004.418*pow(10,8);
Rmer = (re*(1-pow(e,2)))/pow((1-pow(e,2)*pow(sin(Lat),2)),3/2); //////////
Rnorm = (re)/pow((1-pow(e,2)*pow(sin(Lat),2)),1/2); //////////
Reqviv = sqrt(Rmer*Rnorm); /////////
G = Gwgs0*((1+Gwgs1*pow(sin(Lat),2))/pow((1-pow(e,2)*pow(sin(Lat),2)),1/2)); ///////


double i[4] = {Rmer, Rnorm, Reqviv, G};
for (int p = 0; p<4; p++) 
{ 
fout << i[p] << "	" <<  endl;
} 
cout << "������ ���������" << "			" << i[0] << endl;
cout << "���������� ������" << "			" << i[1] << endl;
cout << "��������� ������ �����" << "			" << i[2] << endl;
cout << "���������� � ������� ���������" << "		" << i[3] << endl;

   system("pause");
	
return 0;

fout.close();
	}
