#include<bits/stdc++.h>

using namespace std;

int main()
{
	int cnt=0,minutes,len;
	string str,prevstr;
	ifstream fin;
	ofstream fout;
	fin.open("test2.txt");
	fout.open("temp output.txt");
	cnt=1000;
	prevstr=" ";
	cout<<cnt<<"\n";
	while(!fin.eof())
	{
		fin>>str;
		if(str==prevstr)
		{
			fin>>str;fin>>str;fin>>str;
			continue;
		}
		prevstr=str;
		fout<<str;
		fout<<",";
		fin>>str;
		len=str.size();
		minutes=str[len-10]-'0'+10*(str[len-11]-'0')+60*(str[len-13]-'0'+10*(str[len-14]-'0'));
		fout<<minutes<<",";
		fin>>str;
		fout<<str<<",";
		fin>>str;
		fout<<str;
		fout<<"\n";
		cnt--;
		cout<<cnt<<"\n";
	}
	cout<<cnt<<"\n";
	//file.seekp(0,ios::beg);
	fin.close();
	fout.close();
	return 0;
}
