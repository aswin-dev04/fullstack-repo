#include <iostream>

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
class bst
{
	public:
		node<T>* root;
		bst():root(nullptr){}
		~bst(){clearTree(root);}

		int height(node<T>* root)
		{
			int x{0},y{0};
			if(this->root==nullptr)return 0;
			x=this->height(this->root->left);
			y=this->height(this->root->right);
			return x>y?x+1:y+1;
		}
		node<T>* inorderPred(node<T>* root)
		{
			if(!root)return nullptr;
			if(root->left)
			{
				root=root->left;
				while(root->right)root=root->right;
				return root;
			}
			return nullptr;
		}
		node<T>* inorderSucc(node<T>* root)
		{
			if(!root)return nullptr;
			if(root->right)
			{
				root=root->right;
				while(root->left)root=root->left;
				return root;
			}
			return nullptr;
		}
		
		
		void insertNode(T key)
		{
			node<T>* t=root;
			node<T> *r{nullptr},*p{nullptr};
			if(root==nullptr){root=new node<T>(key);return;}
			while(t)
			{
				r=t;
				if(key<t->data)t=t->left;
				else if(key>t->data)t=t->right;
				else{std::cerr<<"No duplicates allowed!\n";return;}
			}
			p=new node<T>(key);
			if(key<r->data)r->left=p;
			else r->right=p;
		}
		node<T>* deleteNode(node<T>* root,T key)
		{
			if(root==nullptr) return nullptr;
			if(!root->left&&!root->right)
			{
				if(root==this->root)this->root=nullptr;
				delete root;
				return nullptr;
			}
			if(key<root->data)root->left=this->deleteNode(root->left,key);
			else if(key>root->data)root->right=this->deleteNode(root->right,key);
			else
			{
				if(this->height(root->left)>this->height(root->right))
				{
					node<T>* t=this->inorderPred(root);
					root->data=t->data;
					root->left=this->deleteNode(root->left,t->data);
				}
				else 
				{
					node<T>* t=this->inorderSucc(root);
					root->data=t->data;
					root->right=this->deleteNode(root->right,t->data);
				}
			}
			return root;
		}
		
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

	private:

		void clearTree(node<T>* x) 
		{
			if (x == nullptr) return;
			clearTree(x->left);
			clearTree(x->right);
			delete x;
		}

};

int main()
{
	bst<int> tree;
	tree.insertNode(34);
	tree.insertNode(45);
	tree.insertNode(12);
	tree.insertNode(53);
	std::cout<<"PRE-ORDER: ";
	tree.preOrder(tree.root);
	std::cout<<"\n";
	std::cout<<"IN-ORDER: ";
	tree.inOrder(tree.root);
	std::cout<<"\n";
	tree.deleteNode(tree.root,12);
	tree.inOrder(tree.root);
	std::cout<<"\n";



	return 0;
}




