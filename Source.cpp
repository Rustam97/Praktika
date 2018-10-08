#include <iostream>
#include "Hd.h"

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
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double re, e, Latrad, Longrad, Rmer, Rnorm, Reqviv, x1, y1, z1, x, y;      

	vector<point> ps;
	ifstream f("points.txt");
	if (f.is_open())
	{
		cout << "Файл открыт." << endl;
	}
	copy(istream_iterator<point>(f),
		istream_iterator<point>(),
		back_inserter(ps));
	point p ;
	cout << "Введите текущую широту и долготу  ~через пробел~ : ";
	cin >> p;
	auto im = min_element(ps.cbegin(), ps.cend(), p);
	cout << *im;

	////////////////////////////////////////////////////////////////////////////WGS84////////////////////////////////////////////////////////////////////////////////
	re = 6378137;                  // экваториальный радиус(большая полуось)
	e = 0.081819190842622;         // эксцентриситет
	Latrad = p.x * (M_PI / 180);       //перевод широты (x) в радианы
	Longrad = p.y * (M_PI / 180);     //перевод долготы (y) в радианы
	Rmer = (re*(1 - pow(e, 2))) / pow((1 - pow(e, 2)*pow(sin(Latrad), 2)), 3 / 2);    // радиус меридиана
	Rnorm = (re) / pow((1 - pow(e, 2)*pow(sin(Latrad), 2)), 1 / 2);                // нормальный радиус (радиус кривизны вертикала)
	Reqviv = sqrt(Rmer*Rnorm);     //локальный радиус Земли(геоида)
	x1 = (Rnorm + Reqviv)*cos(Latrad)*cos(Longrad);     //координата х
	y1 = (Rnorm + Reqviv)*cos(Latrad)*sin(Longrad);     //координата у
	z1 = ((1 - pow(e, 2))*Rnorm + Reqviv)*sin(Latrad);       //координата z 
	double i[4] = { x1, y1, z1, Reqviv };
	cout << "Координата X (м)" << "		" << i[0] << endl;
	cout << "Координата Y (м)" << "		" << i[1] << endl;
	cout << "Координата Z (м)" << "		" << i[2] << endl;
	cout << "Геодезическая высота H (м)" << "		" << i[3] << endl;


	system("pause");
	return 0;
}