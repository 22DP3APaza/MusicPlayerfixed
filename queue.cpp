
#include <iostream>
class Queue
{
private:
    int front; //shows first number or string in queue
    int back; //shows last number or string in queue
    int max; //max elements in queue
    int* array; //array
public:

    Queue(int m) //sets a parameter for max elements in a queue
    {
        front = back = -1;
        max = m;
        array = new int[m];

    }

    void add(int x) //adds new element to queue back
    {
        if (back == max - 1)
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        array[++back] = x;
    }
    int remove() //removes first element in queue
    {
        if (front == back)
        {
            std::cout << "its already empty" << std::endl;
            return -1;
        }
        return array[++front];
    }
    int last() //shows last element in a queue
    {
        return array[back];
    }
    int size() //shows how many elements queue has
    {
        return back - front;
    }
    int start() //shows first element in queue
    {

        return array[front + 1];
    }
};