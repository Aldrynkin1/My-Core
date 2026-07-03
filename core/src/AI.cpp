#include "../include/AI.hpp"
#include "../include/Logger.hpp"
#include "../include/FileLogger.hpp"

namespace Core
{
    Logger logger;
    std::string workpath = std::string(__FILE__).substr(0, std::string(__FILE__).find_last_of("/\\"));
    Core::FileLogger filelogger(workpath + "/Ai_logs/Ai.log");
    AI::AI() : brain()
    {

        logger.log("Ai create", Core::LogLevel::Level::INFO);
        filelogger.WriteLogToFile(Core::LogLevel::Level::INFO, "Ai create");
    }
    AI::~AI()
    {
    }

    double AI::sigma(double x)
    {
        double result = 1.0 / (1.0 + std::exp(-x));

        return result;
    }

    double AI::derivative_sigma(double x)
    {
        double result = x * (1.0 - x);
        return result;
    }

    double AI::predict(double x1, double x2)
    {
        double w1 = brain.weights[0];
        double w2 = brain.weights[1];
        double w3 = brain.weights[2];

        double sum = (x1 * w1) + (x2 * w2) + (1.0 * w3);

        double output = sigma(sum);

        return output;
    }

    void AI::train(double x1, double x2, double target)
    {
        double output = predict(x1, x2);
        double error = target - output;
        double delta = error * derivative_sigma(output);
        brain.weights[0] = brain.weights[0] + (brain.learning_rate * delta * x1);
        brain.weights[1] = brain.weights[1] + (brain.learning_rate * delta * x2);
        brain.weights[2] = brain.weights[2] + (brain.learning_rate * delta * 1.0);
    }
}
