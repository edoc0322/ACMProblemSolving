#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string title[100001];
string author[100001];
vector<string> returnBook;
vector<string> returnBookAuthor;
map<string,string> titleToAuthor;

string s;
int cnt;
void removeBook(string s1)
{
    int index = -1;
    for(int i = 0 ; i < cnt;++i)
    {
        if(title[i] == s1)
        {
            index = i;
            break;
        }
    }
    if(index != -1)
    {
        if(index == cnt-1 )
        {

        }
        else
        {
            for(int i = index;i < cnt-1;++i)
            {
                title[i] = title[i+1];
                author[i] = author[i+1];
            }
        }

    }

}

void addBook()
{
    for(int i = 0 ; i < returnBook.size();++i)
    {
        if(cnt == 0)
        {
            cout << "Put " << returnBook[i] << " first" <<endl;
            title[cnt] =returnBook[i];
            author[cnt] = titleToAuthor[returnBook[i]];
            cnt++;
        }
        else if(cnt == 1)
        {
            if(titleToAuthor[returnBook[i]] == author[0])
            {
                if(returnBook[i] < title[0])
                {
                    author[1] = author[0];
                    title[1] = title[0];
                    author[0] = titleToAuthor[returnBook[i]];
                    title[0] = returnBook[i];
                }
                else
                {
                    author[1] = titleToAuthor[returnBook[i]];
                    title[1] = returnBook[i];
                }
            }
            else if(titleToAuthor[returnBook[i]] < author[0])
            {
                author[1] = author[0];
                title[1] = title[0];
                author[0] = titleToAuthor[returnBook[i]];
                title[0] = returnBook[i];
            }
            else
            {
                author[1] = titleToAuthor[returnBook[i]];
                title[1] = returnBook[i];
            }
        }
    }
}

int main()
{
    cnt = 0;
    returnBook.clear();
    titleToAuthor.clear();
    while(getline(cin,s))
    {
        if(s=="END")
        {
            while(getline(cin,s))
            {
                if(s[0] == 'B')
                {
                    string s1 = s.substr(7);
                    removeBook(s1);
                    cnt--;
                }
                else if(s[0] == 'R')
                {
                    string s1 = s.substr(7);
                    returnBook.push_back(s1);

                }
                else if(s[0] == 'S')
                {
                    addBook();
                }
                if(s == "END")
                {
                    returnBook.clear();
                    titleToAuthor.clear();
                    cnt = 0;
                    break;
                }
            }
        }
        else
        {
            string s1,s2;
            int status = 0;
            int index;
            for(int i = 0 ; i < s.length();++i)
            {
                if(s[i] == '"' &&status == 0)
                {
                    status = 1;
                }
                else if(s[i] == '"' && status == 1)
                {
                    index = i;
                    break;
                }
            }
            s1 = s.substr(0,index+1);
            s2 = s.substr(index+5);
            title[cnt] = s1;
            author[cnt] = s2;
            titleToAuthor[s1] = s2;
            cnt++;
        }


    }
    return 0;
}
