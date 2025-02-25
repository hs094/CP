#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct Rect { int x1, x2, y1, y2; };

pair<double, double> calculateAreas(const vector<vector<int>>& squares, int mid) {
    vector<Rect> below, above;
    
    // Split squares into regions
    for (auto& X : squares) {
        int x = X[0], y = X[1], l = X[2];
        int y_top = y + l;
        
        // Below mid region
        if (y < mid) {
            int bottom = y;
            int top = min(y_top, mid);
            below.push_back({x, x + l, bottom, top});
        }
        
        // Above mid region
        if (y_top > mid) {
            int bottom = max(y, mid);
            int top = y_top;
            above.push_back({x, x + l, bottom, top});
        }
    }
    auto unionArea = [](vector<Rect>& rects) {
        if (rects.empty()) return 0.0;
        
        vector<int> ys;
        vector<tuple<int, bool, int, int>> events;
        
        // Process vertical edges
        for (auto& r : rects) {
            ys.push_back(r.y1);
            ys.push_back(r.y2);
            events.emplace_back(r.x1, true, r.y1, r.y2);
            events.emplace_back(r.x2, false, r.y1, r.y2);
        }
        
        // Coordinate compression
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        
        // Sort events by x-coordinate
        sort(events.begin(), events.end(), [](auto& a, auto& b) {
            return get<0>(a) < get<0>(b);
        });

        vector<int> count(ys.size(), 0);
        double area = 0;
        int prev_x = get<0>(events[0]);
        
        for (auto& [x, is_start, y1, y2] : events) {
            // Calculate vertical coverage
            if (x != prev_x) {
                double height = 0;
                for (int i = 0; i < ys.size()-1; i++) {
                    if (count[i] > 0) {
                        height += ys[i+1] - ys[i];
                    }
                }
                area += (x - prev_x) * height;
                prev_x = x;
            }
            
            // Update coverage
            auto l = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
            auto r = lower_bound(ys.begin(), ys.end(), y2) - ys.begin();
            for (int i = l; i < r; i++) {
                count[i] += is_start ? 1 : -1;
            }
        }
        
        return area;
    };

    return make_pair(unionArea(below), unionArea(above));
}

int main() {
    vector<vector<int>> squares = {{0, 0, 1}, {2, 2, 1}};
    double y_split = 1;
    
    pair<double, double> result = calculateAreas(squares, y_split);
    // cout << "Area below y=" << y_split << ": " << result.first << endl;
    // cout << "Area above y=" << y_split << ": " << result.second << endl;
    
    return 0;
}