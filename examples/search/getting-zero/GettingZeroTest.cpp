//
// Created by infinite on 28/06/22.
//

#include "GettingZero.h"
#include "gtest/gtest.h"
class GettingZeroTest : public testing::Test {
protected:
    void breadthFirstSearch() {
        int n = 4;
        std::vector<int> result{};
        std::vector<int> input{19, 32764, 10240, 49};
        GettingZero::GettingZero gettingZero{};
        gettingZero.breadthFirstSearch();
        for(int i = 0; i < n; i++) {
            result.push_back(gettingZero.getDepth(input[i]));
        }
        ASSERT_EQ(result, std::vector<int>({14, 4, 4, 15}));
    }
};
TEST_F(GettingZeroTest, breadthFirstSearch) {
    breadthFirstSearch();
}