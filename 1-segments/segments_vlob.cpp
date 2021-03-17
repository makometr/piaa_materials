#include <iostream>
#include <vector>
#include <algorithm>

// Здесь также показано удаление ражи удаления.
// Можно просто отодвигать текущий индекс.

using integer = long long unsigned int;
using Segment = std::pair<integer, integer>;

int main() {
    int n;
    std::cin >> n;

    std::vector<Segment> segments;
    segments.resize(n);
    for (auto i = 0; i < n; i++) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::sort(std::begin(segments), std::end(segments), [](auto lhs, auto rhs) {
        if (lhs.second < rhs.second)
            return true;
        return false;
    });

    std::vector<integer> points;
    while (!segments.empty()) {
        auto newPoint = segments.front().second;
        points.push_back(newPoint);

        auto it = std::find_if(std::cbegin(segments), std::cend(segments), [point=newPoint](auto segment) {
            if (segment.first > point)
                return true;
            return false;
        });
        if (it != std::cend(segments)) {
            segments.erase(std::cbegin(segments), it);
        } else {
            segments.clear();
        }
    };

    std::cout << points.size() << "\n";
    for (const auto &elem: points) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}