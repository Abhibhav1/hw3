#ifndef STACK_H
#define STACK_H
#include <vector>
#include <stdexcept>

// Use private inheritance from std::vector since Stack is not truly a vector
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack() = default; // Default constructor initializes an empty vector
    ~Stack() = default; // Default destructor cleans up automatically

    bool empty() const {
        return std::vector<T>::empty();
    }

    size_t size() const {
        return std::vector<T>::size();
    }

    void push(const T& item) {
        std::vector<T>::push_back(item);
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        std::vector<T>::pop_back();
    }

    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return std::vector<T>::back();
    }
};

#endif