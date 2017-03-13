#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {
private:
  int _size, _capacity;
  T *_data;

public:
  Vector(): _size(0), _capacity(1), _data(new T[this->_capacity]) {}
  Vector(int inCapacity): _size(0), _capacity(inCapacity), _data(new T[this->_capacity]) {}

  int size() const {
    return this->_size;
  }

  int capacity() const {
    return this->_capacity;
  }

  bool empty() const {
    return this->_size == 0;
  }

  void clear() {
    delete[] this->_data;
    this->_data = NULL;
    this->_size = 0;
    this->_capacity = 0;
  }

  ~Vector() {
    delete[] this->_data;
  }

  void push_back(T);
  void push_front(T);
  void pop_back();
  void pop_front();
  void reverse();
  T& operator[](int) const;
};

/**
 * Time complexity: O(1) amortized
 * Space complexity: O(1) amortized
 */
template <typename T>
void Vector<T>::push_back(T val) {
  if (this->_size >= this->_capacity) {
    T *tmpData = new T[this->_capacity * 2];

    for (int i = 0; i < this->_size; ++i) {
      tmpData[i] = this->_data[i];
    }

    delete[] this->_data;
    this->_data = tmpData;

    this->_capacity *= 2;
  }

  this->_data[this->_size++] = val;
}

/**
 * Time complexity: O(n)
 * Space complexity: O(1) amortized
 */
template <typename T>
void Vector<T>::push_front(T val) {
  if (this->_size < this->_capacity) {

    int tmp = this->_data[0], tmp2;

    for (int i = 1; i < this->_size + 1; ++i) {
      tmp2 = this->_data[i];
      this->_data[i] = tmp;
      tmp = tmp2;
    }

  } else {
    T *tmpData = new T[this->_capacity * 2];

    for (int i = 0; i < this->_size; ++i) {
      tmpData[i + 1] = this->_data[i];
    }

    delete[] this->_data;
    this->_data = tmpData;
    this->_capacity *= 2;
  }

  this->_data[0] = val;
  this->_size++;
}

/**
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
template <typename T>
void Vector<T>::pop_back() {
  if (!this->empty()) this->_size--;
}

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
template <typename T>
void Vector<T>::pop_front() {
  if (!this->empty()) {
    for (int i = 1; i < this->_size; ++i) {
      this->_data[i - 1] = this->_data[i];
    }

    this->_size--;
  }
}

/**
 * Time complexity: O(n)
 * Space complexity O(1)
 */
template <typename T>
void Vector<T>::reverse() {
  T tmp;
  int i = 0, j = this->_size - 1;

  while (i < j) {
    tmp = this->_data[i];
    this->_data[i] = this->_data[j];
    this->_data[j] = tmp;
    ++i;
    --j;
  }
}

/**
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
template <typename T>
T& Vector<T>::operator[](int idx) const {
  if (idx >= 0 && idx < this->_size) return this->_data[idx];
  else throw std::logic_error("Access out of bounds " + std::to_string(idx));
}

#endif
