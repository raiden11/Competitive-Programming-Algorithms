

// dijstra in a grid
// call function by dijstra(source_x, source_y);
// final distances stored in dist[x][y];
// change matrix size acc. to convenience


const int sze = 80;
int mat[sze][sze] = {131,673,234,103,18,201,96,342,965,150,630,803,746,422,111,537,699,497,121,956,805,732,524,37,331};
// take matrix from "for 81.txt"

int dist[sze][sze];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int vis[sze][sze];

void dijstra(int x,int y)
{
    int i,j,k;
    rep(i,sze)
        rep(j,sze)
            dist[i][j]=inf;

    rep(i,sze)
        rep(j,sze)
            vis[i][j]=0;

    vis[x][y]=1;

    dist[x][y]=mat[x][y];

    set<pair<int,pair<int,int> > >s;
    s.insert(mp(mat[x][y],mp(x,y)));
    int dt;

    while(!s.empty())
    {
        auto u = *s.begin();
        s.erase(*s.begin());
        x = u.ss.ff;
        y = u.ss.ss;
        dt = u.ff;
        for(i=0;i<4;i++)
        {
            if(x+dx[i]>=0 and y+dy[i]>=0 and x+dx[i]<sze and y+dy[i]<sze)
            {
                if(vis[x+dx[i]][y+dy[i]]==0)
                {
                    s.insert(mp(dt+mat[x+dx[i]][y+dy[i]],mp(x+dx[i],y+dy[i])));
                    dist[x+dx[i]][y+dy[i]] = dt+mat[x+dx[i]][y+dy[i]];
                    vis[x+dx[i]][y+dy[i]]=1;
                }
                else
                {
                    if(dt+mat[x+dx[i]][y+dy[i]]<dist[x+dx[i]][y+dy[i]])
                    {
                        s.erase(mp(dist[x+dx[i]][y+dy[i]],mp(x+dx[i],y+dy[i])));
                        dist[x+dx[i]][y+dy[i]] = dt+mat[x+dx[i]][y+dy[i]];
                        s.insert(mp(dt+mat[x+dx[i]][y+dy[i]],mp(x+dx[i],y+dy[i])));
                    }
                }
            }
        }
    }
}
