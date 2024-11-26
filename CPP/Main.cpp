#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <cstdlib>   // For std::rand, std::srand
#include <ctime>     // For std::time

// Constants
const int MIN = 0;
const int MAX = 999;
const int ARRAY_SIZE = 250;

// Binary Search Function (Recursive)
int binarySearch(const std::vector<int>& userArray, int userNumber, int lowIndex, int highIndex) {
    if (lowIndex > highIndex) {
        // Base case: number not found
        return -1;
    }

    int middleIndex = (lowIndex + highIndex) / 2;

    if (userArray[middleIndex] == userNumber) {
        // Base case: number found
        return middleIndex;
    } else if (userArray[middleIndex] > userNumber) {
        // Recur on the left half
        return binarySearch(userArray, userNumber, lowIndex, middleIndex - 1);
    } else {
        // Recur on the right half
        return binarySearch(userArray, userNumber, middleIndex + 1, highIndex);
    }
}

// Main Program
int main() {
    std::cout << "Binary Search Program\n";

    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate random numbers
    std::vector<int> randomNumberArray(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        randomNumberArray[i] = std::rand() % MAX + 1;
    }

    // Sort the array
    std::sort(randomNumberArray.begin(), randomNumberArray.end());

    // Print the sorted array
    std::cout << "\nSorted list of numbers:\n";
    for (const int& num : randomNumberArray) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // Get user input
    int searchNumber;
    std::cout << "What number are you searching for in the array (integer between 0 and 999): ";
    std::cin >> searchNumber;

    // Validate user input
    if (searchNumber < MIN || searchNumber > MAX) {
        std::cerr << "ERROR: Invalid input. Number must be between 0 and 999.\n";
        return 1;
    }

    // Perform binary search
    int searchResult = binarySearch(randomNumberArray, searchNumber, 0, ARRAY_SIZE - 1);

    // Output the result
    if (searchResult != -1) {
        std::cout << "\nYour number is at index: " << searchResult << "\n";
    } else {
        std::cout << "\nYour number is not in the array.\n";
    }

    return 0;
}