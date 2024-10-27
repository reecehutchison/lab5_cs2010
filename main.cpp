#include <iostream>

using namespace std;

template<class T>
using ELEM=vector<T>;

template<class T>
using VEC=vector<ELEM<T>>;

template <class T>
using action_t = T (*) (int);

template <class T>
using pred_t = bool (*) (T);

template <class T>
using map_t = T (*) (T,T);

template <class T>
void printElem(ELEM<T> &v) {
    size_t n=v.size();
    for(size_t i=0; i<n; ++i) {
        cout << v[i] << " ";
    }
}

int main() {

    ELEM<int> a={1, 2, 3};

    printElem(a);


    return 0;
}
