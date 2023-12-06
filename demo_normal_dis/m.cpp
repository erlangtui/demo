#include <iostream>
#include <boost/math/distributions/normal.hpp>

using namespace boost::math;

int main() {
    double p = 0.8;     // 目标概率
    double mu = 0.0;    // 均值
    double sigma = 1.0; // 标准差

    normal_distribution<> dist(mu, sigma);
    double x = quantile(dist, p);

    std::cout << "分位点为 " << p << " 的随机变量为 " << x << std::endl;

    return 0;
}

