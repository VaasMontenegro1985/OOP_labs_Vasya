#include <iostream>


bool Check(std::string s){
    int counter = 0;
    if (s.size() > 100){
        std::cout << " String too long" << std::endl;
        return false;
    }
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(') counter++;
        else if (s[i] == ')'){
            counter--;
            if (counter < 0) return false;
        }
        if ((s[i] != '(') && (s[i] != ')')) return false;
    }
    if (counter != 0) return false;
    else return true;
}
