#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Question 1: Define a C structure complex for a complex number with two data
members for the (real, imaginary) real and imaginary parts of the
complex number*/
typedef struct complexNumber{
    float imaginaryNumber;
    float realNumber;
} complexNumber;

//exponential complex number representation
typedef struct exponentialComplexNumber{
    float imaginaryNumber;
    float absoluteVal;
} exponentialComplexNumber;




complexNumber raiseComplexNumber(int x, int y, int N);
double convertRadianToDegree(double radian);
double convertDegreeToRadian(double degree);
float raisePower(float number, int n);


int main()
{

    complexNumber result ;
    float x;
    float y;
    int n;
    char sign = ' '  ;

    printf("Enter a real number: ");
    scanf("%f", &x);
    printf("Enter an imaginary number: ");
    scanf("%f", &y);
    printf("Enter power number: ");
    scanf("%d", &n);

    result = raiseComplexNumber(x,y,n);


    if(result.imaginaryNumber > 0){
         sign = '+';
    }
    printf("%c", sign);

   printf("(%.1f,%c%.1fi)", result.realNumber, sign, result.imaginaryNumber);
    return 0;
}

complexNumber raiseComplexNumber(int x, int y, int N){
    complexNumber result ;

    //R = √(𝑥2 + 𝑦2 )
    float R = sqrt(raisePower(x,2) + raisePower(y,2));
    float teta = convertRadianToDegree(atan((float) y/x));

    //writing (𝑥 + 𝑗𝑦)𝑎𝑠 𝑅𝑒𝑗𝜃
    exponentialComplexNumber exponentialVal;
    exponentialVal.absoluteVal = R;
    exponentialVal.imaginaryNumber= teta;


    //writing result as 𝑅𝑛𝑒𝑗𝑛𝜃 𝑎𝑠 (𝑅𝑛𝑐𝑜 𝑠(𝑛𝜃) + 𝑗𝑅𝑛𝑠𝑖𝑛(𝑛𝜃))
    float realNumResult = raisePower(R, N) * cos(convertDegreeToRadian(N * teta));
    float imaginaryNumResult = raisePower(R, N) * sin(convertDegreeToRadian(N * teta));

    result.realNumber = realNumResult;
    result.imaginaryNumber = imaginaryNumResult;
    return result;

}


double convertRadianToDegree(double radian){
    double pi = 3.14159;
    return(radian * (180/pi));
}

double convertDegreeToRadian(double degree){
      double pi = 3.14159;
    return (degree * (pi/180));
}

float raisePower(float number, int n){
    float ans = number;
    for(int i = 1; i < n; i++){
        ans *= number;
    }
    return ans;
}



