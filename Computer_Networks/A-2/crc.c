#include<stdio.h>
int main()
{
    int i,j,k,l;
     
    //Get Frame
    int fs;
    printf("\n Enter Size of data: ");
    scanf("%d",&fs);
     
    int f[20];
     
    printf(" Enter data:");
    for(i=0;i<fs;i++)
    {
        scanf("%d",&f[i]);
    }
 
    //Get Generator
    int gs;
    printf("\n Enter key size: ");
    scanf("%d",&gs);
     
    int g[20];
     
    printf("\n Enter key:");
    for(i=0;i<gs;i++)
    {
        scanf("%d",&g[i]);
    }
 
    printf("\n Sender Side:");
    printf("\n data: ");
    for(i=0;i<fs;i++)
    {
        printf("%d",f[i]);
    }
    printf("\n key :");
    for(i=0;i<gs;i++)
    {
        printf("%d",g[i]);
    }
 
    //Append 0's
    int rs=gs-1;
    printf("\n Number of 0's to be appended: %d",rs);
    for (i=fs;i<fs+rs;i++)
    {
        f[i]=0;
    }
 
    int temp[20];
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    printf("\n Message after appending 0's :");
    for(i=0; i<fs+rs;i++)
    {
        printf("%d",temp[i]);
    }
 
    //Division
    for(i=0;i<fs;i++)
    {
        j=0;
        k=i;
        //check whether it is divisible or not
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    printf("\n CRC bits: ");
    for(i=0;i<rs;i++)
    {
        printf("%d",crc[i]);
    }
 
    printf("\n Transmitted Frame: ");
    int tf[15];
    for(i=0;i<fs;i++)
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)
    {
        printf("%d",tf[i]);
    }
 
    printf("\n Receiver side : ");
    printf("\n Received Frame: ");
    for(i=0;i<fs+rs;i++)
    {
        printf("%d",tf[i]);
    }
 
    for(i=0;i<fs+rs;i++)
    {
        temp[i]=tf[i];
    }
 
    //Division
    for(i=0;i<fs+rs;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    printf("\n Remainder: ");
    int rrem[15];
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)
    {
        printf("%d",rrem[i]);
    }
 
    int flag=0;
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        printf("\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correct");
    }
    else
    {
        printf("\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receriver Contains Error");
    }
return 0;
}




/*output:
res@res-HP-280-G2-MT-Legacy:~$ g++ crc.cpp
res@res-HP-280-G2-MT-Legacy:~$ ./a.out

 Enter Size of data: 10
 Enter data:1
1
0
1
0
1
1
0
1
1

 Enter key size: 5

 Enter key:1
0
0
1
1

 Sender Side:
 data: 1101011011
 key :10011
 Number of 0's to be appended: 4
 Message after appending 0's :11010110110000
 CRC bits: 1110
 Transmitted Frame: 11010110111110
 Receiver side : 
 Received Frame: 11010110111110
 Remainder: 0000
 Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correctres@res-HP-280-G2-MT-Legacy:~$ 

*/

