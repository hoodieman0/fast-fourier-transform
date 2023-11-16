#include "fft.hpp"
#include <iostream>

int main(){
    vector<complex<double>> input;
    input.push_back(complex<double>(1.0, 0.0));
    input.push_back(complex<double>(2.0, -1.0));
    input.push_back(complex<double>(0.0, -1.0));
    input.push_back(complex<double>(-1.0, 2.0));

    vector<complex<double>> output = FourierTransform(input, input.size(), 1);
    
    // 2, -2-2i, -2i, 4+4i
    /*
        2, 0
        -2, -2
        0, -2
        4, 4

    */
    for(complex<double> o : output){
        cout << o << endl;
    }

    return 0;
}

// go through example