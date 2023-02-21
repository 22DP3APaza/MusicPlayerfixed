#include <iostream>
#include <string>

class Queue {
private:
    int front;
    int back;
    int max;
    std::string* array;
public:
    Queue(int m) {
        front = back = -1;
        max = m;
        array = new std::string[m];
    }
    void add(std::string x) {
        if (back == max - 1) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        array[++back] = x;
    }
    std::string remove() {
        if (front == back) {
            std::cout << "Queue is empty" << std::endl;
            return "";
        }
        return array[++front];
    }
    std::string last() {
        return array[back];
    }
    int size() {
        return back - front;
    }
    std::string start() {
        return array[front + 1];
    }
    // Public accessor functions
    int getFront() const { return front; }
    int getBack() const { return back; }
    std::string* getArray() const { return array; }
};