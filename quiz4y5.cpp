#include <iostream>
#include <list>
#include <math.h>

using namespace std;

/* Quiz #4 #5
   Estudiante: Kevin Josue Cubillo Chacon
   Carne: 2021123138
   Profesor: Rodrigo Nunez

*/

void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0; //7
   list<int> pocket[10];
        //1
   for(i = 0; i< max; i++) { //3
      m = pow(10, i+1);  //5
      p = pow(10, i);  //4
           //1
      for(j = 0; j<n; j++) {  //3
         temp = arr[j]%m;  //3
         index = temp/p; //2
         pocket[index].push_back(arr[j]);  //4
      }
      count = 0;  //1
           //1
      for(j = 0; j<10; j++) {//3
         while(!pocket[j].empty()) {  //3 saca los numeros y los mete en el arreglo, por lo que depende de n
            arr[count] = *(pocket[j].begin());   //5
            pocket[j].erase(pocket[j].begin());  //5
            count++;//2
         }
      }
   }
}

/*  Calculo del f(n) y O(n) del Radixsort:

    7+1+(3+5+4+1+(3+3+2+4)*N +1+1+(3*10+15*N))M
          8 + (13 + 12N + 2 + 30 + 15N)M
            8 + (45 + 25N)M
              8 + 45M + 25NM
         f(n) = 8 + 45k + 25nk   -->25nk es el termnio de mayor grado
         O(nk)

    Loop invariant:
    arr[1..i-1] Despues de la i-esima iteracion del for,
    los elementos estan ordenados por sus ultimos i digitos.

                                                    */
int costo(int N, int M, int x[], int y[]) {
    int suma1 = 0; //1
    int suma2 = 0; //1

        //1
    for(int i = 0; i<M-1; i++){ //4
        suma1+=x[i]; //3
    }
        //1
    for(int i = 0; i<N-1; i++){ //4
        suma2+=y[i]; //3
    }
    int costo1 = suma1+(suma2*M), costo2 = suma2+(suma1*N); //6
    if (costo1<costo2){ //1
        return costo1; //1
     }else{
        return costo2; //1
     }
}


/*  Calculo del f(n) y O(n) del algoritmo de costo minimo:

    1+1+1+(4+3)(M-1)+1+(4+3)(N-1)+6+1+1
        3+(7)(M-1)+1+(7)(N-1)+8
            3+7M-7+1+7N-7+8
               7M+7N-2
            f(n) = 7k+7n-2
            O(n+k)


    Loop invariant:

    Para el primer for:  suma1 <= x1+x2+x3...+xM-1
    Para el segundo for: suma2 <= y1+y2+y3...+yN-1
                                                              */

int main()
{
    cout<< "Pruebas algoritmo de costo minimo: \n\n";
    int x[] = {7,3,2} ;
    int y[] = {3,8,1,2};
    cout<<"int x[] = {7,3,2};\nint y[] = {3,8,1,2};\ncosto(5,4,x,y) = "<<costo(5,4,x,y)<<endl<<endl;

    int x2[] = {5,2,3,1};
    int y2[] = {8,9,3,2};
    cout<<"int x2[] = {5,2,3,1};\nint y2[] = {8,9,3,2};\ncosto(5,5,x,y) = "<<costo(5,5,x2,y2)<<endl;
    return 0;

}
