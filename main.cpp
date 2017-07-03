#include <iostream>
#include <string.h>

using namespace std;

char a[100][100],aux[100][100],sirc[10];
int col[10]={1,7,15,23,31,39,47,55,63,69},lin[10]={1,4,9,14,19,24,29,34,39,43},t[10][10],aux2[10][10],coox,cooy,xra,yra,xrn,yrn;
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------



void init()
{
    int i,j,x,y;
    x=8;
    y=8;
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            aux2[i][j]=0;
        }
    }
    for(i=1;i<=8;i++)
    {
        y=8;
        for(j=1;j<=8;j++)
        {
            aux2[i][j]=t[x][y];
            y--;
        }
        x--;
    }
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            t[i][j]=aux2[i][j];
        }
    }
}

void selection(int x,int y)
{
    char c;
    c=254;
    x--;
    y--;
    y--;
    y--;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    x++;
    y=y-6;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
}

void afficher()
{
    int i,j;
    for (i=0;i<=45;i++)
    {
        for (j=0;j<=71;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}

void noir(int x,int y)
{
    x++;
    y--;
    a[x][y]='N';
    y++;
    a[x][y]='o';
    y++;
    a[x][y]='i';
}

void blch(int x,int y)
{
    x++;
    y--;
    a[x][y]='B';
    y++;
    a[x][y]='l';
    y++;
    a[x][y]='c';
}

void case_blanche(int x,int y)
{
    char c;
    c='#';
    x--;y--;y--;y--;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y=y-6;x++;a[x][y]=c;y=y+6;a[x][y]=c;x++;y=y-6;a[x][y]=c;y=y+6;a[x][y]=c;y=y-6;x++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;y++;a[x][y]=c;
}


void case_b(int xx,int yy)
{
    case_blanche(xx,yy);
    yy=yy-2;
    char c;
    c='#';
    a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;xx++;yy=yy-4;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;yy++;a[xx][yy]=c;
}

void case_n(int x,int y)
{
    char c;
    c='#';
    x--;y--;y--;y--;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y=y-6;x++;aux[x][y]=c;y=y+6;aux[x][y]=c;x++;y=y-6;aux[x][y]=c;y=y+6;aux[x][y]=c;y=y-6;x++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;y++;aux[x][y]=c;
}

void case_b2(int xx,int yy)
{
    case_n(xx,yy);
    yy=yy-2;
    char c;
    c='#';
    aux[xx][yy]=c;yy++;aux[xx][yy]=c;yy++;aux[xx][yy]=c;yy++;aux[xx][yy]=c;yy++;aux[xx][yy]=c;xx++;yy=yy-4;aux[xx][yy]=c;yy++;aux[xx][yy]=c;yy++;aux[xx][yy]=c;yy++;aux[xx][yy]=c;yy++;aux[xx][yy]=c;
}

void echiquie()
{
    int ok,x1,i,j;
    char charm;
    for (i=2;i<=42;i++)
    {
        if(i==2 || i==42)
        {
            x1=i;
            strcpy(aux[i],"    --------------------------------------------------------------- ");
        }
        else
        {
            if(i-5==x1)
            {
                strcpy(aux[i],"   |-------|-------|-------|-------|-------|-------|-------|-------|");
                x1=i;
            }
            else
                strcpy(aux[i],"   |       |       |       |       |       |       |       |       |");
        }
    }
    ok=1;
    for(i=1;i<=8;i++)
    {
        if (ok==1)
            ok=0;
        else
            ok=1;
        for(j=1;j<=8;j++)
        {
            if (ok==1)
                ok=0;
            else
                ok=1;
            if (ok==1)
            {
                if (t[i][j]==0)
                    case_b2(lin[i],col[j]);
                else
                    case_n(lin[i],col[j]);
            }
        }
    }
    i=lin[0];
    charm='A';
    for (j=1;j<=8;j++)
    {
        aux[i][col[j]]=charm;
        charm++;
    }
    i=lin[9];
    charm='A';
    for (j=1;j<=8;j++)
    {
        aux[i][col[j]]=charm;
        charm++;
    }
    j=col[0];
    charm='1';
    for (i=1;i<=8;i++)
    {
        aux[lin[i]][j]=charm;
        charm++;
    }
    j=col[9];
    charm='1';
    for (i=1;i<=8;i++)
    {
        aux[lin[i]][j]=charm;
        charm++;
    }
}

void deselection(int x,int y)
{
    char c;
    echiquie();
    x--;
    y--;
    y--;
    if (aux[x][y]==' ')
    {
        c=' ';
    }
    else
    {
        c='#';
    }
    y--;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    x++;
    y=y-6;
    a[x][y]=c;
    y=y+6;
    a[x][y]=c;
    y=y-6;
    x++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
    y++;
    a[x][y]=c;
}

void coeur()
{
    init();
    int i,j,x,y;
    echiquie();
    //--------------------------------------------------------------------------------------------
    for (i=1;i<=45;i++)
    {
        for (j=1;j<=71;j++)
        {
            if ((a[i][j]=='N' && a[i][j+1]=='o') || a[i][j]=='B')
            {
                a[i][j]=' ';
                j++;
                a[i][j]=' ';
                j++;
                a[i][j]=' ';
            }
        }
    }
    //--------------------------------------------------------------------------------------------
    x=8;
    for(i=1;i<=8;i++)
    {
        y=8;
        for(j=1;j<=8;j++)
        {
            aux[lin[i]][col[j]]=a[lin[x]][col[y]];
            y--;
        }
        x--;
    }
    for(i=1;i<=45;i++)
    {
        for(j=1;j<=71;j++)
        {
            a[i][j]=aux[i][j];
        }
    }
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(t[i][j]>0)
            {
                blch(lin[i],col[j]);
            }
            if(t[i][j]<0)
            {
                noir(lin[i],col[j]);
            }
        }
    }
}

