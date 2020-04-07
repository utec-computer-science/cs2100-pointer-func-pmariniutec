#include <iostream>

void* bubbleSort(void* data, void (*functor)(void*, std::size_t, std::size_t), std::size_t size) {
  for (std::size_t i = 0; i < size - 1; ++i)
	for (std::size_t j = 0; j < size - i - 1; ++j)
	  functor(data, j, j + 1);
  return data;
}

void bubbleSortInt(void* data, std::size_t i, std::size_t j) {
  auto arr = static_cast<int*>(data);
  if (arr[i] > arr[j]) {
	std::swap(arr[i], arr[j]);
  }
}

void bubbleSortFloat(void* data, std::size_t i, std::size_t j) {
  auto arr = static_cast<float*>(data);
  if (arr[i] > arr[j]) {
	std::swap(arr[i], arr[j]);
  }
}

void bubbleSortDouble(void* data, std::size_t i, std::size_t j) {
  auto arr = static_cast<double*>(data);
  if (arr[i] > arr[j]) {
	std::swap(arr[i], arr[j]);
  }
}

void bubleSortChar(void* data, std::size_t i, std::size_t j) {
  auto arr = static_cast<char*>(data);
  if (arr[i] > arr[j]) {
	std::swap(arr[i], arr[j]);
  }
}

template<typename T>
void printArr(T* arr, std::size_t size) {
  for (std::size_t i = 0; i < size; ++i) {
	std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

int main() {
  int vecInt[5] = { 2, 20, 7, 108, 9 };
  float vecFloat[5] = { 4.4F, 5.4F, 9.1F, 7.4F, 2.2F };
  double vecDouble[5] = { 3.0, 8.0, 2.0, 4.0, 15.0 };
  char vecChar[6] = { 'k', 'a', 'r', 'l', 'o', 's' };

  bubbleSort(static_cast<void*>(vecInt), bubbleSortInt, 5);
  printArr(vecInt, 5);

  bubbleSort(static_cast<void*>(vecFloat), bubbleSortFloat, 5);
  printArr(vecFloat, 5);

  bubbleSort(static_cast<void*>(vecDouble), bubbleSortDouble, 5);
  printArr(vecDouble, 5);

  bubbleSort(static_cast<void*>(vecChar), bubleSortChar, 6);
  printArr(vecChar, 5);

  return 0;
}
