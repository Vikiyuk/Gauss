#include <iostream>
#include <fstream>
using namespace std;
void zadanie1(string a);
void zadanie2(string a);
void zadanie3(string a);
void zadanie4(string a);
void wysw(double** A,int matrix_size,double *B);
void modyfikacja(double **A, double* B,int matrix_size,int index);
void licz(double** A,int matrix_size,double* B,double* result);
void WyswResult(double* result,int matrix_size);
void swapp(double *a, int index1,int index2);
void wypSwapTable(double *swaptable,int matrix_size);
void Swaping (double* result,double* swapTable,int matrix_size);
void WyborKolumn(double** A,int matrix_size,double* swapTable, double* B);
void WyborWiersz(double**A, double* B, int matrix_size);
void PelnyWybor(double**A, double* B, int matrix_size,double* swapTable);
int main()
{
    zadanie1("plik1.csv");
    zadanie2("plik2.csv");
    zadanie3("plik3.csv");
    zadanie4("plik4.csv");
    return 0;
}
void zadanie1(string a)
{
    double** A;
    double* b;
    double* result;
    int matrix_size;
    ifstream source_file(a);
    if (!source_file.is_open())
    {
        cout <<"The file has not been open!"<<endl;
    }
    source_file >> matrix_size;
    A = new double*[matrix_size];
    A[0] = new double[matrix_size*matrix_size];
    for(int i = 1; i< matrix_size; i++)
        A[i] = A[i-1] + matrix_size;

    b = new double[matrix_size];
    result = new double[matrix_size];
    char semicolumn;
    for (int i = 0; i < matrix_size+1; i++)
        source_file >> semicolumn;

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            source_file >> A[i][j];
            source_file >> semicolumn;
        }
        source_file >> semicolumn;
        source_file >> b[i];
    }
    source_file.close();


          for(int i=0;i<matrix_size;i++)
          {
                modyfikacja(A,b,matrix_size,i);
          }
        licz(A,matrix_size,b,result);
        WyswResult(result,matrix_size);

    delete [] b;
    delete [] A[0];
    delete [] A;
    delete [] result;
}

void zadanie2(string a)
{
    double** A;
    double* b;
    double* result;
    int matrix_size;
    ifstream source_file(a);
    if (!source_file.is_open())
    {
        cout <<"The file has not been open!"<<endl;

    }
    source_file >> matrix_size;
    A = new double*[matrix_size];
    A[0] = new double[matrix_size*matrix_size];
    for(int i = 1; i< matrix_size; i++)
        A[i] = A[i-1] + matrix_size;

    b = new double[matrix_size];
    result = new double[matrix_size];
    char semicolumn;
    for (int i = 0; i < matrix_size+1; i++)
        source_file >> semicolumn;

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            source_file >> A[i][j];
            source_file >> semicolumn;
        }
        source_file >> semicolumn;
        source_file >> b[i];
    }
    source_file.close();
    WyborWiersz(A,b,matrix_size);
    licz(A,matrix_size,b,result);
    WyswResult(result,matrix_size);

    delete [] b;
    delete [] A[0];
    delete [] A;
    delete [] result;

}



void zadanie3(string a)
{
    double** A;
    double* b;
    double* swapTable;
    double* result;
    int matrix_size;
    ifstream source_file(a);
    if (!source_file.is_open())
    {
        cout <<"The file has not been open!"<<endl;

    }
    source_file >> matrix_size;
    A = new double*[matrix_size];
    A[0] = new double[matrix_size*matrix_size];
    for(int i = 1; i< matrix_size; i++)
        A[i] = A[i-1] + matrix_size;

    b = new double[matrix_size];
    result = new double[matrix_size];
    swapTable = new double[matrix_size];
    wypSwapTable(swapTable,matrix_size);
    char semicolumn;
    for (int i = 0; i < matrix_size+1; i++)
        source_file >> semicolumn;

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            source_file >> A[i][j];
            source_file >> semicolumn;
        }
        source_file >> semicolumn;
        source_file >> b[i];
    }
    source_file.close();
    WyborKolumn(A,matrix_size,swapTable,b);
    licz(A,matrix_size,b,result);
    Swaping(result,swapTable,matrix_size);
    WyswResult(result,matrix_size);

    delete [] b;
    delete [] A[0];
    delete [] A;
    delete [] result;
    delete [] swapTable;
}






void zadanie4(string a)
{
    double** A;
    double* b;
    double* swapTable;
    double* result;
    int matrix_size;
    ifstream source_file(a);
    if (!source_file.is_open())
    {
        cout <<"The file has not been open!"<<endl;

    }
    source_file >> matrix_size;
    A = new double*[matrix_size];
    A[0] = new double[matrix_size*matrix_size];
    for(int i = 1; i< matrix_size; i++)
        A[i] = A[i-1] + matrix_size;

    b = new double[matrix_size];
    result = new double[matrix_size];
    swapTable = new double[matrix_size];
    wypSwapTable(swapTable,matrix_size);
    char semicolumn;
    for (int i = 0; i < matrix_size+1; i++)
        source_file >> semicolumn;

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            source_file >> A[i][j];
            source_file >> semicolumn;
        }
        source_file >> semicolumn;
        source_file >> b[i];
    }
    source_file.close();
    PelnyWybor(A,b,matrix_size,swapTable);
    licz(A,matrix_size,b,result);
    Swaping(result,swapTable,matrix_size);
    WyswResult(result,matrix_size);



    delete [] b;
    delete [] A[0];
    delete [] A;
    delete [] result;
    delete [] swapTable;
}



