/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 05 - Foundation of Algorithm
 *   Hari dan Tanggal    : Senin, 11 Mei 2026
 *   Nama (NIM)          : Bismar Alwi Khadavi (13224016)
 *   Nama File           : soal1.c
 *   Deskripsi           : Graph tak berarah dengan adjacency matrix, dilihat degree per barisnya, max vertex, dan yang terisolasi
 * 
 */

#include <stdio.h>
#include <string.h>

#define MAX 20

int adj[MAX][MAX];
int n;
int max = 0;
int maxVer = 0;
int isol[MAX];

void degree(){
    for(int i=0; i<n; i++){
        int hitung = 0;
        for(int j=0; j<n; j++){
            hitung += adj[i][j];
        }
        if(max < hitung){
            max = hitung;
            maxVer = i;
        }
        else if(hitung == 0){
            isol[i] = 1;
        }
        else{isol[i] = 0;}
        printf("DEGREE %d %d\n", i, hitung);
    }
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        scanf("%d", &adj[i][j]);
    }
  }
 
  /*for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        printf("adj[%d][%d] = %d\n", i, j, adj[i][j]);
    }
  }*/

  degree(adj);
  printf("MAX_VERTEX %d\n", maxVer);
  printf("ISOLATED ");
  int cek = 0;
  for(int i=0; i<n; i++){
    if(isol[i] == 1){
    printf("%d ", i);
    cek = 1;
    }
  }
  if(cek == 0){printf("NONE\n");}

  return 0;
}
 
