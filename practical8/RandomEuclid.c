/* 
*Iterative and recursive versions of Euclid's algorithm
* to calculate the gcd of two positive integers.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int iterativeGCD(int a, int b){
	int temp;
	while(b!=0){
		temp = b;
		b=a%b;
		a=temp;
	}
	return a;
}

// recursive version of the ame algorithm
int recursiveGCD(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return(recursiveGCD(b,a%b));
	}
}

int main(){
	int a,b;
	 // Generate two numbur random positive integers 1 and 20
	 srand(time(NULL));
	 a = (rand() % 20) + 1;
	 b = (rand() % 20) + 1;
	
	printf("IterativeGCD(%d,%d)=%d\n",a,b, iterativeGCD(a,b));
	printf("RecursiveGCD(%d,%d)=%d\n",a,b, recursiveGCD(a,b));
	return 0;
}
