#include "lib.h"
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct pairComparator {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

struct tupleComparator {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) const {
        if (std::get<0>(a) == std::get<0>(b)) {
            if (std::get<1>(a) == std::get<1>(b)) {
                return std::get<2>(a) > std::get<2>(b);
            }
            return std::get<1>(a) > std::get<1>(b);
        }

        return std::get<0>(a) > std::get<0>(b);
    }
};

class MovieRentingSystem {
    // movie->shops
    unordered_map<int, vector<int>> who_has_my_movie;
    // shop move price rent
    unordered_map<int, pair<int, bool>> *movie_state;
    vector<tuple<int, int, int>> _entries;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        movie_state = new unordered_map<int, pair<int, bool>>[n]();

        std::sort(entries.begin(), entries.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];
        });

        for (auto& entry : entries) {
            auto shop = entry[0];
            auto movie = entry[1];
            auto price = entry[2];
            _entries.push_back(std::make_tuple(shop, movie, price));

            movie_state[shop][movie] = {price, false};
            if (who_has_my_movie.find(movie) == who_has_my_movie.end()) {
                who_has_my_movie[movie] = vector<int>();
            }
            who_has_my_movie[movie].push_back(shop);
        }
    }
    
    vector<int> search(int movie) {
        if (who_has_my_movie.find(movie) == who_has_my_movie.end()) {
            return vector<int>();
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairComparator> q;
        unordered_set<int> prices;
        for (auto &shop_id : who_has_my_movie[movie]) {
            auto &shop = movie_state[shop_id];
            auto &movie_info = shop[movie];
            if (movie_info.second) {
                continue;
            }
            q.emplace(std::make_pair(movie_info.first, shop_id));
            prices.insert(movie_info.first);
            if (prices.size() == 6) break;
        }

        vector<int> ret;
        while (!q.empty()) {
            ret.push_back(q.top().second);
            q.pop();
            if (ret.size() == 5) break;
        }
        return ret;
    }
    
    void rent(int shop, int movie) {
        movie_state[shop][movie].second = true;
    }
    
    void drop(int shop, int movie) {
        movie_state[shop][movie].second = false;
    }
    
    vector<vector<int>> report() {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, tupleComparator> q;
        unordered_set<int> prices;
        for (auto &entry : _entries) {
            auto shop = std::get<0>(entry);
            auto movie = std::get<1>(entry);
            auto price = std::get<2>(entry);
            if (!movie_state[shop][movie].second) {
                continue;
            }
            prices.insert(price);
            q.emplace(std::make_tuple(price, shop, movie));
            if (prices.size() == 6) break;
        }
        vector<vector<int>> ret;
        while (!q.empty()) {
            auto top = q.top();
            ret.push_back({std::get<1>(top), std::get<2>(top)});
            q.pop();
            if (ret.size() == 5) break;
        }
        return ret;
    }
};

int main() {

    return 0;
}
