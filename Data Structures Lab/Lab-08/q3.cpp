#include<iostream>
#include<string>
#define N 20
using namespace std;
class PQueue{
public:
int Q[N];
int Pr[N];
int Pr2[N];
int SL[N];
int r = -1,f = -1;
int r2 = -1,f2 = -1;
PQueue(){
}
void enqueue(int data,int p,int threshold)
{
	int i;
		if(p>threshold)
			{
			if((f2==0)&&(r2==N-1)) 
		cout<<"Queue is full";
	else
	{
		if(f2==-1)
		{
			f2 = r2 = 0;
			SL[r2] = data;
			Pr2[r2] = p;

		}
		else if(r2 == N-1)
		{
			for(i=f2;i<=r2;i++)
			 { 
                                SL[i-f2] = SL[i]; 
                                Pr2[i-f2] = Pr2[i];
                                r2 = r2-f2; 
                                f2 = 0;
                                for(i = r2;i>f2;i--)
				{
					if(p>Pr2[i])
					{
					SL[i+1] = SL[i];
						Pr2[i+1] = Pr2[i];
					}
					else
						break;
					SL[i+1] = data;
					Pr2[i+1] = p;
					r2++;
				}
			}
		}
		else
		{
			for(i = r2;i>=f2;i--)
			{
				if(p>Pr[i])
				{
					SL[i+1] = SL[i];
					Pr2[i+1] = Pr2[i];	
				}
				else
					break;
			}
			SL[i+1] = data;
			Pr2[i+1] = p;
			r2++;
		}	
	}

}		
		
	else
	{
		int i;
	if((f==0)&&(r==N-1)) 
		cout<<"Queue is full";
	else
	{
		if(f==-1)
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1)
		{
			for(i=f;i<=r;i++)
			 { 
                                Q[i-f] = Q[i]; 
                                Pr[i-f] = Pr[i];
                                r = r-f; 
                                f = 0;
                                for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}

}
}
void print() 
{
int i;
	for(i=f2;i<=r2;i++)
	{
		cout<<"\nShort Order List\n";\
		cout<<"Element ="<<SL[i]<<"Priority = "<<Pr2[i]<<endl;
	}
	for(i=f;i<=r;i++)
	{
		cout<<"\nUnordered List\n";
		cout<<"Element ="<<Q[i]<<"Priority = "<<Pr[i]<<endl;
	}
}
int dequeue() 
{
	if(f2!=-1&&r2!=-1)
	{
	if(f2 == -1)
	{
	cout<<"Queue is Empty";
	}	
	else
	{
	cout<<"deleted Element ="<<SL[f2]<<endl;
	cout<<"Its Priority = "<<Pr2[f2]<<endl;
		if(f2==r2)
			f2 = r2 = -1;
		else
			f2++;
	}
}
	else
	{
	if(f == -1)
	{
	cout<<"Queue is Empty";
	}	
	else
	{
	cout<<"deleted Element ="<<Q[f]<<endl;
	cout<<"Its Priority = "<<Pr[f]<<endl;
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
}

};
int main()
{
	PQueue q;
	int opt,n,i,data,p,thr;
	cout<<"\nEnter Threshold\n";
	cin>>thr;
	cout<<"Enter Your Choice:-"<<endl;
	do{
	cout<<"\n0 Exit\n1 Insert\n2 Print\n3 Deqeue\n4 Change Threshold\n"<<endl;
	cin>>opt;
		switch(opt){
			case 0:
				break;
			
			case 1:
				cout<<"Enter the number of data"<<endl;
				cin>>n;
				cout<<"Enter your data and Priority of data"<<endl;
				i=0;
				while(i<n){
					cin>>data;
					cin>>p;
					q.enqueue(data,p,thr);
					i++;
				}
				break;
			case 2:
				q.print();
				break;
			case 3:
				q.dequeue();
				break;
			case 4:
				cout<<"\nChange Threshold\n";
				cin>>thr;
				break;
			default:
			cout<<"Incorrect Choice"<<endl;
		}
	}
	while(opt!=0);
        return 0;
}
