struct DSU{
	vector<int> link, size;
 
	DSU(int n) {
		link.resize(n);
		size.assign(n, 1);
		for(int i=0; i<n; i++) link[i]=i;
	}
 
	int find(int x) {
		while(x!=link[x]) x=link[x];
		return x;
	}
 
	bool same(int a, int b) {
		return find(a) == find(b);
	}
 
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a, b);
		size[a]+=size[b];
		link[b]=a;
	}
};