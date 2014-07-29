/*******************************************************/
/* UVa 624 CD                                          */
/* Author: LanyiKnight [at] knightzone.org             */
/* Version: 2012/04/03                                 */
/*******************************************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int dp[1005][25];

void printCD( int track[], int i, int j )
{
    if( i == 0 || j == 0 ) return;
    if( dp[i][j] == dp[i][j-1] ) printCD( track, i, j-1 );
    else
    {
        printCD( track, i-track[j], j-1 );
        printf( "%d ", track[j] );
    }
}

int main()
{

    int N, track_num;
    int track[25];

    while( scanf( "%d", &N ) != EOF )
    {
        scanf( "%d", &track_num );


        memset( dp, 0, sizeof(dp) );
        for( int i = 1 ; i <= track_num ; i++ )
            scanf( "%d", &track[i] );

        for( int i = 1 ; i <= N ; i++ )
            for( int j = 1 ; j <= track_num ; j++ )
            {
                if( track[j] <= i ) dp[i][j] = max( dp[i-track[j]][j-1]+track[j], dp[i][j-1] );
                else dp[i][j] = dp[i][j-1];
            }
        printCD( track, N, track_num );
        printf( "sum:%d\n", dp[N][track_num] );
    }
    return 0;
}
