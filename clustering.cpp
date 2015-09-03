#include<bits/stdc++.h>
# define MAX 50000
# define INF 1000000007 
using namespace std;

struct trip
{
	int minutes;
	double lat;
	double lon;
};

void pick_random(struct trip s[],int lim,int k,struct trip mu[])
{
	int i,r;
	bool mark[lim + 1];
	for(i=0;i<lim;i++)
	mark[i]=0;
	i=0;
	while(i < k)
	{
		r = (rand())%lim;
		if(mark[r]==0)
		{
			mark[r]=1;
			mu[i]=s[r];
			i++;
		}
		else ;
	}
}

double calc_dist(struct trip a,struct trip b)
{
	double ans;
	ans=(a.minutes-b.minutes)*(a.minutes-b.minutes) + (a.lat-b.lat)*(a.lat-b.lat) + (a.lon-b.lon)*(a.lon-b.lon);
    return ans;
}

int find_min_pos(int idx,struct trip s[],struct trip mu[],int k)
{
	int i,minpos=-1;
	double minval=INF,val;
	for(i=0;i<k;i++)
	{
		val=calc_dist(mu[i],s[idx]);
		if(val < minval)
		{
			minval=val;
			minpos=i;
		}
	}
	return minpos;
}

struct trip find_mean(int i,struct trip s[],int color[],int lim)
{
	int j,cnt=0;
	struct trip res;
	res.minutes=0;res.lat=0;res.lon=0;
	for(j=0;j<lim;j++)
	{
		if(color[j]==i)
		{
			cnt++;
			res.minutes+=s[j].minutes;
			res.lat+=s[j].lat;
			res.lon+=s[j].lon;
		}
	}
	res.minutes/=cnt;
	res.lat/=cnt;
	res.lon/=cnt;
	return res;
}

void display_cluster(struct trip s[],int lim,int color[],struct trip mu[],int k)
{
	int i,j;
	for(i=0;i<k;i++)
	{
		for(j=0;j<lim;j++)
		{
			if(color[j]==i)
			{
				cout<<j<<" ";
			}
		}
		cout<<"\n";
	}
}

void display(struct trip arr[],int n)
{
	int i;
	cout<<"\ncluster\n";
	for(i=0;i<n;i++)
	{
		cout<<arr[i].minutes<<" "<<arr[i].lat<<" "<<arr[i].lon<<"\n";
	}
	cout<<"\n";
}
int main()
{
	int i,cnt,lim,k,trip_id,idx;
	ifstream fin;
	fin.open("temp output.txt");
	struct trip s[MAX];
	int color[MAX];
	i=0;
	while(!fin.eof())
	{
		fin>>trip_id;
		fin>>s[i].minutes;
		fin>>s[i].lat;
		fin>>s[i].lon;
		cout<<trip_id<<"\n";
		i++;
	}
	lim=i;
	cout<<lim<<"\n";
	cin>>k;
	struct trip mu[k+1];
	pick_random(s,lim,k,mu);
	//while(!converge(mu,k,color,lim))
	cnt=15;
	while(cnt--)
	{
		for(i=0;i<lim;i++)
		{
			idx=find_min_pos(i,s,mu,k);   // idx varies from 0 to k-1
			color[i] = idx;
		}
		for(i=0;i<k;i++)
		{
			mu[i] = find_mean(i,s,color,lim);
		}
		display(mu,k);
	}
	//display_cluster(s,lim,color,mu,k);
	return 0;
}
