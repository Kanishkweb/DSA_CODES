class H2O {
    mutex mt;
    condition_variable cv;
    int turn;
public:
    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mt);
        while(turn == 2){
            cv.wait(lock);
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn += 1;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mt);
        while(turn < 2){
            cv.wait(lock);
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        turn = 0;
        cv.notify_all();
    }
};