void colonnes()
{
    coox=sirc[0]-48;
    if (sirc[1]=='A')
        cooy=1;
    if (sirc[1]=='B')
        cooy=2;
    if (sirc[1]=='C')
        cooy=3;
    if (sirc[1]=='D')
        cooy=4;
    if (sirc[1]=='E')
        cooy=5;
    if (sirc[1]=='F')
        cooy=6;
    if (sirc[1]=='G')
        cooy=7;
    if (sirc[1]=='H')
        cooy=8;
}

void rangees()
{
     char s2[3];
    s2[0]=0;
    s2[1]=0;
    if(sirc[0]>'0' && sirc[0]<'9')
    {
        if(sirc[1]>96 && sirc[1]<'I')
        {
            if (sirc[1]=='a')
                sirc[1]='A';
            if (sirc[1]=='b')
                sirc[1]='B';
            if (sirc[1]=='c')
                sirc[1]='C';
            if (sirc[1]=='d')
                sirc[1]='D';
            if (sirc[1]=='e')
                sirc[1]='E';
            if (sirc[1]=='f')
                sirc[1]='F';
            if (sirc[1]=='g')
                sirc[1]='G';
            if (sirc[1]=='h')
                sirc[1]='H';
        }
    }
    if(sirc[0]>96 && sirc[0]<'i')
    {
        if (sirc[0]=='a')
            sirc[0]='A';
        if (sirc[0]=='b')
            sirc[0]='B';
        if (sirc[0]=='c')
            sirc[0]='C';
        if (sirc[0]=='d')
            sirc[0]='D';
        if (sirc[0]=='e')
            sirc[0]='E';
        if (sirc[0]=='f')
            sirc[0]='F';
        if (sirc[0]=='g')
            sirc[0]='G';
        if (sirc[0]=='h')
            sirc[0]='H';
        s2[1]=sirc[0];
        s2[0]=sirc[1];
        sirc[0]=s2[0];
        sirc[1]=s2[1];
    }
    if (sirc[0]>=64 && sirc[0]<'i')
    {
        s2[1]=sirc[0];
        s2[0]=sirc[1];
        sirc[0]=s2[0];
        sirc[1]=s2[1];
    }
    colonnes();
}

