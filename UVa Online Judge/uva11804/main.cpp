#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


struct person
{
    string name;
    int atk,def;
};

bool cmp(person s1,person s2)
{
    return s1.name < s2.name;
}

int main()
{
    int test;
    cin >> test;
    for(int t = 1 ; t <= test; ++t)
    {
        cout << "Case " << t << ":" <<endl;
        person per[10];
        string name;
        int atk,def;
        int totalAtk = 0,totalDef = 0;
        for(int i = 0 ; i < 10;++i)
        {
            cin >> name >> atk >> def;
            per[i].name = name;
            per[i].atk = atk;
            per[i].def = def;
            totalAtk += atk;
            totalDef += def;
        }
        sort(per,per+10,cmp);
        int maxAtk = -1,maxDef = -1;
        int mark[10];
        for(int i = 0 ; i < 10;++i)
        {
            mark[i] = 0;
        }
        for(int i = 0 ; i < 10;++i)
        {
            for(int j = i+1;j < 10;++j)
            {
                for(int k = j+1;k < 10;++k)
                {
                    for(int m = k+1 ; m < 10;++m)
                    {
                        for(int n = m + 1 ; n < 10 ;++n)
                        {
                            int tempAtk = per[i].atk + per[j].atk + per[k].atk + per[m].atk + per[n].atk;
                            int tempDef = totalDef - (per[i].def + per[j].def + per[k].def + per[m].def + per[n].def);
                            if(tempAtk > maxAtk)
                            {
                                for(int i2 = 0 ; i2 < 10;++i2)
                                {
                                    mark[i2] = 0;
                                }
                                //cout << i << " 1 " <<j << " " << k << " " << m << " " << n <<endl;
                                mark[i] =  mark[j] =  mark[k] =  mark[m] =  mark[n] = 1;
                                maxAtk = tempAtk;
                                maxDef = tempDef;
                            }
                            else if(tempAtk == maxAtk)
                            {
                                if(tempDef > maxDef)
                                {
                                    for(int i2 = 0 ; i2 < 10;++i2)
                                    {
                                        mark[i2] = 0;
                                    }
                                    //cout << i << " 2 " <<j << " " << k << " " << m << " " << n <<endl;
                                    mark[i] =  mark[j] =  mark[k] =  mark[m] =  mark[n] = 1;
                                    maxAtk = tempAtk;
                                    maxDef = tempDef;
                                }
                                else if(tempDef == maxDef)
                                {
                                    vector<int> index1,index2;
                                    index1.push_back(i);
                                    index1.push_back(j);
                                    index1.push_back(k);
                                    index1.push_back(m);
                                    index1.push_back(n);

                                    for(int i2 = 0 ; i2 < 10;++i2)
                                    {
                                        if(mark[i2] == 1)
                                        {
                                            //cout << "push1 " << per[i2].name << endl;
                                            index2.push_back(i2);
                                        }
                                    }



                                    int status = 1;
                                    for(int i2 = 0 ; i2 < 5;++i2)
                                    {
                                        if(per[index1[i2]].name > per[index2[i2]].name)
                                        {
                                            status = 0;
                                            break;
                                        }
                                    }
                                    if(status)
                                    {
                                        for(int i2 = 0 ; i2 < 10;++i2)
                                        {
                                            mark[i2] = 0;
                                        }
                                        cout << i << " 3 " <<j << " " << k << " " << m << " " << n <<endl;
                                        mark[i] =  mark[j] =  mark[k] =  mark[m] =  mark[n] = 1;
                                        maxAtk = tempAtk;
                                        maxDef = tempDef;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int counts = 0;
        cout << "(";
        for(int i = 0 ; i < 10;++i)
        {
            if(mark[i] == 1)
            {
                if(counts == 0)
                {
                    cout << per[i].name;
                }
                else
                {
                    cout << ", " << per[i].name;
                }
                counts++;
            }
        }
        cout << ")\n";
        counts = 0;
        cout << "(";
        for(int i = 0 ; i < 10;++i)
        {
            if(mark[i] == 0)
            {
                if(counts == 0)
                {
                    cout << per[i].name;
                }
                else
                {
                    cout << ", " << per[i].name;
                }
                counts++;
            }
        }
        cout << ")\n";

    }
    return 0;
}
