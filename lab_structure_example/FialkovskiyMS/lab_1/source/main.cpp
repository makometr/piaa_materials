#include "header.hpp"

// !! WARNING !! GOVNOKOD !!

// Зачем здесь статик???? - есть
static auto initGlobals = []() {
    labyrinth = {
        {0,0,0,0,0,1,0,0},
        {1,0,1,1,0,1,0,0},
        {1,0,1,1,0,1,0,0},
        {1,0,0,0,0,1,0,0},
        {1,1,1,1,1,1,0,0},
    };
    startPosition = {0, 0};
    finishPosition = {3, 3};
};

// ??  если удалить возвращемый тип  ?? - есть
static auto printPath = [](std::ostream& out, const Path &path) -> std::ostream& {
    for (const auto &coord : path) {
        out << coord << " -> ";
    }
    out << "Finish!\n";
    return out;
};

static auto printAllPathes = [](std::ostream& out) -> std::ostream& {
    auto counter = 1;
    for (const auto &path : findedPathes) {
        out << counter << ". ";
        printPath(out, path);
        counter++;
    }
    return out;
};

int main() {
    initGlobals();

    // Наша реализация находит все возможные пути.
    findPath(startPosition);
    printAllPathes(std::cout);


    // Теперь найдём минимальный пути среди найденных
    auto minimal = findMinimalPath();

    // Путь есть? Старт == конец
    // Или пути нет?
    std::cout << "Pointer of path vector: " << &minimal << "\n";
    printPath(std::cout, minimal);































    // C++17 
    if (auto optPath = findMinimalPath_2(); optPath) {
        printPath(std::cout, *optPath);
    } else {
        std::cout << "No pathes in global pathes\n";
    }
}