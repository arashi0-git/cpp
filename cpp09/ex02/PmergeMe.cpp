#include "PmergeMe.hpp"

std::vector<int> generate_Jacobsthal_index(int n) {
    std::vector<int> index;
    index.push_back(1);
    index.push_back(3);
    for (int k = 2; k < n; k++) {
        index.push_back(index[k-1] + 2 * index[k - 2]);
        if (index[k-1] + 2 * index[k - 2] > n)
            break;
    }
    std::vector<bool> used(n, false);
    for (int i = 0; i < index.size(); ++i) {
        if (index[i] < n)
            used[index[i]] = true;
    }
    std::vector<int> result = index;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> Jacobsthal(std::vector<int> main, std::vector<int> pending) {
    std::vector<int> order = generate_Jacobsthal_index(pending.size());
    for (int i : order) {
        binaryInsert(main, pending[i]);
    }
}

std::vector<int> Pmerge_vec(std::vector<int> input) {
    std::vector<int> main;
    std::vector<int> pending;
    if (input.size() <= 1) {
        return input;
    }
    for (int i = 0; i < input.size(); i+=2) {
        main.push_back(max(input[i], input[i +1 ]));
        pending.push_back(min(input[i], input[i + 1]));
    }
    if (input.size() % 2 != 0)
        pending.push_back(input[input.size() - 1]);
    std::vector<int> sorted = Pmerge_vec(main);
    return Jacobsthal(sorted, pending); 
}