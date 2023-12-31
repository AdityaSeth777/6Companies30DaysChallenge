class Solution 
{
   #define ll long long 
    public:
    long long gcd(long long int a, long long int b)
    {
        if (b == 0)
            return a;
    
        return gcd(b, a % b);
    }
    
    long long lcm(int a, int b) 
    {
        return (a / gcd(a, b)) * b;
    }
    //Aditya Seth.
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) 
    {
        ll low=0,high=1e18;
        ll ans=0;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            ll a=mid-mid/(ll)div1;
            ll b=mid-mid/(ll)div2;
            ll c=mid-mid/div1-mid/div2+mid/(lcm(div1,div2));
            if(a>=cnt1 and b>=cnt2 and (a+b-c)>=(cnt1+cnt2))
            {
                ans=mid;
                high=mid-1;

            }
            else
            {
                low=mid+1;
            }

        }
        return ans;    
    }
};