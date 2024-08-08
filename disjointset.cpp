#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> siunion_by_size,size,parent;

public:
    DisjointSet(int n){
        siunion_by_size.resize(n+1,1);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int find_ultimate_parent(int node){
        if(node==parent[node]) return node;
        return parent[node]=find_ultimate_parent(parent[node]);
    }
    void union_by_rank(int u,int v){
        int ulp_u=find_ultimate_parent(u);
        int ulp_v=find_ultimate_parent(v);
        if(ulp_u==ulp_v) return;
        if(siunion_by_size[ulp_u]<siunion_by_size[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(siunion_by_size[ulp_u]>siunion_by_size[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            siunion_by_size[ulp_u]++;
        }
    }
    void union_by_size(int u,int v){
        int ulp_u=find_ultimate_parent(u);
        int ulp_v=find_ultimate_parent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.union_by_size(1,2);
    ds.union_by_size(2,4);
    ds.union_by_size(3,5);
    ds.union_by_size(5,6);
    ds.union_by_size(6,7);
    if(ds.find_ultimate_parent(7)==ds.find_ultimate_parent(2)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    ds.union_by_size(7,2);
    if(ds.find_ultimate_parent(7)==ds.find_ultimate_parent(2)){
        cout<<"same"<<endl;
    }else{
        cout<<"not same"<<endl;
    }
    return 0;
}
