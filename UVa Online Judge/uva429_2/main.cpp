// http://uva.onlinejudge.org/external/4/429.html
// Runtime: 2.544s
// Tag: BFS

/*
 * File:   main.cpp
 * Author: shahab
 * Created on April 6, 2011, 12:30 AM
 */

// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for( int i = (a); i < (b); i++ )
#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Read(r) freopen(r, "r", stdin)
#define Write(w) freopen(w, "w", stdout)

using namespace std;

string dictionary [200 + 5];
int dictionary_length;
int vis [200 + 5];

struct node {
    string str;
    int cost;

    node (string a, int c) {
        str = a;
        cost = c;
    }

    node () { }
} tmp;

queue <node> q;

bool isOneCharDiff (string a, string b)
{
    if ( a.length() != b.length() ) return false;

    int cnt = 0;

    for ( int i = 0; i < a.length(); i++ ) {
        if ( a [i] != b [i] ) cnt++;
    }

    return (cnt == 1) ? true : false;
}

void pushValue (node p)
{
    for ( int i = 0; i < dictionary_length; i++ ) {
        if ( !vis [i] ) {
            if ( isOneCharDiff (p.str, dictionary [i]) ) {
                q.push(node (dictionary [i], p.cost + 1));
                vis [i] = true;
            }
        }
    }
}

int bfs (string a, string b)
{
    while ( !q.empty() ) q.pop();

    q.push(node (a, 0));


    Set (vis, false);

    while ( !q.empty() ) {
        tmp = q.front(); q.pop();
        if (tmp.str == b ) return tmp.cost;
        pushValue (tmp);
    }

    return 0;

}

int main(int argc, char** argv)
{
    //Read ("in.txt");
    int testCase;
    bool blank = false;
    scanf ("%d", &testCase);
    getchar (); getchar ();

    while ( testCase-- ) {
        char input [100];
        dictionary_length = 0;

        while ( gets (input) && strcmp (input, "*") ) {
            dictionary [dictionary_length] = input;
            dictionary_length++;
        }

        if ( blank ) printf ("\n"); blank = true;

        while ( gets (input) && strlen (input) ) {
            char *pch;
            string a, b;
            pch = strtok(input, " ");
            a = pch;
            pch = strtok (NULL, " ");
            b = pch;
            cout << a << " " << b;
            printf (" %d\n", bfs (a, b));
        }
    }

    return 0;
}

// @END_OF_SOURCE_CODE
