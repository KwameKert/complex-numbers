#ifndef TEST_H
#define TEST_H


class test
{
    public:
        test();
        virtual ~test();

    protected:

    private:
};


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


//this is new structure



complexNumber raiseComplexNumber(int x, int y, int N);
complexNumber newRaiseComplexNumber(int x, int y, int N);
exponentialComplexNumber formatComplexNumber(int x, int y);
double convertRadianToDegree(double radian);
double convertDegreeToRadian(double degree);
/*Question 2: What we want to do next is to write a procedure to raise any complex
number to any integer power
*/
complexNumber raiseComplexNumber(int x, int y, int N) {
    //using formula: (a+ib)N=rN(cos(Nθ)+isin(Nθ));
    complexNumber result;

    // θ = tan-1(y/x)
   double teta = convertRadianToDegree(atan((float) y/x));
   //r = r2=a2+b2
    float r = sqrt(pow(x, 2) + pow(y,2));

    float R = pow(r, N);

    float cosResult =cos(convertDegreeToRadian(N * teta));
    float sinResult =sin(convertDegreeToRadian(N * teta));

    result.realNumber = R * cosResult;
    result.imaginaryNumber =  R * sinResult;

    return (result);
}

//Question 3: What we want to do next is write (𝑥 + 𝑗𝑦)𝑎𝑠 𝑅𝑒𝑗�
exponentialComplexNumber formatComplexNumber(int x, int y){
    exponentialComplexNumber result ;
    float R = sqrt(pow(x,2) + pow(y,2));
    double teta = convertRadianToDegree(atan((float) y/x));

    result.absoluteVal = R;
    result.imaginaryNumber = teta;

}

/*Question 4: Then we can write (𝑥 + 𝑗𝑦)𝑛 𝑎𝑠 𝑅𝑛𝑒𝑗𝑛𝜃 and go back to write the result as 𝑅𝑛𝑒𝑗𝑛𝜃 𝑎𝑠 (𝑅𝑛𝑐𝑜 𝑠(𝑛𝜃) + 𝑗𝑅𝑛𝑠𝑖𝑛(𝑛𝜃)) */
complexNumber newRaiseComplexNumber(int x, int y, int N){
    complexNumber result ;
    double teta = convertRadianToDegree(atan((float) y/x));
    float R = sqrt(pow(x,2) + pow(y,2));
    float realNumResult = pow(R, N) * cos(convertDegreeToRadian(N * teta));
    printf("val is: %.3f",realNumResult);
    float imaginaryNumResult = pow(R, N) * sin(convertDegreeToRadian(N * teta));

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




#endif // TEST_H
