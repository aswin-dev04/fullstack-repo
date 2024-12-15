#include <cstddef>
#include <iostream>


class node
{
	public:
		int data;
		node *next;
		node():data(0),next(nullptr){}
		node(int x):data(x),next(nullptr){}
		~node()=default;
};

class LL
{
	public:
		node *head;
		LL():head(nullptr){};
		LL(node *x):head(x){};
		~LL()=default;
		int count()
		{
			int c{0};
			node *temp=head;
			if(temp==nullptr) return c;
			else
			{
				while(temp){c++;temp=temp->next;}
			}
			return c;
		}
		void insertAtHead(int x)
		{
			node *newnode=new node(x);
			if(head==nullptr){
				head=newnode;
			}
			else
			{
				newnode->next=head;
				head=newnode;
			}
		}
		void insertInMiddle(int x,int pos)
		{
			if(pos<1){std::cerr<<"Invalid position\n";return;}
			else if(pos==1){insertAtHead(x);return;}
			else
			{
				node *newnode=new node(x);
				node *p=head;
				for(int i{1};i<pos-1&&p;++i) p=p->next;
				if(p)
				{
					newnode->next=p->next;
					p->next=newnode;
				}
				else std::cerr<<"Out of bounds!\n";
			}
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
		void display()
		{
			if(!head){std::cout<<"No elements present in the linked list!\n";return;}
			node *temp=head;
			while(temp)
			{
				std::cout<<temp->data<<"\n";
				temp=temp->next;
			}
		}
		int deleteFirstNode()
		{
			int deleted{};
			if(!head){std::cerr<<"No nodes present to delete\n";return 0;}
			else
			{
			node *temp=head;
			head=head->next;
			deleted=temp->data;
			delete temp;
			}
			return deleted;
		}
		int deleteGivenNode(int pos)
		{
			int deleted{};
			if(pos<1){std::cerr<<"Invalid position!\n"; return 0;}
			else if(pos==1){return deleteFirstNode();}
			else
			{
				node *temp1=head;
				node *temp2=nullptr;
				for(int i{1};i<pos&&temp1;++i)
				{
					temp2=temp1;
					temp1=temp1->next;
				}
				if(!temp1){std::cerr<<"Out of bounds!\n";return 0;}
				temp2->next=temp1->next;
				deleted=temp1->data;
				delete temp1;
			}
			return deleted;
		}
		bool isSorted()
		{
			node *p=head;
			int temp=p->data;
			p=p->next;
			while(p)
			{
				if(p->data>temp)
				{
					temp=p->data;
					p=p->next;
				}
				else return false;
			}
			return true;
		}

		void reverse()
		{
			if(this->count()==0){std::cerr<<"No nodes present to reverse!\n";return;}
			if(this->count()==1) return;
			if(this->count()>1)
			{
				node *p=head;
				node *q=nullptr;
				node *r=nullptr;
				while(p)
				{
					r=q;
					q=p;
					p=p->next;
					q->next=r;
				}
				head=q;
			}
		}
		void concatenate(node *head)
		{
			if(this->head==nullptr&&head==nullptr) return;
			else if(this->head==nullptr) this->head=head;
			else{
				node *temp=this->head;
				node *second=head;
				while(temp->next) temp=temp->next;
				temp->next=second;
				second=nullptr;
			}
		}
		LL merge(node *head)
		{
			node *fin=nullptr;
			if(this->head==nullptr&&head==nullptr) return LL();
			else if(this->head==nullptr){fin=head; return LL(fin);}
			else
			{
				node *third=nullptr;
				node *last=nullptr;
				node *temp1=this->head;
				node *temp2=head;
				if(temp1->data<temp2->data)
				{
					third=last=temp1;
					temp1=temp1->next;
					last->next=NULL;
				}
				else
				{
					third=last=temp2;
					temp2=temp2->next;
					last->next=NULL;
				}
				while(temp1&&temp2)
				{
					if(temp1->data<temp2->data)
					{
						last->next=temp1;
						last=temp1;
						temp1=temp1->next;
						last->next=NULL;
					}
					else
					{
						last->next=temp2;
						last=temp2;
						temp2=temp2->next;
						last->next=NULL;
					}
				}
				if(!temp1) last->next=temp2;
				else last->next=temp1;
				fin=third;
			}
			return LL(fin);
		}
		LL cirLL()
		{
			if(this->head==nullptr) return LL();
			node *temp=this->head;
			if(this->count()==1)
			{
				temp=this->head;
				temp->next=temp;
			}
			else
			{
				while(temp->next) temp=temp->next;
				temp->next=this->head;
			}
			return LL(head);
		}

		int CirCount()
		{
			int c{};
			if(head==nullptr) return 0;
			if(head->next==NULL) return 1;
			else
			{
				node *temp=head;
				do
				{
					c++;
					temp=temp->next;
				}while(temp!=head);
			}
			return c;
		}


		void dispCir()
		{
			if(this->head==nullptr){std::cerr<<"No nodes to display!\n";return;}
			node *temp=this->head;
				do
				{
					std::cout<<temp->data<<"\n";
					temp=temp->next;
				}while(temp!=head);
		}
		void insertCirc(int x,int pos)
		{
			if(pos<1) std::cerr<<"Invalid position!\n";
			node *newnode=new node(x);
			if(head==nullptr) head=newnode;
			else
			{
			if(pos==1)
			{
				node *temp=head;
				while(temp->next!=head) temp=temp->next;
				temp->next=newnode;
				newnode->next=head;
				head=newnode;
			}
			if(pos>1)
			{
				node *temp=head;
				for(int i{1};i<pos-1&&temp;++i)
				{
					if(temp) temp=temp->next;
				}
				newnode->next=temp->next;
				temp->next=newnode;
			}
			}

		}
		int deleteCirc(int pos)
		{
			int deleted{};
			if(head==nullptr){std::cerr<<"Linked List is empty!\n";return 0;}
			else
			{
				if(this->CirCount()==1){
					if(pos<1){std::cerr<<"Invalid position!\n";return 0;}
					else{deleted=head->data;delete head;return deleted;}
				}
				else
				{
					if(pos<1)std::cerr<<"Invalid position!\n";
					if(pos==1)
					{
						node *temp=head;
						while(temp->next!=head) temp=temp->next;
						temp->next=head->next;
						deleted=head->data;
						delete head;
						head=temp->next;
						return deleted;
					}
					if(pos>1)
					{
						node *temp1=head;
						node *temp2=nullptr;
						for(int i{1};i<pos-1;++i){
							if(temp1->next==head||!temp1){std::cerr<<"Out of bounds!\n";return 0;}
							else temp1=temp1->next;
						}
						temp2=temp1->next;
						deleted=temp2->data;
						temp1->next=temp2->next;
						delete temp2;
					}
				}
			}
			return deleted;
		}
		int middle()
		{
			node *p=head;
			node *q=head;
			while(q)
			{
				q=q->next;
				if(q)q=q->next;
				if(q)p=p->next;
			}
			return p->data;
		}



	
};

int main()
{
	LL list;
	int count{0};
	list.insertAtHead(45);
	list.insertAtHead(41);
	list.insertAtHead(40);
	std::cout<<"The middle element of the list is: "<<list.middle()<<"\n";

	return 0;
}











