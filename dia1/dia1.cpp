//Program to get lines from a file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <utility>
using namespace std;

// for string delimiter
std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (s.substr (pos_start));
    return res;
}

int part1(){
    string line;
    ifstream myfile("bigboy.txt");
    vector<int> list1;
    vector<int> list2;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            vector<string> parts = split(line, "   ");
            list1.push_back(stoi(parts[0]));
            list2.push_back(stoi(parts[1]));
        }
        myfile.close();
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int res = 0;
    for (int i = 0; i < list1.size(); i++) {
        cout << list1[i] << " " << list2[i] << endl;
        res += abs(list1[i] - list2[i]);
    }
    cout << res << endl;
    return 0;
}

int part2(){
    ifstream myfile("bigboy.txt");
    vector<int> list1;
    vector<int> list2;
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    if (myfile.is_open())
    {
        int a,b;
        while (myfile >> a >> b)
        {
            if (map1.find(a) == map1.end()) {
                map1[a] = 1;
            } else {
                map1[a]++;
            }
            if (map2.find(b) == map2.end()) {
                map2[b] = 1;
            } else {
                map2[b]++;
            }
        }
        myfile.close();
    }
    //Iterate through map
    u_int64_t result = 0;
    for(auto it = map1.begin(); it != map1.end(); ++it) {
        if(map2.find(it->first) != map2.end()){
            result += it->first * map1.at(it->first) * map2.at(it->first);
        }
    }

    cout << result << endl;
    return 0;
}

int part2bigboy(){
    string line;
    ifstream myfile("bigboy.txt");
    vector<int> list1;
    vector<int> list2;
    if (myfile.is_open())
    {
        int a,b;
        while (myfile >> a >> b)
        {
            list1.push_back(a);
            list2.push_back(b);
        }
        myfile.close();
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int list1ptr = 0;
    int list2ptr = 0;
    long res = 0;
    while(list1ptr < list1.size() && list2ptr < list2.size()){
        int num1 = list1[list1ptr];
        int num2 = list2[list2ptr];
        if(num1 == num2){
            list2ptr++;
            res += num1;
        }
        else if(num1 < num2){
            list1ptr++;
        }
        else{
            list2ptr++;
        }

    }
    cout << res << endl;
    return 0;
}

int main()
{
    //part1();
    //part2();
    part2bigboy();
    return 0;
}