#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<string,int> m; //creation


    pair<string,int> p = make_pair("bhuker",3);
    m.insert(p);

    pair<string,int> p1("Arzoo",2);
    m.insert(p1);

    m["my"] = 1;

    m["my"] = 2;

    cout << m["my"] << endl;
    cout << m.at("bhuker") << endl;
    cout << m["Arzoo"] << endl;

    cout << m["unknownkey"] << endl;
    cout << m.at("unknownkey") << endl;

    cout << m.size() << endl;

    //to check presence
    cout << m.count("xyz") << endl;
    cout << m.count("bhuker") << endl;

    //erase
    cout << m.erase("bhuker") << endl;
    cout << m.size() << endl;

    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end())
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }

    return 0;
}
