class Solution {
public:
    string losingPlayer(int x, int y) {
        bool w = false;
        while (x > 0 && y >= 4) {
            x--;
            y -= 4;
            w = !w;
        }
        return w ? "Alice" : "Bob";
    }
};
