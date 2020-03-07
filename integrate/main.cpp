#include <iostream>
#include <cmath>
#include <fstream>
//#include <thread>
#include <chrono>
#include <cassert>
#include <filesystem>
#include <atomic>
#include <tuple>

// g++ -O3 -o main main.cpp

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Time count

inline std::chrono::steady_clock::time_point get_current_time_fenced() {
    assert(std::chrono::steady_clock::is_steady &&
                   "Timer should be steady (monotonic).");
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::steady_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Function to be integrated

double functionUs(double x_1, double x_2, int m){
//    Counts value of our function in a given coordinate
    double s_1 = 0;
    double s_2 = 0;

    for (int i = 1; i <= m; i++){
        s_1 += i * cos( (i + 1) * x_1 + 1 );
        s_2 += i * cos( (i + 1) * x_2 + 1 );
    }
    return - s_1 * s_2;
}



double function(double x, double y, int m) {
    //     sample of a function
    double a = 20, b = 0.2, c = 2 * M_PI;
    double res = -a * exp(-b * sqrt(0.5 * (x * x + y * y)))
                 - exp(0.5 * (cos(c * x) + cos(c * y))) + a + exp(1);
    return res;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Integral

double integral(double x_1, double x_2, double y_1, double y_2, int steps, int m){
    double result = 0;
    double step_x = ( x_2 - x_1 ) / steps;
    double step_y = ( y_2 - y_1 ) / steps;

    for (x_2; x_2 >= x_1; x_2 -= step_x){
        for (double j = y_2; j >= y_1; j -= step_y){
            result += function(x_2, j, m);
        }
    }
    return result * step_y * step_x;
}

double parallelIntegral(double x_1, double x_2, double y_1, double y_2, int steps, int threadN, int m) {
    //todo
    return 1.2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Config and validate

bool validation(std::tuple<double, int, double, double, double, double, int, int> confs) {
    return (std::get<2>(confs) < std::get<3>(confs)) &&
    (std::get<4>(confs) < std::get<5>(confs)) &&
    (std::get<6>(confs) > 0) && (std::get<7>(confs) > 0) &&
    (std::get<0>(confs) != NULL);
}

std::tuple<double, int, double, double, double, double, int, int> configure(std::string filename) {
    std::ifstream conf(filename);
    std::string line;

    double err = NULL;
    int m = NULL;
    double x1 = NULL, x2 = NULL, y1 = NULL, y2 = NULL;
    int threads = NULL;
    int partition = NULL;

    if (conf.is_open()) {
        getline(conf, line);
        err = std::stod(line);

        getline(conf, line);
        m = std::stoi(line);

        getline(conf, line);
        x1 = std::stod(line);

        getline(conf, line);
        x2 = std::stod(line);

        getline(conf, line);
        y1 = std::stod(line);

        getline(conf, line);
        y2 = std::stod(line);

        getline(conf, line);
        threads = std::stoi(line);

        getline(conf, line);
        partition = std::stoi(line);
    }
    return std::tuple<double, int, double, double, double, double, int, int>{err, m , x1, x2, y1, y2, threads, partition};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Parallel and non-parallel programs

//NON-PARALLEL INTEGRAL
double integrateSeq(double err, int m, double x_1, double x_2, double y_1, double y_2, int cur_partition){
//    Function to find and return amount of squares for accurate integral result;
//    Default accuracy = 0.1 %
    double value_1, value_2, relevant_error;

    value_1 = integral(x_1, x_2, y_1, y_2, cur_partition, m);

    do {
        value_2 = integral(x_1, x_2, y_1, y_2, cur_partition * 2, m);
        cur_partition *= 2;
        relevant_error = (value_1 - value_2) / value_1;

        value_1 = value_2;

        //std::cout << "Val " << value_1 << " \t";
        //std::cout << "Err " << std::abs(relevant_error) << " \t";
        //std::cout << "Partition " << cur_partition << "\n";

    }while (std::abs(relevant_error) > err);
    return value_1;
}

//PARALLEL INTEGRAL
double integratePar(double err, int m, double x_1, double x_2, double y_1, double y_2, int threadN, int cur_partition) {
    //todo
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Main

int main(int argc, char *argv[]) {

    //CHECK IF VALID CMD ARGS
    auto check = (std::filesystem::exists(std::filesystem::path(argv[1])));
    if (argc != 2 || !check) {
        std::cout << "ARG ERROR --> " << argc << " ---> " << argv[1] << " ---> " << check << "\n";
        return 1;
    }

    //CONFIGURE AND VALIDATE
    std::string conffile(argv[1]);
    auto confs = configure(conffile);
    bool valid = validation(confs);
    if (!valid) {
        std::cout << "VALIDATION ERROR ---> " << valid << "\n";
        return 1;
    }

    std::cout << std::get<0>(confs) << "\n";
    std::cout << std::get<1>(confs) << "\n";
    std::cout << std::get<2>(confs) << "\n";
    std::cout << std::get<3>(confs) << "\n";
    std::cout << std::get<4>(confs) << "\n";
    std::cout << std::get<5>(confs) << "\n";
    std::cout << std::get<6>(confs) << "\n";
    std::cout << std::get<7>(confs) << "\n\n";

    //RUN NON-PARALLEL
    if (std::get<6>(confs) == 1) {
        auto start = get_current_time_fenced();
        double res = integrateSeq(std::get<0>(confs), std::get<1>(confs),
                                  std::get<2>(confs), std::get<3>(confs), std::get<4>(confs),
                                  std::get<5>(confs), std::get<7>(confs));
        auto end = get_current_time_fenced();
        auto diff = end - start;

        std::cout << "Result = " << res << "\n";
        //todo
        std::cout << "Absolute and relative errors = " << "TODO\n";
        std::cout << "Time = " << to_us(diff) << " us\n";
    }

    //RUN PARALLEL
    else {
        auto start = get_current_time_fenced();
        double res = integratePar(std::get<0>(confs), std::get<1>(confs),
                                  std::get<2>(confs), std::get<3>(confs), std::get<4>(confs),
                                  std::get<5>(confs), std::get<6>(confs), std::get<7>(confs));
        auto end = get_current_time_fenced();
        auto diff = end - start;

        std::cout << "Result = " << res << "\n";
        //todo
        std::cout << "Absolute and relative errors = " << "TODO!!!!\n";
        std::cout << "Time = " << to_us(diff) << " us\n";
    }
    return 0;
}
