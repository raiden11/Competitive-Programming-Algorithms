//unordered map

#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using tr1::unordered_map;
typedef unordered_map<string, int> umap;
int main()
{
    umap a;
    string string_var;
    cin>>string_var;
    int int_var;
    cin>>int_var;
    a[string_var] = int_var;
    a.insert(umap::value_type("ddd",4));
    a.insert(umap::value_type("dddaaaa",5));
    umap::iterator it = a.find(string_var);
    if(it != a.end())
        cout<<"key:"<<it->first<<" has:"<<it->second<<endl;
    else
        cout<<"not found"<<endl;
    for(umap::const_iterator it = a.begin();it != a.end();++it)
        cout<<"["<<it->first<<","<<it->second<<"]"<<endl;
    return 0;
}
