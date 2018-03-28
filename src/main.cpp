#include<iostream>
#include<limits>
#include "hash.hpp"
#define NO_SWITCH 7 
using namespace std;
int main()
{
    HashTable hashes;
    int t = 0,value;
    while(t!=NO_SWITCH)
    {
        cout<<"1. Add value."<<endl;
        cout<<"2. Show content"<<endl;
        cout<<"3. Delete."<<endl;
        cout<<"4. Find."<<endl;
        cout<<"5. Move hashes forward by 1."<<endl;
        cout<<"6. Move hashes backward by 1."<<endl;
        cout<<"7. Exit."<<endl;
        cin>>t;
        switch(t)
        {
            case 1:
                {
                    while(cout<<"Enter value"<<endl && !(cin>>value))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"Invalid input; please re-enter.\n";
                    }
                    hashes.add(value);
                    break;
                }
            case 2:
                {
                    cout<<hashes<<endl;
                    break;
                }
            case 3:
                {
                    while(cout<<"Enter value"<<endl && !(cin>>value))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"Invalid input; please re-enter.\n";
                    }
                    if(hashes.remove(value))
                        cout<<value<<" removed succesfully."<<endl;
                    else
                        cout<<value<<" cannot be removed."<<endl;
                    break;
                }
            case 4:
                {
                    while(cout<<"Enter value"<<endl && !(cin>>value))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout<<"Invalid input; please re-enter.\n";
                    }
                    if(hashes.search(value))
                    {
                        cout<<value<<" found."<<endl;
                    }
                    else
                    {
                        cout<<value<<" not found."<<endl;
                    }
                    break;
                }
            case 5:
                {
                    ++hashes;
                    cout<<"Hashes moved."<<endl;
                    break;
                }
            case 6:
                {
                    --hashes;
                    cout<<"Hashes moved."<<endl;
                    break;
                }
            default:
                {
                    break;
                }
        }
    }
    return 0;
}
