#ifndef Hd_h
#define Hd_h
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <windows.h>
#include <cstdio>
#include <math.h>
#define M_PI       3.14159265358979323846
using namespace std;
struct point;
ostream & operator<<(ostream &os, const point &p);
istream & operator>>(istream &is, point &p);
#endif 