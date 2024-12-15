#include <iostream>


template<class T>
class node
{
	public:
		T data;
		node<T>* left;
		node<T>* right;
		int height;
		node(T x):left(nullptr),right(nullptr),data(x),height(1){}
		~node()=default;
};


template<class T>
class avl
{
	public:
		node<T>* root;
		avl():root(nullptr){}
		~avl(){clearTree(root);}

		int NodeHeight(node<T>* root)
		{
			int x{0},y{0};
			if(root==nullptr)return 0;
			x=NodeHeight(root->left);
			y=NodeHeight(root->right);
			return x>y?x+1:y+1;
		}
		int balanceFactor(node<T>* root){return root?NodeHeight(root->left)-NodeHeight(root->right):0;}

		node<T>* LLrotate(node<T>* root)
		{
			node<T>* rl=root->left;
			node<T>* rlr=rl->right;
			rl->right=root;
			root->left=rlr;
			root->height=NodeHeight(root);
			rl->height=NodeHeight(rl);
			if(this->root==root)root=rl;
			return rl;
		}
		node<T>* LRrotate(node<T>* root)
		{
			node<T>* rl=root->left;
			node<T>* rlr=rl->right;
			rl->right=rlr->left;
			root->left=rlr->right;
			rlr->left=rl;
			rlr->right=root;
			rlr->height=NodeHeight(rlr);
			root->height=NodeHeight(root);
			rl->height=NodeHeight(rl);
			if(this->root==root)root=rlr;
			return rlr;
		}
		node<T>* RRrotate(node<T>* root)
		{return nullptr;}
		node<T>* RLrotate(node<T>* root)
		{return nullptr;}


		node<T> *insertNode(node<T>*root,T key)
		{
			if(!root)return new node<T>(key);
			if(key<root->data)root->left=insertNode(root->left,key);
			else if(key>root->data)root->right=insertNode(root->right,key);
			else return root;
			root->height=NodeHeight(root);
			if(this->balanceFactor(root)==2&&this->balanceFactor(root->left)==1)return this->LLrotate(root);
			else if(this->balanceFactor(root)==2&&this->balanceFactor(root->left)==-1)return this->LRrotate(root);
			else if(this->balanceFactor(root)==-2&&this->balanceFactor(root->right)==1)return RLrotate(root);
			else if(this->balanceFactor(root)==-2&&this->balanceFactor(root->right)==-1)return RRrotate(root);
			return root;
				
		}
		void preOrder(node<T>* root) 
		{
        if (root == nullptr) return;
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
		}

		void insert(T key){root = insertNode(root, key);}

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
	avl<int> tree;
	/* tree.insertNode(tree.root,23); */
	/* tree.insertNode(tree.root,31); */
	/* tree.insertNode(tree.root,13); */
	/* tree.insertNode(tree.root,19); */
	tree.insert(30);
	tree.insert(10);
	tree.insert(20);
	std::cout<<"Pre-order: ";
	tree.preOrder(tree.root);
	std::cout<<"\n";
	

	return 0;
}




