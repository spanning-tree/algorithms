//
// Created by infinite on 28/06/22.
//

#ifndef ALGORITHMS_BACKPACK_H
#define ALGORITHMS_BACKPACK_H
#include "annealing/Annealing.hpp"
#include "utils/Common.hpp"
#include <algorithm>
#include <iostream>

namespace Knapsack {
    using namespace Utils;
    using namespace Annealing;
    using Solution = Vec<int>;

    class Knapsack : public Problem<Solution> {
    protected:
        const int maxWeight;
        int totalWeight = 0;
        int totalValue = 0;

        struct Item {
            int weight;
            int value;
            Item(int _weight, int _value) : weight(_weight), value(_value) {}
        };
        Vec<Item> items;
    protected:

        double evaluate() const override {
            return totalValue;
        }

        void initSolution() override {
            int n = items.size();
            solution.resize(n);
            for (int i = 0; i < n; ++i) {
                solution[i] = 0;
            }
            totalValue = 0;
            totalWeight = 0;
        }

        void updateSolution(double temperature) override {

            int n = items.size();
            int index = rd() % n;
            int value = items[index].value;
            int weight = items[index].weight;
            if (solution[index] == 1) {
                if (isUpdate(double(-value), temperature)) {
                    solution[index] = 0;
                    totalValue -= value;
                    totalWeight -= weight;
                }
                return;
            }
            if (totalWeight + weight <= maxWeight) {
                solution[index] = 1;
                totalWeight += weight;
                totalValue += value;
            }

        }
    public:
        void addItem(int weight, int value) {
            items.emplace_back(weight, value);
        }

        void printResult() const {
            std::cout << totalValue << std::endl;
        }

        Knapsack(int _maxWeight) : maxWeight(_maxWeight) {}
    };
}

#endif //ALGORITHMS_BACKPACK_H
