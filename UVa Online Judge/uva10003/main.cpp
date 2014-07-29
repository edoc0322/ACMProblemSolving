int len, ll, sa1[N], sa2[N], rank1[N], rank2[N], height[N], h[N][20];
// 比較函數
inline int cmp( int x, int y )
{
    return str[x] < str[y];
}
//求Suffix array
void create_suffix_array( )
{
    int i, k, *s1 = sa1, *s2 = sa2, *r1 = rank1, *r2 = rank2;
    for ( i = 0; i < len; i++ ) s1[i] = i;
    sort( s1, s1+len, cmp );
    for ( r1[s1[0]] = 0, i = 1; i < len; i++ )
    {
        if ( str[s1[i]] == str[s1[i-1]] ) r1[s1[i]] = r1[s1[i-1]];
        else r1[s1[i]] = r1[s1[i-1]]+1;
    }
    for ( k = 1; k < len && r1[s1[len-1]] < len-1; k <<= 1 )
    {
        for ( i = 0; i < len; i++ ) r2[r1[s1[i]]] = i;
        for ( i = len-1; i >= 0; i-- )
            if ( k <= s1[i] )
                s2[r2[r1[s1[i]-k]]--] = s1[i]-k;
        20
        for ( i = len-k; i < len-(k>>1); i++ ) s2[r2[r1[i]]] = i;
        swap( s1, s2 );
        for ( r2[s1[0]] = 0, i = 1; i < len; i++ )
        {
            if ( r1[s1[i]] != r1[s1[i-1]]
                    || r1[s1[i]+k] != r1[s1[i-1]+k] )
                r2[s1[i]] = r2[s1[i-1]]+1;
            else r2[s1[i]] = r2[s1[i-1]];
        }
        swap( r1, r2 );
    }
    if ( s1 != sa1 ) for ( i = 0; i < len; i++ ) sa1[i] = s1[i];
    if ( r1 != rank1 ) for ( i = 0; i < len; i++ ) rank1[i] = r1[i];
}
//計算高度數組
void cal_height( )
{
    int i, j, k;
    for ( i = k = 0; i < len; i++ )
    {
        if ( rank1[i] == 0 ) rank2[i] = 0;
        else
        {
            for ( j = sa1[rank1[i]-1]; str[i+k] == str[j+k]; k++ );
            rank2[i] = k;
            if ( k > 0 ) k--;
        }
    }
    for ( i = 0; i < len; i++ ) height[i] = rank2[sa1[i]];
}
//rmq初始
void rmq_init( )
{
    int i, j, l;
    for ( i = 0; i < len; i++ ) h[i][0] = height[i];
    for ( j = l = 1; l*2 <= len; j++, l <<= 1 )
        for ( i = 0; i <= len-l*2; i++ )
            h[i][j] = MIN( h[i][j-1], h[i+l][j-1] );
}
//rmq查詢 s+1, t
inline int rmq_query( int left, int right )
{
    int j = 0, l = 1;
    while ( l*2 <= right-left+1 )
    {
        l <<= 1;
        j++;
    }
    return MIN( h[left][j], h[right-l+1][j] );
}
