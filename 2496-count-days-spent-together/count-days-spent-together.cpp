class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                      string arriveBob, string leaveBob) {

    vector<int> month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto convert = [&](string date) {
        int m = stoi(date.substr(0, 2));
        int d = stoi(date.substr(3, 2));

        int total = d;

        for (int i = 1; i < m; i++) {
            total += month[i];
        }

        return total;
    };

    int start = max(convert(arriveAlice), convert(arriveBob));
    int end = min(convert(leaveAlice), convert(leaveBob));

    if (start > end) {
        return 0;
    }

    return end - start + 1;
}
};