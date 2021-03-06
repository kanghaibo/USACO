/**
* Description: Supports point update & range query, can be extended to range update
* Verification: SPOJ matsum
* Dependency: Binary indexed tree
*/

template<class T, int SZ> struct BIT2D { 
    BIT<T,SZ> bit[SZ+1];
    void upd(int X, int Y, T val) {
        for (; X <= SZ; X += (X&-X)) bit[X].upd(Y,val);
    }
    T query(int X, int Y) {
        T ans = 0;
        for (; X > 0; X -= (X&-X)) ans += bit[X].query(Y);
        return ans;
    }
    T query(int X1, int X2, int Y1, int Y2) {
        return query(X2,Y2)-query(X1-1,Y2)
            -query(X2,Y1-1)+query(X1-1,Y1-1);
    }
};

int main() {
	int T; cin >> T;
	F0R(i,T) {
	    int N; cin >> N;
	    BIT2D<ll,1024> B = BIT2D<ll,1024>();
	    while (1) {
	        string c; cin >> c;
	        if (c == "SET") {
	            int x, y,num; cin >> x >> y >> num;
	            x++, y++;
	            B.upd(x,y,num-B.query(x,x,y,y));
	        } else if (c == "SUM") {
	            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	            x1 ++, y1 ++, x2 ++, y2++;
	            cout << B.query(x1,x2,y1,y2) << "\n";
	        } else break;
	    }
	}
}