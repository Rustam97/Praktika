#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <math.h>
#define M_PI       3.14159265358979323846



using namespace std;



/////////////////////////////////////////////////////////
double wgs84 (double Lat,double Long)
{double re;       // �������������� ������(������� �������)
double e;       // ��������������
double Rmer;    // ������ ���������
double Rnorm;   // ���������� ������ (������ �������� ���������)
double Reqviv;  //��������� ������ �����(������)
double Lat;     //������� ������ � ��������
double Long;    //������� ������� � ��������
double Latrad;  //������� ������ � �������
double Longrad; //������� ������� � �������
double x;       //���������� �
double y;       //���������� �
double z;       //���������� z
re = 6378137;
e = 0.081819190842622;
Latrad = Lat*(180/M_PI);
Longrad = Long*(180/M_PI);
Rmer = (re*(1-pow(e,2)))/pow((1-pow(e,2)*pow(sin(Latrad),2)),3/2); 
Rnorm = (re)/pow((1-pow(e,2)*pow(sin(Latrad),2)),1/2); 
Reqviv = sqrt(Rmer*Rnorm);
x = (Rnorm + Reqviv)*cos(Latrad)*cos(Longrad);
y = (Rnorm + Reqviv)*cos(Latrad)*sin(Longrad);
z = ((1-pow(e,2))*Rnorm+Reqviv)*sin(Latrad);
double i[3] = {x, y, z};
cout << "���������� X" << "		" << i[0] << endl;
cout << "���������� Y" << "		" << i[1] << endl;
cout << "���������� Z" << "		" << i[2] << endl;
};
/////////////////////////////////////////////////////////			



int main()
{  SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

/////////////////////////////////////////////////////////
double Lat;    
double Long;    
/////////////////////////////////////////////////////////
cout << "������� ������� ������ � ��������"  << endl;
cin >>  Lat;
cout << "������� ������� ������� � ��������"  << endl;
cin >> Long;
/////////////////////////////////////////////////////////
wgs84 (Lat, Long);
/////////////////////////////////////////////////////////
   system("pause");
     return 0;
/////////////////////////////////////////////////////////

}