int verifier_coor()
{
    cin>>sirc;
    if (strlen(sirc)==2)
    {
        if ((sirc[0]>'0' && sirc[0]<'9') || (sirc[0]>96 && sirc[0]<'i') || (sirc[0]>64 && sirc[0]<'I'))
        {
            if ((sirc[1]>'0' && sirc[1]<'9') || (sirc[1]>96 && sirc[1]<'i') || (sirc[1]>64 && sirc[1]<'I'))
            {
                if ((sirc[0]>'0' && sirc[0]<'9') && ((sirc[1]>96 && sirc[1]<'i') || (sirc[1]>=64 && sirc[1]<'I')))
                    return 1;
                if ((sirc[1]>'0' && sirc[1]<'9') && ((sirc[0]>96 && sirc[0]<'i') || (sirc[0]>=64 && sirc[0]<'I')))
                    return 1;
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

void supprimer(int x,int y)
{
    int t=0,i,j;
    y=y-2;
    x--;
    echiquie();
    if (aux[x][y]!=' ')
        t=1;
    y--;
    if (t==1)
    {
        for (i=x;i<=x+3;i++)
        {
            for (j=y;j<=y+6;j++)
            {
                a[i][j]='#';
            }
        }
    }
    else
    {
        for (i=x;i<=x+3;i++)
        {
            for (j=y;j<=y+6;j++)
            {
                a[i][j]=' ';
            }
        }
    }
}

void inserer(int x,int y)
{
    int z,w;
    z=lin[x];
    w=col[y];
    w--;
    w--;
    if (t[x][y]==1)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='P';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        blch(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==2)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='T';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        blch(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==3)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='C';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        blch(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==4)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='F';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        blch(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==5)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='D';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        blch(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==6)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='R';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        blch(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==-1)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='P';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        noir(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==-2)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='T';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        noir(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==-3)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='C';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        noir(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==-4)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='F';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        noir(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==-5)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='D';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        noir(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
    if (t[x][y]==-6)
    {
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]='R';
        w++;
        a[z][w]=' ';
        w++;
        a[z][w]=' ';
        w=w-2;
        noir(z,w);
        z++;
        w=w-2;
        a[z][w]=' ';
        w=w+4;
        a[z][w]=' ';
    }
}
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
int opposee(int xx1,int yy1,int xx2,int yy2)
{
    if (t[xx1][yy1]>0 && t[xx2][yy2]<0)
        return 1;
    if (t[xx1][yy1]<0 && t[xx2][yy2]>0)
        return 1;
    return 0;
}

int pion_inverse(int x1,int y1,int x2,int y2)
{
    int x;
    x=x1;
    if (t[x2][y2]==0 && y1==y2)
    {
        if (x1==7)
        {
            x1++;
            if (x1==x2)
                return 1;
            x1++;
            if (x1==x2)
                return 1;
        }
        x1=x;
        x1++;
        if(x1==x2)
            return 1;
    }
    if (t[x2][y2]!=0)
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            x1++;
            y1++;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
            y1--;
            y1--;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int pion(int x1,int y1,int x2,int y2)
{
    int x;
    x=x1;
    if (t[x2][y2]==0 && y1==y2)
    {
        if (x1==7)
        {
            x1--;
            if (x1==x2)
                return 1;
            x1--;
            if (x1==x2)
                return 1;
        }
        x1=x;
        x1--;
        if(x1==x2)
            return 1;
    }
    if (t[x2][y2]!=0)
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            x1--;
            y1--;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
            y1++;
            y1++;
            if (x1==x2 && y1==y2)
            {
                return 1;
            }
        }
    }
    return 0;
}

int tour(int x1,int y1,int x2,int y2)
{
    int i,ok=1;
    if (t[x2][y2]==0)
    {
        if (y1==y2)
        {
            if (x1<x2)
                for (i=x1+1;i<=x2;i++)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            else
                for (i=x1-1;i>=x2;i--)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
        if (x1==x2)
        {
            if (y1<y2)
                for (i=y1+1;i<=y2;i++)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            else
                for (i=y1-1;i>=y2;i--)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
    }
    else
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            if (y1==y2)
            {
                if (x1<x2)
                    for (i=x1+1;i<x2;i++)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                else
                    for (i=x1-1;i>x2;i--)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
            if (x1==x2)
            {
                if (y1<y2)
                    for (i=y1+1;i<y2;i++)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                else
                    for (i=y1-1;i>y2;i--)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
        }
    }
    return 0;
}

int cavalier(int x1,int y1,int x2,int y2)
{
    if (t[x2][y2]==0)
    {
        if (x1-2==x2 && y1+1==y2)
            return 1;
        if (x1-2==x2 && y1-1==y2)
            return 1;
        if (x1+1==x2 && y1-2==y2)
            return 1;
        if (x1-1==x2 && y1-2==y2)
            return 1;
        if (x1+2==x2 && y1+1==y2)
            return 1;
        if (x1+2==x2 && y1-1==y2)
            return 1;
        if (x1-1==x2 && y1+2==y2)
            return 1;
        if (x1+1==x2 && y1+2==y2)
            return 1;
    }
    else
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            if (x1-2==x2 && y1+1==y2)
                return 1;
            if (x1-2==x2 && y1-1==y2)
                return 1;
            if (x1+1==x2 && y1-2==y2)
                return 1;
            if (x1-1==x2 && y1-2==y2)
                return 1;
            if (x1+2==x2 && y1+1==y2)
                return 1;
            if (x1+2==x2 && y1-1==y2)
                return 1;
            if (x1-1==x2 && y1+2==y2)
                return 1;
            if (x1+1==x2 && y1+2==y2)
                return 1;
        }
    }
    return 0;
}

int fou(int x1,int y1,int x2,int y2)
{
    int i,j,ok;
    if (t[x2][y2]==0)
    {
        ok=1;
        i=x1;
        j=y1;
        if (x1>x2 && y1<y2)
        while (i>x2 && j<y2)
        {
            i--;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1<y2)
        while (i<x2 && j<y2)
        {
            i++;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1>y2)
        while (i<x2 && j>y2)
        {
            i++;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1>x2 && y1>y2)
        while (i>x2 && j>y2)
        {
            i--;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            ok=1;
            i=x1;
            j=y1;
            if (x1>x2 && y1<y2)
            while (i>=x2 && j<=y2)
            {
                i--;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1<y2)
            while (i<=x2 && j<=y2)
            {
                i++;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1>y2)
            while (i<=x2 && j>=y2)
            {
                i++;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1>x2 && y1>y2)
            while (i>=x2 && j>=y2)
            {
                i--;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int dame(int x1,int y1,int x2,int y2)
{
    int i,j,ok=1;
    if (t[x2][y2]==0)
    {
        if (y1==y2)
        {
            if (x1<x2)
                for (i=x1+1;i<=x2;i++)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            else
                for (i=x1-1;i>=x2;i--)
                {
                    if (t[i][y1]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }
        if (x1==x2)
        {
            if (y1<y2)
                for (i=y1+1;i<=y2;i++)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            else
                for (i=y1-1;i>=y2;i--)
                {
                    if (t[x1][i]!=0)
                        ok=0;
                }
            if (ok==1)
                return 1;
        }

        ok=1;
        i=x1;
        j=y1;
        if (x1>x2 && y1<y2)
        while (i>x2 && j<y2)
        {
            i--;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1<y2)
        while (i<x2 && j<y2)
        {
            i++;
            j++;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1<x2 && y1>y2)
        while (i<x2 && j>y2)
        {
            i++;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
        i=x1;
        j=y1;
        if (x1>x2 && y1>y2)
        while (i>x2 && j>y2)
        {
            i--;
            j--;
            if (t[i][j]!=0)
            {
                ok=0;
            }
            if (i==x2 && j==y2)
            {
                if (ok==1)
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            if (y1==y2)
            {
                if (x1<x2)
                    for (i=x1+1;i<x2;i++)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                else
                    for (i=x1-1;i>x2;i--)
                    {
                        if (t[i][y1]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }
            if (x1==x2)
            {
                if (y1<y2)
                    for (i=y1+1;i<y2;i++)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                else
                    for (i=y1-1;i>y2;i--)
                    {
                        if (t[x1][i]!=0)
                            ok=0;
                    }
                if (ok==1)
                    return 1;
            }

            ok=1;
            i=x1;
            j=y1;
            if (x1>x2 && y1<y2)
            while (i>=x2 && j<=y2)
            {
                i--;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1<y2)
            while (i<=x2 && j<=y2)
            {
                i++;
                j++;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1<x2 && y1>y2)
            while (i<=x2 && j>=y2)
            {
                i++;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
            i=x1;
            j=y1;
            if (x1>x2 && y1>y2)
            while (i>=x2 && j>=y2)
            {
                i--;
                j--;
                if (t[i][j]!=0 && i!=x2 )
                {
                    ok=0;
                }
                if (i==x2 && j==y2)
                {
                    if (ok==1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int roi(int x1,int y1,int x2,int y2)
{
    int i,j;
    if (t[x2][y2]==0)
    {
        i=x1;
        j=y1;
        i++;
        j++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i--;
        j++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i++;
        j--;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i--;
        j--;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        i--;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        j++;
        if (i==x2 && j==y2)
            return 1;
        i=x1;
        j=y1;
        j--;
        if (i==x2 && j==y2)
            return 1;
    }
    else
    {
        if (opposee(x1,y1,x2,y2)==1)
        {
            i=x1;
            j=y1;
            i++;
            j++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i--;
            j++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i++;
            j--;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i--;
            j--;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            i--;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            j++;
            if (i==x2 && j==y2)
                return 1;
            i=x1;
            j=y1;
            j--;
            if (i==x2 && j==y2)
                return 1;
        }
    }
    return 0;
}

void pion_de_changement(int x1,int y1)
{
    int ok=0;
    char ch;
    while (ok==0)
    {
        cout<<"    Replacement avec (T,C,F,D):";
        cin>>ch;
        if (ch=='t')
            ch='T';
        if (ch=='c')
            ch='C';
        if (ch=='f')
            ch='F';
        if (ch=='d')
            ch='D';
        if (ch=='T')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=2;
                inserer(x1,y1);
                blch(lin[x1],col[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-2;
                inserer(x1,y1);
                noir(lin[x1],col[y1]);
                ok=1;
            }
        }
        if (ch=='C')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=3;
                inserer(x1,y1);
                blch(lin[x1],col[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-3;
                inserer(x1,y1);
                noir(lin[x1],col[y1]);
                ok=1;
            }
        }
        if (ch=='F')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=4;
                inserer(x1,y1);
                blch(lin[x1],col[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-4;
                inserer(x1,y1);
                noir(lin[x1],col[y1]);
                ok=1;
            }
        }
        if (ch=='D')
        {
            if (t[x1][y1]>0)
            {
                t[x1][y1]=5;
                inserer(x1,y1);
                noir(lin[x1],col[y1]);
                ok=1;
            }
            if (t[x1][y1]<0)
            {
                t[x1][y1]=-5;
                inserer(x1,y1);
                noir(lin[x1],col[y1]);
                ok=1;
            }
        }
    }
}

int echecs(int xx1,int yy1)
{
    int i,j;
    if (t[xx1][yy1]>0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                if (t[i][j]<0)
                {
                    if (t[i][j]==-1)
                    {
                        if (pion_inverse(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-2)
                    {
                        if (tour(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-3)
                    {
                        if (cavalier(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-4)
                    {
                        if (fou(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-5)
                    {
                        if (dame(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==-6)
                    {
                        if (roi(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if (t[xx1][yy1]<0)
    {
         for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                if (t[i][j]>0)
                {
                    if (t[i][j]==1)
                    {
                        if (pion_inverse(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==2)
                    {
                        if (tour(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==3)
                    {
                        if (cavalier(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==4)
                    {
                        if (fou(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==5)
                    {
                        if (dame(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                    if (t[i][j]==6)
                    {
                        if (roi(i,j,xx1,yy1)==1)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int verifier(int x1,int y1,int x2,int y2)
{
    if (t[x1][y1]>0)
        if (x1==x2)
            if (t[x1][y1]==6)
            {
                if (t[x2][y2]==2)
                {
                    if (y2-y1==3)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0)
                        {
                            return 1;
                        }
                    }
                    if (y1-y2==4)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0 && t[x1][y1-3]==0)
                        {
                            return 1;
                        }
                    }
                }
            }
    if (t[x1][y1]<0)
    {
        if (x1==x2)
            if (t[x1][y1]==-6)
            {
                if (t[x2][y2]==-2)
                {
                    if (y1-y2==3)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0)
                        {
                            return 1;
                        }
                    }
                    if (y2-y1==4)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0 && t[x1][y1+3]==0)
                        {
                            return 1;
                        }
                    }
                }
            }
    }
    return 0;
}

void la_rocada(int x1,int y1,int x2,int y2)
{
    // La Recada est le changement du place entre le roi ey le tour !!!!!!!

    if (t[x1][y1]>0)
        if (x1==x2)
            if (t[x1][y1]==6)
            {
                if (t[x2][y2]==2)
                {
                    if (y2-y1==3)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0)
                        {
                            t[x1][y1+1]=2;
                            t[x1][y1+2]=6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col[y1+1]]='T';
                            inserer(x1,y1+1);
                            a[lin[x1]][col[y1+2]]='R';
                            inserer(x1,y1+2);
                            supprimer(lin[x1],col[y1]);
                            supprimer(lin[x2],col[y2]);
                        }
                    }
                    if (y1-y2==4)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0 && t[x1][y1-3]==0)
                        {
                            t[x1][y1-1]=2;
                            t[x1][y1-2]=6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col[y1-1]]='T';
                            inserer(x1,y1-1);
                            a[lin[x1]][col[y1-2]]='R';
                            inserer(x1,y1-2);
                            supprimer(lin[x1],col[y1]);
                            supprimer(lin[x2],col[y2]);
                        }
                    }
                }
            }
    if (t[x1][y1]<0)
    {
        if (x1==x2)
            if (t[x1][y1]==-6)
            {
                if (t[x2][y2]==-2)
                {
                    if (y1-y2==3)
                    {
                        if (t[x1][y1-1]==0 && t[x1][y1-2]==0)
                        {
                            t[x1][y1-1]=-2;
                            t[x1][y1-2]=-6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col[y1-1]]='T';
                            inserer(x1,y1-1);
                            a[lin[x1]][col[y1-2]]='R';
                            inserer(x1,y1-2);
                            supprimer(lin[x1],col[y1]);
                            supprimer(lin[x2],col[y2]);
                        }
                    }
                    if (y2-y1==4)
                    {
                        if (t[x1][y1+1]==0 && t[x1][y1+2]==0 && t[x1][y1+3]==0)
                        {
                            t[x1][y1+1]=-2;
                            t[x1][y1+2]=-6;
                            t[x1][y1]=0;
                            t[x2][y2]=0;
                            a[lin[x1]][col[y1+1]]='T';
                            inserer(x1,y1+1);
                            a[lin[x1]][col[y1+2]]='R';
                            inserer(x1,y1+2);
                            supprimer(lin[x1],col[y1]);
                            supprimer(lin[x2],col[y2]);
                        }
                    }
                }
            }
    }
}

int deplacer(int coox1,int cooy1,int coox2,int cooy2)
{
    if (t[coox1][cooy1]==1)
    {
        if (pion(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==2)
    {
        if (tour(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==3)
    {
        if (cavalier(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==4)
    {
        if (fou(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==5)
    {
        if (dame(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==6)
    {
        if (roi(coox1,cooy1,coox2,cooy2)==1)
        {
            t[coox2][cooy2]=6;
            if (echecs(coox2,cooy2)==0)
                return 1;
            t[coox2][cooy2]=0;
        }
        return 0;
    }
    if (t[coox1][cooy1]==-1)
    {
        if (pion(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-2)
    {
        if (tour(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-3)
    {
        if (cavalier(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-4)
    {
        if (fou(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-5)
    {
        if (dame(coox1,cooy1,coox2,cooy2)==1)
            return 1;
        else
            return 0;
    }
    if (t[coox1][cooy1]==-6)
    {
        if (roi(coox1,cooy1,coox2,cooy2)==1)
        {
            t[coox2][cooy2]=-6;
            if (echecs(coox2,cooy2)==0)
                return 1;
            t[coox2][cooy2]=0;
        }
        return 0;
    }
    return 0;
}

int echec_mat(int x,int y)
{
    int i,j,ok=1,i2,j2,z,w,var,var2;
    if (t[x][y]>0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]>0)
                        {
                            if (t[i2][j2]==1)
                            {
                                if (pion(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=1;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==2)
                            {
                                if (tour(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=2;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==3)
                            {
                                if (cavalier(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=3;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==4)
                            {
                                if (fou(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=4;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==5)
                            {
                                if (dame(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=5;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==6)
                            {
                                if (roi(i2,j2,i,j)==1)
                                {
                                    z=i;
                                    w=j;
                                    var=t[z][w];
                                    t[i2][j2]=0;
                                    t[z][w]=6;
                                    if (echecs(z,w)==0)
                                    {
                                        ok=0;
                                    }
                                    t[z][w]=var;
                                    t[i2][j2]=6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (t[x][y]<0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]<0)
                        {
                            if (t[i2][j2]==-1)
                            {
                                if (pion(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-1;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-2)
                            {
                                if (tour(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-2;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-3)
                            {
                                if (cavalier(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-3;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-4)
                            {
                                if (fou(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-4;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-5)
                            {
                                if (dame(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-5;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=0;
                                    }
                                    t[i2][j2]=-5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-6)
                            {
                                if (roi(i2,j2,i,j)==1)
                                {
                                    z=i;
                                    w=j;
                                    var=t[z][w];
                                    t[i2][j2]=0;
                                    t[z][w]=-6;
                                    if (echecs(z,w)==0)
                                    {
                                        ok=0;
                                    }
                                    t[z][w]=var;
                                    t[i2][j2]=-6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ok==1)
        return 1;
    else
        return 0;
}

int lire(int x,int y)
{
    int i,j,i2,j2,ok=0,z,w,var;
    if (t[x][y]>0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]>0)
                        {
                            if (t[i2][j2]==1)
                            {
                                if (pion(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=1;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==2)
                            {
                                if (tour(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=2;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==3)
                            {
                                if (cavalier(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=3;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==4)
                            {
                                if (fou(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=4;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==5)
                            {
                                if (dame(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=5;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==6)
                            {
                                if (roi(i2,j2,i,j)==1)
                                {
                                    z=i;
                                    w=j;
                                    var=t[z][w];
                                    t[i2][j2]=0;
                                    t[z][w]=6;
                                    if (echecs(z,w)==0)
                                    {
                                        ok=1;
                                    }
                                    t[z][w]=var;
                                    t[i2][j2]=6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (t[x][y]<0)
    {
        for (i=1;i<=8;i++)
        {
            for (j=1;j<=8;j++)
            {
                for (i2=1;i2<=8;i2++)
                {
                    for (j2=1;j2<=8;j2++)
                    {
                        if (t[i2][j2]<0)
                        {
                            if (t[i2][j2]==-1)
                            {
                                if (pion(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-1;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-1;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-2)
                            {
                                if (tour(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-2;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-2;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-3)
                            {
                                if (cavalier(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-3;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-3;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-4)
                            {
                                if (fou(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-4;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-4;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-5)
                            {
                                if (dame(i2,j2,i,j)==1)
                                {
                                    var=t[i][j];
                                    t[i][j]=-5;
                                    t[i2][j2]=0;
                                    if (echecs(x,y)==0)
                                    {
                                        ok=1;
                                    }
                                    t[i2][j2]=-5;
                                    t[i][j]=var;
                                }
                            }
                            if (t[i2][j2]==-6)
                            {
                                if (roi(i2,j2,i,j)==1)
                                {
                                    z=i;
                                    w=j;
                                    var=t[z][w];
                                    t[i2][j2]=0;
                                    t[z][w]=-6;
                                    if (echecs(z,w)==0)
                                    {
                                        ok=1;
                                    }
                                    t[z][w]=var;
                                    t[i2][j2]=-6;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ok==1)
        return 1;
    else
        return 0;
}

int main()
{
    int i,j,ok,x1,x2,y1,y2,blanche[4]={0,1,1,1},noire[4]={0,1,1,1};
    char p1[256],p2[256],charm;
    xra=8;
    yra=5;
    xrn=8;
    yrn=4;
    cout<<endl;
    cout<<"    Joueur 1:";
    cin>>p1;
    cout<<"    Joueur 2:";
    cin>>p2;
    cout<<endl;
    cout<<endl;
    cout<<"    ***********************************************************************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"    Regles:";
    cout<<endl;
    cout<<endl;
    cout<<"    Pour deplacer une piece, tapez les coordonnees de cette piece pour la selectionner" <<endl;
    cout<<"    et ensuite les coordonnees de la destination."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"    ***********************************************************************************"<<endl;
    cout<<endl;
    cout<<"         !!!!!!!!!! ATTENTION !!!!!!!!!!"<<endl;
    cout<<"    Ce jeu n'accepte pas la regle en passant !! .";
    cout<<endl;
    cout<<endl;
    cout<<"    ***********************************************************************************"<<endl;
    cout<<endl;
    cout<<"    Pour deselectionner une piece, selectionnez-la a nouveau.";
    cout<<endl<<endl;
    cout<<"    ***********************************************************************************"<<endl;
    cout<<endl;
    cout<<"    Specifications:";
    cout<<endl;
    cout<<endl;
    cout<<"    P = Pion";
    cout<<endl;
    cout<<"    T = Tour";
    cout<<endl;
    cout<<"    F = Fou";
    cout<<endl;
    cout<<"    C = Cavalier";
    cout<<endl;
    cout<<"    D = Dame";
    cout<<endl;
    cout<<"    R = Roi";
    cout<<endl<<endl;
    cout<<"    ***********************************************************************************"<<endl;
    cout<<endl<<endl;
    cout<<"    Le jeu est commence' :";
    cout<<endl<<endl;



    //Teste

    i=2;
    for (j=1;j<=8;j++)
    {
        t[i][j]=-1;
    }
    i=7;
    for (j=1;j<=8;j++)
    {
        t[i][j]=1;
    }
    x1=1;
    x2=8;
    y1=1;
    y2=8;
    t[x1][y1]=-2;
    t[x1][y2]=-2;
    t[x2][y1]=2;
    t[x2][y2]=2;

    y1=2;
    y2=7;
    t[x1][y1]=-3;
    t[x1][y2]=-3;
    t[x2][y1]=3;
    t[x2][y2]=3;

    y1=3;
    y2=6;
    t[x1][y1]=-4;
    t[x1][y2]=-4;
    t[x2][y1]=4;
    t[x2][y2]=4;

    y1=4;
    y2=5;
    t[x1][y1]=-5;
    t[x1][y2]=-6;
    t[x2][y1]=5;
    t[x2][y2]=6;


//--------------------------------------------------------------------------------------------


    for (i=2;i<=42;i++)
    {
        if(i==2 || i==42)
        {
            x1=i;
            strcpy(a[i],"    --------------------------------------------------------------- ");
        }
        else
        {
            if(i-5==x1)
            {
                strcpy(a[i],"   |-------|-------|-------|-------|-------|-------|-------|-------|");
                x1=i;
            }
            else
                strcpy(a[i],"   |       |       |       |       |       |       |       |       |");
        }
    }
//--------------------------------------------------------------------------------------------
    ok=1;
    for(i=1;i<=8;i++)
    {
        if (ok==1)
            ok=0;
        else
            ok=1;
        for(j=1;j<=8;j++)
        {
            if (ok==1)
                ok=0;
            else
                ok=1;
            if (ok==1)
            {
                if (t[i][j]==0)
                    case_b(lin[i],col[j]);
                else
                    case_blanche(lin[i],col[j]);
            }
        }
    }
//--------------------------------------------------------------------------------------------
    i=lin[0];
    charm='a';
    for (j=1;j<=8;j++)
    {
        a[i][col[j]]=charm;
        charm++;
    }
    i=lin[9];
    charm='a';
    for (j=1;j<=8;j++)
    {
        a[i][col[j]]=charm;
        charm++;
    }
    j=col[0];
    charm='1';
    for (i=1;i<=8;i++)
    {
        a[lin[i]][j]=charm;
        charm++;
    }
    j=col[9];
    charm='1';
    for (i=1;i<=8;i++)
    {
        a[lin[i]][j]=charm;
        charm++;
    }
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//Test
    i=lin[2];
    for (j=1;j<=8;j++)
    {
       a[i][col[j]]='P';
       noir(i,col[j]);
    }
    i=lin[7];
    for (j=1;j<=8;j++)
    {
       a[i][col[j]]='P';
       blch(i,col[j]);
    }

    x1=lin[1];
    x2=lin[8];
    y1=col[1];
    y2=col[8];
    a[x1][y1]='T';
    a[x1][y2]='T';
    a[x2][y1]='T';
    a[x2][y2]='T';

    y1=col[2];
    y2=col[7];
    a[x1][y1]='C';
    a[x1][y2]='C';
    a[x2][y1]='C';
    a[x2][y2]='C';

    y1=col[3];
    y2=col[6];
    a[x1][y1]='F';
    a[x1][y2]='F';
    a[x2][y1]='F';
    a[x2][y2]='F';

    y1=col[4];
    y2=col[5];
    a[x1][y1]='D';
    a[x1][y2]='R';
    a[x2][y1]='D';
    a[x2][y2]='R';
//--------------------------------------------------------------------------------------------
    i=lin[1];
    for(j=1;j<=8;j++)
    {
        noir(i,col[j]);
    }
    i=lin[8];
    for(j=1;j<=8;j++)
    {
        blch(i,col[j]);
    }
    //C'est un test
//--------------------------------------------------------------------------------------------
    int sw=2,okk,z,w,okkk,dis,ok10,echc=0,v,v2,sm=0;
    ok=1;
    while(ok==1)
    {
        afficher();
        if(sw==1)
            sw=2;
        else
            sw=1;
        if (sw==1)
            cout<<"    "<<p1<<" C'est ton tour:";
        else
            cout<<"    "<<p2<<" C'est ton tour:";
        okk=0;
        while(okk==0)
        {
            if (verifier_coor()==1)
                if (sw==1)
                {
                    rangees();
                    if(t[coox][cooy]>0)
                        okk=1;
                    else
                        cout<<"    Coordonnees incorrectes:";
                }
                else
                {
                    rangees();
                    if(t[coox][cooy]<0)
                        okk=1;
                    else
                        cout<<"    Coordonnees incorrectes:";
                }
            else
                cout<<"    Coordonnees incorrectes:";
        }
        okkk=0;
        selection(lin[coox],col[cooy]);
        z=coox;
        w=cooy;
        dis=1;
        ok10=0;
        while(okkk==0)
        {
            afficher();
            if (echc==1)
                cout<<"    Vous etes en echec:";
            echc=0;
            if (dis==1)
            {
                z=coox;
                w=cooy;
                cout<<"    Deplacer sur les coordonnees:";
            }
            if (ok10==1 && dis==0)
                cout<<"    Deplacement rejete'. Reessayer :";
            dis=0;
            ok10=0;
            if (verifier_coor()==1)
            {
                rangees();
                if (coox==z && cooy==w)
                {
                    dis=1;
                    deselection(lin[coox],col[cooy]);
                    okk=0;
                    afficher();
                    cout<<"    Nouvelles coordonnees:";
                    while(okk==0)
                    {
                        if (verifier_coor()==1)
                            if (sw==1)
                            {
                                rangees();
                                if(t[coox][cooy]>0)
                                    okk=1;
                                else
                                    cout<<"    Coordonnees incorrectes:";
                            }
                            else
                            {
                                rangees();
                                if(t[coox][cooy]<0)
                                    okk=1;
                                else
                                    cout<<"    Coordonnees incorrectes:";
                            }
                        else
                            cout<<"    Coordonnees incorrectes:";
                    }
                    selection(lin[coox],col[cooy]);
                }
            }
            if(deplacer(z,w,coox,cooy)==1)
            {
                if (sw==1)
                {
                    if (z==8 && w==1)
                        blanche[1]=0;
                    if (z==8 && w==5)
                    {
                        blanche[2]=0;
                    }
                    if (z==8 && w==8)
                        blanche[3]=0;
                }
                else
                {
                    if (z==8 && w==1)
                        noire[1]=0;
                    if (z==8 && w==4)
                        noire[2]=0;
                    if (z==8 && w==8)
                        noire[3]=0;
                }
                if (t[z][w]==6)
                {
                    xra=coox;
                    yra=cooy;
                }
                if (t[z][w]==-6)
                {
                    xrn=coox;
                    yrn=cooy;
                }
                if (sw==1)
                {
                    if (echecs(xra,yra)==0)
                    {
                        v2=t[coox][cooy];
                        t[coox][cooy]=t[z][w];
                        t[z][w]=0;
                        if (echecs(xra,yra)==0)
                        {
                            okkk=1;
                            deselection(lin[z],col[w]);
                            supprimer(lin[z],col[w]);
                            inserer(coox,cooy);
                        }
                        else
                        {
                            t[z][w]=t[coox][cooy];
                            t[coox][cooy]=v2;
                        }
                    }
                    else
                    {
                        echc=1;
                        v=t[coox][cooy];
                        t[coox][cooy]=9;
                        if (echecs(xra,yra)==0)
                        {
                            echc=0;
                            okkk=1;
                            t[coox][cooy]=t[z][w];
                            t[z][w]=0;
                            deselection(lin[z],col[w]);
                            supprimer(lin[z],col[w]);
                            inserer(coox,cooy);
                        }
                        else
                        {
                            t[coox][cooy]=v;
                        }
                    }
                }
                else
                {
                    if (echecs(xrn,yrn)==0)
                    {
                        v2=t[coox][cooy];
                        t[coox][cooy]=t[z][w];
                        t[z][w]=0;
                        if (echecs(xrn,yrn)==0)
                        {
                            okkk=1;
                            deselection(lin[z],col[w]);
                            supprimer(lin[z],col[w]);
                            inserer(coox,cooy);
                        }
                        else
                        {
                            t[z][w]=t[coox][cooy];
                            t[coox][cooy]=v2;
                        }
                    }
                    else
                    {
                        echc=1;
                        v=t[coox][cooy];
                        t[coox][cooy]=9;
                        if (echecs(xrn,yrn)==0)
                        {
                            echc=0;
                            okkk=1;
                            t[coox][cooy]=t[z][w];
                            t[z][w]=0;
                            deselection(lin[z],col[w]);
                            supprimer(lin[z],col[w]);
                            inserer(coox,cooy);
                        }
                        else
                        {
                            t[coox][cooy]=v;
                        }
                    }
                }

            }
            else
            {
                ok10=1;
                if (sw==1)
                {
                    if (z==8 && w==5)
                    {
                        if (blanche[1]==1 && blanche[2]==1 && coox==8 && cooy==1)
                        {
                            if (verifier(z,w,coox,cooy)==1)
                            {
                                blanche[1]=0;
                                blanche[2]=0;
                                deselection(lin[z],col[w]);
                                la_rocada(z,w,coox,cooy);
                                okkk=1;
                            }
                        }
                        else
                        {
                            if (blanche[2]==1 && blanche[3]==1 && coox==8 && cooy==8)
                            {
                                if (verifier(z,w,coox,cooy)==1)
                                {
                                    blanche[2]=0;
                                    blanche[3]=0;
                                    deselection(lin[z],col[w]);
                                    la_rocada(w,z,coox,cooy);
                                    okkk=1;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (z==8 && w==4)
                    {
                        if (noire[1]==1 && noire[2]==1 && coox==8 && cooy==1)
                        {
                            if (verifier(z,w,coox,cooy)==1)
                            {
                                noire[1]=0;
                                noire[2]=0;
                                deselection(lin[z],col[w]);
                                la_rocada(z,w,coox,cooy);
                                okkk=1;
                            }
                        }
                        else
                        {
                            if (noire[2]==1 && noire[3]==1 && coox==8 && cooy==8)
                            {
                                if (verifier(z,w,coox,cooy)==1)
                                {
                                    noire[2]=0;
                                    noire[3]=0;
                                    deselection(lin[z],col[w]);
                                    la_rocada(z,w,coox,cooy);
                                    okkk=1;

                                }
                            }
                        }
                    }
                }
            }
        }
        i=1;
        for (j=1;j<=8;j++)
        {
            if (sw==1)
            {
                if (t[i][j]==1)
                {
                    pion_de_changement(i,j);
                }
            }
            else
            {
                if (t[i][j]==-1)
                {
                    pion_de_changement(i,j);
                }
            }
        }
        coeur();
        if (sw==1)
        {
            if (echecs(xrn,yrn)==1)
            {
                if(echec_mat(xrn,yrn)==1)
                {
                    ok=0;
                    sm=1;
                }
            }
        }
        else
        {
            if (echecs(xra,yra)==1)
            {
                if (echec_mat(xra,yra)==1)
                {
                    ok=0;
                    sm=1;
                }
            }
        }
        if (sw==1)
        {
            if (lire(xrn,yrn)==0)
            {
                ok=0;
            }
        }
        else
        {
            if (lire(xra,yra)==0)
            {
                ok=0;
            }
        }
    }
    afficher();
    if (sm==1)
    {
        cout<<"    Check Mate !!!"<<endl<<endl;
        cout<<"    Le gagnant est : ";
        if (sw==1)
            cout<<p1<<" !!!";
        else
            cout<<p2<<" !!!";
    }
    else
        cout<<"    C'est un Pat !!! ."<<endl;;

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------
//----------------------------------------FIN-------------------------------------------------
}
