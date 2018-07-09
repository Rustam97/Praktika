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
	
	
	
	float re; // экваториальный радиус(большая полуось)
double e; // эксцентриситет
double Gwgs0; // ускорение свободного падения на экваторе геоида
double Gwgs1; //  гравитационная постоянная Земли
double Rmer; // радиус меридиана
double Rnorm; // нормальный радиус 
double Reqviv; //локальный радиус Земли
double G; //гравитация в текущем положении
int Lat; // текущая широта в градусах

cout << "Введите текущую широту в градусах"  << endl;
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
cout << "РАДИУС МЕРИДИАНА" << "			" << i[0] << endl;
cout << "НОРМАЛЬНЫЙ РАДИУС" << "			" << i[1] << endl;
cout << "ЛОКАЛЬНЫЙ РАДИУС ЗЕМЛИ" << "			" << i[2] << endl;
cout << "ГРАВИТАЦИЯ В ТЕКУЩЕМ ПОЛОЖЕНИИ" << "		" << i[3] << endl;

   system("pause");
	
return 0;

fout.close();
	}
