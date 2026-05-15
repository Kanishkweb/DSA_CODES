class ZeroEvenOdd {
private:
    int n;
    bool turn;
    int no;
    mutex mt;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn = 0;
        no = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mt);
            while (turn == 1 && no <= n) {
                cv.wait(lock);
            }
            if (no > n) {
                cv.notify_all();
                return;
            }

            printNumber(0);
            turn = 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mt);
            while ((turn == 0 || no % 2 == 1) && no <= n) {
                cv.wait(lock);
            }
            if (no > n) {
                cv.notify_all();
                return;
            }

            if (no % 2 == 0) {
                printNumber(no);
                no++;
                turn = 0;
                cv.notify_all();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mt);
            while ((turn == 0 || no % 2 == 0) && no <= n) {
                cv.wait(lock);
            }
            if (no > n) {
                cv.notify_all();
                return;
            }

            if (no % 2 == 1) {
                printNumber(no);
                no++;
                turn = 0;
                cv.notify_all();
            }
        }
    }
};
