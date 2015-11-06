#include <iostream>
#include <cmath>
#include <vector>

double sinTaylor(int N, double x);
double cosTaylor(int N, double x);
long double faculty(int N);
double horner(std::vector<long double> & a_coeff,double x);

int main(){
	int iter;
	double x_test; 
	//Takes input in pairs: Iteration, X 
	while(std::cin >> iter >> x_test){
		//Calculate sin(x) using approximation and "cmath" 
		//Output comparision
		std::cout << "Sin calculation \n";
		double sinAppr = sinTaylor(iter,x_test);
		std::cout << "ApproxValue :  Ref. Value  :  Expct. Error :  Actu. Error \n";
		std::cout << sinAppr << "       " << sin(x_test) << "       ";
		std::cout << std::abs((sinTaylor(iter,x_test) - sinTaylor(iter+1,x_test)));
		std::cout << "        ";
		std::cout << std::abs(sinAppr-sin(x_test)) << "\n"; //<<" :actual error\n";
					//Calculate cos(x) 
		std::cout << "Cos calculation\n";
		double cosAppr = cosTaylor(iter,x_test);
		std::cout << "ApproxValue :  Ref. Value  :  Expct. Error :  Actu. Error \n";
		std::cout << cosAppr <<"       " << cos(x_test) << "       ";
		std::cout << std::abs((cosTaylor(iter,x_test) - cosTaylor(iter+1,x_test)));
		std::cout << "        " << std::abs(cosAppr-cos(x_test));	
		std::cout << "\n";
	}
	return 1;
}

//Both cosTaylor and sinTaylor finds the coefficient infront in the respective taylor series
double cosTaylor(int N, double x){
	int signOne = 1;
	
	std::vector<long double> a_coefficient;
	for (int i = 0; i <N ;i++){
		if(i%2) signOne = -1;
		else signOne = 1;
		a_coefficient.push_back(signOne/faculty((int) 2*i));
		a_coefficient.push_back(0);
	}
	//Once the coefficient in front of the taylor series is computed, Horner method is used to calculate the sum
	double polyVal = horner(a_coefficient,x);
	return polyVal;
}

double sinTaylor(int N, double x){
	int signOne = 1;
	
	std::vector<long double> a_coefficient;
	for (int i = 0; i < N;i++){
		a_coefficient.push_back(0);
		if(i%2) signOne = -1;
		else signOne = 1;
		a_coefficient.push_back(signOne/faculty((int)2*i+1));
	}
	double polyVal = horner(a_coefficient,x);
	return polyVal;
}


//Given polynomial coefficient, calculates the polynomial with horner method
double horner(std::vector<long double> & a_coeff, double x){
	int degPoly = a_coeff.size()-1;
	double hornMethodRes = 0;
	//b_n = a_n
	//b_n-1 = a_n-1 + b_n*x
	for (int i = degPoly; i >=0; i--){ 
		hornMethodRes = hornMethodRes*x + a_coeff[i];
	}
	return hornMethodRes;
	
}

//Calculates the faculty
long double faculty(int N){
	long double fact = 1;
	for(int i = 1; i<=N;++i){
		fact *= i;
	}
	return fact;
}
