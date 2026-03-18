//#pragma once
#ifndef HEAD6_H
#define HEAD6_H

#include <vector>

// ADDED: объявление новой версии рюкзака
int backpack(int capacity,
    const std::vector<int>& weights,
    const std::vector<int>& values,
    std::vector<int>& chosen_indices,
    int& total_weight);

// ADDED: безопасный ввод числа
bool safe_input_int(int& value);

// ADDED: сортировка (оставлена, хотя не используется)
void insert_sort(std::vector<int>& w, std::vector<int>& p);

#endif
