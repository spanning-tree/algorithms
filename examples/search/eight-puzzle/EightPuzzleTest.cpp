//
// Created by infinite on 28/06/22.
//

#include "EightPuzzle.h"
#include "gtest/gtest.h"

class EightPuzzleTest : public testing::Test {
    protected:
    void breadFirstSearchTest() {
        EightPuzzle::EightPuzzle eightPuzzle{
                {1, 2, 3, 4, 5, 6, 7, 8, 0},
                {0, 1, 2, 3, 4, 5, 6, 7, 8}
        };
        auto result = eightPuzzle.breadthFirstSearch();
        ASSERT_EQ(result.has_value(), true);
        ASSERT_EQ(result.value(), std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    }

    void depthFirstSearchTest() {
        EightPuzzle::EightPuzzle eightPuzzle{
                {1, 2, 3, 4, 5, 6, 7, 8, 0},
                {0, 1, 2, 3, 4, 5, 6, 7, 8}
        };
        auto result = eightPuzzle.depthFirstSearch();
        ASSERT_EQ(result.has_value(), true);
        ASSERT_EQ(result.value(), std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    }

    void greedySearchTest() {
        EightPuzzle::EightPuzzle eightPuzzle{
                {1, 2, 3, 4, 5, 6, 7, 8, 0},
                {0, 1, 2, 3, 4, 5, 6, 7, 8}
        };
        auto result = eightPuzzle.greedySearch();
        ASSERT_EQ(result.has_value(), true);
        ASSERT_EQ(result.value(), std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    }

    void uniformCostSearchTest() {
        EightPuzzle::EightPuzzle eightPuzzle{
                {1, 2, 3, 4, 5, 6, 7, 8, 0},
                {0, 1, 2, 3, 4, 5, 6, 7, 8}
        };
        auto result = eightPuzzle.uniformCostSearch();
        ASSERT_EQ(result.has_value(), true);
        ASSERT_EQ(result.value(), std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    }

    void aStarSearchTest() {
        EightPuzzle::EightPuzzle eightPuzzle{
                {1, 2, 3, 4, 5, 6, 7, 8, 0},
                {0, 1, 2, 3, 4, 5, 6, 7, 8}
        };
        auto result = eightPuzzle.aStarSearch();
        ASSERT_EQ(result.has_value(), true);
        ASSERT_EQ(result.value(), std::vector<int>({0, 1, 2, 3, 4, 5, 6, 7, 8}));
    }
};

TEST_F(EightPuzzleTest, breadFirstSearchTest) {
    breadFirstSearchTest();
}
TEST_F(EightPuzzleTest, depthFirstSearchTest) {
    depthFirstSearchTest();
}
TEST_F(EightPuzzleTest, greedySearchTest) {
    greedySearchTest();
}
TEST_F(EightPuzzleTest, uniformCostSearchTest) {
    uniformCostSearchTest();
}
TEST_F(EightPuzzleTest, aStarSearchTest) {
    aStarSearchTest();
}