// MULTI-SOURCE SHORTEST PATHS

FloydWarshall() {
    int n, m, d[mxN][mxN];
    memset(d, 0x3f, sizeof(d));
    for(int i=0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], w);
        d[b][a] = min(d[a][b], w);
    }
    for(int i=0; i<n; i++)
        d[i][i]=0;
    
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j])
}