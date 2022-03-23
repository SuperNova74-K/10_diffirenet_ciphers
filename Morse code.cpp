//
// Created by walid on 3/17/2022.
//

/*
* Purpose     : Morse code translator
* Author      : Khaled Waleed Salah / ID : 20210127
* Institution : FCAI - CU
* Date        : 3/14/2022
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<string>
#include "MORSE CODE.h"

using namespace std;


map<char, string> dictionary;

void clear(){
   system("cls");
}

string encrypt(string in){
   string out;
   bool flag;
   for (int i = 0; i < in.size(); ++i) {
       flag = false;
       for (auto &it : dictionary) {
           if(it.first == in[i]){
               out += dictionary[in[i]];
               out += " ";
               flag = true;
               break;
           }
       }
       if(!flag){
           return "-1";
       }
   }
   return out;
}


string decrypt(string in){
   string out;
   // for every character
   for (int i = 0; i < in.size(); ++i) {
       //if character is equal to one space
       if(in[i] == ' '){
           if(in[i+1] == ' ') {
               out += ' ';
               i++;
           }
       }
           // if that is not the case then
       else{
           int loop_over_one_character = 0;
           string character = "";
           while( i + loop_over_one_character < in.size() && in[i+loop_over_one_character] != ' '){
               character += in[i + loop_over_one_character];
               loop_over_one_character++;
           }
           i += loop_over_one_character;

           bool should_we_continue;
           bool flag = false;
           for (auto &it : dictionary){
               if(it.second == character){
                   out+= it.first;
                   flag = true;
                   break;
               }
           }
           if(!flag){
               return "_";
           }
       }
   }
   return out;
}

string string_to_upper(string in){
   string out;
   for(auto i : in){
       if(i >= 'a' && i <= 'z'){
           out += char(i - 32);
       }else{
           out += i;
       }
   }
   return out;
}


int main_of_morse(){

   dictionary['A'] = "*_"  ;  dictionary['B'] = "_***";  dictionary['C'] = "_*_*"  ;
   dictionary['D'] = "_**" ;  dictionary['E'] = "*"   ;  dictionary['F'] = "**_*"  ;
   dictionary['G'] = "__*" ;  dictionary['H'] = "****";  dictionary['I'] = "**"    ;
   dictionary['J'] = "*___";  dictionary['K'] = "_*_" ;  dictionary['L'] = "*_**"  ;
   dictionary['M'] = "__"  ;  dictionary['N'] = "_*"  ;  dictionary['O'] = "___"   ;
   dictionary['P'] = "*__*";  dictionary['Q'] = "__*_";  dictionary['R'] = "*_*"   ;
   dictionary['S'] = "***" ;  dictionary['T'] = "_"   ;  dictionary['U'] = "**_"   ;
   dictionary['V'] = "***_";  dictionary['W'] = "*__" ;  dictionary['X'] = "_**_"  ;
   dictionary['Y'] = "_*__";  dictionary['Z'] = "__**";


   dictionary['0'] = "_____"; dictionary['5'] = "*****";  dictionary['.'] = "*_*_*_" ; dictionary['/'] = "_**_*" ;dictionary[';'] = "_*_*_*"  ;
   dictionary['1'] = "*____"; dictionary['6'] = "_****";  dictionary[','] = "__**__" ; dictionary['('] = "_*__*" ;dictionary['='] = "_***_"   ;
   dictionary['2'] = "**___"; dictionary['7'] = "__***";  dictionary['?'] = "**__**" ; dictionary[')'] = "_*__*_";dictionary['+'] = "*_*_*"   ;
   dictionary['3'] = "***__"; dictionary['8'] = "___**";  dictionary['\''] = "*____*";dictionary['&'] = "*_***"  ;dictionary['-'] = "_****_"  ;
   dictionary['4'] = "****_"; dictionary['9'] = "____*";  dictionary['!'] = "_*_*__" ; dictionary[':'] = "___***";dictionary['\"'] = "*_**_*" ;
   dictionary['@'] = "*__*_*"; dictionary[' '] = "  ";


   string choice;
   while(1) {
       cout << endl <<"Please choose from options:" << endl << "(1) Encrypt" << endl << "(2) Decrypt" << endl << "(3) Exit" << endl;
       cin >> choice;  //  taking input
       while((getchar()) != '\n'); //  flushing cin buffer

       if (choice == "1") {
           while(1){
               string wanted;
               cout << "Please enter the text you want to encrypt (double press enter to finish input): " << endl;
               getline(cin, wanted, '\n');

               while((getchar()) != '\n');
               if(encrypt(string_to_upper(wanted)) == "-1"){
                   cout << "Oops, looks like you are trying to convert a letter that isn't included in the universal English morse code, ";
                   cout << "Try again below..." << endl;
               }else{
                   cout << "The encrypted text is: " << endl <<encrypt(string_to_upper(wanted)) << endl;
                   cout << "Enter anything to get back to main menu: ";
                   string exit;
                   cin >> exit;
                   while ((getchar()) != '\n');
                   break;
               }
           }

       } else if (choice == "2") {
           while(1){
               string wanted;
               cout << "Please enter the text you want to encrypt (double press enter to finish input): " << endl;
               getline(cin, wanted,'\n');


               while((getchar()) != '\n');
               if(decrypt(wanted) == "_"){
                   cout << "Oops, looks like you are trying to convert a letter that isn't included in the universal English morse code." << endl;
                   cout << endl <<"Try again below..." << endl;
               }else{
                   cout << "The string is: " << endl <<decrypt(wanted) << endl;
                   cout << "Enter anything to get back to main menu: ";
                   string exit;
                   cin >> exit;
                   while ((getchar()) != '\n');
                   break;
               }
           }
       } else if (choice == "3") {
           break;
       } else {
           cout << "Invalid input.\n";
       }
   }




   return 0;
}



// cheap travel
//int n,m,a,b; cin >> n >> m >> a >> b;
//    int sum = 0;
//
//    sum += m * b;
//    n -= m;
//
//    if(n > 0){
//        sum += n * a;
//    }



//Alcoholc (i)
//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    double n,x,v[1005],p[1005];cin >> n >> x;
//    double til_now = 0;
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> v[i] >> p[i];
//        til_now += v[i] * p[i] / 100;
//        if(til_now > x){
//            cout << i;
//            return 0;
//        }
//    }
//
//    cout << -1;
//    return 0;
//}



//alchoholic second try
//double n,x,v[1005] = {}, p[1005] = {};cin >> n >> x;
//double til_now = 0;
//
//for (int i = 1; i <= n; ++i) {
//cin >> v[i] >> p[i];
//}
//
//for (int i = 1; i <= n; ++i) {
//til_now += (v[i] * (p[i] / 100));
//if(til_now > x) {
//cout << i;
//return 0;
//}
//
//}
//
//
//cout << -1;
//return 0;


// cheap trip 2
//
//int n,m,a,b; cin >> n >> m >> a >> b;
//int sum = 0;
//int cost = 0;
//
//if(b > m * a){
//cout << a * n;
//}else{
//
//if(n > m){
//cost += (n/m) * b;
//cost += (n % m) * a;
//}
//}
//
//cout << cost;

//cheap 3
//int n,m,a,b; cin >> n >> m >> a >> b;
//int sum = 0;
//int cost = 0;
//
//while(n!= 0){
//int cost_of_taking_special_for_needed_trips = ceil(n/m) * b;
//int cost_of_taking_normal = n * a;
//
//if(cost_of_taking_special_for_needed_trips <= cost_of_taking_normal){
//cost += cost_of_taking_special_for_needed_trips;
//}else{
//cost += cost_of_taking_normal;
//}
//
//}


//cheap 4

//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n,m,a,b; cin >> n >> m >> a >> b;
//    int sum = 0;
//    int cost = 0;
//
//    double cost_per_trip_special = double(b) / m;
//    if (cost_per_trip_special < a){
//        int number_of_minimum_m = n / m;
//
//        if(number_of_minimum_m * b < a * number_of_minimum_m * m ){
//            cost += number_of_minimum_m * b;
//            n -= number_of_minimum_m * m;
//
//            if(b < n * a){
//                cost += b;
//            }else{
//                cost += a * n;
//            }
//        }
//
//    }else{
//        cost = a * n;
//    }
//
//
//    cout << cost;
//    return 0;
//}



//stupid alcoholic final
//
//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n,x,v[1005] = {}, p[1005] = {};cin >> n >> x;
//    int til_now = 0;
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> v[i] >> p[i];
//    }
//    x *= 100;
//
//    for (int i = 1; i <= n; ++i) {
//        til_now += v[i] * p[i] ;
//        if(til_now > x) {
//            cout << i;
//            return 0;
//        }
//    }
//
//
//    cout << -1;
//
//    return 0;
//
//}