#include <stdio.h>
#include <math.h>

//static array	
#define N 12 
//global variable
float TanArr[N+1];  // array to store 13 elements

//function declaration : float is the return type of function degtorad and arguement is of type float degarg
float degtorad(float degarg);
float traprule(); //global variables are automatically taken as arguement

int main()
{
	float a = 0.0, b_deg = 60.0; // in degrees-pi/3
	
    float deg; 

	
// Calculate the area from pts x1 to x11 and add them up using for loop
	int i;
	for(i = 0; i < N; i++)
	{
		deg = i*5.0;
		TanArr[i] = tan(degtorad(deg));//(M_PI*deg)/180.0);
		printf("TanArr(%d) = %f\n",i,TanArr[i]);
	}

float area = traprule();

// Approximated result
printf("\n Trapezoidal result is:%f\n",area);
//Actual result
// Integral of tan is ln(2)
printf("Real result is:%f\n",log(2.0));	
	return 0;
}
// function definition
float degtorad(float degarg){
	float pi = 3.1415927;
	return ((pi * degarg)/180.0);
}
float traprule(){
	float area;
	int i;
	// Sum of tan(a) and tan (b) where tan takes arguements in radians, and b are radians		
    area = TanArr[0]+TanArr[N];
	printf("Initial area(sum at x(0) and x(12)) before the loop is: %f\n", area);

    for(i=1;i<N;i++){
    	area = area+2*TanArr[i];
	}
	printf("The vaue of sum after the loop is: %f\n",area);
// Multiply area by (pi/3).2*12 
	float mul_rad = degtorad((60.0-0.0)/(2*N));///(M_PI*((b_deg-a)/(2*N)))/180.0;
	area = mul_rad*area;
}

