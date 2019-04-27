#include<iostream>
using namespace std;
//------------------------------------------------------------------   // Martyna Grabelus
int rok_przestepny( int r );
int dni_w_miesiacu( int m, int r );
//------------------------------------------------------------------------------
int main()
{

	int r1, r2, m1, m2, d1, d2, g1, g2, min1, min2, s1, s2, d;
	
	do
	{
	cin>>d;	
	}while(d<1 || d>2000);

	d = d*2;
	//-------------------------------------------------------  //tworzenie dynamicznej tablicy dwuwymiarowej / generowanie poszczegolnych wymiarów
	int ** tablica = new int * [ d ];
	
	
     for (int i = 0; i<d; i++)
          tablica[i] = new int [d];
	//-------------------------------------------------------
	for(int i=0 ; i<d ; i++ )
	{
		do
		{
		cin>>tablica[i][0]>>tablica[i][1]>>tablica[i][2]>>tablica[i][3]>>tablica[i][4]>>tablica[i][5];
		}while( tablica[i][0]<1600 || tablica[i][0]>2500 || tablica[i][1]<1 || tablica[i][1]>12 || tablica[i][2]<1 || tablica[i][2]>31 || tablica[i][3]<0 || tablica[i][3]>23 || tablica[i][4]<0 || tablica[i][4]>59 || tablica[i][5]<0 || tablica[i][5]>59 );
	}
	//-------------------------------------------------------
	for( int i=0 ; i<d ; i=i+2 )
	{
		r1=tablica[i][0];
		m1=tablica[i][1];
		d1=tablica[i][2];
		g1=tablica[i][3];
		min1=tablica[i][4];
		s1=tablica[i][5];
		
		r2=tablica[i+1][0];
		m2=tablica[i+1][1];
		d2=tablica[i+1][2];
		g2=tablica[i+1][3];
		min2=tablica[i+1][4];
		s2=tablica[i+1][5];
		
	     
	      //  pierwsza data poczatek
	       int tx1=0;
	
	     for(int i=0; i<m1 ; i++ )
	          tx1=tx1 + dni_w_miesiacu( i , r1 );
	
	        tx1=tx1+d1;
	     
	      //  pierwsza data koniec
	       // int xx1=0;
	       // xx1= rok_przestepny(  r1 ) ;
	       // xx1=xx1 - tx1;
	
	      // druga data poczatek
	        int tx2=0;
	
	        for(int i=0; i<m2 ; i++ )
	         tx2=tx2 + dni_w_miesiacu( i ,  r2 );
	
	         tx2=tx2+d2;
	      
	      // druga data koniec
	         int xx2=0;
 	         xx2= rok_przestepny(  r2 ) ;
	         xx2=xx2 - tx2;
		  
	
	      // zusamen do kupy  
	         int suma=0;
	
	         for( int i=r1 ; i<=r2 ; i++ )
                 suma = suma + rok_przestepny(  i );
		
                 suma=suma -tx1 -xx2;


	         s1= s1 + min1*60 + g1*60*60;
             s2= s2 + min2*60 + g2*60*60;
	
	
	        if(s1>s2)
	        {
	        	suma=suma-1;
	        	
	        	if(suma<0)
	        	   suma=0;
	        	
			}
               
	
	
	
	cout<<suma<<endl;
	}
	
	//-----------------------------------------------------   //zwalnianie pamieci
	for (int i = 0; i<d; i++)
         delete [] tablica[i];

	
	delete [] tablica;
	//-----------------------------------------------------
	cout<<endl<<endl;
	system("pause");
	return 0;
	//------------------------------------------------------
}
//------------------------------------------------------------------
int rok_przestepny( int r )
{
	int x;
    if(( r % 4 == 0 ) &&(( r % 400 == 0 ) ||( r % 100 != 0 ) ) )
         x= 366;
    else
         x= 365;
         
        return x ;
}
//------------------------------------------------------------------
int dni_w_miesiacu( int m, int r )
{
        int m_dni;
	    
	    
	    if( m==1)
	       m_dni=31;
		else
	     if( m==2)
	    {
	    	  if(rok_przestepny( r )==366)
	    	     m_dni=29;
	    	  else
			     m_dni=28;   
	    }
	    else
	     if( m==3)
	        m_dni=31;
		 else
	     if( m==4)
	        m_dni=30;
		 else
	     if( m==5)
	        m_dni=31;	
		 else
	     if( m==6)
	        m_dni=30;
		 else
	     if( m==7)
	        m_dni=31;	
		 else
	     if( m==8)
	        m_dni=31;
		 else
	     if( m==9)
	        m_dni=30;
		 else
	     if( m==10)
	        m_dni=31;
		 else
	     if( m==11)
	        m_dni=30;
		 else
	     if( m==12)
	        m_dni=31;	
		 else
	    	m_dni=0;	
	    
	
return m_dni;
}



