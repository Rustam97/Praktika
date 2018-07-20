#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <math.h>
#define M_PI       3.14159265358979323846



using namespace std;


class wgs84
{double re, e, Latrad, Longrad, Rmer,  Rnorm, Reqviv, x, y, z, Lat, Long;      //Lat - текущая широта в градусах; Long - текущая долгота в градусах;      
public:      
void get_res()
{ cout << "Введите текущую широту в градусах"  << endl;
cin >>  Lat;
cout << "Введите текущую долготу в градусах"  << endl;
cin >> Long;
double re = 6378137;                  // экваториальный радиус(большая полуось)
double e = 0.081819190842622;         // эксцентриситет
double Latrad = Lat*(M_PI/180);       //перевод широты в радианы
double Longrad = Long*(M_PI/180);     //перевод долготы в радианы
double Rmer = (re*(1-pow(e,2)))/pow((1-pow(e,2)*pow(sin(Latrad),2)),3/2);    // радиус меридиана
double Rnorm = (re)/pow((1-pow(e,2)*pow(sin(Latrad),2)),1/2);                // нормальный радиус (радиус кривизны вертикала)
double Reqviv = sqrt(Rmer*Rnorm);     //локальный радиус Земли(геоида)
double x = (Rnorm + Reqviv)*cos(Latrad)*cos(Longrad);     //координата х
double y = (Rnorm + Reqviv)*cos(Latrad)*sin(Longrad);     //координата у
double z = ((1-pow(e,2))*Rnorm+Reqviv)*sin(Latrad);       //координата z 
double i[4] = {x, y, z, Reqviv};
cout << "Координата X" << "		" << i[0] << endl;
cout << "Координата Y" << "		" << i[1] << endl;
cout << "Координата Z" << "		" << i[2] << endl;
cout << "Геодезическая высота H" << "		" << i[3] << endl;
}
}s1;
		



int main()
{  SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

s1.get_res();
   system("pause");
     return 0;

}




