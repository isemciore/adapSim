//
// Created by root on 2015-11-02.
//
#include "adaptiveSimpson.h"
#include <iostream>
#include <cmath>

int funEval = 0;
double funSinExp(double x){
    funEval++;
    double tmp = 1+ sin(exp(3*x));
    return tmp;
}


int main(){
    double (*fun) (double);
    fun = &funSinExp;
    double a, b, tol;
    std::cout.precision(15);
    while(std::cin >> a >> b >> tol){
        double result = ASI(fun,a,b,tol);
        std::cout << "calc area : "<< result << "\n";
        std::cout << "error "<< result-2.5008091103361667680093444 << "\n";
        std::cout << "Number of iteration " << funEval << "\n\n";
        funEval = 0;
    }
    return 0;

}
