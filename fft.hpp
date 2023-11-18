#ifndef FFT_HPP
#define FFT_HPP

#include <cmath>
#include <complex>
#include <vector>

using namespace std;

// complex number i
#define C_I complex<double>(0.0, 1.0)

// PI for doubles and complex numbers
#define C_PI atan(1) * 4

/// @brief A Cooley-Tukey Fast Fourier Transform Algorithm for complex numbers of time nlgn
/// @param input a std::vector of std::complex<double>
/// @return a std::vector<complex<double>> of the new transform, the same size as input 
vector<complex<double>> FourierTransform(const vector<complex<double>> input);

#endif