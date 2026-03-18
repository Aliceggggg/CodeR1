#include "Head6.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>

/*Добавлено чтение данных из файла  
– раньше данные вводились вручную через std::cin  
– теперь читаются из artifacts.txt (N, Z, веса, ценности)

Удалён ручной ввод артефактов  
– старый ввод веса/ценности каждого предмета закомментирован
– заменён на чтение из файла (требование задачи)

Добавлена новая версия функции backpack  
– старая версия возвращала только максимальную ценность
– новая восстанавливает выбранные предметы
– считает суммарный вес
– возвращает индексы выбранных артефактов

Добавлен вывод результата согласно условию  
– номера выбранных артефактов
– суммарный вес
– суммарная ценность

Добавлена функция безопасного ввода safe_input_int  
– чтобы программа не ломалась при вводе мусора
– старый ввод оставлен закомментированным

Удалена сортировка артефактов  
– сортировка ломала исходные индексы
– теперь предметы остаются в исходном порядке (как требует задача)

Исправлены стилистические нарушения Google Style  
– добавлены std::  
– имена переменных приведены к lower_case_with_underscores
– функции — к lower_case_with_underscores
– большие блоки кода оформлены через ADDED START / END*/

int main() {
    setlocale(LC_ALL, "Russian");
    //SetConsoleOutputCP(1251);
    //SetConsoleCP(1251);

    int n, capacity;

    // FIX_ME: по условию данные должны считываться из файла
    /*
    std::cin >> W;
    std::cin >> n;
    ...
    */

    // ADDED START: чтение данных из файла
    std::ifstream input("artifacts.txt");
    if (!input.is_open()) {
        std::cout << "Не удалось открыть файл artifacts.txt\n";
        return 1;
    }

    input >> n >> capacity;

    if (n <= 0 || capacity <= 0) {
        std::cout << "Некорректные данные в файле.\n";
        return 1;
    }

    std::vector<int> weights(n);
    std::vector<int> values(n);

    for (int i = 0; i < n; ++i) input >> weights[i];
    for (int i = 0; i < n; ++i) input >> values[i];

    input.close();
    // ADDED END

    // FIX_ME: сортировка ломает индексы
    //insert_sort(weights, values);

    // ADDED: вызов новой версии рюкзака
    std::vector<int> chosen_indices;
    int total_weight = 0;
    int max_value = backpack(capacity, weights, values, chosen_indices, total_weight);

    std::cout << "Максимальная ценность: " << max_value << "\n";

    std::cout << "Выбранные артефакты: ";
    for (int idx : chosen_indices) std::cout << idx << " ";
    std::cout << "\n";

    std::cout << "Суммарный вес: " << total_weight << "\n";
    std::cout << "Суммарная ценность: " << max_value << "\n";

    return 0;
}
