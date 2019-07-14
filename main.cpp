#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) {
            m[list1[i]] = i;
        }
        int res = INT_MAX;
        vector<string> choice;
        for (int i = 0; i < list2.size(); ++i) {
            string str = list2[i];
            if (m.count(str)) {
                int index = m[str] + i;
                if (index < res) {
                    res = index;
                    choice = vector<string>{str};
                } else if (index == res) {
                    choice.push_back(str);
                }
            }
        }
        return choice;
    }
};

void test1() {
    vector<string> v1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> v2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};

    cout << " ? " << Solution().findRestaurant(v1,v2) << endl;
}

void test2() {

}

void test3() {

}