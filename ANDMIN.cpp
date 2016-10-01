#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class SegmentTree
{ // the segment tree is stored like a heap array
    private:
    vi st, A; // recall that vi is: typedef vector<int> vi;
    int n;
    int left (int p)
    {
         return p << 1;
    } // same as binary heap operations
    int right(int p)
    {
        return (p << 1) + 1;
    }
    void build(int p, int L, int R)
    { // O(n)
        if (L == R) // as L == R, either one is fine
            st[p] = L; // store the index
        else
        { // recursively compute the values
            build(left(p) , L , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j)
    { // O(log n)
        if (i > R || j < L)
            return -1; // current segment outside query range
        if (L >= i && R <= j)
            return st[p];
        // compute the min position in the left and right part of the interval
        int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
        int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
        if (p1 == -1)
            return p2; // if we try to access segment outside query
        if (p2 == -1)
            return p1; // same as above
        return (A[p1] <= A[p2]) ? p1 : p2; // as in build routine
    }
    public:
    SegmentTree(const vi &A1)
    {
        A = A1;
        n = (int)A.size(); // copy content for local usage
        st.assign(4 * n, 0); // create large enough vector of zeroes
        build(1, 0, n - 1); // recursive build
    }
    int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading
};
int main() {
 //   int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; // the original array


  //  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3)); // answer = index 2
   // printf("RMQ(4, 6) = %d\n", st.rmq(4, 6)); // answer = index 5


    int n,q,arr[100000];
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    vi A(arr, arr + n);
    SegmentTree st(A);
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==0)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            int x=st.rmq(l-1,r-1);
            printf("%d\n",arr[x]);
        }
        else
        {
            int l,r,x;
            for(int i=l-1;i<r;i++)
                arr[i]=arr[i]&x;
            vi A(arr, arr + n);
            SegmentTree st(A);
        }

    }
} // return 0;
