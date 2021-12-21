#include<bits/stdc++.h>
using namespace std;
int n;
int arr[200005];
//double single[200005];
double couple[200005];
pair<double,int> single[200005];
double sum;
//bool cmp(pair<double,int>)
int main()
{
    cin.sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    for(int i=1;i<=n+1;i++)
    {
        sum+=sqrt( 1+ (arr[i]-arr[i-1])*((arr[i]-arr[i-1])) );
    }
    for(int i=1;i<=n;i++)
    {
        single[i].second=i;
        single[i].first = sqrt(1+ (arr[i]-arr[i-1])*(arr[i]-arr[i-1]) ) + sqrt(1+ (arr[i]-arr[i+1])*(arr[i]-arr[i+1]) ) -sqrt(4+ (arr[i+1]-arr[i-1])*(arr[i+1]-arr[i-1]) );
    }
    for(int i=1;i<n;i++)
    {
        couple[i]=sqrt( 1+ (arr[i]-arr[i-1])*(arr[i]-arr[i-1]) ) + sqrt( 1 + (arr[i]-arr[i+1])*(arr[i]-arr[i+1]) ) + sqrt( 1 + (arr[i+1]-arr[i+2])*(arr[i+1]-arr[i+2]) ) - sqrt( 9 + (arr[i-1]-arr[i+2])*(arr[i-1]-arr[i+2])  );
    }
//    cout << "deng : " << couple[1] << endl;
//    cout << endl;
    sort(single+1,single+1+n);
    sort(couple+1,couple+n);
    if(n>2)
    {
        double tmp;
        if( abs(single[n].second - single[n-1].second ) !=1 )
        {
            tmp=single[n].first+single[n-1].first;
        }
        else if( abs(single[n].second - single[n-2].second ) !=1 )
        {
            tmp=single[n].first+single[n-2].first;
        }
        else
        {
            tmp=single[n].first+single[n-3].first;
            tmp=max(tmp, single[n-1].first+single[n-2].first );
        }
        printf("%.8lf",sum-tmp);
    }
    else
    {
        printf("%.8lf",sum-couple[1]);
    }
    return 0;
}
