#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
double ASI_help(double (*fun)(double), double a, double b,std::unordered_map<double,double>& map, double lastInt ,double tol);

double integral(double(*fun)(double),double a,double b, std::unordered_map<double,double> & mapFunEval);
double ASI(double (*fun)(double), double a, double b,double tol);
double funSinExp(double x);
int funEval = 0;
int counter = 0;
int main(){
	//Creates function pointer, makes easly change function to integrate
	double (*fun)(double);
	fun = &funSinExp;
    double startInt = -1;
    double endInt = 1;
    double tol;
    std::cout.precision(15);
	while(std::cin >> tol){
		//Performs integration on function, fun, from startInt to endInt with tolerance tol
		double intValue = ASI(fun,startInt,endInt,tol);
		std::cout << "calc area : "  << intValue<< "\n";
		std::cout << "error "<< intValue-2.5008091103361667680093444 << "\n";
		std::cout << "Number of iteration " << funEval << "\n\n";
		funEval = 0;}
	return 0;
}
//functin to be integrated, should return density/value of a point.
double funSinExp(double x){
	funEval++;
	double tmp = 1+ sin(exp(3*x));
	return tmp;
}

double integral(double(*fun)(double),double a,double b, std::unordered_map<double,double> & mapFunEval){
		if (mapFunEval.find(a) == mapFunEval.end()){mapFunEval.emplace(a,fun(a));}
		if (mapFunEval.find((a+b)/2) == mapFunEval.end()){mapFunEval.emplace((a+b)/2,fun((a+b)/2));}
		if (mapFunEval.find(b) == mapFunEval.end()){mapFunEval.emplace(b,fun(b));}
		double yA = mapFunEval[a];
		double yC = mapFunEval[(a+b)/2];
		double yB = mapFunEval[b];
		return (b-a)/6*(yA + 4*yC + yB);
	}
//	return ((b-a)/6) * (fun(a) + 4*fun((a+b)/2) + fun(b));

double ASI(double (*fun)(double), double a, double b,double tol){
	std::unordered_map<double,double> map;
	
	double gamma = (a+b)/2;
	double inte_1 =   integral(fun,a,b,map);
	double inte_2_a = integral(fun,a,gamma,map);
	double inte_2_b = integral(fun,gamma,b,map);
	double inte_2 = inte_2_a + inte_2_b;
	double errest = (double) std::fabs(inte_1-inte_2);
	if (errest < 15*tol){
		return inte_2;}
	else
		return ASI_help(fun,a,gamma,map,inte_2_a,tol/2) + ASI_help(fun,gamma,b,map,inte_2_b,tol/2);
	
}

double ASI_help(double (*fun)(double), double a, double b,std::unordered_map<double,double>& map, double lastInt ,double tol){
	double gamma = (a+b)/2;
	double inte_1 = lastInt;
	double inte_2_a = integral(fun,a,gamma,map);
	double inte_2_b = integral(fun,gamma,b,map);
	double inte_2 = inte_2_a + inte_2_b;
	double errest = (double) std::fabs(inte_1-inte_2);
	if (errest < 15*tol){
		return inte_2;}
	else{
		return ASI_help(fun,a,gamma,map,inte_2_a,tol/2) + ASI_help(fun,gamma,b,map,inte_2_b,tol/2);
	}
}
/*Hashmap
 * keyMap
 * iterate, throw in new x into
 * integrate by sum up key diff and height
 */
