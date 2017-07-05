
//	freopen("", "w", stdout);
//	freopen("", "r", stdin);
#include <bits/stdc++.h>
using namespace std;
struct read
	{
	string Name;
	string ConnectedReference;
	int Coordinate;
	string Read;
	string Quality;
	};
struct element
	{
	int value;
	int x;
	int y;
	};
struct reference
	{
	string Name;
	string Ref;
	};
int MaxThree(int First, int Second, int Third)
	{
	return max(max(First, 0), max(Second, Third));
	}
int Check(int FirstSymbol, int SecondSymbol)
	{
	if(FirstSymbol==SecondSymbol)
		return 1;
	else
		return -1;
	}
int main()
{
reference Reference;
read Read;
element Maximal;
int x, y, i;
int S;
string L1, L2;
////freopen("result.txt", "w", stdout);
FILE *result, *small_ref, *small;
small_ref=fopen("small_ref.fa","r");
result=fopen("result.txt","w");
//freopen("small_ref.fa", "r", stdin);
fscanf(small_ref,"%s %s",&Reference.Name,&L1);
//cin >> Reference.Name >> L1;
fclose(small_ref);
//freopen("small.fastq", "r", stdin);
small=fopen("small.fastq","r");
while(sizeof(small)/*getline(cin, Read.Name)*/)
{
//cin >> L2;
fscanf(small,"%s\n",&L2);
//cout << L2;
fprintf(result,"%s0x09",L2);
//cin >> Read.Read; 
fscanf(small,"%s\n",&Read.Read);
//cout << Read.Read; 
fprintf(result,"%s0x09",Read.Read);
//cin >> Read.Quality;
fscanf(small,"%s\n",&Read.Quality);
//cout << Read.Quality;
fprintf(result,"%s0x09",Read.Quality)
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
		Result2.push(L2[R2]);
		R1--;
		R2--;
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
//cout << Read.Name << L1 << x << L2 << Read.Quality;
fprintf("%s0x09%s0x09%d0x09%s0x09%s\n",Read.Name,L1,x,L2,Read.Quality);
}
		
return 0;
}
