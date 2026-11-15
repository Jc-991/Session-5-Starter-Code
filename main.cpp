#include <iostream>
#include <string>
#include <vector>


double multiplication(double a, double b){
    return a * b;
}

int main(){
    double result = multiplication(1.2, 2.0);
    std::cout << result;
}