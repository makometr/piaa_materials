#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include <optional>
#include <algorithm>


// По хорошему реалиацию и объявление нужно вынести в отдельные файлы.
struct Coord {
    int y;
    int x;
    Coord moveUp() {
        return {y-1,x};
    };
    Coord moveDown() {
        return {y+1,x};
    };
    Coord moveLeft() {
        return {y,x-1};
    }
    Coord moveRight() {
        return {y,x+1};
    }
    friend bool operator==(const Coord &lhs, const Coord &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};

// Зачем inline ??????????? - есть
inline std::ostream& operator<<(std::ostream& out, const Coord &coord ) {
    out << "{y: " << coord.y << "; x: "<< coord.x << "}";
    return out;
}

using Lab = std::vector<std::vector<int>>;
using Path = std::vector<Coord>;


// Зачем extern ??????????? - есть
extern std::deque<Coord> curPath;
extern std::vector<Path> findedPathes;
extern Lab labyrinth;
extern Coord startPosition;
extern Coord finishPosition;



void findPath(Coord currentPosition);
bool checkCell(Coord checked);
bool isCellVisited(Coord checked);
bool isCellFinish(Coord checked);
Path findMinimalPath();
std::optional<Path> findMinimalPath_2();
