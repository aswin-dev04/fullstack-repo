#include <cstddef>
#include <iostream>



class node
{
	public:
	    int data;
	    node *next;
	    node *prev;
		node():data(0),next(nullptr),prev(nullptr){}
		node(int x):data(x),next(nullptr),prev(nullptr){};
		~node()=default;
};

class LL
{
	public:
		node *head;
		LL():head(nullptr){};
		LL(node *x):head(x){}
		~LL()=default;
		int count()
		{
			if(head==nullptr) return 0;
			if(head->next==nullptr) return 1;
			int c{0};
			node *temp=head;
			while(temp){c++;temp=temp->next;}
			return c;
		}

		void insertAtHead(int x)
		{
			node *newnode=new node(x);
			if(head==nullptr)head=newnode;
			else
			{
				head->prev=newnode;
				newnode->next=head;
				head=newnode;
			}
		}

		void insertAtPos(int x,int pos)
		{
			if(pos<1){std::cerr<<"Invalid Position!\n";return;}
			if(pos==1){insertAtHead(x);return;}
			if(pos>1)
			{
				node *newnode=new node(x);
				node *p=head;
				for(int i{1};i<pos-1&&p;++i) p=p->next;
				if(p)
				{
					newnode->next=p->next;
					newnode->prev=p;
					p->next->prev=newnode;
					p->next=newnode;
				}
				else std::cerr<<"Out of bounds!\n";
			}
		}

		void display()
		{
			if(!head){std::cerr<<"Linked List is empty!\n";return;}
			node *temp=head;
			while(temp){std::cout<<temp->data<<"\n";temp=temp->next;}
		}
		
		node *search(int key)
		{
			if(head==nullptr){std::cerr<<"Linked List is empty!\n";return nullptr;}
			node *temp=head;
			while(temp)
			{
				if(temp->data==key)return temp;
				temp=temp->next;
			}
			return nullptr;
		}

		int deleteFirstNode()
		{
			int deleted{};
			if(!head){std::cerr<<"Linked List is empty and cannot delete any node!\n";return 0;}
			else 
			{
				node *temp=head;
				head=head->next;
				if(head)head->prev=nullptr;
				deleted=temp->data;
				delete temp;
			}
			return deleted;
		}
		int deleteGivenNode(int pos)
		{
			int deleted{};
			if(pos<1)std::cerr<<"Invalid Position,cannot delete node!\n";
			if(pos==1){return deleteFirstNode();}
			if(head){
			if(pos>1)
			{
				node *temp=head;
				for(int i{1};i<pos;++i)temp=temp->next;
				if(temp){
				temp->prev->next=temp->next;
				if(temp->next)temp->next->prev=temp->prev;
				deleted=temp->data;
				delete temp;
				}
				else std::cerr<<"Out of bounds!\n";
			}
			}
			else std::cerr<<"Linked List is empty and cannot delete any node!\n"; 
			return deleted;
		}

		void reverse()
		{
			if(this->count()==0){std::cerr<<"Linked List is empty and cannot reverse!\n";return;}
			if(this->count()==1)return;
			if(this->count()>1)
			{
				node *p=head;
				node *temp=nullptr;
				while(p)
				{
					temp=p->next;
					p->next=p->prev;
					p->prev=temp;
					p=p->prev;
					if(p&&p->next==NULL) head=p;
				}
			}
		}

		LL cirLL()
		{
			if(head==nullptr){std::cerr<<"Linked List is empty!\n";return LL();}
			node *temp=head;
			if(this->count()==1)
			{
				head->next=head;
				head->prev=head;
			}
			else
			{
				while(temp->next) temp=temp->next;
				temp->next=head;
				head->prev=temp;
			}
			return LL(head);
		}

		int cirCount()
		{
			int c{};
			if(!head)return 0;
			if(!head->next)return 1;
			else
			{
				node *temp=head;
				do
				{
					c++;
					temp=temp->next;
				}while(temp!=head);
			} return c;
		}

		void dispCir()
		{
			if(!head){std::cerr<<"Circular Linked List is empty!\n";return;}
			node *temp=head;
			do
			{
				std::cout<<temp->data<<"\n";
				temp=temp->next;
			}while(temp!=head);
		}

		void insertCir(int x,int pos)
		{
			if(pos<1){std::cerr<<"Invalid position!\n";return;}
			node *newnode=new node(x);
			if(!head){head=newnode;return;}
			else
			{
				if(pos==1)
				{
					newnode->next=head;
					newnode->prev=head->prev;
					newnode->prev->next=newnode;
					newnode->next->prev=newnode;
					head=newnode;
					return;
				}
				node *temp=head;
				for(int i{1};i<pos-1;++i){if(temp)temp=temp->next;}
				newnode->prev=temp;
				newnode->next=temp->next;
				temp->next->prev=newnode;
				temp->next=newnode;
			}
		}
		
		int deleteCir(int pos)
		{
			int deleted{};
			if(!head){std::cerr<<"Linked List is empty,cannot delete node!\n";return 0;}
			else
			{
				if(this->cirCount()==1)
				{
					if(pos<1){std::cerr<<"Invalid position!\n";return 0;}
					else{deleted=head->data;delete head;return deleted;}
				}
				else
				{
					if(pos<1){std::cerr<<"Invalid position!\n";return 0;}
					if(pos==1)
					{
						head->prev->next=head->next;
						head->next->prev=head->prev;
						deleted=head->data;
						head=head->next;
						delete head->prev;
						return deleted;
					}
					if(pos>1)
					{
						node *temp=head;
						for(int i{0};i<pos-1;++i){if(temp&&temp->next!=head)temp=temp->next;}
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
						deleted=temp->data;
						delete temp;
					}
				}
			}
			return deleted;
		}


};



int main()
{
	LL list;
	int count{0};
	list.insertAtHead(23);
	list.insertAtHead(12);
	list.insertAtPos(9,2);
	list.display();
	std::cout<<"Number of elements in the linked list is: "<<list.count()<<"\n";
	int key{9};
	node *found=list.search(key);
	if(found)std::cout<<"Element found with key: "<<key<<" at address "<<found<<"\n";
	else std::cout<<"Element was not found with key: "<<key<<"\n";
	/* list.deleteFirstNode(); */
	/* std::cout<<"================================\n"<<"After deletion:\n"; */
	/* int deleted=list.deleteGivenNode(2); */
	/* std::cout<<"Before reversal: \n"; */
	/* list.display(); */
	/* /1* std::cout<<"Deleted element: "<<deleted<<"\n"; *1/ */
	/* list.reverse(); */
	/* std::cout<<"After reversal: \n"; */
	/* list.display(); */
	LL temp;
	temp.insertAtHead(23);
	temp.insertAtHead(12);
	temp.insertAtPos(9,2);
	LL circ=temp.cirLL();
	circ.dispCir();
	std::cout<<"==========================\n";
	circ.insertCir(18,4);
	circ.insertCir(19,5);
	circ.insertCir(4,1);
	circ.dispCir();
	std::cout<<"\n";
	std::cout<<"Deleted: "<<circ.deleteCir(3)<<"\n";
	std::cout<<"List after deletion:\n";
	circ.dispCir();
	return 0;
}