void wysw(double **A,int matrix_size,double *B)
{
     for(int i=0;i<matrix_size;i++){
        for(int j=0;j<matrix_size;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<" = "<<B[i];
        cout<<endl;
    }
}
void modyfikacja(double **A, double* B,int matrix_size,int index)
{
    double* c = new double[matrix_size];
    c[0]=A[index][index];
    int j=0;
    int k=0;
    for (int i=index+1;i<matrix_size;i++)
    {
        c[j]=(float)A[i][index]/A[index][index];
        A[i][index]=0;
        j++;
    }
    for (int i=index+1;i<matrix_size;i++)
    {

       for (int j=index+1;j<matrix_size;j++)
        {
            A[i][j]=A[i][j]-A[index][j]*c[k];
        }
        B[i]=B[i]-B[index]*c[k];
        k++;
    }
    delete[] c;
}
void licz(double** A,int matrix_size,double* B,double* result)
{
    for(int i=matrix_size-1;i>0;i--)
    {
        result[i]=B[i]/A[i][i];
        for(int j=i;j<=matrix_size-1;j++)
            {
                B[i-1]=B[i-1]-result[j]*A[i-1][j];
            }
    }
    result[0]=B[0]/A[0][0];
}
void WyswResult(double* result,int matrix_size)
{
    for (int i=0;i<matrix_size;i++)
    {
        cout<<"x"<<i<<"="<<result[i]<<endl;
    }
}

void swapp(double *a, int index1,int index2)
{
    double temp=a[index2];
    a[index2]=a[index1];
    a[index1]=temp;
}
void wypSwapTable(double *swaptable,int matrix_size)
{
    for(int i=0;i<matrix_size;i++)
    {
        swaptable[i]=i;
    }
}
void Swaping (double* result,double* swapTable,int matrix_size)
{
    for(int i=0;i<matrix_size;i++)
    {
        for (int j=0;j<matrix_size;j++)
        {
            if (swapTable[j]==i)
            {
                swapp(result,i,j);
                swapp(swapTable,i,j);

            }
        }
    }
}
void WyborKolumn(double** A,int matrix_size,double* swapTable,double* B)
{
    for(int i=0;i<matrix_size;i++)
          {

                int somecoef=-1;
                double max = A[i][i];

                        for (int j = i; j < matrix_size; j++) {
                        if (A[i][j] > max) {
                                max = A[i][j];
                                somecoef=j;
                            }
                        }

                if(somecoef>-1)
                {

                    for (int l=0;l<matrix_size;l++)
                {

                    double temp= A[l][somecoef];

                    A[l][somecoef]=A[l][i];
                    A[l][i]=temp;


                }
                    swapp(swapTable,i,somecoef);

                }

                modyfikacja(A,B,matrix_size,i);



                somecoef=-1;
          }

}
void WyborWiersz(double**A, double* B, int matrix_size)
{
int somecoef=-1;
for(int i=0;i<matrix_size;i++)
    {

        double max = A[i][i];
        for (int j = i; j < matrix_size; j++) {
            if (A[j][i] > max) {
                max = A[j][i];
                somecoef=j;
            }
        }
        if(somecoef>-1)
        {
            for (int l=0;l<matrix_size;l++)
            {
                double temp= A[somecoef][l];
                A[somecoef][l]=A[i][l];
                A[i][l]=temp;
            }
            swapp(B,i,somecoef);
        }
                modyfikacja(A,B,matrix_size,i);
                somecoef=-1;
          }
}
void PelnyWybor(double**A, double* B, int matrix_size,double* swapTable)
{
    int somecoef=-1;
    int somecoef2=-1;
    for(int i=0;i<matrix_size;i++)
          {

                        double maxwiersz = A[i][i];
                        double maxkol = A[i][i];

                        for (int j = i; j < matrix_size; j++) {
                        if (A[j][i] > maxwiersz) {
                                maxwiersz = A[j][i];
                                somecoef=j;
                            }
                        }
                        for (int j = i; j < matrix_size; j++) {
                        if (A[i][j] > maxkol) {
                                maxkol = A[i][j];
                                somecoef2=j;
                            }
                        }
                        if (maxkol>maxwiersz)
                        {
                            if(somecoef2>-1)
                            {

                                for (int l=0;l<matrix_size;l++)
                                {
                                    double temp= A[l][somecoef2];
                                    A[l][somecoef2]=A[l][i];
                                    A[l][i]=temp;
                                }
                                swapp(swapTable,i,somecoef2);

                            }
                        }
                         if (maxwiersz>maxkol)
                        {
                            if(somecoef>-1)
                            {
                                for (int l=0;l<matrix_size;l++)
                                {
                                    double temp= A[somecoef][l];
                                    A[somecoef][l]=A[i][l];
                                    A[i][l]=temp;
                                }
                                swapp(B,i,somecoef);
                            }
                        }
                somecoef=-1;
                somecoef2=-1;
                modyfikacja(A,B,matrix_size,i);
          }
}

