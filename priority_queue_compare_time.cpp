//pq
//not understood

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct Time {
    int h; // >= 0
    int m; // 0-59
    int s; // 0-59
};

class CompareTime {
public:
    bool operator()(Time& t1, Time& t2)
    {
       if (t1.h < t2.h) return true;
       if (t1.h == t2.h && t1.m < t2.m) return true;
       if (t1.h == t2.h && t1.m == t2.m && t1.s < t2.s) return true;
       return false;
    }
};

int main()
{
    priority_queue<Time, vector<Time>, CompareTime> pq;

    // Array of 4 time objects:

    Time t[4] = { {3, 2, 40}, {3, 2, 26}, {5, 16, 13}, {5, 14, 20}};

    for (int i = 0; i < 4; ++i)
       pq.push(t[i]);

    while (! pq.empty()) {
       Time t2 = pq.top();
       cout << setw(3) << t2.h << " " << setw(3) << t2.m << " " <<
       setw(3) << t2.s << endl;
       pq.pop();
    }

    return 0;
}
