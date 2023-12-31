#include "fft.hpp"

// Must be a power of 2
// Not tested with any other size
vector<complex<double>> FourierTransform(const vector<complex<double>> input) {
    const int N = input.size();
    
    // recursion base case, no work is done
    if (N == 1){
        return input;
    }

    // make the even-indexed and odd-indexed arrays
    vector<complex<double>> transformEven, transformOdd;
    for(int i = 0; i < N; i=i+2){
        transformEven.push_back(input[i]);
        if (i+1 > N) break;
        transformOdd.push_back(input[i+1]);
    }
    
    transformEven = FourierTransform(transformEven);
    transformOdd = FourierTransform(transformOdd);

    // make an array of input.size() and fill it with new Fast Fourier Transform values
    vector<complex<double>> output(N);
    complex<double> p, q;
    for (int k = 0; k < N/2; k++){
        p = transformEven[k];
        q = exp((-2 * C_PI * C_I * (double)k)/(double)N) * transformOdd[k];
        
        output[k] = p + q;
        output[k+(N/2)] = p - q;
    }

    return output;
}