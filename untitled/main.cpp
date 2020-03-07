#include <iostream>
#include <cmath>

double function(double x_1, double x_2){
//    Counts value of a function in a given coordinate
    double s_1 = 0;
    double s_2 = 0;
    int m = 5;
    for (int i = 1; i <= m; i++){
        s_1 += i * cos( (i + 1) * x_1 + 1 );
        s_2 += i * cos( (i + 1) * x_2 + 1 );
    }
    return - s_1 * s_2;
}

//double function(double x, double y) {
//    //     sample of a function
//    double a = 20, b = 0.2, c = 2 * M_PI;
//    return -a * exp(-b * sqrt(0.5 * (x * x + y * y))) - exp(0.5 * (cos(c * x) + cos(c * y))) + a + exp(1);
//}

double integral(double x_1, double x_2, double y_1, double y_2, int steps){
//    Integral calculation using Trapezoidal rule
    double result = 0;
    double step = ( x_2 - x_1 ) * ( y_2 - y_1 ) / steps;

    for (x_2 ;x_2 >= x_1; x_2 -= step){

        for (double j = y_2; j >= y_1; j -= step){
            result += function(x_2, j);
        }
    }
    return result * pow(step, 2);
}

int ma(){
//    Function to find and return amount of squares for accurate integral result;
//    Default accuracy = 0.1 %
    int cur_partition = 1000;
    double value_1, value_2, relevant_error;

    value_1 = integral(-100, 100, -100, 100, cur_partition);
    do {
       value_2 = integral(-100, 100, -100, 100, cur_partition * 2);
       cur_partition *= 2;
       relevant_error = (value_1 - value_2) / value_1;
       value_1 = value_2;
       std::cout << "Rel error:" <<  std::abs(relevant_error) << "\n";
       std::cout << "Integral value: " << value_2 << "\n";
//       std::cout << cur_partition << "\n";
    }while (std::abs(relevant_error) > 0.001);
    return cur_partition;
}

int main() {
    ma();
    return 0;
}
