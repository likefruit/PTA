#include <iostream>
#include<vector>
using namespace std;



class node {
public:
	int xishu;
	int mi;
	node *next;
	//node(int x, int y) :xishu(x), mi(y){}

};

void attach(int x, int m, node* &rear)
{
	node *p = new node;
	p->xishu = x;
	p->mi = m;
	rear->next = p;
	p->next = NULL;
	rear = p;
}


node* create()//创建链表
{
	int N;
	int a_xishu, b_mi;
	node *head = new node;
	node *rear,*temp;
	head->next = NULL;
	rear = head;
	cin >> N;
	while (N--)
	{
		cin >> a_xishu >> b_mi;
		attach(a_xishu, b_mi, rear);
	}
	//删除头结点
	temp = head;
	head = head->next;
	delete temp;
	return head;
}
node* Multiply(node *L1, node *L2)
{
	node *head = new node;
	node *rear, *temp; 
	int x, m;
	node *temp1=L1, *temp2=L2;	
	head->next = NULL;
	rear = head;
	if (temp1 == NULL||temp2 == NULL)
		return NULL;
	while (temp2 != NULL)
	{
		if (temp1->xishu*temp2->xishu) {
			attach(temp1->xishu*temp2->xishu, temp1->mi + temp2->mi, rear);
			temp2 = temp2->next;
		}
	}

	temp1 = temp1->next;
	
	while (temp1 != NULL)
	{
		temp2 = L2;
		rear = head;
		while (temp2 != NULL)
		{
			x = temp1->xishu*temp2->xishu;
			m = temp1->mi + temp2->mi;
			if (x)
			{
				while (rear->next != NULL&&m < rear->next->mi)
					rear = rear->next;
				if ( rear->next==NULL||m > rear->next->mi)
				{
					node *temp3 = new node;
					temp3->next = rear->next;
					rear->next = temp3;
					temp3->mi = m;
					temp3->xishu = x;
				}
				else 
				{
					if (rear->next->xishu + x)
						rear->next->xishu += x;
					else
					{
						temp = rear->next;
						rear->next = temp->next;
						delete temp;
					}
				}
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
	}

	temp = head;
	head = head->next;
	delete temp;
	return head;

}


node* add(node *L1, node *L2)
{
	node *head = new node;
	node *rear, *temp;
	head->next = NULL;
	rear = head;
	while (L1 != NULL&&L2 != NULL)
	{
		
		if (L1->mi == L2->mi)
		{
			if (L1->xishu + L2->xishu)
				attach(L1->xishu+L2->xishu, L1->mi, rear);
			L1 = L1->next;
			L2 = L2->next;
		}
		else if (L1->mi > L2->mi)
		{
			if (L1->xishu)
				attach(L1->xishu, L1->mi, rear);
			L1 = L1->next;
		}
		else if (L1->mi < L2->mi)
		{
			if (L2->xishu)
				attach(L2->xishu, L2->mi, rear);
			L2 = L2->next;
		}
		
	}
	while (L1 != NULL)
	{
		if (L1->xishu)
			attach(L1->xishu, L1->mi, rear);
		L1 = L1->next;
	}
	while (L2 != NULL)
	{
		if (L2->xishu)
			attach(L2->xishu, L2->mi, rear);
		L2 = L2->next;
	}
	temp = head;
	head = head->next;
	delete temp;
	return head;
}

void print(node* head)
{
	int flag = 0;
	if (head == NULL)
		cout << "0 0";
	while (head != NULL)
	{
		if (!flag)
			flag = 1;
		else
			cout << " ";
		cout << head->xishu << " " << head->mi ;
		head = head->next;
	}
	cout << endl;
}

int main()
{
	node *l1 = create();
	node *l2 = create();
	node *l3 =NULL;
	node *l4 = NULL;
	l3=add(l1, l2);
	l4 = Multiply(l1, l2);
	print(l4);
	print(l3);
	
	return 0;
}