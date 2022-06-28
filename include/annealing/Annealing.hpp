//
// Created by infinite on 27/06/22.
//

#ifndef ALGORITHMS_ANNEALING_HPP
#define ALGORITHMS_ANNEALING_HPP

#include "utils/Common.hpp"
#include <cmath>
namespace Annealing {
    using namespace Utils;
    template <class Solution>
    class Problem {
    protected:
        double coolingRate = 0.98;
        double initialTemperature = 1e4;
        double finalTemperature = 1e-8;
        double epsilon = 1e-8;
        int maxIterations = 1e1;

        Solution solution;

    public:
        void setInitialTemperature(double _initialTemperature) {
            this->initialTemperature = _initialTemperature;
        }
        void setFinalTemperature(double _finalTemperature) {
            this->finalTemperature = _finalTemperature;
        }
        void setCoolingRate(double _coolingRate) {
            this->coolingRate = _coolingRate;
        }
        void setMaxIterations(int _maxIterations) {
            this->maxIterations = _maxIterations;
        }
        void setEpsilon(double _epsilon) {
            this->epsilon = _epsilon;
        }

        bool isUpdate(double delta, double temperature) {
            if (delta > epsilon) {
                return true;
            } else {
                double probability = std::exp(delta / temperature);
                if (probability > 1) {
                    return true;
                } else {
                    double random = rand() / (double) RAND_MAX;
                    if (random < probability) {
                        return true;
                    }
                }
            }
            return false;
        }

    protected:
        virtual void initSolution() = 0;

        virtual void updateSolution(double temperature) = 0;

        virtual bool isGoal() const {
            return false;
        };

    public:

        Solution solve() {
            initSolution();
            double temperature = initialTemperature;
            while (temperature > finalTemperature) {
                for (int i = 0; i < maxIterations; i++) {
                    updateSolution(temperature);
                    if (isGoal()) {
                        return solution;
                    }
                }
                temperature *= coolingRate;
            }
            return solution;
        }
    };

}
#endif //ALGORITHMS_ANNEALING_HPP
