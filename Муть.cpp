#include <bits/stdc++.h>
using namespace std;
int MaxThree(int First, int Second, int Third)	{return max(First, max(Second, Third));}
int Check(int FirstSymbol, int SecondSymbol)
{
	if(FirstSymbol==SecondSymbol) return 1;
	else return -1;
}
int main()
{int x, y, i;
int S;
string L1, L2;
cin >> L1;
cin >> L2;
int Al[L1.length()+1][L2.length()+1]  {0};
for(i=1;i<=L1.length();i++)	Al[i][0]=Al[i-1][0]-1;
for(i=1;i<=L2.length();i++)	Al[0][i]=Al[0][i-1]-1;
for(x=1;x<=L1.length();x++)	
	for(y=1;y<=L2.length();y++)	
		Al[x][y]=MaxThree(Al[x-1][y-1]+Check(L1[x-1],L2[y-1]), Al[x-1][y]+Check(L1[x-1],'-'), Al[x][y-1]+Check('-',L2[y-1]));
for(x=0;x<=L1.length();x++)
	{
	for(y=0;y<=L2.length();y++)	
		{if(Al[x][y]>=0)	cout << ' ';
		cout << Al[x][y] << ' ';
		}
	cout << '\n';	
	}
int R1=L1.length()-1, R2=L2.length()-1;
stack <char> Result2;
stack <char> Result1;
x=L1.length();
y=L2.length();

while(x!=0||y!=0) {
		if(x>0&&y>0 && Al[x][y]==Al[x-1][y-1]+Check(L1[x-1],L2[y-1])) {
			x--; y--;
			Result1.push(L1[R1]);
			Result2.push(L2[R2]); R1--; R2--;
			}
		if(x>0 && Al[x][y]==Al[x-1][y]+Check(L1[x-1],'-'))
		 {x--;	Result1.push(L1[R1]); Result2.push('-'); R1--;}
		if(y > 0 && Al[x][y]==Al[x][y-1]+Check('-',L2[y-1]))	
		{y--;	Result1.push('-'); Result2.push(L2[R2]); R2--;}
			}


while(!Result1.empty()) {cout << Result1.top();	Result1.pop();}
cout << '\n';	
while(!Result2.empty()) {cout << Result2.top();	Result2.pop();}
return 0;
}
