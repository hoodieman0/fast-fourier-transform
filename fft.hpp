#ifndef FFT_HPP
#define FFT_HPP

#include <cmath>
#include <complex>
#include <vector>

using namespace std;

#define C_I complex<double>(0.0, 1.0)
#define C_PI atan(1) * 4

vector<complex<double>> FourierTransform(const vector<complex<double>> input, const int N, const int s);

#endif