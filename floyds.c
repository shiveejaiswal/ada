#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<sys/resource.h>
void floyd(int a[20][20], int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]>(a[i][k]+a[k][j])){
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    printf("All pairs shortest paths:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
int main(){
     struct timeval tv1, tv2;
    struct rusage r_usage;
    int n, a[20][20];
    printf("enter the number of vertices:\n");
    scanf("%d",&n);
    printf("enter the cost adjacency matrix [999 for no edge and 0 for self loops]:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    gettimeofday(&tv1, NULL);
    floyd(a,n);
    gettimeofday(&tv2, NULL);
    printf("the time is %f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF,&r_usage);
    printf("memory is %ld kilobytes\n", r_usage.ru_maxrss);
    return 0;
}
