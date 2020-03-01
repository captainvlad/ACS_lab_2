#include <iostream>
#include <cmath>

double function(double x_1, double x_2){
    double s_1, s_2;
    int m = 5;
    for (int i = 1; i <= m; i++){
        s_1 += i * cos( (i + 1)*x_1 + 1 );
        s_2 += i * cos( (i + 1)*x_2 + 1 );
    }
    return -1 * s_1 * s_2;
}

int main() {
    std::cout << function(1, 1) << std::endl;
    return 0;
}
