#include <iostream>
#include <cmath>

double function(double x_1, double x_2){
//    Counts value of a function in a given coordinate
    double s_1, s_2;
    int m = 5;
    for (int i = 1; i <= m; i++){
        s_1 += i * cos( (i + 1) * x_1 + 1 );
        s_2 += i * cos( (i + 1) * x_2 + 1 );
    }
    return -s_1 * s_2;
}

//double function(double x_1, double y_1) {
////     sample of a function
//    return ( x_1 * x_1 * y_1 ) / (x_1 * x_1 * x_1 * x_1 + y_1 * y_1 );
//}

double integral(double x_1, double x_2, double y_1, double y_2, double step){
//    Integral calculation using Trapezoidal rule
    double result = 0;

    for (x_2; x_2 >= x_1; x_2 -= step){

        for (double j = y_2; j >= y_1; j -= step){
            result += function(x_2, j);
        }
    }
    return result * pow(step, 2);
}


int main() {
    double step = (double) 1/100;

    std:: cout << integral(-50, -2, 2, 100, step);
    return 0;
}
