#include<bits/stdc++.h>

using namespace std;

struct trip
{
	int minutes;
	float lat;
	float lon;
};

int main()
{
	ifstream fin;
	fin.open("temp output.txt");
	struct trip s[MAX];
	i=0;
	while(!fin.eof())
	{
		fin>>trip_id;
		fin>>s[i].minutes;
		fin>>s[i].lat;
		fin>>s[i].lon;
		i++;
	}
	lim=i;
	cin>>k;
	struct trip mu[k+1];
	pick_random(s,lim,k,mu);
	while(!converge(mu,k,color,lim))
	{
		for(i=0;i<lim;i++)
		{
			idx=find_min_pos(i,mu,k);
			color[i] = idx;
		}
		for(i=0;i<k;i++)
		{
			mu[i] = findmean(i,color,lim);
		}
	}
	display_cluster(s,lim,color,mu,k);
	return 0;
}
