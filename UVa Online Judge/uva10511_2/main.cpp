    #include <iostream>
    #include <cstdio>
    #include <queue>
    #include <string>
    #include <cstring>
    #include <vector>
    #include <map>
    #include <sstream>
    using namespace std;

    const int maxn=10010;
    const int inf=1<<30;
    struct edge{
        int u,v,next,f;
        edge(int u0=0,int v0=0,int f0=0,int next0=0){
            u=u0,v=v0,f=f0,next=next0;
        }
    }e[maxn*10];
    int head[maxn*2],visited[maxn*2],path[maxn*2];
    int cnt,from,to,marked;
    map <int,string> tos;
    int nc,np,nd;

    void initial(){
        cnt=0;
        marked=1;
        memset(head,-1,sizeof(head));
        memset(visited,0,sizeof(visited));
        tos.clear();
    }

    void adde(int u,int v,int f){
        e[cnt].u=u,e[cnt].v=v,e[cnt].f=f,e[cnt].next=head[u],head[u]=cnt++;
        e[cnt].u=v,e[cnt].v=u,e[cnt].f=0,e[cnt].next=head[v],head[v]=cnt++;
    }

    void input(){
        string st;
        vector <string> v;
        map <string,int> mpc,mpp,mpd;
        map <string,int>::iterator it;
        while(getline(cin,st) && st.length()>0){
            v.push_back(st);
            stringstream ss(st);
            ss>>st;
            mpp[st]=1;
            ss>>st;
            mpd[st]=1;
            while(ss>>st) mpc[st]=1;
        }
        from=0;
        nc=mpc.size();
        np=mpp.size();
        nd=mpd.size();
        to=nc+np+nd+1;
        //to num the string
        it=mpc.begin();
        for(int i=1;i<=nc;i++){
            adde(from,i,1);
            it->second=i;
            tos[it->second]=it->first;
            it++;
        }
        it=mpp.begin();
        for(int i=1;i<=np;i++){
            it->second=nc+i;
            tos[it->second]=it->first;
            it++;
        }
        it=mpd.begin();
        for(int i=1;i<=nd;i++){
            adde(nc+np+i,to,(nc+1)/2-1);
            it->second=nc+np+i;
            tos[it->second]=it->first;
            it++;
        }
        for(int i=0;i<v.size();i++){
            string name,party,club;
            stringstream ss(v[i]);
            ss>>name>>party;
            adde(mpp[name],mpd[party],1);
            while(ss>>club){
                adde(mpc[club],mpp[name],1);
            }
        }
    }

    bool bfs(){
        int s=from,d;
        queue <int> q;
        q.push(s);
        marked++;
        visited[s]=marked;
        while(!q.empty()){
            s=q.front();
            q.pop();
            for(int i=head[s];i!=-1;i=e[i].next){
                d=e[i].v;
                if(visited[d]!=marked && e[i].f>0){
                    visited[d]=marked;
                    path[d]=i;
                    q.push(d);
                    if(d==to) return true;
                }
            }
        }
        return false;
    }

    int maxf(){
        int maxflow=0;
        while(bfs() ){
            int offflow=inf;
            for(int i=to;i!=from;i=e[path[i]].u){
                offflow=min(e[path[i]].f,offflow);
            }
            for(int i=to;i!=from;i=e[path[i]].u){
                e[path[i]].f-=offflow;
                e[path[i]^1].f+=offflow;
            }
            maxflow+=offflow;
         }
         return maxflow;
    }

    void solve(){
        int ans=maxf();
        if(ans>=nc){
            for(int i=0;i<cnt;i++){
                if(e[i].u>=1 && e[i].u<=nc && e[i].v>=nc+1 && e[i].v<=nc+np){
                    if(e[i].f<=0){
                        printf("%s %s\n",tos[e[i].v].c_str(),tos[e[i].u].c_str());
                    }
                }
            }
        }else printf("Impossible.\n");
    }

    int main(){
        //freopen("in.txt","r",stdin);
        int t;
        scanf("%d\n",&t);
        for(int i=0;i<t;i++){
            initial();
            input();
            if(i>0) cout<<endl;
            solve();
        }
        return 0;
    }
