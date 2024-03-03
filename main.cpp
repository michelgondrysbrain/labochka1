#include <iostream> 
#include <random> 
#include <chrono> 
#include <fstream> 

int linearSearch(int* data, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (data[i] == key) return i;
    }
    return 0;
}

int binarySearch(int* data, int size, int key) {
    int left = 0;
    int right = size - 1;
    int mid;

    while ((left <= right)) {
        mid = (left + right) / 2;

        if (data[mid] == key)
            return 1;
        if (data[mid] > key)
            right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int straightSumOfTwo(int* data, int size, int key) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j != i) {
                if (data[i] + data[j] == key) return 1;
            }
        }
    }
    return 0;
}

int fastSumOfTwo(int* data, int size, int key) {
    int left = 0;
    int right = size;
    while (left != right) {
        int currentSum = data[left] + data[right];
        if (currentSum < key) {
            ++left;
        }
        else if (currentSum > key) {
            --right;
        }
        else {
            return 1;
        }
    }
    return 0;
}

void swapElementsA(int* data, int i) {
    if (i != 0) std::swap(data[0], data[i]);
}

void swapElementsB(int* data, int i) {
    if (i != 0) std::swap(data[i - 1], data[i]);
}

void swapElementsC(int* data, int i, int* elemCheck) {
    if (i != 0) {
        ++elemCheck[i];
        if (elemCheck[i - 1] < elemCheck[i]) {
            std::swap(data[i - 1], data[i]);
            std::swap(elemCheck[i - 1], elemCheck[i]);
        }
    }
}

static int dataArray[1000000] = {};
static int elemCheckArray[1000000] = {};

int main() {
    std::ofstream dataFile;
    std::ofstream timeFile;
    dataFile.open("n_data.txt");
    timeFile.open("time_data.txt");
    int counter = 100;
    unsigned seed = 1001;
    std::default_random_engine rng(seed);
    while (true) {
        counter += 10;
        if (counter > 1000000) { break; }
        std::normal_distribution <> distribution(0, counter / 30);
        for (int i = 0; i < counter; ++i) {
            dataArray[i] = abs(static_cast<int>(distribution(rng)));
        }
        for (int i = 0; i < (counter / 100); ++i) {
            swapElementsA(dataArray, linearSearch(dataArray, counter, abs(static_cast<int>(distribution(rng)))));
        }

        auto startTime = std::chrono::steady_clock::now();
        for (int j = 10; j != 0; j--) {
            linearSearch(dataArray, counter, counter + 1);
        }
        auto endTime = std::chrono::steady_clock::now();
        auto timeSpan = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

        dataFile << counter << '\n';
        std::cout << counter << '\n';
        timeFile << timeSpan.count() << '\n';
    }
}

