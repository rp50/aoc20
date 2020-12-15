#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool contains_shiny_gold(string bag_color, map<string, map<string,int>> bags){
    map<string, int> bags_contained = bags[bag_color];
    bool contained = false;
    for(auto cur_bag = bags_contained.begin(); cur_bag != bags_contained.end() && !contained; cur_bag++){
        if(cur_bag->first == "shiny gold"){
            contained = true;
        }
        else{
            contained = contains_shiny_gold(cur_bag->first, bags);
        }
    }
    return contained;
}

int part1(map<string, map<string, int>> bags){
    int total = 0;
    for(auto cur_bag = bags.begin(); cur_bag != bags.end(); cur_bag++){
        if(contains_shiny_gold(cur_bag->first, bags)){
            total++;
        }
    }
    return total;
}

int num_bags_contained(string bag_color, map<string,map<string, int>> bags){
    int num_bags = 0;
    map<string, int> bags_contained = bags[bag_color];
    for(auto cur_bag = bags_contained.begin(); cur_bag != bags_contained.end(); cur_bag++){
        cout << cur_bag->first << endl;
        num_bags = num_bags + cur_bag->second + ((cur_bag->second)*(num_bags_contained(cur_bag->first, bags)));
    }
    return num_bags;
}

int part2(map<string, map<string, int>> bags){
    int total = num_bags_contained("shiny gold", bags);
    return total;
}

void find_held(string str, map<string, int> &bags_held){
    int num_of_bags = stoi(str, 0, 10);
    string color = str.substr(2, str.find(" bag")-2);
    bags_held[color] = num_of_bags;
    if(str.find(",") != -1 && str.find(",") < str.find(".")){
        find_held(str.substr(str.find(",")+2), bags_held);
    }
    
}

int main(){
    ifstream input_file("inputs/d7.txt");
    map<string, map<string, int>> bags; // format for the input. Outer map is the color of the bag, second map is the bags that it holds, as well as the amt.
    string curr;
    while(getline(input_file, curr)){
        int start_pos = 0, end_pos = curr.find(" bags");
        string color = curr.substr(start_pos, end_pos);
        map<string, int> bags_held;
        if(curr.find("no") == -1){
            find_held(curr.substr(curr.find("contain")+8), bags_held);
        }
        bags.emplace(color, bags_held);
    }
    cout << part1(bags) << endl << part2(bags) << endl;
    input_file.close();
}
