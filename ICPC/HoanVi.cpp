#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s){
    stringstream ss(s.substr(0, s.length()-1));
    vector<string> res;
    string tmp;
    ss >> tmp;
    while (ss >> tmp){
        if (tmp!="=")
            res.push_back(tmp);
    }
    return res;  
}

pair<string, string> query(string s){
    int i = s.length() - 1;
    while (i >= 0 && (!isdigit(s[i]) || isdigit(s[i-1]))) i--;
    string str = s.substr(i, s.length()-i);
    int idx = str.find('~');
    return {str.substr(0, idx), str.substr(idx+1, str.length()-idx)};
}

map<string, string> process(string s){
    map<string, string> res;
    vector<string> v1 = split(s);
    for (int i = 0; i<v1.size(); i+=2){
        res[v1[i]] = v1[i+1].substr(1, v1[i+1].length()-2);
    }
    return res;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    cin.ignore();
    vector<map<string, string>> vec;
    for (int i=0; i<N/2; i++){
        string s;
        getline(cin, s);
        map<string, string> v1;
        v1 = process(s);
        vec.push_back(v1);
    }

    for (int i= 0; i<N/2; i++){
        string tmp;
        getline(cin, tmp);
    }

    vector<pair<string, string>> vecq;
    for (int i = 0; i<Q; i++){
        string q;
        getline(cin, q);
        vecq.push_back(query(q));
    }
    for (auto i : vecq){
        int id = stoi(i.first);
        if (vec[id-1].count(i.second))
            cout << vec[id-1][i.second] << endl;
        else cout << "Not Found!" << endl;
    }
    return 0;
}