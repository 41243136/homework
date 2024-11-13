#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
int binary_search(T arr[], int size, T target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int test_cases;
    std::cin >> test_cases;

    int results[1000]; // 假設最多有1000個查詢
    int result_index = 0;

    for (int t = 0; t < test_cases; ++t) {
        char T;
        int n, q;
        std::cin >> T >> n >> q;

        if (T == 'i') {
            int arr[30];
            for (int i = 0; i < n; ++i) {
                std::cin >> arr[i];
            }

            for (int i = 0; i < q; ++i) {
                int target;
                std::cin >> target;
                results[result_index++] = binary_search(arr, n, target);
            }
        }
        else if (T == 's') {
            std::string arr[30];
            for (int i = 0; i < n; ++i) {
                std::cin >> arr[i];
            }

            for (int i = 0; i < q; ++i) {
                std::string target;
                std::cin >> target;
                results[result_index++] = binary_search(arr, n, target);
            }
        }
    }

    for (int i = 0; i < result_index; ++i) {
        std::cout << results[i] << std::endl;
    }

    return 0;
}