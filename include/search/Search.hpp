/**
 * @brief: This is the header file for the problem base class.
 * @author: spanning-tree
 * @date: 2022-4-10
 */

#ifndef ALGORITHMS_SEARCH_HPP
#define ALGORITHMS_SEARCH_HPP

#include <iostream>
#include <functional>
#include "utils/Common.hpp"

namespace Search {
    using namespace Utils;

    template<class State, class Action, class Cost = int, class Hash = std::hash<State>>
    class Problem {
    protected:
        using CostFunction = std::function<Cost(const State &, const Action &, const State &)>;

        struct Node {
            State parent;
            State state;
            Cost cost;
            uint depth;
            Cost g;

            bool operator<(const Node &node) const {
                return cost > node.cost;
            }
        };

        virtual bool isGoal(const State &state) const = 0;

        virtual Vec<Action> getActions(const State &state) const = 0;

        virtual Cost g(const State &state, const Action &action) const {
            return 0;
        };

        virtual Cost h(const State &state) const {
            return 0;
        };

        virtual State transferState(const State &state, const Action &action) const = 0;

        virtual bool isValid(const State &state) const {
            return true;
        }

        void clear() {
            goalState = nullopt;
            HashMap<State, Node, Hash> emptyMap;
            std::swap(emptyMap, nodeMap);
        }

    protected:
        State startState;

        Option<State> goalState;

        HashMap<State, Node, Hash> nodeMap;

        /**
         * @brief a container for specific search algorithm
         * @tparam type 's' represents stack, 'q' represents queue, 'p' represents priority queue
         */
        template<char type>
        class Container {
        private:
            Stack<Node> stack;

            Queue<Node> queue;

            PriorityQueue<Node> priorityQueue;
        public:
            void push(const Node &node) {
                if (type == 's') {
                    stack.push(node);
                } else if (type == 'q') {
                    queue.push(node);
                } else if (type == 'p') {
                    priorityQueue.push(node);
                }
            }

            void pop() {
                if (type == 's') {
                    stack.pop();
                } else if (type == 'q') {
                    queue.pop();
                } else if (type == 'p') {
                    priorityQueue.pop();
                }
            }

            Node peek() {
                if (type == 's') {
                    return stack.top();
                } else if (type == 'q') {
                    return queue.front();
                } else if (type == 'p') {
                    return priorityQueue.top();
                }
            }

            bool empty() {
                if (type == 's') {
                    return stack.empty();
                } else if (type == 'q') {
                    return queue.empty();
                } else if (type == 'p') {
                    return priorityQueue.empty();
                }
            }
        };

    protected:
        template<char type>
        Option<State> baseSearch(Container<type> container, CostFunction f, CostFunction g) {
            clear();
            State state = startState;
            Node node{state, state, 0, 0, 0};
            container.push(node);
            do {
                if (container.empty()) {
                    return nullopt;
                }
                node = container.peek();
                container.pop();
                state = node.state;

                if (nodeMap.find(state) != nodeMap.end()) {
                    continue;
                }
                nodeMap.insert({state, node});

                if (!isValid(state)) {
                    continue;
                }
                if (isGoal(state)) {
                    goalState = state;
                    return goalState;
                }

                Vec<Action> actions = getActions(state);
                for (const Action &action: actions) {
                    State childState = transferState(state, action);
                    if (nodeMap.find(childState) == nodeMap.end()) {
                        Node childNode{state, childState, f(state, action, childState), node.depth + 1, g(state, action, childState)};
                        container.push(childNode);
                    }
                }
            } while (true);
        }

    public:
        void setStartState(const State &state) {
            startState = state;
        }

        Option<State> breadthFirstSearch() {
            Container<'q'> container;
            return baseSearch(
                    container,
                    [](const State &state, const Action &action, const State &childState) {
                        return 0;
                    },
                    [](const State &state, const Action &action, const State &childState) {
                        return 0;
                    }
            );
        }

        Option<State> depthFirstSearch() {
            Container<'s'> container;
            return baseSearch(
                    container,
                    [](const State &state, const Action &action, const State &childState) {
                        return 0;
                    },
                    [](const State &state, const Action &action, const State &childState) {
                        return 0;
                    }
            );
        }

        Option<State> uniformCostSearch() {
            Container<'p'> container;
            return baseSearch(
                    container,
                    [this](const State &state, const Action &action, const State &childState) {
                        return this->g(state, action);
                    },
                    [this](const State &state, const Action &action, const State &childState) {
                        return this->g(state, action);
                    }
            );
        }

        Option<State> greedySearch() {
            Container<'p'> container;
            return baseSearch(
                    container,
                    [this](const State &state, const Action &action, const State &childState) {
                        return this->h(childState);
                    },
                    [](const State &state, const Action &action, const State &childState) {
                        return 0;
                    }
            );
        };

        Option<State> aStarSearch() {
            Container<'p'> container;
            return baseSearch(
                    container,
                    [this](const State &state, const Action &action, const State &childState) {
                        return this->g(state, action) + this->h(childState);
                    },
                    [this](const State &state, const Action &action, const State &childState) {
                        return this->g(state, action);
                    }
            );
        }

        virtual void printPath() const {
            if (!goalState) {
                std::cout << "Cannot access goal state" << std::endl;
                return;
            }
            std::cout << "Not implemented" << std::endl;
        }
    };

};

#endif //ALGORITHMS_SEARCH_HPP
