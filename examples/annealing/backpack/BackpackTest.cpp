//
// Created by infinite on 28/06/22.
//
#include "Backpack.h"
#include "gtest/gtest.h"
class BackpackTest : public testing::Test {
    protected:
    void solveTest() {
        Backpack::Backpack backpack{20};
        backpack.addItem(10, 9);
        backpack.addItem(10, 8);
        backpack.addItem(11, 16);
        auto result = backpack.solve();
        ASSERT_EQ(result, std::vector<int>({1, 1, 0}));

    }
};

TEST_F(BackpackTest, solveTest) {
    solveTest();
}