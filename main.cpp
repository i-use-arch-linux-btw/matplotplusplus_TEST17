#include <cmath>
#include <matplot/matplot.h>
#include <thread>
#include "csv-parser/single_include/csv.hpp"
#include <chrono>
#include <iostream>
#include <vector>

int main() {
    using namespace matplot;
    using namespace csv;

    auto start = std::chrono::high_resolution_clock::now();

    CSVReader reader("/home/ap/CLionProjects/matplotplusplus-TEST17/csvs/2021.10.23EOSUSDT-M1-NoSession.csv");

    std::vector<float> x;
    std::vector<double> y;
    long counter = 0;

    int miniCounter = 0;
    float miniSum = 0;
    int numberOf1mBars = 1;

    double max = 0;
    double min = 9999999999999999;

    for (CSVRow& row: reader) {

        float close = row["Close"].get<float>();
        miniSum += close;

        if(close>max)
            max = close;
        if(close<min)
            min = close;

        if(++miniCounter == numberOf1mBars)
        {
            x.push_back(++counter);
            y.push_back(miniSum/numberOf1mBars);

            miniSum = 0, miniCounter = 0;
        }


    }

    std::cout<<"calculated"<<std::endl;

    plot( x, y);
    ylim({min*0.8, max*1.2});
    xlim({0, (double) counter});
    xlabel("x");
    ylabel("Close");

    auto finish = std::chrono::high_resolution_clock::now();

    auto nanoseconds =(finish-start).count();

    std::cout<<"\n\n"<<nanoseconds/1000000<< std::endl;

    show();

    /*

    auto t = iota(0, pi / 500, 40 * pi);
    auto xt =
            transform(t, [](auto t) { return (3. + cos(sqrt(32.) * t)) * cos(t); });
    auto yt = transform(t, [](auto t) { return sin(sqrt(32.) * t); });
    auto zt =
            transform(t, [](auto t) { return (3. + cos(sqrt(32.) * t)) * sin(t); });
    plot3(xt, yt, zt);
    axis(equal);
    xlabel("x(t)");
    ylabel("y(t)");
    zlabel("z(t)");

    auto ax = gca();
    float da = ax->azimuth();
    for (size_t i = 0; i <= 360; ++i) {
        ax->azimuth(da + 2 * i);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    show();
*/
    return 0;
}