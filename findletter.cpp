#include <iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;
int solution(int size,string s)
{
	unordered_map<char,int>map;
	int most =0;
	for(int i=0;i<size;i++)
	{
		map[s[i]]++;
	}
	 for ( auto road : map) {
            if(road.second>most)
			most =road.second;
        }

	return most ;
}
int main() {
	int num;
	cin >> num;    //Reading input from STDIN
	string s;
	cin>>s;
	cout<<solution(num,s);
}