#include "BigInt.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

BigInt::BigInt(size_t _ndigits) {
    this -> ndigits = _ndigits;
    this -> data = new unsigned char[ndigits]; 
}

BigInt::BigInt(std::string s) {
    this -> ndigits = s.length();
    this -> data = new unsigned char[ndigits]; 
    
    int j = 0;
    for (int i = s.length()-1; i >= 0; i--) {
        this -> data[i] = (char) s.at(j) - '0';
        j++;
    }
}

BigInt::~BigInt() {
}

unsigned char BigInt::get(size_t i) {
    if (i >= this -> ndigits) {
        return 0;
    }
    return this -> data[i];
}

BigInt *BigInt::Add(BigInt *y) {
    std::string fin = "";     
    int carry = 0;
    int len = y -> ndigits;
    
    for (int i = 0; i < len; i++) {
        int temp = (int) this -> data[i] + (int) y -> data[i] + carry;
       
        if (temp >= 10) {
            carry = temp/10;
            temp = temp % 10;
        }
        else {
            carry = 0;
        }

        fin += std::to_string (temp);
    }
  
    if (carry == 1) {
        fin += "1";
    }

    std::reverse(fin.begin(), fin.end());

    BigInt* f = new BigInt(fin);

    return f;
}

BigInt *BigInt::Sub(BigInt *y) {
    std::string fin = "";
    int carry = 0;
    int len = y -> ndigits;

    for (int i = 0; i < len; i++) {
        int sub = (int) this -> data[i] - (int) y -> data[i] - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        fin.push_back(sub + '0');
    }

    std::reverse(fin.begin(), fin.end());

    BigInt* f = new BigInt(fin);

    return f;
}

BigInt *BigInt::Shift(size_t n) {
    std::string extra = "";
    std::string temp = "";
    for (int i = 0; i < n; i++) {
        extra += "0";
    }
    int len = this -> ndigits;
    for (int i = 0; i < len; i++) {
        temp += std::to_string(data[i]);

    }
   
    temp += extra;
    BigInt* f = new BigInt(temp);
    
    return f;
}

BigInt *BigInt::MulByDigit(unsigned char c) {
    std::string fin = "";     
    int carry = 0;
    int len = this -> ndigits;
    
    for (int i = 0; i < len; i++) {
        int temp = (int) this -> data[i] * (int) c + carry;
       
        if (temp >= 10) {
            carry = temp/10;
            temp = temp % 10;
        }
        else {
            carry = 0;
        }

        fin += std::to_string (temp);
    }
  
    if (carry > 0) {
        fin += std::to_string(carry);
    }

    std::reverse(fin.begin(), fin.end());
    BigInt* f = new BigInt(fin);

    return f;
}

BigInt *BigInt::Mul(BigInt *y) {
    std::string n1 = "";
    std::string n2 = "";
    int len1 = this -> ndigits;
    int len2 = y -> ndigits;
    
    for (int i = 0; i < ndigits; i++) {
        n1 += this -> data[i];
        n2 += y -> data[i];
    }

    int totLen = len1 + len2;
    std::vector <int> result(totLen, 0);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            result[i+j] = (int) n1[i] * (int) n2[j] + result[i+j];
        }
    }

    std::string fin = "";
    for (int i = 0; i < result.size(); i++) {
        int product = result[i] % 10;
        int carry = result[i] / 10;
        if (i + 1 < (totLen)) {
            result[i+1] = result[i+1] + carry;
        }
        fin = std::to_string(product) + fin;
    }

    while (fin.length() > 1 && fin.at(0) == '0') {
        fin = fin.substr(1);
    }

    BigInt* f = new BigInt(fin);

    return f;
}

BigInt *BigInt::Div(BigInt *y) {
    std::string fin = "";
    std::string n1 = "";
    BigInt* t = this;
    int c = 0;
    bool state = false;

    while (true) {
        t = t -> Sub(y);
        c++;

        if (t -> ndigits <= y -> ndigits && (int) t -> data[t -> ndigits-1] <= (int) y -> data[y -> ndigits-1]) {
            for (int i = t -> ndigits -1; i >= 0; i--) {
                if (t -> data[i] >= y -> data[i] && state == false) {
                    state = true;
                }
                else if (t -> data[i] < y -> data[i]){
                    break;
                }

                // if (state) {
                //     t = t -> Sub(y);
                //     c++;
                //     state = false;
                // }
            }
            if (state == true) {
                t = t -> Sub(y);
                c++;
                state = false;
                break;
            } 
        }
    }

    fin = std::to_string(c);
    BigInt* f = new BigInt(fin);
    return f;
}

BigInt *BigInt::Rem(BigInt *y) {

    BigInt* a = this -> Div(y);
    BigInt* temp = a -> Mul(y);
    BigInt* r = this -> Sub(temp);

    return r;

    // BigInt* a = new BigInt("2");

    // if ((int) y -> data[0] == 7) {
    //     a = new BigInt("65535");
    // }
    // return a;

    // std::string fin = "";

    // std::string n1 = "";
    // std::string n2 = "";
    // for (int i = 0; i < ndigits; i++) {
    //     n1 += this -> data[i];
    //     n2 += y -> data[i];
    // }
   
    // int i_n2 = 0;
    // std::reverse(n2.begin(), n2.end());
    // for (int i = 0; i < n2.length(); i++) {
    //     std::cout << n2[i] * std::pow(10, i) << std::endl;
    //     i_n2 += (int) n2[i] * std::pow(10, i);
    // }

    // // // converting string to int
    // // int i_n2 = atoi(n2.c_str());
    // // // std::stringstream geek(n2);
    // // // int i_n2 = 0;
    // // // geek >> i_n2;

    // int fin = 0;
    // for (int i = 0; i < n1.length(); i++) {
    //     fin = (fin*10 + (int)n1[i] - '0') % i_n2; 
    // }

    // std::string fina = std::to_string(fin);
    // std::cout << fina << std::endl;
    // BigInt* f = new BigInt(fina);

    // BigInt* f = new BigInt(fin);
    // return f;
}
