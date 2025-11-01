#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isTriangle(int a, int b, int c){
  if (a < a + b && a > abs(b - c)){
    return 1;
  }
  return 0;
}

int main(int argc, char *argv[]){
  if (argc == 2 && strcmp(argv[1], "user") == 0){
    char * myBuffer = malloc(1000);
    fgets(myBuffer, sizeof(myBuffer), stdin);
    int x; int y; int z;
    sscanf(myBuffer, "%d %d %d", &x, &y, &z);
    if (x < y + z && x > abs(y - z)){
      printf("valid");
    }
    else{
      printf("invalid");
    }
  }
  else if (argc == 3 && strcmp(argv[1], "horizontal") == 0){
    char * myBuffer = malloc(1000);
    FILE *myFile;
    myFile = fopen(argv[2], "r");
    char * line = fgets(myBuffer, sizeof(myBuffer), myFile);
    int total = 0;
    while (line != NULL){
      int x; int y; int z;
      sscanf(myBuffer, "%d, %d, %d", &x, &y, &z);
      total += isTriangle(x, y, z);
      line = fgets(myBuffer, sizeof(myBuffer), myFile);
    }
    printf("total: %d", total);
  }
  else if (argc == 3 && strcmp(argv[1], "vertical") == 0){
    char * myBuffer = malloc(1000);
    FILE *myFile;
    myFile = fopen(argv[2], "r");
    char * line = fgets(myBuffer, sizeof(myBuffer), myFile);
    int total = 0;
    int arr[9];
    while (line != NULL){
      for (int i = 0; i < 3; i++){
        int x; int y; int z;
        sscanf(myBuffer, "%d, %d, %d", &x, &y, &z);
        arr[i] = x;
        arr[i + 3] = y;
        arr[i + 6] = z;
        line = fgets(myBuffer, sizeof(myBuffer), myFile);
      }
      total += isTriangle(arr[0], arr[1], arr[2]);
      total += isTriangle(arr[3], arr[4], arr[5]);
      total += isTriangle(arr[6], arr[7], arr[8]);
    }
    printf("total: %d", total);
  }
}
