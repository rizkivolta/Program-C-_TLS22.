#include <iostream>
#include <cmath>
using namespace std;

// a. Fungsi menghitung jarak antara dua titik
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// b. Fungsi menghitung jari-jari lingkaran
double radius(double x_center, double y_center, double x_point, double y_point) {
    return distance(x_center, y_center, x_point, y_point);
}

// c. Fungsi menghitung keliling lingkaran
double circumference(double r) {
    const double pi = 3.1416;
    return 2 * pi * r;
}

// d. Fungsi menghitung luas lingkaran
double area(double r) {
    const double pi = 3.1416;
    return pi * r * r;
}

int main() {
    double x_center, y_center, x_point, y_point;

    cout << "Masukkan koordinat pusat lingkaran (x1 y1): ";
    cin >> x_center >> y_center;

    cout << "Masukkan koordinat titik pada lingkaran (x2 y2): ";
    cin >> x_point >> y_point;

    double r = radius(x_center, y_center, x_point, y_point);
    double d = 2 * r;
    double c = circumference(r);
    double a = area(r);

    cout << "\n=== Hasil Perhitungan Lingkaran ===\n";
    cout << "Jari-jari (radius)     = " << r << endl;
    cout << "Diameter               = " << d << endl;
    cout << "Keliling (circumference) = " << c << endl;
    cout << "Luas (area)            = " << a << endl;

    return 0;
}
