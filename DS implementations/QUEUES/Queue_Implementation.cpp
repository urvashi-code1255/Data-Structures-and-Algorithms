// C++ program for array implementation of queue

#include <bits/stdc++.h>
using namespace std;

// A class to represent a queue
class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// function to create a queue of given capacity, it initializes size of queue as 0
Queue *createQueue(unsigned capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // assigning last index of the queue to the rear.
    queue->rear = capacity - 1;
    // dynamically allocating int array of capacity.
    queue->array = new int[(queue->capacity * sizeof(int))]; 
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue. It changes rear and size
void enqueue(Queue *queue, int item)
{
    // if queue is full then we can't push more.
    if (isFull(queue))
        return;
    // updating rear to next index.
    queue->rear = (queue->rear + 1) % queue->capacity;
    // storing the item at the rear index of the queue.
    queue->array[queue->rear] = item;
    // as we added one more element so increment the size of the queue.
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue. It changes front and size
int dequeue(Queue *queue)
{
    // if queue is empty then we can't dequeue more, so for handling the underflow we will return INT_MIN.
    if (isEmpty(queue))
        return INT_MIN;
    // as we dequeue from the front of the queue so we will store the front element in item variable.
    int item = queue->array[queue->front];
    // updating the front to the next index.
    queue->front = (queue->front + 1) % queue->capacity;
    // as we have removed one element so we will decrement the size of the queue by 1.
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(Queue *queue)
{
    // in underflow condition we will return INT_MIN.
    if (isEmpty(queue))
        return INT_MIN;
    // otherwise returning the element at the front index of the queue.
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(Queue *queue)
{
    // in underflow condition we will return INT_MIN.
    if (isEmpty(queue))
        return INT_MIN;
    // otherwise returning the element at the rear index of the queue.
    return queue->array[queue->rear];
}

// Driver code
int main()
{
    // creating a queue of maximum capacity 1000.
    Queue *queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << dequeue(queue) << " dequeued from queue\n";

    cout << "Front item is "<< front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;

    return 0;
}