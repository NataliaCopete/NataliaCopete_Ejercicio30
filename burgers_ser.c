#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <math.h>


using std::cout;
using std::endl;


double** inicial(int N, double L){
double** xu= new double*[2];
for(int j=0; j<2;j++){
xu[j]=new double[N];
}
double delta=L/N;
for (int i =0; i<N;i++){
xu[0][i]= i*delta; 
xu[1][i]=0.0;
}
for(int i=0;i<N;i++){
if(xu[0][i]<2.0){
xu[1][i]=1.0;   
}       
}
return xu;
}

double flux(double u){
return 0.5*u*u;    
}

double* Lax(double* u, int N, double t_max,double delta_t,double delta_x){
    
int N_t=t_max/delta_t;
double* u_final= new double[N];
double* F= new double[N];
for (int i=0; i<N_t;i++){
for(int j=0;j<N;j++){
F[j]=flux(u[j]);
}
for(int k=1; k<N-1;k++){
u_final[k]= 0.5*(u[k+1]+u[k-1]);    
u_final[k] -= (0.5*delta_t/delta_x)*(F[k+1]-F[k-1]);    
}
for (int m=0;m<N;m++){
u[m]=u_final[m];    
}    
}
return u_final;    
    
}

int main(int argc, char *argv[]){
double L= 4.0;
double d_x=0.05;
int N= L/d_x +1;   
/*int rows = sizeof(arr)/sizeof(arr[0]);
int cols = sizeof(arr[0])/sizeof(arr[0][0]);*/
double t_m=0.0;
double* u_in =new double[N];
double* u_f =new double[N];

double** iniciales=inicial(N,L);
for(int j=0;j<N;j++){
cout<<iniciales[1][j]<<" "<<iniciales[0][j]<<endl;        
}

while(t_m<2.0){
double** arr_ini =inicial(N, L);
for (int i=0;i<N;i++){
u_in[i]=arr_ini[1][i];
}
u_f=Lax(u_in, N,t_m,0.5*d_x,d_x);
for(int k=0;k<N;k++){
cout<<u_f[k]<<" "<<arr_ini[0][k]<<endl;
}
t_m=t_m+0.5;    
}
return 0;
}
