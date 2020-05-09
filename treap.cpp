

    #include<bits/stdc++.h>
    using namespace std;
    #define N 100001
    #define LL long long
    LL n,k,ans;
    vector<LL>d[N];
    struct rua{LL x,r,f;}a[N];
    bool cmp(rua x,rua y){return x.r>y.r;}
    int main()
    {
    scanf("%I64d%I64d",&n,&k);
    for(LL i=1;i<=n;i++)
    scanf("%I64d%I64d%I64d",&a[i].x,&a[i].r,&a[i].f);
    sort(a+1,a+n+1,cmp);
    for(LL i=1;i<=n;i++)
    {
    for(LL j=max(1ll,a[i].f-k);j<=a[i].f+k;j++)
    ans+=upper_bound(d[j].begin(),d[j].end(),a[i].x+a[i].r)-
    lower_bound(d[j].begin(),d[j].end(),a[i].x-a[i].r);
    d[a[i].f].insert(upper_bound(d[a[i].f].begin(),d[a[i].f].end(),a[i].x),a[i].x);
    }
    printf("%I64d\n",ans);
