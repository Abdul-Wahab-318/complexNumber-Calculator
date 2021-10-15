#include <iostream>
using namespace std ;

//returns + symbol if number is positive else returns blank space
char getSymbol ( float number )
{
	if( number >= 0)
	return '+' ;
	else
	return ' ';
}

int main ()
{
	//declare variables
	float firstReal , firstImaginary ;
	float secondReal , secondImaginary ;
	float realResult , imaginaryResult , denominator ;
	char  operation;
	
	//input real and imaginary parts seperately from user .We solve real and imaginary parts seperately
	cout << "Enter real part of first number : " ;
	cin >> firstReal ;
	
	cout << "Enter complex part of second number : " ;
	cin >> firstImaginary ;
		
	cout << "\nEnter real part of second number : " ;
	cin >> secondReal ;
	
	cout << "Enter complex part of second number : " ;
	cin >> secondImaginary ;
	
	cout << "\n\nFirst complex number : " << firstReal << getSymbol(firstImaginary) << firstImaginary << "i" ;
	cout << "\nSecond complex number : " << secondReal << getSymbol(secondImaginary) << secondImaginary << "i" ;
	
	cout << "\nChoose the operation ( +  -  *  / ) : " ;
	cin >> operation ;
	
	if( operation == '+' )
	{
		realResult = firstReal + secondReal ;
		imaginaryResult = firstImaginary + secondImaginary ;
	}
	else if ( operation == '-' )
	{
		realResult = firstReal - secondReal ;
		imaginaryResult = firstImaginary - secondImaginary ;
	}
	else if ( operation == '*' )
	{
		// (a+bi) * (c+di) = (a)(c) + (a)(di) + (bi)(c) + (bi)(di) , seperating real and imaginary
		realResult = ( firstReal * secondReal ) + ( firstImaginary * secondImaginary * -1 ); // -1 because i^2 = -1
		imaginaryResult = (firstReal * secondImaginary) + (firstImaginary * secondReal);
	}
	else if ( operation == '/' )
	{
		//multiply by conjugate of denominator and take square of both operands in denominator . math trick :)
		// (a+bi) * (c-di) = (a)(c) + (a)(-di) + (bi)(c) + (bi)(-di) , seperating real and imaginary
		realResult = (firstReal * secondReal) + (firstImaginary * -secondImaginary ) * -1 ;
		imaginaryResult =  firstReal * -secondImaginary + firstImaginary * secondReal ;
		denominator = secondReal*secondReal + secondImaginary * secondImaginary ; 
	}
	else
	{
		cout << "Wrong input";
	}
	
	cout << "\nAnswer :  " <<  realResult << getSymbol(imaginaryResult) << imaginaryResult << "i" ;
	
	//if numbers were divided then print the denominator 
	if( operation == '/' )
	cout << "/" << denominator ; 

	
}






