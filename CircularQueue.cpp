#include <iostream>
#include <vector>

class MyCircularQueue {
private:
    int head;
    int tail;
    int size;
    std::vector<int> data;

public:
    MyCircularQueue(int k) {
        head = -1;
        tail = -1;
        size = k;
        data.resize(size);
        std::cout << "Circular Queue Has Been Initiated" << std::endl;
    }

    void Display(){
        std::cout << "Current Circular Queue Status\n";
        std::cout << "==============================\n";
        for(int i=0; i<data.size(); i++){
            std::cout << "Space " << i << ": " << data[i];
            if(i==head)
                std::cout << " HEAD ";
            if(i==tail)
                std::cout << " TAIL ";
            std::cout << std::endl;
        }
        std::cout << "==============================\n";
    }

    void enQueue(int value) {
        //this is a check to see if the queue is full
        if((tail+1)%size == head){
            //the queue is full
            std::cout << "The queue is full" << std::endl;
        } else {
            tail = (tail+1) % size;
            data[tail] = value;
            //this is a check to see if the queue is empty
            if(head==-1)
                head=0;
        }
    }

    void deQueue() {
        //this moves the head position to the next one in the queue
        //note that it doesn't delete the contents in the head position
        //we could have overwritten the previous head value with - 1 or something similar
        //data[head] = -1;
        if(head == tail ){
            //queue is empty
            std::cout << "Nothing to deQueue" << std::endl;
        } else {
            //removing item from front of queue by moving the head
            data[head] = -1;
            head = (head+1) % size;
        }
    }

    void Front() {
        if(head==-1)
            std::cout << "Queue is empty!" << std::endl;
        else {
            std::cout << "Printing the Front of the Queue" << std::endl;
            std::cout << data[head] << std::endl;
            std::cout << "===============================" << std::endl;
        }
    }

    void Rear() {
        if(tail==-1)
            std::cout << "Queue is empty!" << std::endl;
        else {
            std::cout << "Printing the Rear of the Queue" << std::endl;
            std::cout << data[tail] << std::endl;
            std::cout << "==============================" << std::endl;
        }
    }
}; // end class

int main(){
    //Declares the circular queue with a size of 5
    MyCircularQueue q(5);

    char ans;
    //Loop for Queue menu
    while(ans!='q'){
        std::cout << "QUEUE MENU" << std::endl;
        std::cout << "==========" << std::endl;
        std::cout << "Enter <1> to Display the Queue" << std::endl;
        std::cout << "Enter <2> to Add Integer to the Queue" << std::endl;
        std::cout << "Enter <3> to Remove an Integer from the Queue" << std::endl;
        //std::cout << "Enter <4> to Get the Front of the Queue" << std::endl;
        //std::cout << "Enter <5> to Get the Rear of the Queue" << std::endl;
        std::cout << "Enter <q> to Quit" << std::endl;
        std::cin >> ans;
        switch(ans){
            case '1':
                std::cout <<"Case 1\n";
                q.Display();
                break;
            case '2':
                std::cout <<"Case 2\n";
                int val;
                std::cout << "Please enter an integer" << std::endl;
                std::cin >> val;
                q.enQueue(val);
                break;
            case '3':
                std::cout << "Case 3\n";
                q.deQueue();
                break;
            case '4':
               std::cout << "Case 4\n";
               q.Front();
               break;
            case '5':
               std::cout << "Case 5\n";
               q.Rear();
               break;
            case 'q':
                std::cout << "Case Quit\n";
                break;
            default:
                std::cout <<"Default Case\n";
                break;
        } // end switch/case
    } // end while loop

    return 0;
}
