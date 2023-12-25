#include "fft.hpp"
#include <iostream>
#include <random>

void print(vector<complex<double>> input);
bool checkVec(vector<complex<double>> vec1, vector<complex<double>> vec2);
int UnitTest_SimpleCase();
int UnitTest_RandomCase(int size);

int main(){
    if (UnitTest_SimpleCase()) { cout << "Unit_Test Simple Case failed!" << endl;}
    else { cout << "Unit_Test Simple Case Passed!" << endl; }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 10000);

    for (int i = 0; i < 10000; i++)
        if (UnitTest_RandomCase(distribution(gen))) { cout << "Unit_Test Random Case failed!" << endl; }

    return 0;
}

/**
 * @brief check if the simple example works with FourierTransform()
 * 
 * @return int 0 on pass, 1 on fail 
 */
int UnitTest_SimpleCase(){
    // 1, 2-i, -i, -1+2i
    vector<complex<double>> input;
    input.push_back(complex<double>(1.0, 0.0));
    input.push_back(complex<double>(2.0, -1.0));
    input.push_back(complex<double>(0.0, -1.0));
    input.push_back(complex<double>(-1.0, 2.0));

    // should be: 2, -2-2i, -2i, 4+4i
    vector<complex<double>> output = FourierTransform(input);
    vector<complex<double>> known = {
        complex<double>(2.0,0.0), 
        complex<double>(-2.0,-2.0),
        complex<double>(0.0, -2.0),
        complex<double>(4.0, 4.0)
    };

    if (checkVec(output, known)) { return 0; }
    else return 1;
}

/**
 * @brief create a random vector to transform 
 *        does not check if transform is correct
 * @return int 0 on pass, 1 on fail 
 */
int UnitTest_RandomCase(int size){
    if (size > 0 && !(size & (size - 1)) == 0) return 1; // size not a power of 2

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the distribution for the desired range
    std::uniform_int_distribution<int> distribution(-100000, 100000);

    vector<complex<double>> input;
    for(int i = 0; i < size; i++) input.push_back(complex<double>(distribution(gen), (distribution(gen))));
    FourierTransform(input);

    return 0;
}

/**
 * @brief check equivalance of two complex<double> vectors 
 * 
 * @return bool true if equivalent, false if not
 */
bool checVec(vector<complex<double>> vec1, vector<complex<double>> vec2){
    if (vec1.size() != vec2.size()) return false;
    for (int i = 0; i < vec1.size(); i++){
        if (vec1[i] != vec2[i]) return false;
    }
    return true;
}

/**
 * @brief quick way to send vector to cout
 */
void print(vector<complex<double>> input){
    for (complex<double> o : input){
        cout << o << endl;
    }
}