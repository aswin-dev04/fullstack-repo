#include <cstddef>
#include <iostream>
#include <cstring>



template<class T>
class stack
{
	public:
	int top;
	T *stk;
	int size;
	stack(int capacity){size=capacity;stk=new T[size];top=-1;}
	~stack(){delete []stk;}


	bool isFull()
	{
		if(this->top==size-1) return true;
		else return false;
	}
	bool isEmpty()
	{
		if(this->top==-1)return true;
		else return false;
	}
	void push(T x){
		if(this->isFull()){std::cerr<<"Stack is full, cannot push element!\n";return;}
		this->stk[++top]=x;
	}
	T pop()
	{
		T popped{};
		if(this->isEmpty()){std::cerr<<"Stack is empty, cannot remove any elements!\n";return popped;}
		popped=this->stk[top--];
		return popped;
	}
	T peek(){return this->stk[top];}

};

class node
{
	public:
	int data;
	node *next;
	node():data(0),next(nullptr){}
	node(int x):data(x),next(nullptr){}
	~node()=default;
};

class stkLL
{
	public:
		node *top;
		stkLL():top(nullptr){}
		stkLL(node *x):top(x){}
		~stkLL()=default;

		bool LLisFull()
		{
			node *t=new node();
			return t==NULL;
		}
		bool LLisEmpty(){return this->top==nullptr;}

		void LLpush(int x)
		{
			if(LLisFull()){std::cerr<<"Stack is full, cannot insert any element!\n";return;}
			node *temp=new node(x);
			temp->next=this->top;
			this->top=temp;
		}
		int LLpop()
		{
			if(LLisEmpty()){std::cerr<<"Stack is empty, cannot delete any element!\n";return -1;}
			node *temp=this->top;
			this->top=this->top->next;
			int popped{};
			popped=temp->data;
			delete temp;
			return popped;
		}
		int LLpeek()
		{
			if(this->LLisEmpty()){std::cout<<"Stack is empty!\n";return -1;}
			return this->top->data;
		}

};


bool isOperand(char x)
{
	if(x=='+'||x=='-'||x=='*'||x=='/') return false;
	return true;
}

int pre(char x)
{
	if(x=='-'||x=='+')return 1;
	if(x=='*'||x=='/')return 2;
	return 0;
}

char *postfix(const char *inf)
{
	int i{0},j{0};
	stack<char> *x=new stack<char>(strlen(inf));
	/* x->push('#'); */
	char *post=new char[strlen(inf)+1];
	while(inf[i]!='\0')
	{
		if(isOperand(inf[i]))post[j++]=inf[i++];
		else
		{
			if(pre(inf[i])>pre(x->peek()))x->push(inf[i++]);
			else post[j++]=x->pop();
		}
	}
	while(!x->isEmpty())post[j++]=x->pop();
	post[j]='\0';
	return post;
}


int main()
{
	



	return 0;
}








