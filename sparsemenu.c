#include <stdio.h>

void sparse(int r, int c, int d[r][c], int u[100][3]) {
    int i, j, k = 1;
    u[0][0] = r;
    u[0][1] = c;
    u[0][2] = 0;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(d[i][j] != 0) {
                u[k][0] = i;
                u[k][1] = j;
                u[k][2] = d[i][j];
                k++;
            }
        }
    }
    u[0][2] = k-1;

    printf("\n // Sparse Matrix Representation // \n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", u[i][0], u[i][1], u[i][2]);
    }
}

void sparset(int r, int c, int d[r][c], int u[100][3]){
    int i, j, k = 1; 
    int t[100][3]; 

    t[0][0] =  u[0][1];
    t[0][1] =  u[0][0];
    t[0][2] =  u[0][2];

    for(i = 0; i < u[0][1]; i++){
        for( j = 1; j <= u[0][2]; j++){
            if(u[j][1] == i){
                t[k][0] = u[j][1]; 
                t[k][1] = u[j][0]; 
                t[k][2] = u[j][2]; 
                k++; 
            }

        }
    
    } 
    for( i = 0; i <=t[0][2]; i++){
        printf(" %d  %d  %d \n", t[i][0], t[i][1], t[i][2]); 
    }
}

void sparseadd(int b[100][3]){
    int nr, nc, i, j;

    printf("\n");
    printf("Enter the number of rows of matrix B: ");
    scanf("%d", &nr); 
    printf("Enter the number of columns of matrix B: ");
    scanf("%d", &nc); 

    int c[nr][nc]; // second matrix created
    int d[100][3];

    for(i = 0; i<nr; i++){
        for(j=0; j<nc; j++){
            printf("Enter the element: "); 
            scanf("%d", &c[i][j]);
        }
    }

    sparse(nr, nc, c, d); 

   if (b[0][0] != d[0][0] || b[0][1] != d[0][1]){
    printf("Since the rows & columns do not match the matrix cannot be added!"); 
    return; 

   } 

   int e[100][3];
   e[0][0] = b[0][0];
   e[0][1] = b[0][1]; 
   
   i = 1;
   j = 1;
   int k = 1; 
   
   
   while(i<= b[0][2] && j<= d[0][2]){
    if(b[i][0] < d[j][0] || (b[i][0] == d[j][0] && b[i][1] < d[j][1])){
        e[k][0] = b[i][0];
        e[k][1] = b[i][1];
        e[k][2] = b[i][2]; 
        i++; 
        k++; 
    } 
    else if(b[i][0] > d[j][0] || (b[i][0] == d[j][0] && b[i][1] > d[j][1])){
        e[k][0] = d[j][0];
        e[k][1] = d[j][1];
        e[k][2] = d[j][2];
        j++;
        k++;

    }

      else {
        int sum = b[i][2] + d[j][2];
        if (sum != 0) {
            e[k][0] = b[i][0];
            e[k][1] = b[i][1];
            e[k][2] = sum;
            k++;
        }
        i++;
        j++;
    }
   }

   // Copy any remaining elements from B
while(i <= b[0][2]) {
    e[k][0] = b[i][0];
    e[k][1] = b[i][1];
    e[k][2] = b[i][2];
    i++;
    k++;
}

// Copy any remaining elements from D
while(j <= d[0][2]) {
    e[k][0] = d[j][0];
    e[k][1] = d[j][1];
    e[k][2] = d[j][2];
    j++;
    k++;
}

e[0][2] = k - 1; 

printf("\n// Result of Sparse Matrix Addition //\n");
for(int x = 0; x <= e[0][2]; x++) {
    printf("%d %d %d\n", e[x][0], e[x][1], e[x][2]);
}

}

void main(){

    int r,c, i, j;
   
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int A[r][c];
    int B[100][3];

    for(i = 0; i < r; i++){
        for( j = 0; j< c; j++){
            printf("Enter the element: ");
            scanf("%d", &A[i][j]);
        }
    }
   
    printf("\n");
    printf(" // The Matrix // ");
    printf("\n");
   
    for(i = 0; i<r; i++){
        for( j = 0; j< c; j++){
            printf(" %d ", A[i][j]);
        }
        printf("\n");
    }
   

    sparse(r, c , A, B);

    int choice; 
    char op; 

    do{
        printf("Menu\n");
        printf("Select your choice:\n");
        printf("1. Sparse Matrix Addition\n");
        printf("2. Sparse Matrix Transpose\n");
        printf("3. Exit\n");
        printf("Enter your choice [1 | 2 | 3]:  ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
            printf("// Sparse Matrix Addition // "); 
            sparseadd(B);
            break;

            case 2: 
            printf("// Sparse Matrix Transpose //"); 
            sparset(r, c, A, B);
            break;

            default:
            printf("Invalid choice! \n");
            break; 

        }
        
        printf("Do you wish to continue: "); 
        scanf(" %c", &op); 
    }while(op == 'Y' || op== 'y'); 
} 
