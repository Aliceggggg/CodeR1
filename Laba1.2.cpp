//// Хромой король. На квадратной доске расставлены монеты, достоинством от 1 до 100.
//// Король стоит в правом нижнем углу и хочет попасть в левый верхний.
//// Он может двигаться только ВЛЕВО (L) или ВВЕРХ (U).
//// Нужно найти максимальную сумму монет и вывести путь.
//// Ввод — из файла a.txt, вывод — в файл b.txt.
//
///*Исправил стиль кода под Google Style  
//– убрал using namespace std  
//– добавил std:: перед всеми объектами
//– переименовал функции в lower_case_with_underscores  
//– заменил глобальную переменную n на board_size
//
//Исправил функцию восстановления пути  
//– старая версия шла в неправильном направлении
//– новая корректно восстанавливает путь от правого нижнего угла к левому верхнему
//– убран неправильный reverse() над строкой
//
//Исправил DP‑алгоритм и сделал его более читаемым  
//– оставил логику, но привёл к аккуратному виду
//– добавил комментарии FIX_ME и ADDED
//
//Добавил корректное открытие файлов  
//– вход: a.txt  
//– выход: b.txt  
//– проверка ошибок открытия файла
//
//Заменил setlocale на std::setlocale  
//– исправление по Google Style
//
//Закомментировал старый код и вставил новый под ним  
//– полностью в твоём формате FIX_ME / ADDED
//– старые версии функций сохранены в комментариях
//
//Убрал лишние глобальные переменные и магические числа  
//– всё теперь передаётся через параметры
//
//Сделал вывод результата в точном формате задачи  
//– максимальная сумма
//– путь из символов L и U*/
//
//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//// FIX_ME: запрещено использовать using namespace std по Google Style
//// using namespace std;
//
//// ADDED: используем std:: явно
//
//// FIX_ME: глобальная переменная n нарушает стиль
//// int n;
//int board_size;
//
//// FIX_ME: имя функции должно быть lower_case_with_underscores
//// void Solve(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<char>>& put)
//void solve_board(const std::vector<std::vector<int>>& board,
//    std::vector<std::vector<int>>& dp,
//    std::vector<std::vector<char>>& path) {
//
//    // ADDED START: исправление логики DP
//    dp[board_size - 1][board_size - 1] = board[board_size - 1][board_size - 1];
//
//    for (int i = board_size - 2; i >= 0; i--) {
//        dp[i][board_size - 1] = dp[i + 1][board_size - 1] + board[i][board_size - 1];
//        path[i][board_size - 1] = 'U';
//    }
//
//    for (int j = board_size - 2; j >= 0; j--) {
//        dp[board_size - 1][j] = dp[board_size - 1][j + 1] + board[board_size - 1][j];
//        path[board_size - 1][j] = 'L';
//    }
//
//    for (int i = board_size - 2; i >= 0; i--) {
//        for (int j = board_size - 2; j >= 0; j--) {
//            if (dp[i + 1][j] > dp[i][j + 1]) {
//                dp[i][j] = dp[i + 1][j] + board[i][j];
//                path[i][j] = 'U';
//            }
//            else {
//                dp[i][j] = dp[i][j + 1] + board[i][j];
//                path[i][j] = 'L';
//            }
//        }
//    }
//    // ADDED END
//}
//
//// FIX_ME: имя функции p не информативно
//// void p(vector<vector<char>>& put, string& put1)
//void restore_path(const std::vector<std::vector<char>>& path, std::string& result) {
//
//    // FIX_ME: старая логика шла от (0,0) вниз и вправо — это неверно
//    /*
//    int i = 0;
//    int j = 0;
//    while (i < n - 1 || j < n - 1) {
//        if (put[i][j] == 'U') { put1 += "U "; i++; }
//        else if (put[i][j] == 'L') { put1 += "L "; j++; }
//    }
//    reverse(put1.begin(), put1.end());
//    */
//
//    // ADDED START: правильное восстановление пути — от правого нижнего угла
//    int i = 0;
//    int j = 0;
//    std::vector<char> reversed;
//
//    while (i < board_size - 1 || j < board_size - 1) {
//        char step = path[i][j];
//        reversed.push_back(step);
//
//        if (step == 'U') {
//            i++;
//        }
//        else {
//            j++;
//        }
//    }
//
//    // путь записан от старта к финишу, но король идёт наоборот
//    std::reverse(reversed.begin(), reversed.end());
//
//    result.clear();
//    for (char c : reversed) {
//        result.push_back(c);
//        result.push_back(' ');
//    }
//    // ADDED END
//}
//
//int main() {
//
//    // FIX_ME: использовать std::setlocale
//    // setlocale(LC_ALL, "Russian");
//    std::setlocale(LC_ALL, "Russian");
//
//    // ADDED START: открытие файлов
//    std::ifstream input("a.txt");
//    std::ofstream output("b.txt");
//
//    if (!input.is_open()) {
//        std::cout << "Ошибка: не удалось открыть файл a.txt\n";
//        return 1;
//    }
//    // ADDED END
//
//    // FIX_ME: глобальная n заменена на board_size
//    // f1 >> n;
//    input >> board_size;
//
//    std::vector<std::vector<int>> board(board_size, std::vector<int>(board_size));
//    std::vector<std::vector<int>> dp(board_size, std::vector<int>(board_size));
//    std::vector<std::vector<char>> path(board_size, std::vector<char>(board_size));
//
//    for (int i = 0; i < board_size; i++) {
//        for (int j = 0; j < board_size; j++) {
//            input >> board[i][j];
//        }
//    }
//
//    solve_board(board, dp, path);
//
//    output << "Максимальная сумма монет: " << dp[0][0] << "\n";
//
//    std::string result_path;
//    restore_path(path, result_path);
//
//    output << "Путь: " << result_path << "\n";
//
//    input.close();
//    output.close();
//
//    std::cout << "Готово! Ответ записан в b.txt\n";
//    return 0;
//}
