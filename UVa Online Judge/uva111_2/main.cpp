#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n; scanf("%d",&n);
	int ar[20];
	for ( int i=0; i<n; i++ ) scanf("%d",&ar[i]);
	int seq[20];
	for ( int i=0; i<n; i++ ) seq[ar[i]-1]=i;
	int each[20];
	for ( int i=0; i<n; i++ ) each[seq[i]]=i;
	while ( scanf("%d",&ar[0])!=EOF ) {
		for ( int i=1; i<n; i++ ) scanf("%d",&ar[i]);
		int tran[20];
		for ( int i=0; i<n; i++ ) tran[ar[i]-1]=i;
		int trans[20];
		for ( int i=0; i<n; i++ ) trans[i]=each[tran[i]];
		for(int i = 0 ; i < n;++i)
        {
            printf("%d ",trans[i]);
        }
        printf("\n");
		int dp[20];
		int mx=0;
		for ( int i=0; i<n; i++ ) {
			dp[i]=1;
			for ( int j=0; j<i; j++ )
				if ( trans[j]<trans[i] ) dp[i]=max(dp[i],dp[j]+1);
			mx=max(mx,dp[i]);
		}
		printf("%d\n",mx);
	}
    return 0;
}
