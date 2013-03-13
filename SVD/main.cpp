#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void test_svd_builtin(mat &A);
void test_SVD(mat &A);
void SVD(mat &U, vec &S, mat &V, mat &A);
int main(int argc, char** argv)
{

    mat A(atoi(argv[1]),atoi(argv[2]));
    // fill the matrix with some random numbers
    A.randn();
    mat U,V;
    vec S;
    test_svd_builtin(A);

    test_SVD(A);
    // calling the built in svd function



}
void test_svd_builtin(mat &A) {
    mat U, V;
    vec S;

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

void test_SVD(mat &A) {
    mat U, V;
    vec S;

    SVD(U,S,V,A);
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
void SVD(mat &U , vec &S, mat &V,mat &A) {
    // find A*A^T, then the eigevnvalues and eigevnvectors.
    mat AAT = A*A.t();
    vec eigval;
    eig_sym(eigval,U,AAT);
    // find A^T*A, then the eigevnvalues and eigevnvectors.
    mat ATA = A.t()*A;
    eig_sym(eigval,V,ATA);
    S=arma::sqrt(eigval);





}

