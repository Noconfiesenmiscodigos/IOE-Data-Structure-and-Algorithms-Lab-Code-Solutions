/*WAP for implementation of Circular Queue*/
#include<iostream>
using namespace std;
class queue
{
    int FRONT;
    int REAR;
    int MAX;
    int *arr;
public:
    queue()
    {
        cout<<"Enter the size of queue:\t";
        cin>>MAX;
        FRONT=-1;
        REAR=-1;
        arr = new int[MAX];
    }
    bool is_empty()
    {
        if (FRONT==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool is_full()
    {
        if (((REAR==MAX-1)&& (FRONT==0))|| (FRONT == REAR+1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int num)
    {
        if (REAR ==-1 && FRONT==-1)
        {
            FRONT=0;
            REAR=0;
            arr[REAR]=num;
        }
        else if (!is_full())
        {
            if(REAR==MAX-1)
            {
                REAR=0;
            }
            else
            {
                REAR+=1;
            }
            arr[REAR]=num;
        }
        else
        {
            cout<<num<<"****************Overflow****************"<<endl;
        }
    }
    int dequeue()
    {
        if(!is_empty())
        {
            int VALUE=arr[FRONT];
            if (FRONT==REAR)
            {
                FRONT=-1;
                REAR=-1;
            }
            else if (FRONT==MAX-1)
            {
                FRONT=0;
            }
            else
            {
                FRONT+=1;
            }
            return VALUE;
        }
    }
};
int main()
{
    queue q;
    int choice;
    int num;
    do
    {
        cout<<endl<<"Enter your choice:"<<endl;
        cout<<"1)enqueue"<<endl;
        cout<<"2)dequeue"<<endl;
        cout<<"3)quit"<<endl;
        cout<<"Enter your choice:\t";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter number to enqueue:\t";
            cin>>num;
            q.enqueue(num);
            break;
        case 2:
            if (!q.is_empty())
            {
                cout<<"\n*********Dequeued number:"<<q.dequeue()<<"*********\n";
            }
            else
            {
                cout<<"****************Underflow****************"<<endl;
            }
            break;
        case 3:
            break;
        }
    }
    while (choice !=3);
}
