#include<iostream>
using namespace std;
int main()
{
	int k,j,q,i,n,ts,temp;
     int aw;                      float awt;
     int bt[10],wt[10],te[10],rt[10],at[10];j=0; 
	cout<<"Enter number of processes"<<endl;
	 cin>>n;
	 for(i=0;i<n;i++)
	 {	 
	 cout<<"Enter burst time"<<endl; 
		 cin>>bt[i];
		 cout<<"Enter arrival times"<<endl;
		 cin>>at[i];
		 te[i] = 0; wt[i] = 0;
	 }
	 for(i=0;i<n;i++)
	 {
		 for(j = i+1;j<n;j++)
		 {
			 if(at[j]<at[i])
			 {
				 temp = at[i];
			     at[i] = at[j];
				 at[j] = temp;
             if(at[j] ==at[i])
				 temp = bt[i];
			     bt[i] = bt[j];
				 bt[j] = temp;
			 }
		 }
	 }
	 cout<<"Enter time slice"<<endl;
	 cin>>ts;
	 cout<<"process:"<<endl;
	    for(i=0;i<n;i++)
	 {
		 cout<<"\t"<<i+1<<endl;
	 } 
	cout<<"Burst time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"  "<<bt[i]<<endl;
		rt[i] = bt[i];
	}
	cout<<"arrival time:"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"  "<<at[i]<<endl;
	}
	cout<<"Gaint chart"<<endl;
	while (j<=n)
	{
		j++;
		for(i = 0;i<n;i++)
		{
			if(rt[i] ==0) continue;
			if(rt[i]>=ts)
			{
				cout<<"\t"<<q<<i+1<<endl;
				q = q + ts;
				rt[i] = rt[i] - ts;
				te[i] = te[i] + 1;
			}
			else
			{
				cout<<"  "<<q<<i+1<<endl;
				wt[i] = q-te[i]*ts;
				q = q +rt[i];
				rt[i] = rt[i] - rt[i];
			}
		}
	}
	awt = 0;
	cout<<"Process Waiting Time"<<endl;
	for(i =0;i<n;i++)
	{
		wt[i] = wt[i] - at[i];
		cout<<"  "<<i+1<<endl;
			cout<<wt[i]<<endl;
		awt = awt + wt[i];
	}
	aw = awt;
	cout<<"Total waiting time"<<aw<<endl;
	cout<<"Average waiting time "<<awt/n<<endl;
	return 0;
}
