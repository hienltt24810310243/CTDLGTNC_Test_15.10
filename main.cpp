#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define LIMIT 100
#define VoCung 100000
int n;                  //number of vertice
int s;                  //Start  vertice
int t;                  //Target vertice
int Matrix[LIMIT][LIMIT];
int Temp  [LIMIT][LIMIT];
int d     [LIMIT];
int truoc [LIMIT];
int T     [LIMIT];
void Nhap()
{
    freopen("Grap.txt","r", stdin);
    cin>>n;
    cout<<"Number of vertices: "<< n<<endl;
    cin>>s>>t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                cin>>Matrix[i][j];
                Temp[i][j] = Matrix[i][j];
                if (Matrix[i][j] == 0) Matrix[i][j] = VoCung;
            }
}
void HienThi()
{
    cout<<"\nMatrix: \n";
    for(int i = 1 ; i <= n ; i++ )
        for(int j = 1 ; j <= n ; j++ )
            cout<<Temp[i][j]<<"\t\n"[j==n];
    cout<<endl;
}
//(!T[<>]) -> Tập T chưa bao gồm tất cả các đỉnh của đồ thị

void Dijkstra()
{
    int u, minp;
    for (int v = 1; v <= n; v++)
    {
        d[v] = Matrix[s][v];
        truoc[v] = s;
        T[v] = 0;
    }
    truoc[s] = 0;
    d[s] = 0;
    T[s] = 1;
    while (!T[t])
    {
        minp = VoCung;
        for (int v = 1; v <= n; v++)
            if ((!T[v]) && (minp > d[v]))
            {
                u = v;
                minp = d[v];
            }
        T[u] = 1;
        if (!T[t])
        {
            for (int v = 1; v <= n; v++)
                if ((!T[v]) && (d[u] + Matrix[u][v] < d[v]))
                {
                    d[v] = d[u] + Matrix[u][v];
                    truoc[v] = u;
                }
        }
    }
}

void TimDuongDi(void)
{
    cout<<"Shortest Path from "
        <<(char)(s + 'A' -1)
        <<" to "
        <<(char)(t + 'A' -1)
        << ": ";

    cout<<"\t"
        <<(char)(t + 'A' -1) <<" <= ";

    int i = truoc[t];
    while (i != s)
    cout<<(char)(i + 'A' -1) <<" <= ",
        i = truoc[i];

    cout<<(char)(s + 'A' -1);
    cout<<endl<<"\nWeight of path: "<< d[t]<<endl;
}
int main()
{
    Nhap();
    HienThi();
    Dijkstra();
    TimDuongDi();
    return 0;
}

/*
Problem:
    Find Shortest Path in Matrix
Struct :
    Graph (Matrix[][])
    d = distance
Request:
    Nhap
    HienThi
    Dijkstra
    TimDuongDi
*/
