//This code is written by Mustafa Hesham Mohamed to find the root of a function using Newton-Raphson method.
//My student code at ISSR is 201800378.
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double resultxi, resultxis, resultxi1, accerror, apperror, xi, xi1;
	int n,iter,iten;
	cout<<"Please enter number of terms: "<<endl; //Enter number of equation terms.
	cin>>n;
	double coeff[n]; //Array to store the coefficient of each term.
	double powers[n]; //Array to store the exponent of each term.
	double coeff1[n]; //Array to store coefficients of the original function derivative terms.
	double powers1[n]; //Array to store exponents of the original function derivative terms.
	cout<<"Please enter the accepted error (percent) "<<endl; 
	cin>>accerror;
	for (int i = 0; i<n; i++){
		cout<<"Please enter coefficient number "<<i+1<<":"<<endl;
		cin>>coeff[i];
		cout<<"Please enter power number "<<i+1<<":"<<endl;
		cin>>powers[i];
	}
	cout<<"Please enter initial guess: "<<endl;
	cin>>xi;
	cout<<"Please enter number of maximum iterations: "<<endl;
	cin>>iter;
	
	for (int i = 0; i<n; i++){ //differentiation of each term to calculate f'(x).
		
		if (powers[i] >0 && powers[i] != 1) {
			
		coeff1[i]  = coeff[i] * powers[i];
		powers1[i] = powers[i] - 1;	
	}
		else if (powers[i] == 0){
			
			powers1[i] = 0;
			coeff1[i] = 0;
		}
		
		else if (powers[i] == 1) {
		powers1[i] = 0;
		coeff1[i]  = coeff[i];
	}
	}
	
	
	for (int f=0; f<iter; f++){
	resultxi  = 0; //Resetting the variable which stores f(xi).
	resultxis = 0; //Resetting the variable which stores f'(xi).
	for (int i=0; i<n; i++){
		resultxi += coeff[i] * pow(xi, powers[i]);
	}
    for (int i=0; i<n; i++){
		resultxis += coeff1[i] * pow(xi, powers1[i]);
	}
	
	xi1 = xi -(resultxi/resultxis);
    apperror = (xi1 - xi)*100/xi1;
    
    cout<<"The percentage error is "<<apperror<<"%"<<endl;
    cout<<"The f(xi) is "<<resultxi<<endl;
    cout<<"The f'(xi) is "<<resultxis<<endl;
    cout<<"Xi+1 is "<<xi1<<endl;
    cout<<"--------------------------------------------"<<endl;
    xi = xi1; //Assign the new value of xi after calculating f(xi), f'(xi) and the relative error.
    iten = f+1;
    if (accerror > apperror){
    	f = iter + 2; //If the calculated error is less than the accepted error, loop stops.
	}
		
	}
	
	cout<<"Number of iterations is: "<<iten<<endl;
	return 0;
	
}
