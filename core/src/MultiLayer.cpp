#include "../include/MultiLayer.hpp"

namespace Core
{
    MultiLayer::MultiLayer()
    {
        hidden_layer.resize(3);
        bias_hidden.resize(3);
        weights_hidden_to_output.resize(3);

        weights_input_to_hidden.resize(2);
        for (int i = 0; i < 2; i++)
        {
            weights_input_to_hidden[i].resize(3);
        }
        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<double> dist(-1.0, 1.0);

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                weights_input_to_hidden[i][j] = dist(gen);
            }
        }

        for (int j = 0; j < 3; j++)
        {
            weights_hidden_to_output[j] = dist(gen);
            bias_hidden[j] = dist(gen);
        }
        bias_output = dist(gen);
    }
    double MultiLayer::sigma(double x)
    {
        double result = 1.0 / (1.0 + std::exp(-x));

        return result;
    }

    double MultiLayer::derivative_sigma(double x)
    {
        double result = x * (1.0 - x);
        return result;
    }

    double MultiLayer::predict(double x1, double x2)
    {
        for (int j = 0; j < 3; j++)
        {
            double sum_hidden = (x1 * weights_input_to_hidden[0][j]) +
                                (x2 * weights_input_to_hidden[1][j]) +
                                bias_hidden[j];
            hidden_layer[j] = sigma(sum_hidden);
        }
        double sum_out = (hidden_layer[0] * weights_hidden_to_output[0]) +
                         (hidden_layer[1] * weights_hidden_to_output[1]) +
                         (hidden_layer[2] * weights_hidden_to_output[2]) +
                         bias_output;
        output_node = sigma(sum_out);
        return output_node;
    }

    void MultiLayer::train(double x1, double x2, double target)
    {
        predict(x1, x2);
        double error_out = target - output_node;
        double delta_out = error_out * derivative_sigma(output_node);
        std::vector<double> hide_delta(3);
        for (int i = 0; i < 3; i++)
        {
            double hide_error = delta_out * weights_hidden_to_output[i];
            hide_delta[i] = hide_error * derivative_sigma(hidden_layer[i]);
            weights_hidden_to_output[i] += learning_rate * delta_out * hidden_layer[i];
        }
        bias_output += learning_rate * delta_out * 1.0;

        for (int i = 0; i < 3; i++)
        {
            weights_input_to_hidden[0][i] += learning_rate * hide_delta[i] * x1;
            weights_input_to_hidden[1][i] += learning_rate * hide_delta[i] * x2;
            bias_hidden[i] += learning_rate * hide_delta[i] * 1.0;
        }
    }

    MultiLayer::~MultiLayer()
    {
    }
}
