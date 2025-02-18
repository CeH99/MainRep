#include <iostream>
#include <ctime>

using namespace std;

class Stopwatch {
private:
    time_t startTime;
    time_t stopTime;
    bool running;

public:
    Stopwatch() : startTime(0), stopTime(0), running(false) {}

    void start() {
        if (!running) {
            startTime = time(nullptr);
            running = true;
        }
    }

    void stop() {
        if (running) {
            stopTime = time(nullptr);
            running = false;
        }
    }

    void show() const {
        if (running) {
            cout << "Elapsed time: " << (time(nullptr) - startTime) << " seconds" << endl;
        } else {
            cout << "Elapsed time: " << (stopTime - startTime) << " seconds" << endl;
        }
    }

    ~Stopwatch() {
        if (running) {
            cout << "Stopwatch destroyed. Total time: " << (time(nullptr) - startTime) << " seconds" << endl;
        } else {
            cout << "Stopwatch destroyed. Total time: " << (stopTime - startTime) << " seconds" << endl;
        }
    }
};

int main() {
    Stopwatch sw;
    cout << "Press Enter to start..." << endl;
    cin.get();
    sw.start();

    cout << "Stopwatch started. Press Enter to stop..." << endl;
    cin.get();
    sw.stop();
    
    sw.show();
    return 0;
}
