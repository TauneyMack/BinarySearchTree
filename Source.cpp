#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;

struct node
{
	string info;
	node *left, *right;
};

void insert(node* &p, string x) //insert x in BST
{
	if (p == NULL)
	{
		p = new node; p->info = x;
		p->left = NULL; p->right = NULL;
	}
	else
	{
		if (x < p->info) insert(p->left, x);
		if (x > p->info) insert(p->right, x);
	}
}

void show(node* p) //display BST using inorder traversal
{
	if (p != NULL)
	{
		show(p->left);
		cout << p->info << " ";
		show(p->right);
	}
}
void sideWay(node* t, int s) //display BSt sideway
{
	if (t != NULL)
	{
		sideWay(t->right, s += 5);
		cout << setw(s) << t->info << endl;
		sideWay(t->left, s);
	}
}
int height(node* p)//return tree height 
{
	if (p == NULL) return -1; //for tree level return 0
	else return 1 + max(height(p->left), height(p->right));
}

int countNodes(node* t) //count number of nodes recursively
{
	if (t == NULL) return 0;
	else return 1 + countNodes(t->left) + countNodes(t->right);
	//to find total of all nodes replace 1 w/ t->info
}

bool showAncestor(node*t, string target) //display ancestors of node w/ info target
{
	if (t == NULL) return false;
	if (t->info == target) return true;
	if (showAncestor(t->left, target) || showAncestor(t->right, target))
	{
		cout << t->info << " ";
		return true;
	}
	else return false;	
}

struct node* leafDelete(node* t)
{
	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL) 
		{
			delete(t);
			return NULL;
		}
		else
		{ 	// recursively delete in left and right subtrees. 
			t->left = leafDelete(t->left);
			t->right = leafDelete(t->right);
		}
	}
	return t;
}
int main()
{
	node *t = NULL; node *t2 = NULL;
	string monthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	//create and display tree using inorder traversal
	for (int i = 0; i < 12; i++)
	{
		insert(t, monthName[i]); insert(t2, monthName[i]);
	}
	cout << "Tree using inorder traversal: ";
	show(t); cout << endl;
	
	cout << "Tree height: " << height(t) << endl;

	cout << "Ancestors of Dec: ";
	showAncestor(t, "Dec"); cout << endl;

	//remove leaves of tree
	leafDelete(t);
	//display tree sideway
	cout << "Tree in sideway direction:\n";
	int s = 0; sideWay(t, s); cout << endl;
	
	//count number of nodes in new tree
	cout << "Number of nodes: " << countNodes(t) << endl;

	system("pause");
}
/*
Tree using inorder traversal: Apr Aug Dec Feb Jan Jul Jun Mar May Nov Oct Sep
Tree height: 5
Ancestors of Dec: Aug Apr Feb Jan
Tree in sideway direction:
				 Sep
					  Oct
			May
	   Mar
			Jun
  Jan
	   Feb
				 Aug
			Apr

Number of nodes: 9
Press any key to continue . . .
*/