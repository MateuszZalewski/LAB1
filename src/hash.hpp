#include<vector>
#include<list>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

class HashTable{

    private:

    list<vector<int>> table;
    int sizeOfHashTable;
    int moved=0;
    auto getIterator(int n)
    {
        auto it = std::next(table.begin(),(n+moved)%sizeOfHashTable);
        return it;
    }

    public:

    HashTable(int size=100)
    {
        sizeOfHashTable=size;
        for(int i=0;i<size;i++)
        {
            vector<int> v;
            table.push_back(v);
        }
    }
    ~HashTable()
    {
        table.clear();
    }
    void add(int value)
    {
        auto it = getIterator(value);
        if(search(value))
        {
            cout<<"Error! Value already in Hash Table."<<endl;
            return;
        }
        else
        {
            it->push_back(value);
            cout<<"Value added to Hash Table"<<endl;
            return;
        }
    }
    bool remove(int value)
    {
        if(search(value))
        {
            auto it = getIterator(value);
            auto to = std::find((*it).begin(),(*it).end(),value);
            std::swap(*to,(*it).back());
            (*it).pop_back();
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool search(int value)
    {
        auto it = getIterator(value);
        for(auto k:*it)
        {
            if(k==value)
            {
                return 1;
            }
        }
        return 0;
    }
    friend ostream& operator<<(ostream& out,HashTable hash)
    {
        for(auto v = hash.table.begin(),end = hash.table.end();v!=end;++v)
        {
            for(auto i = (*v).begin(),end=(*v).end();i!=end;++i)
            {
                out<<(*i)<<" "<<endl;
            }
        }
        return out;
    }
    HashTable& operator++()
    {
        auto v=table.end();
        auto it1=--v--;
        for(auto end = table.begin();;--v)
        {
            std::iter_swap(it1,v);
            it1=v;
            if(v==end)
                break;
        }
        moved= (moved+1)==sizeOfHashTable ? 0 : (moved+1);
    }
    HashTable& operator--()
    {
        auto it1=table.begin();
        for(auto v = it1,end = table.end();v!=end;++v)
        {
            std::iter_swap(it1,v);
            it1=v;
        }
        moved= (moved-1)==-1 ? (sizeOfHashTable-1) : (moved-1);
    }
};
