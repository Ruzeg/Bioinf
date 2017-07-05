#include <bits/stdc++.h>
using namespace std;
struct element
	{
	int value;
	int x;
	int y;
	};
int MaxThree(int First, int Second, int Third)	{return max(max(First, 0), max(Second, Third));}
int Check(int FirstSymbol, int SecondSymbol)
	{
	if(FirstSymbol==SecondSymbol) return 1;
	else return -1;
	}
int main()
{
element Maximal;
int x, y, i;
int S;
string L1, L2;
cin >> L1;
cin >> L2;
int Al[L1.length()+1][L2.length()+1]  {0};
for(i=1;i<=L1.length();i++)	Al[i][0]=0;
for(i=1;i<=L2.length();i++)	Al[0][i]=0;
for(x=1;x<=L1.length();x++)	
	for(y=1;y<=L2.length();y++)	
		{
		Al[x][y]=MaxThree(Al[x-1][y-1]+Check(L1[x-1],L2[y-1]), Al[x-1][y]+Check(L1[x-1],'-'), Al[x][y-1]+Check('-',L2[y-1]));
		if(Al[x][y]>Maximal.value)
			{
			Maximal.value=Al[x][y];
			Maximal.x=x;
			Maximal.y=y;
			}
		}
cout << Maximal.value << ' '<< Maximal.x << ' '<< Maximal.y << "\n";
for(x=0;x<=L1.length();x++)
	{
	for(y=0;y<=L2.length();y++)	
		{
		if(Al[x][y]>=0)	cout << ' ';
		cout << Al[x][y] << ' ';
		}
	cout << '\n';	
	}
int R1=Maximal.x-1, R2=Maximal.y-1;
stack <char> Result2;
stack <char> Result1;
x=Maximal.x;
y=Maximal.y;
while(Al[x][y]!=0)
		{
		if(x>0 && y>0 && Al[x][y]==Al[x-1][y-1]+Check(L1[x-1],L2[y-1]))
			{
			x--;
			y--;
			Result1.push(L1[R1]);
			Result2.push(L2[R2]); R1--; R2--;
			}
		if(x>0 && Al[x][y]==Al[x-1][y]+Check(L1[x-1],'-'))
			{
			x--;
			Result1.push(L1[R1]);
			Result2.push('-');
			R1--;
			}
		if(y > 0 && Al[x][y]==Al[x][y-1]+Check('-',L2[y-1]))	
			{
			y--;
			Result1.push('-');
			Result2.push(L2[R2]);
			R2--;
			}
		}
while(!Result1.empty())
	{
	cout << Result1.top();
	Result1.pop();
	}
cout << '\n';
while(!Result2.empty())
	{
	cout << Result2.top();
	Result2.pop();
	}
return 0;
}
