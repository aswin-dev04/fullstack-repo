#include <iostream>
#include <queue>

template<class T>
class node
{
	public:
		node* left;
		node* right;
		T data;
		node(T x):left(nullptr),right(nullptr),data(x){}
		~node()=default;
};

template<class T>
class bitree
{
	public:
		node<T>* root;
		bitree():root(nullptr){}
		~bitree(){clearTree(root);}

		void insert(T val){root=ins(root,val);}
		void postOrder(node<T>* x)
		{
			if(x==nullptr)return;
			postOrder(x->left);
			postOrder(x->right);
			std::cout<<x->data<<" ";
		}
		void preOrder(node<T>* x)
		{
			if(x==nullptr)return;
			std::cout<<x->data<<" ";
			preOrder(x->left);
			preOrder(x->right);
		}
		void inOrder(node<T>* x)
		{
			if(x==nullptr)return;
			inOrder(x->left);
			std::cout<<x->data<<" ";
			inOrder(x->right);
		}
		void levelOrder(node<T>* x)
		{
			if(x==nullptr)return;
			std::queue<node<T>*>q;
			std::cout<<x->data<<" ";
			q.push(x);
			while(!q.empty())
			{
				x=q.front();
				q.pop();
				if(x->left){std::cout<<x->left->data<<" ";q.push(x->left);}
				if(x->right){std::cout<<x->right->data<<" ";q.push(x->right);}
			}
		}
	private:
		node<T>* ins(node<T>* x,T val)
		{
			if(x==nullptr)return new node<T>(val);
			std::queue<node<T>*> q;
			q.push(x);
			while(!q.empty())
			{
				node<T>* temp=q.front();
				q.pop();
				if(temp->left==nullptr)
				{
					temp->left=new node<T>(val);
					return x;
				}
				else q.push(temp->left);
				if(temp->right==nullptr)
				{
					temp->right=new node<T>(val);
					return x;
				}
				else q.push(temp->right);
			}
			return x;

				
		}
		void clearTree(node<T>* x) {
        if (x == nullptr) return;
        clearTree(x->left);
        clearTree(x->right);
        delete x;
    }
};

int main()
{
	bitree<int> tree;
	tree.insert(15);
	tree.insert(36);
	tree.insert(13);
	tree.insert(17);
	tree.insert(54);
	tree.insert(34);
	tree.preOrder(tree.root);
	std::cout<<"\n";
	tree.inOrder(tree.root);
	std::cout<<"\n";
	tree.postOrder(tree.root);
	std::cout<<"\n";
	tree.levelOrder(tree.root);
	std::cout<<"\n";


	return 0;
}
		





		
