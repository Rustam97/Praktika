#include "Hd.h"
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
	return os << "Ближайший город расположен по координатам: " << p.x << " " << p.y << " " << p.city << "над уровнем моря  " << endl;
}
istream & operator>>(istream &is, point &p) {
	return is >> p.x >> p.y >> p.city;
}