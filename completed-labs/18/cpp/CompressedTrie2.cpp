#include "Trie.hpp"
#include "CompressedTrie.hpp"
#include <iostream>
#include <typeinfo>

CompressedTrie::CompressedTrie() {
    this -> children = std::map<std::string, CompressedTrie *>();
}

CompressedTrie *CompressedTrie::compressTrie(Trie* t) {
    if (t -> children == NULL) {
        return NULL;
    }
    
    CompressedTrie* temp = new CompressedTrie();
    // CompressedTrie* other = new CompressedTrie();
    // std::vector<std::string> chars = other -> addStr(t, NULL);

    // for (int i = 0; i < chars.size(); i++) {
    //     temp -> insert(chars.at(i) + "{");
    // }
    
    std::string jokes;
    for (int i = 0; i < 27; i++) {
        if (t -> children[i] != NULL) {
            std::string prefix;
            //std::to_string((char) i + 'a');
            char c = i + 'a';
            prefix += c;
            jokes += c;
            // std::cout << c << std::endl;
            Trie* child = t -> children[i]; 
            int nullNum;
            
            do {
                nullNum = 0;
                int tempj;
                for (int j = 0; j < 27; j++) {
                    if (child -> children[j] != NULL) {
                        tempj = j;
                        nullNum++;
                    }
                }
                if (nullNum == 1) {
                    char z = tempj + 'a';
                    jokes += z;
                    // std::cout << z << std::endl;
                    prefix += z;
                    // prefix += std::to_string((char) tempj + 'a');
                    child = child -> children[tempj];
                }
            } while (nullNum == 1);
            

            temp -> children.insert(std::pair<std::string, CompressedTrie*> (prefix, compressTrie(child)));
        }
    }

    return temp;
}

bool CompressedTrie::query(std::string s) {
    CompressedTrie* temp = this;
    if (!(endsWith(s, "{"))) {
        s += "{";
    }

    std::string f = "";
    std::map<std::string, CompressedTrie*>::iterator it;
    bool found = false;
    for (int i = 0; i < s.length(); i++) {
        f += s[i];

        // if (it != temp -> children.end()) {
        for (int j = 0; j < 27; j++) {
            if (temp -> children.count(f) > 0) {
                temp = temp -> children[f];
                f = "";
            }
        }
    }

    if (f.length() == 0) {
        return true;
    }
    return false;
}

void CompressedTrie::insert(std::string s) {
//     std::string a = std::to_string(s[0]);
//     std::string b = prefix(a);
// 
//     if (b.empty()) {
//         while (prefix(b).empty()) {
//             a += s[a.length()];
// 
//             if (s == a){
//                 return;
//             }
//         }
// 
//         std::string c = s.substr(0, a.length()-1);
//         std::string d = s.substr(a.length()-1);
// 
//         if (c == b) {
//             this -> children.insert(std::pair<std::string , CompressedTrie*> (b, new CompressedTrie())); 
//         }
//         else {
//             CompressedTrie* e = children.find(b) -> second;
//             CompressedTrie* f = new CompressedTrie();
//             children.erase(b);
//             children.insert(std::pair<std::string, CompressedTrie*> (c, f));
//             std::string g = b.substr(a.length()-1);
//             f -> children.insert(std::pair<std::string, CompressedTrie*> (g, e));
//             f -> children.insert(std::pair<std::string, CompressedTrie*> (d, f));
//         }
//     }
//     else {
//         this -> children.insert(std::pair<std::string, CompressedTrie*> (s, new CompressedTrie()));
//     }
// 
}

std::string CompressedTrie::prefix(std::string p){
    std::vector<std::string> v;
    for (std::map<std::string, CompressedTrie *>::iterator it = children.begin(); it != children.end(); it++) {
        v.push_back(it -> first);
    }

    for (auto x : v) {
        if (x.find(p) == 0) {
            return x;
        } 
    }
    return NULL;
}

bool CompressedTrie::endsWith(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } 
    else {
        return false;
    }
}

std::vector<std::string> CompressedTrie::addStr(Trie* t, std::string s) {
    std::vector<std::string> temp;

    for (int i = 0; i < 27; i++) {
        if (t -> children[i] != NULL) {
            std::string n = "";
            if (s.empty()) {
                n = std::to_string((char) i + 'a');
            }
            else {
                n = s + std::to_string((char) i + 'a'); 
            }
            std::vector<std::string> temp2 = addStr(t -> children[i], n);
            temp.insert(std::end(temp), std::begin(addStr(t -> children[i], n)), std::end(addStr(t -> children[i], n)));
            //temp.insert(temp.end(), temp2.begin(), temp2.end());
        }
    }

    if (t -> children[26] != NULL) {
        temp.push_back(s); 
    }
    
    return temp;
}
