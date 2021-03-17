#include <iostream>
#include <vector>
#include <algorithm>

// На самом деле это не самая эффективная реализация, поэтому она и названа "в лоб".
// Можно не манипулировать внтуренностями массива segments, а просто отодвигать
// "текущее начало" массива до его конца.
// Процесс удаления показан в целях показа процесса удаления.

using integer = long long unsigned int;
using Segment = std::pair<integer, integer>;

std::vector<Segment> readSegments(std::istream &in);
void sortSegmentsByEnds(std::vector<Segment> &segments);
integer findGreedyNewPoint(std::vector<Segment> &segments);
void removeSegmentWithPointInside(std::vector<Segment> &segments, integer point);
void printOptimalPointCovering(std::vector<integer> &points);

int main() {
    auto segments = readSegments(std::cin);
    sortSegmentsByEnds(segments);

    std::vector<integer> points;
    while (!segments.empty()) {
        auto newPoint = findGreedyNewPoint(segments);
        points.push_back(newPoint);
        removeSegmentWithPointInside(segments, newPoint);
    };

    printOptimalPointCovering(points);
}

std::vector<Segment> readSegments(std::istream &in) {
    int n;
    in >> n;

    std::vector<Segment> segments;
    segments.resize(n);
    for (auto i = 0; i < n; i++) {
        in >> segments[i].first >> segments[i].second;
    }

    return segments;
    // или вот так
    // псеводокод! Необходимо создать отдельный тип вместо псевдонима.
    // И перегрузить оператор ввода для этого типа.
    // std::istream_iterator<Segment> it{in};
    // std::istream_iterator<Segment> end;
    // std::copy(it, end, std::back_inserter(segments));
    return segments;
}

void sortSegmentsByEnds(std::vector<Segment> &segments) {
    std::sort(std::begin(segments), std::end(segments), [](auto lhs, auto rhs) {
        if (lhs.second < rhs.second)
            return true;
        return false;
    });
}

integer findGreedyNewPoint(std::vector<Segment> &segments) {
    return segments.front().second;
}

void removeSegmentWithPointInside(std::vector<Segment> &segments, integer point) {
    // Можно использовать факт сортированности массива более выразительно.
    auto it = std::find_if(std::begin(segments), std::end(segments), [point](auto segment) {
        if (segment.first > point)
            return true;
        return false;
    });
    if (it != std::end(segments)) {
        segments.erase(std::begin(segments), it);
    } else {
        segments.clear();
    }
}

void printOptimalPointCovering(std::vector<integer> &points) {
    std::cout << points.size() << "\n";
    for (const auto &elem: points) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}