#include "header.hpp"

// Зачем здесь их писать ещё раз????????????
std::deque<Coord> curPath{};
std::vector<Path> findedPathes{};
Lab labyrinth{};
Coord startPosition{};
Coord finishPosition{};



void findPath(Coord curPos) {
    if (!checkCell(curPos)) {
        return;
    }
    if (isCellVisited(curPos)) {
        return;
    }
    // std::cout << "Check " << curPos << std::endl;
    curPath.push_back(curPos);

    if (curPos == finishPosition) {
        findedPathes.push_back({std::begin(curPath), std::end(curPath)});
    }

    findPath(curPos.moveUp());
    findPath(curPos.moveRight());
    findPath(curPos.moveDown());
    findPath(curPos.moveLeft());
    curPath.pop_back();

    return;
}

bool isCellVisited(const Coord checked) {
    return std::find(std::begin(curPath), std::end(curPath), checked) != std::end(curPath);
}

bool checkCell(Coord checked) {
    int y_length = labyrinth.size();
    if (y_length == 0) return false;
    int x_length = labyrinth[0].size();

    if (checked.y >= y_length || checked.y < 0 || checked.x >= x_length || checked.x < 0) {
        return false;
    }

    return labyrinth[checked.y][checked.x] == 0;
}

// Плохая идея! Правило 21. Скотт Мейерс. Эффективное использование С++-55.
// Но что тогда делать????
// 1. Работает с исключениями - Java Python
// 2. Код ошибки std::pair<Path, error_code> - golang/С
// 3. Код ошибка передавать в качестве значения - C
// auto result = findMinimalPath (Error &errorCode);
// if (!error.not()) {
    // handle error
// }
// 4. Возвращаем указатель Path*. Если nullptr -> пути нет, если Path{} -> путь есть, но он пустой:  деревня
// 4-2. std::unique_ptr<Path> 
// 5. std::optinal<Path> - Функциональный подход Rust C++ Haskell C# Scala(?) Maybe<Path>

Path findMinimalPath() {
    auto it = std::min_element(std::begin(findedPathes), std::end(findedPathes), [](const auto &lhs, const auto &rhs){
        return lhs.size() < rhs.size();
    });
    if (it == std::end(findedPathes)) {
        return Path{};
    }
    return *it;
}

// ответ внизу ↓↓↓↓↓
























std::optional<Path> findMinimalPath_2() {
    auto it = std::min_element(std::begin(findedPathes), std::end(findedPathes), [](const auto &lhs, const auto &rhs){
        return lhs.size() < rhs.size();
    });
    if (it == std::end(findedPathes)) {
        return std::nullopt;
    }
    return *it;
}












