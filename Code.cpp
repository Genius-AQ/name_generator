#include <stdio.h>
#include <conio.h>
#include <string.h>

#define m 100000000
#define m1 10000
#define b 29979221

struct sinh_vien {
	int stt;
	char hoten[23];
	int tuoi;
	char gioi[4];
	long mssv;
	float toan;
	float ly;
	float hoa;
} sv[200];

int i, n, len1, len2;
long a, r;
char fn[23], gt[4];

char NA1[7]= "AEIOUY";
char na1[7]= "aeiouy";

char NA2[6] = "AUOEI";
char na2[5][5] = 
{
	{'a','u','o','e','i'},
	{'i','a','a','o','a'},
	{'o','i','e','u','u'},
	{'u','o','i',NULL,NULL},
	{'y','y',NULL,NULL,NULL}
};

char NA22[4]="OUI";
char na22[2][3] =
{
	{'o','u','i'},
	{'a','o','e'}
};
    
char pa11[17]= "CKPBDGHLMNRSTVXQ";
char pa12[6]= "cnpmt";
    
char pa2[3][3] =
{
	{'G','N','T'},
	{'h','h','h'},
	{'i','g','r'}
};

long mul(long p, long q) {
   long p0, p1, q0, q1,mul;
   p0 = p%m1;
   p1 = p/m1;
   q0 = q%m1;
   q1 = q%m1;
   return (((p0*q1+p1*q0)%m1)*m1+p0*q0)%m;
}

long random3(long r) {
a = (mul(b,a)+1)%m;
return (a/m1)*r/m1;
}

float kbp(int n, long r){
	int *f;
	f = new int [r];
	int t;
	
	for(i = 0; i < r; i++) f[i] = 0;
	for(i = 0; i < n; i++){
		t = random3(r);
		printf(" %d ", t);
		f[t]++;
	}
	printf("\n");
	
	for(i = 0; i < r; i++) {
		printf("\n%3d", i);
		for (int j = 0; j<f[i]; j++)
		   printf(" | ");
		printf("\n");
	}
	
	t = 0;
	for(i = 0; i < r; i++) t += f[i]*f[i];
	delete []f;
	return r*t*(1.0/n) - n;
}

