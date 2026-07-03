#include "../include/AI.hpp"
#include "../include/Logger.hpp"
#include "../include/MultiLayer.hpp"

struct Test_data_row
{
    double x1;
    double x2;
    double target;
};

void test_ai()
{
    Core::Logger logger;
    std::vector<Test_data_row> dataset = {
        {0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0},
        {1.0, 0.0, 1.0},
        {1.0, 1.0, 1.0}};
    Core::AI my_ai;
    for (int epoch = 0; epoch < 100000; epoch++)
    {
        for (const auto &row : dataset)
        {
            my_ai.train(row.x1, row.x2, row.target);
        }

        if (epoch % 10000 == 0)
        {
            for (const auto &row : dataset)
            {
                double res = my_ai.predict(row.x1, row.x2);
                std::string msg = std::to_string(row.x1) + " or " + std::to_string(row.x2) +
                                  " | Target: " + std::to_string(row.target) +
                                  " | Output: " + std::to_string(res);

                logger.log(msg, Core::LogLevel::Level::INFO);
            }
            std::cout << std::endl;
        }
    }
}

void test_multi_ai()
{
    std::vector<Test_data_row> dataset = {
        {0.0, 0.0, 0.0},
        {0.0, 1.0, 1.0},
        {1.0, 0.0, 1.0},
        {1.0, 1.0, 0.0},
    };
    Core::MultiLayer multi_ai;
    Core::Logger logger;
    for (int epoch = 0; epoch < 1000000; epoch++)
    {
        for (const auto &row : dataset)
        {
            multi_ai.train(row.x1, row.x2, row.target);
        }
        if (epoch % 100000 == 0)
        {
            for (const auto &row : dataset)
            {
                double res = multi_ai.predict(row.x1, row.x2);
                std::string msg = std::to_string(row.x1) + " or " + std::to_string(row.x2) +
                                  " | Target: " + std::to_string(row.target) +
                                  " | Output: " + std::to_string(res);

                logger.log(msg, Core::LogLevel::Level::INFO);
            }
            std::cout << std::endl;
        }
    }
}

