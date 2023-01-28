/******************************************************************************
Samantha Sinnerine - CS211- Integration using typedef
*******************************************************************************/

#include <iostream>

using namespace std;
typedef double (*func)(double); //func is a pointer to a function that takes a double as input and returns a double

double square (double x){
    return x*x;  // y=x^2
}

double integrate(func f, double a, double b){
    
    double x = a;  
    double d = 0.0001; //width of each rectangle
    double area = 0;  //sum of rectangles under the curve
    
    while (x < b){
        area += f(x) * d;
        x = x + d;
    }
    
    return area;
}

int main()
{
    cout<<integrate(square, 2.0, 4.0);  //18.6661

    return 0;
}
