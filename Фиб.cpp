#include <bits/stdc++.h>
using namespace std;
long long F=1, S=0;
int n;
int i;
int main()
{cin >> n;
for(i=2;i<=n;i++)
	{
		F=F+S;
		S=F-S;
	}
if(n==0)	cout << S;
else	cout << F;
return 0;
}
