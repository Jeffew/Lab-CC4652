#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

class LES {
private:
    int n=0;
    int v[MAX];

public:
    LES() : n(0){

    }

    int getN(){
        return n;
    }

    bool insert(int value) {
        if (n==MAX)
            return false;

        int i;
        for (i=0;i<n && v[i] < value;i++);

        for(int j=n;j>i;j--){
            v[j] = v[j-1];
        }
        v[i]=value;
        n++;
        return true;
    }

    bool remove(int value){
        if (n<=0){
            cout <<"Erro: Vetor vazio, impossivel remover" << endl;
            return false;
        }
        int i;
        for(i=0;i<n && v[i]!=value;i++);

        for(int j=i;j<n;j++) {
            v[j] = v[j + 1];
        }
        if(i>=n){
            cout << "Erro: Valor nao encontrado" << endl;
            return false;
        }else {
            cout << "Valor removido: "<<value<<endl;
            n--;
        }
        return true;
    }

    bool search(int value){
        if (n<=0){
            cout << "Erro: Vetor vazio, impossivel encontrar numero" << endl;
            return false;
        }
        int i;
        for(i=0;i<n && v[i]!=value;i++);
        if(i>=n){
            cout << "Erro: Valor nao encontrado na busca" << endl;
            return false;
        }else {
            cout << "v[" << i <<"] = " << value << endl;
        }
        return true;
    }

    void print() const{
        if(n<=0){
            cout<<"Erro: Vetor vazio, impossivel imprimir"<<endl;
            return;
        }
        for(int i=0;i<n;i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
};

void operator<<(ostream& a, const LES& b){
    b.print();
}

int main() {
    LES v;
    //cout<< v.getN();
    v.search(15);
    v.remove(15);
    v.insert(1);
    v.insert(10);
    v.insert(-7);
    v.insert(5);
    cout<< v;
    //cout<< v.getN();
    v.search(1);
    v.remove(1);
    cout<< v;
    v.remove(-7);
    //cout<< v.getN();
    cout<< v;
    v.remove(10);
    cout<< v;
    v.search(1);
    v.remove(5);
    v.search(999);
    cout<<v;


    return 0;

}