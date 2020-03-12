//*****************************************
// count the number of base in fasta file
// Longest sequence name 1023
//*****************************************
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * fp = fopen(argv[1],"r");
    if(!fp) 
    {
        printf("Can't open %s!\n",argv[1]);
        printf("Usage:\n");
        printf("./factg yourfile.fa\n");
        return -1;
    };
    printf("# Calculating ATCG in %s.\n",argv[1]);
    int ch;
    long int Aa=0,Tt=0,Cc=0,Gg=0,Total=0;
    long int a=0,t=0,c=0,g=0,total=0;
    int chr=0;
    char chrname[1024];
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch=='>')
        {  
            int i = 0;
            if(chr!=0)
            {
                printf("%s\tA\t%ld\t%lf\n",chrname,a,(double)a/total);
                printf("%s\tT\t%ld\t%lf\n",chrname,t,(double)t/total);
                printf("%s\tC\t%ld\t%lf\n",chrname,c,(double)c/total);
                printf("%s\tG\t%ld\t%lf\n",chrname,g,(double)g/total);
                printf("# Number of bases:\t%ld\n",total);
            }
            memset(chrname,0,1024);
            while(ch!='\n')
            { 
                chrname[i++] = ch;
                ch = fgetc(fp);
            }
            // output last char \n in > line
            //printf("%s",chrname);
            printf("%c",ch);
            Aa = Aa + a;
            Tt = Tt + t;
            Cc = Cc + c;
            Gg = Gg + g;
            Total = Total + total;
            a=0;t=0;c=0;g=0;total=0;
            ch = fgetc(fp);
            chr++;
        }
        // cope with the last char in sequence
        if(ch!=10 && ch!=-1)total++;
        //printf("%ld\t%d\n",total,ch);
        switch (ch)
        {
        case 'A':
        case 'a':
            a++;
            break;
        case 'T':
        case 't':
            t++;
            break;
        case 'C':
        case 'c':
            c++;
            break;
        case 'G':
        case 'g':
            g++;
            break;
        default:
            break;
        }
    }
    //print last chr
    printf("%s\tA\t%ld\t%lf\n",chrname,a,(double)a/total);
    printf("%s\tT\t%ld\t%lf\n",chrname,t,(double)t/total);
    printf("%s\tC\t%ld\t%lf\n",chrname,c,(double)c/total);
    printf("%s\tG\t%ld\t%lf\n",chrname,g,(double)g/total);
    printf("# Number of bases:\t%ld\n",total);
    // add last count
    Aa = Aa + a;
    Tt = Tt + t;
    Cc = Cc + c;
    Gg = Gg + g;
    Total = Total + total;
    printf("\n# --------- Summary -----------\n");
    printf("# The number of sequences:\t%d\n",chr);
    printf("# The number of bases:\t%ld\n",Total);
    printf("# Total number of A:\t%ld\t%lf\n",Aa,(double)Aa/Total);
    printf("# Total number of T:\t%ld\t%lf\n",Tt,(double)Tt/Total);
    printf("# Total number of C:\t%ld\t%lf\n",Cc,(double)Cc/Total);
    printf("# Total number of G:\t%ld\t%lf\n",Gg,(double)Gg/Total);
    fclose(fp);
    return 0;
}
