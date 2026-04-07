class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0; // 0:E, 1:N, 2:W, 3:S
    int cycle;

    vector<string> dirs = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        cycle = 2 * (w + h) - 4;
    }

    void step(int num) {
        num %= cycle;

        // Special case
        if (num == 0) {
            if (x == 0 && y == 0) {
                dir = 3; // South
            }
            return;
        }

        while (num--) {
            int nx = x, ny = y;

            if (dir == 0) nx++;       // East
            else if (dir == 1) ny++;  // North
            else if (dir == 2) nx--;  // West
            else ny--;                // South

            // If out of bounds → turn
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                num++; // retry this step
                continue;
            }

            x = nx;
            y = ny;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};
