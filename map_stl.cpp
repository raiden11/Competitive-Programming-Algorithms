#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using tr1::unordered_map;
typedef unordered_map<int,char> umap;
int main()
{
    umap a;
    int ab;
    int int_var;
    cin>>int_var;
    cin>>ab;
    a.insert(umap::value_type(ab,'y'));
    a.insert(umap::value_type(5,'y'));
    umap::iterator it = a.find(int_var);
    if(it != a.end())
        cout<<"key:"<<it->first<<" is"<<it->second<<endl;
    else
        cout<<"not found"<<endl;
    for(umap::const_iterator it = a.begin();it != a.end();++it)
        cout<<"["<<it->first<<" "<<it->second<<"]"<<endl;
    return 0;
}

