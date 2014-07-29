#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;

const char mirror[36] = "A000300HIL0JM0O0002TUVMXY51SE0Z0080";

int main()
{
    string s;
    bool palindrome, mirrored;
    while( getline( cin, s ) )
    {
        palindrome = true;
        mirrored = true;
        for( int i = 0; i <= s.length()/2 ; i++ )
        {
            if( s[i] != s[s.length()-i-1] )
                palindrome = false;
            if( isupper(s[s.length()-i-1]) && (s[i] != mirror[s[s.length()-i-1]-'A']) )
                mirrored = false;
            if( isdigit(s[s.length()-i-1]) && (s[i] != mirror[s[s.length()-i-1]-'1'+26]) )
                mirrored = false;
        }
        printf( "%s -- is ", s.c_str() );
        if( palindrome && mirrored ) printf( "a mirrored palindrome.\n" );
        else if( palindrome ) printf( "a regular palindrome.\n" );
        else if( mirrored ) printf( "a mirrored string.\n" );
        else printf( "not a palindrome.\n" );
        printf( "\n" );
    }
    return 0;
}
