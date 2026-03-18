#include "Head6.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>

/*Археолог нашел N артефактов.Известны веса(сi) и ценности(di) артефактов.Нужно
выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил Z кг, а их
общая ценность оказалась максимальной.Известно, что решение единственно.Укажите поряд
ковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, в
первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - ценность
находок.Вывести так же суммарный вес и общую ценность результата.*/

// FIX_ME: имя функции должно быть lower_case_with_underscores
//void insert_sort(std::vector<int>& w, std::vector<int>& p) {
void insert_sort(std::vector<int>& w, std::vector<int>& p) {
    for (int i = 1; i < static_cast<int>(w.size()); i++) {
        int temp = i;
        while (temp - 1 >= 0 && w[temp] < w[temp - 1]) {
            std::swap(w[temp], w[temp - 1]);
            std::swap(p[temp], p[temp - 1]);
            temp--;
        }
    }
}

// FIX_ME: старая версия не восстанавливала решение
/*
int backpack(int W, std::vector<int>& wt, std::vector<int>& val, int n) {
    ...
}
*/

// ADDED START: новая версия рюкзака с восстановлением решения
int backpack(int capacity,
    const std::vector<int>& weights,
    const std::vector<int>& values,
    std::vector<int>& chosen_indices,
    int& total_weight) {

    int n = static_cast<int>(weights.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = capacity;
    total_weight = 0;
    chosen_indices.clear();

    // ADDED: восстановление решения
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            chosen_indices.push_back(i);
            total_weight += weights[i - 1];
            w -= weights[i - 1];
        }
    }

    std::reverse(chosen_indices.begin(), chosen_indices.end());
    return dp[n][capacity];
}
// ADDED END

// ADDED: безопасный ввод числа
bool safe_input_int(int& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}
