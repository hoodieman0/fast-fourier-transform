# Cooley-Tukey Fast Fourier Transform
<!-- Badges -->
![License](https://img.shields.io/github/license/hoodieman0/fast-fourier-transform?style=plastic) 
![Issues](https://img.shields.io/github/issues/hoodieman0/fast-fourier-transform?style=plastic)
![Contributors](https://img.shields.io/github/contributors/hoodieman0/fast-fourier-transform?color=Red&style=plastic)
![LastCommit](https://img.shields.io/github/last-commit/hoodieman0/fast-fourier-transform?style=plastic)

<!-- Summary -->
An implementation of the Cooley-Tukey 1965 Fast Fourier Transform algorithm. The algorithm is a decimation-in-time algorithm, meaning that its input is split into smaller sets of inputs [2]. This is implemented as a recursive function.
While not the most exhaustive function for every case, it serves as a baseline for future expansion. The Cooley-Tukey algorithm runs in O(nlgn) time [2].

<!-- How to use -->
## Usage
All that is needed to use the algorithm is to download fft.hpp and fft.cpp and compile it with the program. Include fft.hpp in the file it is needed in. The lib_fft.so library can also be dynamically linked like such if needed:

```
>> c++ -shared -o lib_fft.so fft.o
>> c++ -o main Unit_Test.o -L. -l_fft
```

The unit test is not needed unless you wish to test the fft program. The dynamically linked way is preferred for ease of exporting and linking the FFT function to other code.

Because the Cooley-Tukey algorithm is a decimation-in-time algorithm, the FFT's input vector should have a size that is a power of 2. The following example would not produce useful results and should be avoided.

```
// vector of length 3
vector<complex<double>> myVec = {
        complex<double>(2.0,0.0), 
        complex<double>(-2.0,-2.0),
        complex<double>(0.0, -2.0),
    }; 
FourierTransform(myVec); // returns garbage data
```

<!-- Why -->
## Why?
I mainly did this to learn what the FFT algorithm was. Using the function provided, it takes discrete samples of a function and finds the frequencies present in that function [3]. The output of the function is a complex-valued function of frequency [4]. Discrete fourier transforms like this one can be used in many computer-based applications such as digital signal processing and image processing [4]. If I need it for future projects, I have it here. There can be practical uses to this code, but since it does not cover every possibility it would need more tweaking. Regardless, this was a good coding experience to learn a new math concept.

<!-- Further Work -->
## Future Work
* Allow sizes that are not powers of 2 (see [2])
* Allow overload for non-complex numbers
* Add more prewritten unit tests
* More reading on Fourier Transforms
* Research possibilities of Inverse Fourier Transforms

## Notes

* Euler's formula converts cos(2pift) + isin(2pift) to e^(i2pift)
* [[1] Veritasium Video on FFT](https://www.youtube.com/watch?v=nmgFG7PUHfo)
    * Accessed 24 Dec. 2023
* [[2] University of Oxford Information Engineering lecture on FFT ](https://www.robots.ox.ac.uk/~sjrob/Teaching/SP/l7.pdf)
    * Accessed 24 Dec. 2023
* [[3] Wikipedia on Fourier Transforms](https://en.wikipedia.org/wiki/Fourier_transform)
    * Accessed 24 Dec. 2023
* [[4] Wikipedia on Discrete Fourier Transform](https://en.wikipedia.org/wiki/Discrete_Fourier_transform)
    * Accessed 24 Dec. 2023