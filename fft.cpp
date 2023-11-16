#include "fft.hpp"

// N must be a multiple of 2
vector<complex<double>> FourierTransform(const vector<complex<double>> input, const int N, const int s) {
    vector<complex<double>> transform;

    if (N == 1){
        transform.push_back(input[0]);
        return transform;
    }

    vector<complex<double>> trans1 = FourierTransform(input, N/2, 2 * s);
    vector<complex<double>> trans2 = FourierTransform(vector<complex<double>>(input.begin()+s, input.end()), N/2, 2 * s);

    // make the list of the transforms into one
    transform = trans1;
    transform.insert(transform.end(), trans2.begin(), trans2.end());


    complex<double> p, q;
    for (int k = 0; k < N/2 - 1; k++){
        p = transform[k];
        q = exp((-2 * C_PI * C_I * (double)k)/(double)N) * transform[k+(N/2)];
        transform[k] = p + q;
        transform[k+(N/2)] = p - q;
    }

    return transform;
}