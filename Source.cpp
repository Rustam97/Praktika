#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <windows.h>
#include <cstring>
#include <cstdio>
#include <math.h>
#define M_PI       3.14159265358979323846

using namespace std;

struct point {
	float x, y;
	char city[40];
	int sqr_dist(const point &other) const {
		return (x - other.x) * (x - other.x)
			+ (y - other.y) * (y - other.y);
	}
	int operator()(const point &p1, const point &p2) const {
		return sqr_dist(p1) < sqr_dist(p2);
	}
};

ostream & operator<<(ostream &os, const point &p) {
	return os  << "��������� ����� ���������� �� �����������: " << p.x << " " << p.y << " " << p.city << "��� ������� ����  " << endl;
}

istream & operator>>(istream &is, point &p) {
	return is  >> p.x >> p.y >> p.city;
}

class wgs84
{
	double re, e, Latrad, Longrad, Rmer, Rnorm, Reqviv, x, y, z, Lat, Long;      //Lat - ������� ������ � ��������; Long - ������� ������� � ��������;      
public:
	void get_res()
	{
		cout << "������� ������� ������ � ��������" << endl;
		cin >> Lat;
		cout << "������� ������� ������� � ��������" << endl;
		cin >> Long;
		double re = 6378137;                  // �������������� ������(������� �������)
		double e = 0.081819190842622;         // ��������������
		double Latrad = Lat * (M_PI / 180);       //������� ������ � �������
		double Longrad = Long * (M_PI / 180);     //������� ������� � �������
		double Rmer = (re*(1 - pow(e, 2))) / pow((1 - pow(e, 2)*pow(sin(Latrad), 2)), 3 / 2);    // ������ ���������
		double Rnorm = (re) / pow((1 - pow(e, 2)*pow(sin(Latrad), 2)), 1 / 2);                // ���������� ������ (������ �������� ���������)
		double Reqviv = sqrt(Rmer*Rnorm);     //��������� ������ �����(������)
		double x = (Rnorm + Reqviv)*cos(Latrad)*cos(Longrad);     //���������� �
		double y = (Rnorm + Reqviv)*cos(Latrad)*sin(Longrad);     //���������� �
		double z = ((1 - pow(e, 2))*Rnorm + Reqviv)*sin(Latrad);       //���������� z 
		double i[4] = { x, y, z, Reqviv };
		cout << "���������� X (�)" << "		" << i[0] << endl;
		cout << "���������� Y (�)" << "		" << i[1] << endl;
		cout << "���������� Z (�)" << "		" << i[2] << endl;
		cout << "������������� ������ H (�)" << "		" << i[3] << endl;
	}
}s1;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	s1.get_res();

	vector<point> ps;
	ifstream f("points.txt");
	if (f.is_open())
	{
		cout << "���� ������." << endl;
	}
	copy(istream_iterator<point>(f),
		istream_iterator<point>(),
		back_inserter(ps));
	point p;
	cout << "�������� ������� ������� ������ � �������  ~����� ������~ : ";
	cin >> p;
	auto im = min_element(ps.cbegin(), ps.cend(), p);
	cout << *im;
	system("pause");
	return 0;
}