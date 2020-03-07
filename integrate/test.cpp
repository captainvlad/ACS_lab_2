#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>

using namespace std;


double function(double x, double y) {
   //     sample of a function
   double a = 20, b = 0.2, c = 2 * M_PI;
   return -a * exp(-b * sqrt(0.5 * (x * x + y * y))) - exp(0.5 * (cos(c * x) + cos(c * y))) + a + exp(1);
}

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

void integral_2(double x_1, double x_2, double y_1, double y_2, int steps, int threads, double &data){
//    Integral calculation using Trapezoidal rule
    data = integral(x_1, x_2, y_1, y_2, steps / threads);
}

int mult_icomputations(double x_1, double x_2, double y_1, double y_2, int steps, int thr){
    vector<thread> v;
    vector<double> results;
    double tot_res = 0;

    int delta_x = (x_2 - x_1) / thr;

    for(int i = 0; i < thr; ++i){
        results.push_back(0.0);
    }

    for(int i = 0; i < thr; ++i){
        v.push_back(thread{integral_2, x_1 + i * delta_x, x_1 + (i + 1) * delta_x, y_1, y_2, steps, thr, ref(results[i]) });
    }

    for(auto& t: v){
        t.join();
    }

    double r = 0;
    for (auto x: results){
        tot_res += x;
    }

    return tot_res;

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

    }while (std::abs(relevant_error) > 0.0001);
    return cur_partition;
}

int main() {
    cout << mult_icomputations(-100, 100 , -100, 100, ma(), 5 ) << endl;
    // cout << integral(-100, 100, -100, 100, ma()) << endl;
    return 0;
}