#include <iostream>
#include <vector>

/*
 * Reverses the array in-place. 
 * Time: O(n)
 * Memory: O(1)
 */
template <typename T>
void reverse(std::vector<T> &arr)
{
    for (size_t i = 0; i < arr.size() / 2; i++)
    {
        size_t other_idx = arr.size() - i - 1;
        auto temp = arr[i];
        arr[i] = arr[other_idx];
        arr[other_idx] = temp;
    }
}

template <typename T>
void print_vector(const std::string &prefix, const std::vector<T> &arr)
{
    std::cout << prefix;
    for (T i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<int> arr1;
    for (int i = 0; i < 10; i++)
    {
        arr1.push_back(i);
    }
    print_vector("Arr1: ", arr1);
    reverse(arr1);
    print_vector("Arr1Reversed: ", arr1);
    return EXIT_SUCCESS;
}