char name(){
	int c;
	char s[6];
	for (i=0; i<26; i++ ) fn[i]=NULL;
	int j, k = 2 + random3(3);
	
	for (j=1 ; j<=k ; j++){
		fflush(stdin);
	for (i=0; i<6; i++ ) s[i]=NULL;

	switch (random3(4))
	{
		case 0: { //truong hop chi co nguyen am
			switch(random3(3))
			{
				case 0: {
					s[0] = NA1[random3(6)];   //don
					break;
				}
				case 1: {     //ghep 2
					c = random3(5);
				    if (c<2) {
				    	s[0]=NA2[c];
				   		s[1]=na2[1+random3(4)][c];
			    	}
					else if (c==2) {
				   		s[0]=NA2[c];
				   		s[1]=na2[1+random3(3)][c];
					}
					else {
				   		s[0]=NA2[c];
				   		s[1]=na2[1+random3(2)][c];
					}
					break;
				}
				case 2: {        // ghep 3
					switch (random3(6))
					{
						case 0: {
							s[0]='I';
							s[1]='e';
							s[2]='u';
							break;
						}
						case 1: {
							s[0]='O';
							s[1]='a';
							s[2]='i';
							break;
						}
						case 2: {
							s[0]='O';
							s[1]='a';
							s[2]='y';
							break;
						}
						case 3: {
							s[0]='U';
							s[1]='a';
							s[2]='y';
							break;
						}
						case 4: {
							s[0]='U';
							s[1]='o';
							s[2]='i';
							break;
						}
						case 5: {
							s[0]='Y';
							s[1]='e';
							s[2]='u';
							break;
						}
					}
					break;
				}
			}
			break;
	    }
		case 1: {   //truong hop nguyen am - phu am
			switch (random3(3))
			{
				case 0: {    // don - don
					s[0]=NA1[random3(5)];
			   		s[1]=pa12[random3(6)];
					break;
				}
				case 1: {   // don - ghep
					c = random3(3);
		       		if (!c){
		          		s[0]='A';
		          		if (random3(1)) {
		          			s[1]='n';
		          			s[2]='g';
		          		}
		          		else {
		          	 		s[1]=pa12[random3(2)];
				     		s[2]='h';
		          		}
		       		}
		       		else if(c==1) {
			      		s[0]=NA1[1+random3(2)];
				  		s[1]=pa12[random3(2)];
				  		s[2]='h';
			   		}
			   		else {
			   	  		s[0]=NA1[3+random3(2)];
			   	  		s[1]='n';
			   	  		s[2]='g';
			   		}
					break;
				}
				case 2: {   //ghep - don
					c = random3(3);
					s[0]=NA22[c];
					s[1]=na22[1][c];
					s[2]=pa12[random3(5)];
					break;
				}
			}
		    break;
	    }
		case 2: {   //truong hop phu am - nguyen am

			switch(random3(4))
			{
				case 0: { //don - don
					c = random3(16);
					if (c<15 ) {
						s[0]=pa11[c];
						s[1]=na1[random3(6)];
					}
					else {
						s[0]='Q';
						s[1]='u';
						s[2]=na1[random3(4)];
					}
					break;
				}
				case 1: {   //ghep - don
					if (random3(1)) {
						s[0]=pa11[random3(3)];
						s[1]='h';
						s[2]=na1[random3(6)];
					}
					else {
						c = random3(3);
						s[0]=pa2[0][c];
						s[1]=pa2[1+random3(1)][c];
						s[2]=na1[random3(6)];
					}
					break;
				}
				case 2: {   //don - ghep
					s[0]=pa11[random3(15)];
					c = random3(5);
				    if (c<2) {
				    	s[1]=na2[0][c];
				    	s[2]=na2[1+random3(4)][c];
				    }
				    else if (c==2) {
				    	s[1]=na2[0][c];
				    	s[2]=na2[1+random3(3)][c];
				    }
				    else {
				    	s[1]=na2[0][c];
				    	s[2]=na2[1+random3(2)][c];
				    }
					break;
				}
				case 3: {   //ghep - ghep
					if (random3(1)){   //ghep - ghep 2
					
						if (random3(1)){
							s[0]=pa11[random3(3)];
							s[1]='h';
							c = random3(5);
				        	if (c<2) {
				        		s[2]=na2[0][c];
				        		s[3]=na2[1+random3(4)][c];
				        	}
				        	else if (c==2) {
				        		s[2]=na2[0][c];
				        		s[3]=na2[1+random3(3)][c];
				        	}
				        	else {
				        		s[2]=na2[0][c];
				        		s[3]=na2[1+random3(2)][c];
				        	}
						}
						else{
							c = random3(3);
							s[0]=pa2[0][c];
							s[1]=pa2[1+random3(1)][c];
							c = random3(5);
				        	if (c<2) {
				        		s[2]=na2[0][c];
				        		s[3]=na2[1+random3(4)][c];
				        	}
				        	else if (c==2) {
				        		s[2]=na2[0][c];
				        		s[3]=na2[1+random3(3)][c];
				        	}
				        	else {
				        		s[2]=na2[0][c];
				        		s[3]=na2[1+random3(2)][c];
				        	}
						}
					}
					else { //ghep - ghep 3
						if (random3(1)){
							s[0]=pa11[random3(3)];
							s[1]='h';
						}
						else{
							c = random3(3);
							s[0]=pa2[0][c];
							s[1]=pa2[1+random3(1)][c];
						}
						switch (random3(5))
						{
							case 0: {
								s[2]='i';
								s[3]='e';
								s[4]='u';
								break;
							}
							case 1: {
								s[2]='o';
								s[3]='a';
								s[4]='i';
								break;
							}
							case 2: {
								s[2]='o';
								s[3]='a';
								s[4]='y';
								break;
							}
							case 3: {
								s[2]='u';
								s[3]='a';
								s[4]='y';
								break;
							}
							case 4: {
								s[2]='u';
								s[3]='o';
								s[4]='i';
								break;
							}
						}
					}
					break;
				}
		    }
			break;
		}
		case 3: {   // phu am - nguyen am - phu 
		    //th1 = random3(3);
		    switch (random3(5))
		    {
		    	case 0: { // don - don - don
				   s[0]=pa11[random3(15)];
				   s[1]=na1[random3(5)];
				   s[2]=pa12[random3(5)];
				   break;
		    	}
		    	case 1: { //ghep - don - don
		    		if (random3(1)) {
		    			s[0]=pa11[random3(3)];
		    			s[1]='h';
		    			s[2]=na1[random3(5)];
		    			s[3]=pa12[random3(5)];
		    		}
		            else {
		          	   c = random3(3);
		          	   s[0]=pa2[0][c];
		          	   s[1]=pa2[1+random3(1)][c];
		          	   s[2]=na1[random3(5)];
		          	   s[3]=pa12[random3(5)];
		    	    }
		    	    break;
		        }
		        case 2: {   // don - ghep - don
		        	s[0]=pa11[random3(15)];
		        	c = random3(3);
					s[1]=na22[0][c];
					s[2]=na22[1][c];
					s[3]=pa12[random3(5)];
		        	break;
		        }
		        case 3: { //ghep - don - ghep
		        	if (random3(1)){
		        		s[0]=pa11[random3(3)];
		        		s[1]='h';
						c = random3(3);
		                if (!c){
		                   s[2]='a';
		                   if (random3(1)) {
		                   	  s[3]='n';
		                   	  s[4]='g';
		                   }
		                   else {
		                   	  s[3]=pa12[random3(2)];
		                   	  s[4]='h';
		                   }
		                }
		                else if(c==1) {
		                	s[2]=na1[1+random3(2)];
		                	s[3]=pa12[random3(2)];
		                	s[4]='h';
		                }
			            else {
			            	s[2]=na1[3+random3(2)];
			            	s[3]='n';
			            	s[4]='g';
			            }
				    }
					else {
						c = random3(3);
						s[0]=pa2[0][c];
						s[1]=pa2[1+random3(1)][c];
						c = random3(3);
		                if (!c){
		                   s[2]='a';
		                   if (random3(1)) {
		                   	  s[3]='n';
		                   	  s[4]='g';
		                   }
		                   else {
		                   	s[3]=pa12[random3(2)];
		                   	s[4]='h';
		                   }
		                }
		                else if(c==1) {
		                	s[2]=na1[1+random3(2)];
		                	s[3]=pa12[random3(2)];
		                	s[4]='h';
		                }
			            else {
			            	s[2]=na1[3+random3(2)];
			            	s[3]='n';
			            	s[4]='g';
			            }
					}
		        	break;
		        }
		        case 4: {   //ghep - ghep - don
		        	if (random3(1)){
		        		s[0]=pa11[random3(3)];
		        		s[1]='h';
		        	}
		        	else {
						c = random3(3);
						s[0]=pa2[0][c];
						s[1]=pa2[1+random3(1)][c];
					}
					c = random3(3);
					s[2]=na22[0][c];
					s[3]=na22[1][c];
					s[4]=pa12[random3(5)];
		        	break;
		        }
			}
			break;
		}
	}
	strcat(fn,s);
	if(j==4) break;
	strcat(fn," ");
    }
    
	len1 = strlen(fn);
	return *fn;
}

