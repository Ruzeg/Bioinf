#include <bits/stdc++.h>
using namespace std;
vector <long long> RabbitsCount;
int main()
{int n;
int i;
int m;
cin >> n;
cin >> m;
RabbitsCount.push_back(0);
RabbitsCount.push_back(1);
for(i=2;i<=m;i++)
	RabbitsCount.push_back(RabbitsCount[i-1]+RabbitsCount[i-2]);
for(i=m+1;i<=n;i++)
	RabbitsCount.push_back(RabbitsCount[i-1]+RabbitsCount[i-2]-RabbitsCount[i-m-1]);
cout << RabbitsCount[n]-(n-m-1);
return 0;
}
