#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void SVD(mat &src, mat &U, mat &V, mat &S);
int main(int argc, char** argv)
{

    mat A(atoi(argv[1]),atoi(argv[2]));
    // fill the matrix with some random numbers
    A.randn();
    mat U,V;
    vec S;
    // calling the built in svd function
    svd(U,S,V,A);
    cout<<A<<endl;
    cout<<"\nU:"<<endl;
    cout<<U<<endl;
    cout<<"\nV:"<<endl;
    cout<<V<<endl;
    cout<<"\nS:"<<endl;

    mat S_diag(A.n_rows,A.n_cols);
    S_diag.zeros();
    S_diag.diag()=S;
    cout<<S_diag<<endl;
    cout<<"\nUSV^T:"<<endl;
    mat recover=U*S_diag*V.t();
    cout<<recover<<endl;
    cout<<"\ndiff(A,svd(A))"<<endl;
    cout<<A-recover<<endl;


}
// our own SVD function
void SVD(mat &src, mat &U, mat &V, mat &S) {


}

