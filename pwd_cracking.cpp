#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
///made by d4rkn19ht
using namespace std;
typedef long long ll;
ll MOD;
typedef pair<ll,ll> pir;
#define fi first
#define se second

ll bin_to_num(string &a)
{
    ll num = 0;
    for(auto i:a)
    {
        num = (num<<1) + (i - '0');
    }
    return num;
}
ll char32_to_int(char a)
{
    if ('a' <= a && a<='z')
    {
        return a - 'a';
    }
    else
    {
        return a - '0' + 26;
    }
}
char int_to_char32(ll a)
{
    if (a>=26)  return char(a - 26 + '0');
    else return char(a + 'a');
}


bool valid_char(char a)
{
    if ('a'<=a && a<='z') return true;
    if ('0'<=a && a<='5') return true;
    return false;
}
ll string_to_num(string a)
{
    ll num = 0;
    for(auto i:a)
    {
        for(int j = 4; j>=0; --j)
        {
            num = num<<1;
            if (char32_to_int(i)&(1<<j)) num += 1;
        }
    }
    return num;
}
string num_to_string(ll a,int t)
{
    string b = "";
    _for(i,0,t/5)
    {
        int s = 0;
        _for(j,0,5)
        {
            s = s | ((a&1)<<j);
            a >>=1;
        }
        b += int_to_char32(s);
    }
    reverse(b.begin(), b.end());
    return b;
}
void nhap_du_lieu(vector<ll>& a)
{
 ///   ifstream fi;
///    fi.open("data.inp");
    freopen("data.inp","r",stdin);
    int N;
    cin>>N;
    N = N;
    _for(i,0,N)
    {
        string bin;
        cin>>bin;
        ll num = bin_to_num(bin);
        a.push_back(num);
    }

}

void snp(int pos, ll sum,ll state, vector<ll>& numset, vector<pir>& gen)
{
    if (pos >= int(numset.size()))
        gen.push_back(pir(sum, state));
    else
    {
        snp(pos + 1, sum,state, numset, gen);
        snp(pos + 1, (sum + numset[pos])%MOD,state | (ll(1) << pos), numset, gen);
    }
}
ll encoding_password(string password, vector<ll>& numset)
{
    ll num = 0;
    ll state = string_to_num(password);
    int N = numset.size();
    _for(i,0,N)
    {
        if (state & (ll(1)<<i))
            num += numset[i];
        num %= MOD;
    }
    num %= MOD;
    return num;
}
bool checking(string password, string encoded_password, vector<ll>& numset)
{
    if (num_to_string(encoding_password(password, numset), int(numset.size())) == encoded_password) return true;
    else return false;
}
void password_crzcking(string encoded_pass, vector<ll>& numset)
{
    /**
    cout<<"DEBUGGING MSG: bbbbbbbb = "<<string_to_num("bbbbbbbb")<<"\n";
    cout<<"DEBUGGING MSG: "<<string_to_num(encoded_pass)<<"\n";
    cout<<"DEBUGGING MSG: "<<encoding_password("bbbbbbbb",numset)<<"\n";
    cout<<"DEBUGGING MSG: h(\"bbbbbbbb\") = "<<num_to_string(encoding_password("bbbbbbbb",numset), int(numset.size()))<<"\n";
    */
    /// change password from string to number
    ll enc_num = string_to_num(encoded_pass);

    MOD = ll(1) << int(numset.size());/// create MOD

    vector<ll> numset1, numset2;
    /// divide set into 2 equal-length sets
    int len = int(numset.size());
    _for(i,0,len/2)
        numset1.push_back(numset[i]);

    _for(i,len/2, len)
        numset2.push_back(numset[i]);

    /// generate 2^(len/2) subset sum
    vector<pir> gen1,gen2;
    snp(0, 0, 0,numset1, gen1);
    snp(0, 0, 0,numset2, gen2);

    ///sorting gen2
    sort(gen2.begin(), gen2.end());

    /// checking if password is valid
    if (len != int(encoded_pass.size())*5)
    {
        cout<<"Invalid password!!!!\n";
        return ;
    }
    for(auto i:encoded_pass)
        if (!valid_char(i))
        {
            cout<<"Invalid password!!!!\n";
            return ;
        }

    /// cracking
    vector<string> found_password;
    for(auto i:gen1)
    {
        ll p1 = (enc_num + MOD - i.fi)%MOD;
        int pos = lower_bound(gen2.begin(), gen2.end(), pir(p1, 0)) - gen2.begin();
        if (pos == int(gen2.size())) continue;
        if ((gen2[pos].fi + i.fi)%MOD == enc_num) /// if found a way
        {
            ll state = (gen2[pos].se << int(numset2.size())) | i.se;
            string found_pass = num_to_string(state, int(numset.size()));
       ///     cout<<"Found password:"<<found_pass<<"\n";
            if (checking(found_pass, encoded_pass, numset))
            {
      ///          cout<<"Correct password!!!!\n";
     ///           cout<<"Recoverd password: "<<found_pass<<"\n";
      ///          return;
                    found_password.push_back(found_pass);
            }
      ///      else cout<<"Not right password!!!!\n";
        }
    }
    sort(found_password.begin(), found_password.end());
    for(auto i : found_password) cout<<i<<"\n";
  ///  cout<<"NOT FOUND!!\n";
}
int main()
{
    ios_base::sync_with_stdio();
    cout.tie();
    cin.tie();
    vector<ll> numset;
    nhap_du_lieu(numset);
 ///   cout<<"Finished reading data!!!\n";
    string enc_pass = "";
    MOD = ll(1) << int(numset.size());
    reverse(numset.begin(), numset.end());
 ///   cout<<"Nhap password de khoi phuc:\n";
    cin>>enc_pass;
    password_crzcking(enc_pass, numset);
    return 0;
}
