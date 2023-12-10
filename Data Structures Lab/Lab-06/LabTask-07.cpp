#include<iostream>
using namespace std;
class node{
	
	public:
		int data;
		int key;
		node* next;
		node* prev;
		
	node()
	{
		data= 0;
		key= 0;
		next= NULL;
		prev= NULL;	
	}
	node(int d, int k)
	{
		data= d;
		key= k;	
	}
};
class sort
{
	public:
		void append(int data, node*& head)
		{
			node* n= new node();
			n->data = data;
		
			if(head == NULL)
			{
				head= n;
				n->next = NULL;
				n->prev = NULL;
			}
			else
			{
				node* ptr= head;                                      
				while(ptr->next != NULL)
				{
					ptr= ptr->next;
				}
				ptr->next= n;
				n->prev = ptr;
				n->next = NULL;				
			}
		}
		
	void selectionsort(node *&head,int size)
		{
			node* temp = head;
			    while (temp) {
			        node* min = temp;
			        node *temp2 = temp->next;
			        while (temp2) {
			            if (min->data > temp2->data)
			                min = temp2;
			  
			            temp2= temp2->next;
			        }
			        int x = temp->data;
			        temp->data = min->data;
			        min->data = x;
			        temp = temp->next;
			    }
			
		}
		void bubblesort(node *&head,int size)
		{
			node *temp1=head;
			node *temp2=NULL;	
			while(temp1->next!=NULL)
			{
				temp2=temp1->next;
				while(temp2!=NULL)
				{
					if(temp1->data>temp2->data)
					{
						int t=temp1->data;
						temp1->data=temp2->data;
						temp2->data=t;
					}
				temp2=temp2->next;	
				}
				temp1=temp1->next;
			}
		}
		void insertionsort(node *&head,int size)
		{
			node* temp = head;
			    while (temp) {
			        node* min = temp;
			        node *temp2 = temp->next;
			        while (temp2) {
			            if (min->data > temp2->data)
			                min = temp2;
			  
			            temp2= temp2->next;
			        }
			        int x = temp->data;
			        temp->data = min->data;
			        min->data = x;
			        temp = temp->next;
			    }
			
		}
		
		void print(node* &head)
		{
			node* ptr= head;
			while(ptr != NULL)
			{
				cout<<"("<<ptr->data<<")-->";
				ptr= ptr->next;
			}
			
		}
		
};
int main()
{
	system("color 70");
	node *head=NULL;
	sort d1;
	int choice;
	d1.append(19,head);
	d1.append(38,head);
	d1.append(56,head);
	d1.append(24,head);
	d1.append(49,head);
	cout<<endl<<"Randomly Generated Link-List: ";
	cout<<endl;d1.print(head);
	cout<<endl;
	block:
	cout<<endl<<"Menu"<<endl<<"1. Bubble-Sort"<<endl<<"2. Insertion-Sort"<<endl<<"3. Selection-Sort"<<endl<<"4. Exit";
	cout<<endl<<"Enter your choice: ";cin>>choice;
	int size=6;
	if(choice==1)
	{
		system("cls");
		system("pause");
		d1.bubblesort(head,size);
		d1.print(head);
		goto block;
	}
	if(choice==2)
	{
		system("cls");
		system("pause");
		d1.insertionsort(head,size);
	    d1.print(head);
		goto block;
	}
	if(choice==3)
	{
		system("cls");
		system("pause");
	    d1.selectionsort(head,size);
	    d1.print(head);
		goto block;
	}
	if(choice==4)
	{
		return 0;
	}
}

