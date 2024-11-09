#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/*
Find e uing a Taylor series expansion from e^0.
The estimate gets worse after 13th order polynomial
because 13! is bigger than the maximum number that 
can be stored in 4 byte integer
*/
int factorial(int n);

int main(void){
	int i, order;
	// to dynamically allocate the array we use pointers and hence creating the below variable
	double e, *terms;
	
	printf("Enter the required polynomial order\n");
	if(scanf("%d",&order) !=1)
	{
		printf("Did not enter a number\n");
		return 1;
	}
	
	// Allocate space depending on n
	// sizeof(double)-kind of variable that will be used, order - how many of it will be used, double - then convert it to correct data type
	terms = (double*)malloc(order*sizeof(double));
	for(i=0;i<order;i++)
	{
		terms[i] = 1.0 / (double)factorial(i+1);
		printf("%.16lf\n",terms[i]);
	}
	e=1.0;
	for(i=0;i<order;i++)
	{
		e = e + terms[i];
	}
	// write immediately after writing malloc
	free(terms);
	
	printf("e is etimated as %.10lf, with difference %e\n",e,e - exp(1.0));
	return 0;
	
}

int factorial(int n){
	if(n<0){
		printf("Error! : Negative number passed to factorial\n");
		return(-1);
	}
	else if(n==0){
		return 1;
	}
	else{
		return(n*factorial(n-1));
	}
}
