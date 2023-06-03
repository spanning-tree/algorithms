//
// Created by infinite on 28/06/22.
//
#include "Knapsack.h"
#include "gtest/gtest.h"
class KnapsackTest : public testing::Test {
    protected:
    void solveTest() {
        Knapsack::Knapsack knapsack{20};
        knapsack.addItem(10, 9);
        knapsack.addItem(10, 8);
        knapsack.addItem(11, 16);
        auto result = knapsack.solve();
        ASSERT_EQ(result, std::vector<int>({1, 1, 0}));

    }
};

TEST_F(KnapsackTest, solveTest) {
    solveTest();
}