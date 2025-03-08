#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>
#include <functional>
#include <string>
#include <iostream>

// Functor for Min-Heap (default)
template <typename T>
struct MinComparator {
  bool operator()(const T& lhs, const T& rhs) const {
    return lhs < rhs;
  }
};

// Functor for Max-Heap
template <typename T>
struct MaxComparator {
  bool operator()(const T& lhs, const T& rhs) const {
    return lhs > rhs;
  }
};

// Functor for lexicographic string comparison
struct AlphaStrComp {
  bool operator()(const std::string& lhs, const std::string& rhs) const {
    return lhs < rhs;
  }
};

// Functor for comparing strings by length
struct LengthStrComp {
  bool operator()(const std::string& lhs, const std::string& rhs) const {
    return lhs.size() < rhs.size();
  }
};

// Function template for comparing strings with custom comparator
template <class Comparator>
void DoStringCompare(const std::string& s1, const std::string& s2, Comparator comp) {
    std::cout << comp(s1, s2) << std::endl;
}

template <typename T, typename PComparator = MinComparator<T> >
class Heap {
public:
  Heap(int m = 2, PComparator c = PComparator());
  ~Heap();
  void push(const T& item);
  T const & top() const;
  void pop();
  bool empty() const;
  size_t size() const;

private:
  std::vector<T> heap_;
  int m_;
  PComparator comp_;

  void heapifyUp(size_t index);
  void heapifyDown(size_t index);
};

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

// Push function
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  heap_.push_back(item);
  heapifyUp(heap_.size() - 1);
}

// Top function
template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const {
  if (empty()) {
    throw std::underflow_error("Heap is empty");
  }
  return heap_.front();
}

// Pop function
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() {
  if (empty()) {
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heap_.front(), heap_.back());
  heap_.pop_back();
  if (!heap_.empty()) {
    heapifyDown(0);
  }
}

// Empty function
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heap_.empty();
}

// Size function
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heap_.size();
}

// Heapify Up
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyUp(size_t index) {
  while (index > 0) {
    size_t parent = (index - 1) / m_;
    if (comp_(heap_[index], heap_[parent])) {
      std::swap(heap_[index], heap_[parent]);
      index = parent;
    } else {
      break;
    }
  }
}

// Heapify Down
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapifyDown(size_t index) {
  while (true) {
    size_t best = index;
    for (int i = 1; i <= m_; ++i) {
      size_t child = m_ * index + i;
      if (child < heap_.size() && comp_(heap_[child], heap_[best])) {
        best = child;
      }
    }
    if (best != index) {
      std::swap(heap_[index], heap_[best]);
      index = best;
    } else {
      break;
    }
  }
}

#endif
