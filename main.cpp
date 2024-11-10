#include <iostream>
#include <vector>

using namespace std;

template <class T>
using ELEM=vector<T>;

template <class T>
using VEC=vector<ELEM<T>>;

template <class T>
using action_t = T (*) (int);

template <class T>
using pred_t = bool (*) (T);

template <class T>
using map_t = T (*) (T,T);


template <class T>
void printElem(const ELEM<T>& elems) {
    int n=elems.size(); 
    if(n<2) {
        for(int i=0; i<n; ++i) {
            cout << elems[i];
        }
    } else {
        cout << "(";
        for(int i=0; i<n; ++i) {
            cout << elems[i];
            if(i!=n-1)
                cout << " ";
        }
        cout << ")";
    }
}

template <class T>
void initVec(VEC<T>& my_vector, const ELEM<T>& elements) {
    for(const T& e : elements) {
        ELEM<int> curr{e};
        my_vector.push_back(curr);
    }    
}

template <class T>
void printVec(const VEC<T>& my_vector) {
    cout << "[ ";
    int n=my_vector.size(); 
    for(int i=0; i<n; ++i) {
        printElem(my_vector[i]);
        if(i!=n-1)
            cout << ",";
        cout << " ";
    }
    cout << "]" << endl;
}

// note: that the intended use is for vectors of the
//       same size.
template<class T>
VEC<T> zip(VEC<T> vec1, VEC<T> vec2) {
    VEC<T> ans;
    int n=vec1.size();
    for(int i=0; i<n; ++i) {
        ELEM<T> curr;
        int m=vec1[i].size();
        for(int j=0; j<m; ++j) {
            curr.push_back(vec1[i][j]);
        }
        for(int j=0; j<m; ++j) {
            curr.push_back(vec2[i][j]);
        }
        ans.push_back(curr);
    } 
    return ans;
}

int main() {


    return 0;
}
