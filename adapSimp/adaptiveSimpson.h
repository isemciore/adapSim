//https://en.wikipedia.org/wiki/Adaptive_Simpson's_method
// Created by root on 2015-11-02.
//

#ifndef ADAPSIMP_ADAPTIVESIMPSON_H
#define ADAPSIMP_ADAPTIVESIMPSON_H
#include <cmath>

double ASIHelp(double(*fun) (double), double& a, double& b, double& tol,double& prevIVal, double& fun_a, double& fun_b, double& fun_c, unsigned recDepth );


double ASI(double (*fun)(double), double& a, double& b,double tol = 1e-10, unsigned recDepth = 100){
    double c = (a+b)/2;
    double width = b-a;
    double fun_a = fun(a);
    double fun_b = fun(b);
    double fun_c = fun(c);
    double inteValue = (width/6)*(fun_a+4*fun_c + fun_b);
    return ASIHelp(fun,a,b,tol,inteValue,fun_a,fun_b,fun_c,recDepth);
}

//INTEGRATION POINTS
//A D C E B
double ASIHelp(double(*fun) (double), double& a, double& b, double& tol,double& prevIVal, double& fun_a, double& fun_b, double& fun_c, unsigned recDepth ){
    double c = (a+b)/2;
    double subWidth = (b-a)/2;
    double d = (a+c)/2;
    double e = (c+b)/2;
    double fun_d = fun(d);
    double fun_e = fun(e);

    double inteValLeft  = (subWidth/6)*(fun_a+4*fun_d+fun_c);
    double inteValRight = (subWidth/6)*(fun_c+4*fun_e+fun_b);
    double inteValue = inteValLeft+inteValRight;

    if(recDepth < 1 || fabs(inteValue-prevIVal) < 15*tol){
        return inteValue + (inteValue-prevIVal)/15;
    }
    return ASIHelp(fun,a,c,tol,inteValLeft,fun_a,fun_c,fun_d,recDepth-1) +
           ASIHelp(fun,c,b,tol,inteValRight,fun_c,fun_b,fun_e,recDepth-1);

}


#endif //ADAPSIMP_ADAPTIVESIMPSON_H
