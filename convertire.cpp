// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

    using std::cin;
    using std::cout;
    using std::string;


int verificare(string &og, int b);
int c_pw(string &og, int b, int *pw);
void htoz(string &og, int *pw, int baza);
void otoz(string &og, int *pw, int baza);
int switch_underworld(char c);

int main() {
    
    int baza;
    int run=1;
    
    string og;
    int pw[20];

    while (run)
    {
        cout<<"DACA VREI SA IESI APASA COMBINATIA CTRL+C\n";
        cout<<"Introdu Nr si baza in care este \n";
        og.clear();
        cin>>og>>baza;

        if(!verificare(og, baza)) continue;

        if(!c_pw(og, baza, pw)) continue;

        
        if(baza>10) htoz(og, pw, baza); 
        else otoz(og, pw, baza);

        og.clear();

        for(int x=0; x<20; x++){
            pw[x]=0;
        }

        continue;
    }

    
    return 0;
}


int verificare(string &og, int b){
    if (og.empty()){
        cout<<"Introdu un numar valid\n";
        return 0;
    }
    for (int i = 0; i < og.length(); i++) { //FAce ca toate literele sa fie uppercase
        og[i] = std::toupper(og[i]);
    }
    
    
    if(b<2 || b>16){
        cout<<"Baza incorecta\n";
        return 0;
    }

    if(b>10){
        for (int i = 0; i < og.length(); i++) //Verifica hexadecimalele
        {
            if(switch_underworld(og.at(i)) < 0 && og.at(i)!='.'){
                cout<<"Date incompatibile";
                return 0;
            }
        }
    }else{
        for(int e=0; e < og.length(); e++){   //Verifica daca cifrele coincid cu bazele
            if((og.at(e)-'0') >= b && og.at(e)!='.' ){
                cout<<"Date incompatibile";
            return 0;
            }
        }
    }
    return 1;
}

int c_pw(string &og, int b, int *pw){

    int p = og.find('.');
    if (p != string::npos){
        og.erase(p,1);
        cout<<"OG test"<<og[0]<<og[1]<<"\n";
    }else{
        p=0;
    }
    
    if (p>0){
        int x = p -1;

        for(int i=0; i<og.length(); i++){
            pw[i]=x;
            x--;
        }

    }else{
        int x = og.length()-1;

        for(int i=0; i<og.length(); i++){
            pw[i]=x;
            x--;
        }    
    }
    return 1;
}

void htoz(string &og, int *pw, int baza){
    double result=0;
    cout<<"OG in htoz "<<og.length()<<"\n";
    for (int i = 0; i < og.length(); i++){
        int d =switch_underworld(og.at(i));
        result+=d * pow(baza, pw[i]);

        cout<<"D "<<d<<"\n";

        cout<<"I "<<pw[i]<<"\n";
        cout<<"restul"<<result<<"\n";

    }
    cout<<"Dupa transformare rezultatul e "<<result<<" in baza 10\n";
}

void otoz(string &og, int *pw, int baza){
    double result=0;
    for (int i = 0; i < og.length(); i++){
        int d = og.at(i)-'0';
        result+=d*pow(baza, pw[i]);
    }
    cout<<"Dupa transformare rezultatul e "<<result<<" in baza 10\n";
}

int switch_underworld(char c){
    switch (c)
    {
    case '0': return 0; break;
    case '1': return 1; break;
    case '2': return 2; break;
    case '3': return 3; break;
    case '4': return 4; break;
    case '5': return 5; break;
    case '6': return 6; break;
    case '7': return 7; break;
    case '8': return 8; break;
    case '9': return 9; break;
    case 'A': return 10; break;
    case 'B': return 11; break;
    case 'C': return 12; break;
    case 'D': return 13; break;
    case 'E': return 14; break;
    case 'F': return 15; break;
    default: return -1;
    }
}