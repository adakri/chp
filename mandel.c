#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <string.h>



struct grid{
    int length;
    int width; 
    int *pixel;
};

/* void compute_mandel(struct grid *im, int nb_iter);
void draw_mandel(struct grid *img); */


//draw works
void draw_mandel(struct grid *img)
{
    printf("\n");
    const char charset[] = ".,c8M@jawrpogOQEPGJ";
    for(int i=0; i<img->length; i++)
    {
        for(int j=0; j<img->width; j++)
        {
            unsigned n = img->pixel[i*img->width + j];
            if(n==0)
            {
                fprintf(stderr, "*"); //diverge
            }else if(n>strlen(charset)){
                fprintf(stderr, "$"); //high convergence
            }else{
                char p = n > 0 ? charset[n % (sizeof(charset)-1)] : ' ';
                fprintf(stderr, "%c", p); //disinguishable convergence
            }
        }
        fprintf(stderr, "\n");
        
    }
    printf("\n");
}

//computes mandelborot set
void compute_mandel(struct grid *im, int nb_iter, double x_min, double x_max, double y_min, double y_max)
{    
    double pasx = (x_max - x_min) / im -> length;
    double pasy = (y_max - y_min) / im -> width;
    //parses the image and chooses constant c=(i,j)
    for(int i=0; i<im->length; i++)
    {
        for(int j=0; j<im->width; j++)
        {
            double cx = x_min + i*pasx, cy = y_min + j*pasy;
            double xn=0.;
            double yn=0.;
            int nb=0;
            int new=0;
            while( (xn*xn+yn*yn < 4.) && (nb<nb_iter) )
            {
                new=xn*xn-yn*yn+cx;
                yn=2.0*xn*yn*+cy;
                xn=new;
                nb++;
            }
            //intensity of the set is number of iterations to convergence
            fprintf(stderr, "%d :", nb);
            if(nb==nb_iter){nb=0;} //just a simple tab, do not want to deal with a matrix and all those shananigans
            im->pixel[i*im->width+j]=nb;
        }
    }
}

int main(int argc,char* argv[]) 
{ 
    int nb_iter=0;
    printf("Program Name Is: %s \n",argv[0]); 
    if(argc==1) 
    {
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name \n"); 
        nb_iter=atoi(argv[1]);
    }
    if(argc>=2) 
    { 
        printf("\nNumber Of Arguments Passed: %d \n",argc); 
        printf("\n----Following Are The Command Line Arguments Passed---- \n"); 
        for(int counter=0;counter<argc;counter++) 
            printf("\nargv[%d]: %s \n",counter,argv[counter]); 
        nb_iter=atoi(argv[1]);
    } 
    //define a grid
    struct grid im;
    im.length=40;
    im.width=100;
    im.pixel=(int*)malloc(im.length*im.width*sizeof(int));

    if (im.pixel == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
        printf("drawing of a mandel set for %d iterations \n",nb_iter);
        compute_mandel(&im, nb_iter, -2.5, 1.5, -2.0, 2.0);
        draw_mandel(&im);
        printf("\n");
    }
    return 0; 
} 