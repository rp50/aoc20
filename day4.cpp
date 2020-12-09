#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool isAlNum(string s){
    bool valid = true;
    for(int i = 0; i < s.length() && valid == true; i++){
        valid = isalnum(s[i]);
    }
    return valid;
}

bool isNum(string s){
    bool valid = true;
    for(int i = 0; i < s.length() && valid == true; i++){
        valid = isdigit(s[i]);
    }
    return valid;
}

bool hclCheck(string value){
    bool valid = (value.length() == 7 && value[0] == '#' && isAlNum(value.substr(1)));
    return valid;
}

bool hgtCheck(string value){
    bool valid = false;
    if(value.find("cm") != -1){
        int eov = value.find("cm");
        int val_hgt = stoi(value.substr(0, eov));
        valid = (val_hgt >= 150 && val_hgt <= 193);
    }
    else if(value.find("in") != -1){
        int eov = value.find("cm");
        int val_hgt = stoi(value.substr(0, eov));
        valid = (val_hgt >= 59 && val_hgt <= 76);
    }
    return valid;
}

bool eclCheck(string value){
    bool valid = false;
    int num_ecl = 0;
    string ecl[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    for(int i = 0; i < 7 && num_ecl < 2; i++){
        if(value.find(ecl[i]) != -1){
            num_ecl++;
        }
    }
    valid = (num_ecl == 1);
    return valid;
}

bool pidCheck(string value){
    bool valid = (value.length() == 9 && isNum(value));    
    return valid;
}

bool validator(string input){
    bool valid = true;
    stringstream reader(input);
    string expected_fields[7] = {"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};  
    for(int i = 0; i < 7 && valid; i++){
        int loc_of_field = input.find(expected_fields[i]);
        if(loc_of_field == -1){
            valid = false;
        }
        else{
            int pos_of_value = loc_of_field+expected_fields[i].length();
            int len_of_value = (input.substr(pos_of_value).find(" ")); 
            string value = input.substr(pos_of_value, len_of_value);
            switch(i){
                case 0:
                    valid = (stoi(value) <= 2002 && stoi(value) >= 1920);
                    break;
                case 1:
                    valid = (stoi(value) <= 2020 && stoi(value) >= 2010);
                    break;
                case 2: 
                    valid = (stoi(value) <= 2030 && stoi(value) >= 2020);
                    break;
                case 3:
                    valid = hgtCheck(value);
                    break;
                case 4:
                    valid = hclCheck(value);
                    break;
                case 5:
                    valid = eclCheck(value);
                    break;
                case 6:
                    valid = pidCheck(value);
                    break;
            }
        }
    }
    return valid;
}

int part2(vector<string> input){
    int num_valid = 0;
    for(int i = 0; i < input.size(); i++){
        if(validator(input[i])){
            num_valid++;
        }
    }
   return num_valid;
}

int part1(vector<string> input){
    string expected_fields[7] = {"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};
    int num_valid = 0;
    for(int i = 0; i < input.size(); i++){
        bool expected_fields_present = true;
        for(int j = 0; j < 7 && expected_fields_present; j++){
            if(input[i].find(expected_fields[j]) == -1){
                expected_fields_present = false;
            }
        }
        if(expected_fields_present){
            num_valid++;
        }
    }
    return num_valid;
}

int main(){
    ifstream input_file("inputs/d4.txt");
    vector<string> input;
    input.push_back("");
    string curr;
    int i = 0;
    while(getline(input_file, curr)){
        if(curr != ""){
            input.at(i)+= (curr + " ");
        }
        else{
            input.push_back("");
            i++;
        }
    }
    cout << part1(input) << endl << part2(input) << endl;
    input_file.close();
}
