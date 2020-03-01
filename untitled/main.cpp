#include <iostream>
#include <cmath>

double function(double x_1, double x_2){
//    Counts value of a function in a given coordinate
    double s_1, s_2;
    int m = 5;
    for (int i = 1; i <= m; i++){
        s_1 += i * cos( (i + 1)*x_1 + 1 );
        s_2 += i * cos( (i + 1)*x_2 + 1 );
    }
    return -s_1 * s_2;
}

double integral(double step, double x_1, double x_2, double y_1, double y_2){
//    counts integral for 2-dimensional function with given step and bounds
    if (x_1 >= x_2 || y_1 >= y_2 || step <= 0){
        std::cout << "Wrong input given";
        return 0;
    }

    double i_value = function(x_1, y_1);
    for (double x = x_1; x <= x_2; x += step){
        for (double y = y_1; y <= y_2; y += step){
            i_value += function(x, y);
        }
    }
    return i_value;

}

int main() {
    std::cout << integral(0.125, -100, 100, -100, 100);
    return 0;
}
