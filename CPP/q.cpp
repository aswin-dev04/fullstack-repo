#include <iostream>


template<class T>
class queue
{
public:
	int size;
	int front;
	int rear;
	T *q;
	queue(int cap){size=cap;q=new T[size];rear=0;front=0;}
	~queue()=default;

	void enqueue(int x)
	{
		if((rear+1)%size==front){std::cerr<<"Queue is full, cannot insert element!\n";return;}
		else
		{
			rear=(rear+1)%size;
			q[rear]=x;
		}
	}
	int dequeue()
	{
		int deleted{-1};
		if(rear==front)std::cerr<<"Queue is empty, cannot delete any element!\n";
		else
		{
			front=(front+1)%size;
			deleted=q[front];
		}
		return deleted;
	}
	bool isFull(){return rear==size-1;}
	bool isEmpty(){return rear==front;}
	int back(){return q[rear];}
	int frnt(){return q[front+1];}
};

template<class T>
class node
{
	public:
		T data;
		node *next;
		node<T>(T x):data(x),next(nullptr){}
		~node()=default;
};


template<class T>
class qLL
{
	public:
		node<T> *front;
		node<T> *rear;
		qLL():front(nullptr),rear(nullptr){}
		~qLL()=default;
		
		bool LLisFull(){node<T> *t;return t==nullptr;}
		bool LLisEmpty(){return front==nullptr;}

		void LLenqueue(T x)
		{
			if(this->LLisFull()){std::cerr<<"Queue is full!\n";return;}
			node<T> *newnode=new node<T>(x);
			if(front==nullptr){front=rear=newnode;}
			else
			{
				rear->next=newnode;
				rear=newnode;
			}
		}
		T LLdequeue()
		{
			T deleted{};
			if(this->LLisEmpty()){std::cerr<<"Queue is empty!\n";return T();}
			else
			{
				node<T> *temp=front;
				front=front->next;
				deleted=temp->data;
				delete temp;
			}
			if(this->LLisEmpty())rear=nullptr;
			return deleted;
		}
		T LLfront(){return this->front->data;}
		T LLrear(){return this->rear->data;}

};




int main()
{
	/* queue<int> *q=new queue<int>(5); */
	/* q->enqueue(5); */
	/* q->enqueue(7); */
	/* q->enqueue(3); */
	/* q->enqueue(8); */
	/* std::cout<<"The back of the queue is: "<<q->back()<<"\n"; */
	/* std::cout<<"The front of the queue is: "<<q->frnt()<<"\n"; */
	qLL<int> q;
	if(q.LLisEmpty())std::cout<<"Queue is empty, insert elements!\n";
	q.LLenqueue(46);
	q.LLenqueue(64);
	q.LLenqueue(53);
	std::cout<<"The front of the queue is: "<<q.LLfront()<<" and the rear of the queue is: "<<q.LLrear()<<"\n";



	return 0;
}

