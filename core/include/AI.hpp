#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <random>

namespace Core
{
    struct Perceptron
    {
        std::vector<double> weights;
        double learning_rate = 0.1;

        Perceptron()
        {
            std::mt19937 gen(std::random_device{}());
            std::uniform_real_distribution<double> dist(-1.0, 1.0);
            weights.resize(3);
            for (int i = 0; i < 3; i++)
            {
                weights[i] = dist(gen);
            }
        }
    };
    class AI
    {
    private:
        Perceptron brain;

    public:
        double sigma(double x);
        double predict(double x1, double x2);
        void train(double x1, double x2, double target);
        double derivative_sigma(double x);
        AI();
        ~AI();
    };

}