#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N;
    while(cin >> N)
    {
        string s;
        int blockAddr[100];
        vector<int> blocks[100];
        for(int i = 0 ; i < N;++i)
        {
            blockAddr[i] = i;
            blocks[i].push_back(i);
        }
        while(cin >> s)
        {
            if(s == "quit")
            {
                break;
            }
            int a,b;
            string s2;
            cin >> a >> s2 >> b;
            int adr1 = blockAddr[a];
            int adr2 = blockAddr[b];
            if( a==b || adr1 == adr2 )
            {

            }
            else if(s == "move" && s2 == "onto")
            {
                int addr1 = blockAddr[a];
                int addr2 = blockAddr[b];
                int index1 = -1 , index2 = -1;
                for(int i = 0 ; i < blocks[addr1].size();++i)
                {
                    if(blocks[addr1][i] == a)
                    {
                        index1 = i + 1;
                        break;
                    }
                }
                for(int i = index1 ; i < blocks[addr1].size();++i)
                {
                    blockAddr[blocks[addr1][i]] = blocks[addr1][i];
                    blocks[blocks[addr1][i]].push_back(blocks[addr1][i]);
                }
                //cout << " a b are " << a << " " << b <<endl;
                //cout << "check move onto " <<addr1 << ":";
                //for(int j = 0 ; j < blocks[addr1].size();++j)
                //{
                //    cout << " " << blocks[addr1][j];
                //}
               // cout << endl;

                blocks[addr1].erase(blocks[addr1].begin()+index1-1, blocks[addr1].end());

                //for(int j = 0 ; j < blocks[addr1].size();++j)
               // {
                //    cout << " " << blocks[addr1][j];
                //}
                //cout << endl;

                for(int i = 0 ; i < blocks[addr2].size();++i)
                {
                    if(blocks[addr2][i] == b)
                    {
                        index2 = i + 1;
                        break;
                    }
                }
                for(int i = index2 ; i < blocks[addr2].size();++i)
                {
                    blockAddr[blocks[addr2][i]] = blocks[addr2][i];
                    blocks[blocks[addr2][i]].push_back(blocks[addr2][i]);
                }
               // cout << "check move onto " <<addr2 << ":";
                //for(int j = 0 ; j < blocks[addr2].size();++j)
                //{
                //    cout << " " << blocks[addr2][j];
                //}
                //cout << endl;

                blocks[addr2].erase(blocks[addr2].begin()+index2, blocks[addr2].end());

                //for(int j = 0 ; j < blocks[addr2].size();++j)
                //{
                //    cout << " " << blocks[addr2][j];
                //}
               // cout << endl;

                blockAddr[a] = addr2;
                blocks[addr2].push_back(a);
            }
            else if(s == "move" && s2 == "over")
            {
                int addr1 = blockAddr[a];
                int addr2 = blockAddr[b];
                int index1 = -1 , index2 = -1;
                //cout << "ad1 ad2 " << addr1 << " " << addr2 <<endl;
                for(int i = 0 ; i < blocks[addr1].size();++i)
                {
                    if(blocks[addr1][i] == a)
                    {
                        index1 = i + 1;
                        break;
                    }
                }
                //cout << "index1 " << index1 <<endl;
                for(int i = index1 ; i < blocks[addr1].size();++i)
                {
                    blockAddr[blocks[addr1][i]] = blocks[addr1][i];
                    blocks[blocks[addr1][i]].push_back(blocks[addr1][i]);
                }
                blocks[addr1].erase(blocks[addr1].begin()+index1-1, blocks[addr1].end());
                //cout << "blocks[addr1] size " << blocks[addr1].size() <<endl;
                blockAddr[a] = addr2;
                blocks[addr2].push_back(a);
            }
            else if(s == "pile" && s2 == "onto")
            {
                int addr1 = blockAddr[a];
                int addr2 = blockAddr[b];
                int index1 = -1 , index2 = -1;

                for(int i = 0 ; i < blocks[addr2].size();++i)
                {
                    if(blocks[addr2][i] == b)
                    {
                        index2 = i + 1;
                        break;
                    }
                }
                //cout << index2 << " index2" <<endl;
                //cout << addr2 << " addr2 " <<endl;
                //cout  << blocks[addr2].size() << " i < blocks[addr2].size()" <<endl;
                for(int i = index2 ; i < blocks[addr2].size();++i)
                {
                    //cout << blocks[addr2][i] << endl;
                    blockAddr[blocks[addr2][i]] = blocks[addr2][i];
                    blocks[blocks[addr2][i]].push_back(blocks[addr2][i]);
                }
               // cout << "check pile " <<addr2 << ":";
               // for(int j = 0 ; j < blocks[addr2].size();++j)
                //{
                 //   cout << " " << blocks[addr2][j];
                //}
                //cout << endl;

                blocks[addr2].erase(blocks[addr2].begin()+index2, blocks[addr2].end());
                //for(int j = 0 ; j < blocks[addr2].size();++j)
               // {
                //    cout << " " << blocks[addr2][j];
                //}
               // cout << endl;

                for(int i = 0 ; i < blocks[addr1].size();++i)
                {
                    if(blocks[addr1][i] == a)
                    {
                        index1 = i;
                        break;
                    }
                }
                for(int i = index1 ; i < blocks[addr1].size();++i)
                {
                    blockAddr[blocks[addr1][i]] = addr2;
                    blocks[addr2].push_back(blocks[addr1][i]);
                }
                blocks[addr1].erase(blocks[addr1].begin()+index1, blocks[addr1].end());

            }
            else if(s == "pile" && s2 == "over")
            {
                int addr1 = blockAddr[a];
                int addr2 = blockAddr[b];
                int index1 = -1 , index2 = -1;

                for(int i = 0 ; i < blocks[addr1].size();++i)
                {
                    if(blocks[addr1][i] == a)
                    {
                        index1 = i;
                        break;
                    }
                }
                for(int i = index1 ; i < blocks[addr1].size();++i)
                {
                    blockAddr[blocks[addr1][i]] = addr2;
                    blocks[addr2].push_back(blocks[addr1][i]);
                }
                blocks[addr1].erase(blocks[addr1].begin()+index1, blocks[addr1].end());
            }
            /*
            for(int i = 0 ; i < N;++i)
            {
                cout << i << ": and size.. "  <<blocks[i].size() << " ;";
                for(int j = 0 ; j < blocks[i].size();++j)
                {
                    cout << " " << blocks[i][j];
                }
                cout << endl;
            }
            */
            //int t;
           // cin >> t;

        }
        for(int i = 0 ; i < N;++i)
        {
            cout << i << ":";
            for(int j = 0 ; j < blocks[i].size();++j)
            {
                cout << " " << blocks[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
