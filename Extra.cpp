#include "Extra.h"

bool Extra::isNumber(string s){
   for(int i = 0; i < s.length(); i++){
       if (isdigit(s[i]) == false){
           return false;
       }
   }
   if(s.length() == 0){
       return false;
   }
   return true;
}