char gender(){
	for(int j=0 ; j<5 ; j++) gt[j] = NULL;
	if (random3(2)) {
		gt[0]='N';
		gt[1]='a';
		gt[2]='m';
	}
	else {
		gt[0]='N';
		gt[1]='u';
	}
	len2 = strlen(gt);
	return *gt;
}

int main() {
	char ch;
	printf("DE TAI: TAO CO SO DU LIEU GIA THONG QUA XAY DUNG HAM TAO SO GIA NGAU NHIEN SU DUNG PHUONG PHAP DONG DU TUYEN TINH\n\n");
	
	do {
	
       printf("An 1 de tao so ngau nhien va kiem dinh.\nAn 2 de tao danh sach sinh vien ngau nhien.\n");
       ch = getch();
       
       if(ch=='1'){
          printf("Nhap n: "); scanf("%d",&n);
          printf("Nhap r: "); scanf("%d",&r);
          a = 1000000 + random3(1000000);
          for (i = 0; i < n; i++) {
		      if (!(i%20)) printf("\n");
			  printf ("%d ",random3(r));
   		  }
          printf("\n\nMuon kiem dinh tinh ngau nhien? An phim bat ky de tiep tuc. An K/k de ket thuc.\n");
          ch = getch();
          if (!(ch=='K'||ch=='k')) printf("\nKhi binh phuong = %.4f\n", kbp(n,r));
       }

       if(ch=='2'){
       	  int j;
       	  a = 1000000 + random3(1000000);
       	
          printf("\nNhap so sinh vien muon tao: "); scanf("%d",&n);
          printf("\n|STT| ");
          printf("Ho va ten              | ");
          printf("Tuoi | ");
          printf("Gioi | ");
		  printf("  MSSV   | ");
		  printf(" Toan | ");
		  printf("  Ly  | ");
		  printf(" Hoa  |\n");
		  printf("-------------------------------------------------------------------------------\n");
		  
		  for (int t=0 ; t<n ; t++){
		  	fflush(stdin);
		  	
		  	sv[t].stt = t+1;
		  	for (j=0 ; j<23 ; j++) (sv[t].hoten)[j] = NULL;
		  	*sv[t].hoten = name();
		  	for (j=0 ; j<len1 ; j++) (sv[t].hoten)[j] = fn[j];
		  	sv[t].tuoi = 17 + random3(14);
		  	for (j=0 ; j<5 ; j++) (sv[t].gioi)[j] = NULL;
		  	*sv[t].gioi = gender();
		  	for (j=0 ; j<len2 ; j++) (sv[t].gioi)[j] = gt[j];
		  	sv[t].mssv = 20070000 + 10000*random3(8) + random3(9999);
		  	sv[t].toan = (12 + random3(29))*(1.0/4);
		  	sv[t].ly = (12 + random3(29))*(1.0/4);
		  	sv[t].hoa = (12 + random3(29))*(1.0/4);
		  	
		  	printf("|%3d| ",t+1);
		  	printf("%s",sv[t].hoten);
		  	for (j=0 ; j<(23-len1) ; j++) printf(" ");
		  	printf("| ");
		  	printf("%3d  | ",sv[t].tuoi);
		  	printf("%s",sv[t].gioi);
		  	for (j=0 ; j<(5-len2) ; j++) printf(" ");
		  	printf("| ");
		  	printf("%d | ",sv[t].mssv);
		  	printf("%5.2f | ",sv[t].toan);
		  	printf("%5.2f | ",sv[t].ly);
		  	printf("%5.2f |\n",sv[t].hoa);
		  	if(!((t+1)%5))
				printf("-------------------------------------------------------------------------------\n");
			if(((t+1)==n)&&((t+1)%5))
				printf("-------------------------------------------------------------------------------\n");
		  }
       }
       
       printf("\nLam lai? An K/k de ket thuc.\n");
       ch = getch();
    }
    while(!(ch=='K'||ch=='k'));
}
