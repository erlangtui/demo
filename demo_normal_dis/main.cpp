#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::default_random_engine engine(rd());

    double mu = 0.0;      // 均值
    double sigma = 1.0;   // 标准差

    std::normal_distribution<double> norm_dist(mu, sigma);
    std::uniform_real_distribution<double> uni_dist(0.0, 1.0);

    double target_probability = 0.8;   // 目标概率

    // 使用二分法来逼近目标概率对应的随机变量
    double lower = -std::numeric_limits<double>::max();
    double upper = std::numeric_limits<double>::max();
    double x;

    while (true) {
        x = norm_dist(engine);
        double cumulative_probability = 0.5 * (1 + std::erf((x - mu) / (sigma * std::sqrt(2))));

        if (cumulative_probability < target_probability) {
            lower = x;
        }
        else {
            upper = x;
        }
        
        if (target_probability - cumulative_probability <= 0.00001) {
            break;
        }
    }

    std::cout << "对应概率为 " << target_probability << " 的随机变量为 " << x << std::endl;

    return 0;
}

