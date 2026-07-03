#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

namespace Core
{
    class MultiLayer
    {
    private:
        std::vector<double> hidden_layer; 
        double output_node;

        std::vector<std::vector<double>> weights_input_to_hidden; 
        
        std::vector<double> weights_hidden_to_output;

        std::vector<double> bias_hidden;
        double bias_output;

        double learning_rate = 0.5;

        double sigma(double x);
        double derivative_sigma(double x);

    public:
        MultiLayer();
        ~MultiLayer();

        double predict(double x1, double x2);
        void train(double x1, double x2, double target);
    };
}
