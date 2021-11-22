#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main(int argc, char *argv[]) {
	char ch;
	FILE *fp;
	char dosya[1000];
	char dizi[1000];
	int i = 0;
	int boyut = 0;
	int ram[256];
	int AX = 0;
	int BX = 0;
	int CX = 0;
	int DX = 0;
	int a;
	int mod;
	int c;
	int etiket;
	int j;
	int dAX[8]= {1,0,1,0,1,0,1,0};
	int dBX[8]= {0,1,0,1,0,1,0,1};
	int dCX[8]= {1,1,1,1,1,1,1,1};
	int dDX[8]= {0,0,0,0,0,0,0,0};
	int dEX[8];

	printf("Okumak istediginiz dosyanin ismini veya yolunu giriniz: ");
	scanf("%s", dosya);

	if ((fp = fopen(dosya, "r")) == NULL) {

		printf("Dosya acilamadi...\n");

	} else {

		printf("\nOkunan dosya icerigi:\n\n ");
		while(ch!= EOF) {

			ch=fgetc(fp);
			dizi[i]=ch;
			printf("%c", dizi[i]);
			i++;

		}

		i = 0;

		while(dizi[i] != NULL) {
			boyut++;
			i++;
		}

		for(i=0; i<1000; i++) {
			if(dizi[i]==':') {
				etiket=i;
			}
			if(dizi[i]=='H') {
				if(dizi[i+4]=='A' && dizi[i+7]=='B') {
					AX=BX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='C') {
					AX=CX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='D') {
					AX=DX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]!='A') {
					a=dizi[i+7] - '0';
					AX=a;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='A') {
					BX=AX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]!='B') {
					a=dizi[i+7] - '0';
					BX=a;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='C') {
					BX=CX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='D') {
					BX=DX;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='A') {
					CX=AX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='B') {
					CX=BX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]!='C') {
					a=dizi[i+7] - '0';
					CX=a;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='D') {
					CX=DX;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='A') {
					DX=AX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='B') {
					DX=BX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='C') {
					DX=CX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]!='D') {
					a=dizi[i+7] - '0';
					DX=a;
					c=DX;
				}
			}
			if(dizi[i]=='T' && dizi[i+1]=='O') {
				if(dizi[i+4]=='A' && dizi[i+7]=='B') {
					AX=AX+BX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='C') {
					AX=AX+CX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='D') {
					AX=AX+DX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='A') {
					AX=AX+AX;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='A') {
					BX=BX+AX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='B') {
					BX=BX+BX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='C') {
					BX=BX+CX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='D') {
					BX=BX+DX;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='A') {
					CX=CX+AX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='B') {
					CX=CX+BX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='C') {
					CX=CX+CX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='D') {
					CX=CX+DX;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='A') {
					DX=DX+AX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='B') {
					DX=DX+BX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='C') {
					DX=DX+CX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='D') {
					DX=DX+DX;
					c=DX;
				} else if(dizi[i+4]=='A' && dizi[i+7]!='A') {
					a=dizi[i+7] - '0';
					AX=AX+a;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]!='B') {
					a=dizi[i+7] - '0';
					BX=BX+a;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]!='C') {
					a=dizi[i+7] - '0';
					CX=CX+a;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]!='D') {
					a=dizi[i+7] - '0';
					DX=DX+a;
					c=DX;
				}

			}

			if(dizi[i]=='C' && dizi[i+1]=='R') {

				if(dizi[i+4]=='A' && dizi[i+7]=='B') {
					AX=AX*BX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='C') {
					AX=AX*CX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='D') {
					AX=AX*DX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='A') {
					AX=AX*AX;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='A') {
					BX=BX*AX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='B') {
					BX=BX*BX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='C') {
					BX=BX*CX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='D') {
					BX=BX*DX;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='A') {
					CX=CX*AX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='B') {
					CX=CX*BX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='C') {
					CX=CX*CX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='D') {
					CX=CX*DX;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='A') {
					DX=DX*AX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='B') {
					DX=DX*BX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='C') {
					DX=DX*CX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='D') {
					DX=DX*DX;
					c=DX;
				} else if(dizi[i+4]=='A' && dizi[i+7]!='A') {
					a=dizi[i+7] - '0';
					AX=AX*a;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]!='B') {
					a=dizi[i+7] - '0';
					BX=BX*a;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]!='C') {
					a=dizi[i+7] - '0';
					CX=CX*a;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]!='D') {
					a=dizi[i+7] - '0';
					DX=DX*a;
					c=DX;
				}

			}


			if(dizi[i]=='C' && dizi[i+1]=='I') {

				if(dizi[i+4]=='A' && dizi[i+7]=='B') {
					AX=AX-BX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='C') {
					AX=AX-CX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='D') {
					AX=AX-DX;
					c=AX;
				} else if(dizi[i+4]=='A' && dizi[i+7]=='A') {
					AX=AX-AX;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='A') {
					BX=BX-AX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='B') {
					BX=BX-BX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='C') {
					BX=BX-CX;
					c=BX;
				} else if(dizi[i+4]=='B' && dizi[i+7]=='D') {
					BX=BX-DX;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='A') {
					CX=CX-AX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='B') {
					CX=CX-BX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='C') {
					CX=CX-CX;
					c=CX;
				} else if(dizi[i+4]=='C' && dizi[i+7]=='D') {
					CX=CX-DX;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='A') {
					DX=DX-AX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='B') {
					DX=DX-BX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='C') {
					DX=DX-CX;
					c=DX;
				} else if(dizi[i+4]=='D' && dizi[i+7]=='D') {
					DX=DX-DX;
					c=DX;
				} else if(dizi[i+4]=='A' && dizi[i+7]!='A') {
					a=dizi[i+7] - '0';
					AX=AX-a;
					c=AX;
				} else if(dizi[i+4]=='B' && dizi[i+7]!='B') {
					a=dizi[i+7] - '0';
					BX=BX-a;
					c=BX;
				} else if(dizi[i+4]=='C' && dizi[i+7]!='C') {
					a=dizi[i+7] - '0';
					CX=CX-a;
					c=CX;
				} else if(dizi[i+4]=='D' && dizi[i+7]!='D') {
					a=dizi[i+7] - '0';
					DX=DX-a;
					c=DX;
				}

			}


			if(dizi[i]=='B' && dizi[i+1]=='O') {
				if(dizi[i+4]=='A' && dizi[i+7]=='B') {
					AX=AX/BX;
					mod=AX%BX;
					c=AX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='A' && dizi[i+7]=='C') {
					AX=AX/CX;
					mod=AX%CX;
					c=AX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='A' && dizi[i+7]=='D') {
					AX=AX/DX;
					mod=AX%DX;
					c=AX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='A' && dizi[i+7]=='A') {
					AX=AX/AX;
					mod=AX%AX;
					c=AX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='B' && dizi[i+7]=='A') {
					BX=BX/AX;
					mod=BX%AX;
					c=BX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='B' && dizi[i+7]=='B') {
					BX=BX/BX;
					mod=BX%BX;
					c=BX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='B' && dizi[i+7]=='C') {
					BX=BX/CX;
					mod=BX%CX;
					c=BX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='B' && dizi[i+7]=='D') {
					BX=BX/DX;
					mod=BX%DX;
					c=BX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='C' && dizi[i+7]=='A') {
					CX=CX/AX;
					mod=CX%AX;
					c=CX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='C' && dizi[i+7]=='B') {
					CX=CX/BX;
					mod=CX%BX;
					c=CX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='C' && dizi[i+7]=='C') {
					CX=CX/CX;
					mod=CX%CX;
					c=CX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='C' && dizi[i+7]=='D') {
					CX=CX/DX;
					mod=CX%DX;
					c=CX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='D' && dizi[i+7]=='A') {
					DX=DX/AX;
					mod=DX%AX;
					c=DX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='D' && dizi[i+7]=='B') {
					DX=DX/BX;
					mod=DX%BX;
					c=DX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='D' && dizi[i+7]=='C') {
					DX=DX/CX;
					mod=DX%CX;
					c=DX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='D' && dizi[i+7]=='D') {
					DX=DX/DX;
					mod=DX%DX;
					c=DX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='A' && dizi[i+7]!='A') {
					a=dizi[i+7] - '0';
					AX=AX/a;
					mod=AX%a;
					c=AX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='B' && dizi[i+7]!='B') {
					a=dizi[i+7] - '0';
					BX=BX/a;
					mod=BX%a;
					c=BX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='C' && dizi[i+7]!='C') {
					a=dizi[i+7] - '0';
					CX=CX/a;
					mod=CX%a;
					c=CX;
					printf("Mod Kalan= %d",mod);
				} else if(dizi[i+4]=='D' && dizi[i+7]!='D') {
					a=dizi[i+7] - '0';
					DX=DX/a;
					mod=DX%a;
					c=DX;
					printf("Mod Kalan= %d",mod);
				}

			}

			if(dizi[i]=='V' && dizi[i+1]=='E') {
				if(dizi[i+2]=='Y') {
					if(dizi[i+5]=='A' && dizi[i+8]=='B') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]+dBX[j];
							if(dAX[j]>1) {
								dAX[j]=1;
							}
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+5]=='A' && dizi[i+8]=='C') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]+dCX[j];
							if(dAX[j]>1) {
								dAX[j]=1;
							}
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+5]=='A' && dizi[i+8]=='D') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]+dDX[j];
							if(dAX[j]>1) {
								dAX[j]=1;
							}
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+5]=='A' && dizi[i+8]=='A') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]+dAX[j];
							if(dAX[j]>1) {
								dAX[j]=1;
							}
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+5]=='B' && dizi[i+8]=='A') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dBX[j]+dAX[j];
							if(dBX[j]>1) {
								dBX[j]=1;
							}
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+5]=='B' && dizi[i+8]=='B') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]+dBX[j];
							if(dBX[j]>1) {
								dBX[j]=1;
							}
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+5]=='B' && dizi[i+8]=='C') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]+dCX[j];
							if(dBX[j]>1) {
								dBX[j]=1;
							}
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+5]=='B' && dizi[i+8]=='D') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]+dDX[j];
							if(dBX[j]>1) {
								dBX[j]=1;
							}
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+5]=='C' && dizi[i+8]=='A') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]+dAX[j];
							if(dCX[j]>1) {
								dCX[j]=1;
							}
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+5]=='C' && dizi[i+8]=='B') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]+dBX[j];
							if(dCX[j]>1) {
								dCX[j]=1;
							}
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+5]=='C' && dizi[i+8]=='C') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]+dCX[j];
							if(dCX[j]>1) {
								dCX[j]=1;
							}
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+5]=='C' && dizi[i+8]=='D') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]+dDX[j];
							if(dCX[j]>1) {
								dCX[j]=1;
							}
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+5]=='D' && dizi[i+8]=='A') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]+dAX[j];
							if(dDX[j]>1) {
								dDX[j]=1;
							}
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+5]=='D' && dizi[i+8]=='B') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]+dBX[j];
							if(dDX[j]>1) {
								dDX[j]=1;
							}
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+5]=='D' && dizi[i+8]=='C') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]+dCX[j];
							if(dDX[j]>1) {
								dDX[j]=1;
							}
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+5]=='D' && dizi[i+8]=='D') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]+dDX[j];
							if(dDX[j]>1) {
								dDX[j]=1;
							}
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+5]=='A' && dizi[i+8]!='A') {
						a=dizi[i+8] - '0';
						printf("\n\nAX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]+dEX[j];
							if(dAX[j]>1) {
								dAX[j]=1;
							}
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+5]=='B' && dizi[i+8]!='B') {
						a=dizi[i+8] - '0';
						printf("\n\nBX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]+dEX[j];
							if(dBX[j]>1) {
								dBX[j]=1;
							}
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+5]=='C' && dizi[i+8]!='C') {
						a=dizi[i+8] - '0';
						printf("\n\nCX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]+dCX[j];
							if(dCX[j]>1) {
								dCX[j]=1;
							}
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+5]=='D' && dizi[i+8]!='D') {
						a=dizi[i+8] - '0';
						printf("\n\nDX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]+dEX[j];
							if(dDX[j]>1) {
								dDX[j]=1;
							}
							printf("%d,",dDX[j]);
						}
					}
				} else {
					if(dizi[i+3]=='A' && dizi[i+6]=='B') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]*dBX[j];
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+3]=='A' && dizi[i+6]=='C') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]*dCX[j];
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+3]=='A' && dizi[i+6]=='D') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]*dDX[j];
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+3]=='A' && dizi[i+6]=='A') {
						printf("\n\nAX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]*dAX[j];
							printf("%d,",dAX[j]);
						}
					} else if(dizi[i+3]=='B' && dizi[i+6]=='A') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dAX[j]=dBX[j]*dAX[j];
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+3]=='B' && dizi[i+6]=='B') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]*dBX[j];
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+3]=='B' && dizi[i+6]=='C') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]*dCX[j];
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+3]=='B' && dizi[i+6]=='D') {
						printf("\n\nBX Binary= ");
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]*dDX[j];
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+3]=='C' && dizi[i+6]=='A') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]*dAX[j];
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+3]=='C' && dizi[i+6]=='B') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]*dBX[j];
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+3]=='C' && dizi[i+6]=='C') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]*dCX[j];
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+3]=='C' && dizi[i+6]=='D') {
						printf("\n\nCX Binary= ");
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]*dDX[j];
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+3]=='D' && dizi[i+6]=='A') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]*dAX[j];
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+3]=='D' && dizi[i+6]=='B') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]*dBX[j];
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+3]=='D' && dizi[i+6]=='C') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]*dCX[j];
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+3]=='D' && dizi[i+6]=='D') {
						printf("\n\nDX Binary= ");
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]*dDX[j];
							printf("%d,",dDX[j]);
						}
					} else if(dizi[i+3]=='A' && dizi[i+6]!='A') {
						a=dizi[i+6] - '0';
						printf("\n\nAX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dAX[j]=dAX[j]*dEX[j];
							printf("%d,",dAX[j]);
						}

					} else if(dizi[i+3]=='B' && dizi[i+6]!='B') {
						a=dizi[i+6] - '0';
						printf("\n\nBX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dBX[j]=dBX[j]*dEX[j];
							printf("%d,",dBX[j]);
						}
					} else if(dizi[i+3]=='C' && dizi[i+6]!='C') {
						a=dizi[i+6] - '0';
						printf("\n\nCX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dCX[j]=dCX[j]*dEX[j];
							printf("%d,",dCX[j]);
						}
					} else if(dizi[i+3]=='D' && dizi[i+6]!='D') {
						a=dizi[i+6] - '0';
						printf("\n\nDX Binary= ");
						for(j=8; a>0; j--) {
							dEX[j]=a%2;
							a=a/2;
						}
						for(j=0; j<8; j++) {
							dDX[j]=dDX[j]*dEX[j];
							printf("%d,",dDX[j]);
						}
					}

				}
			}

			if(dizi[i]=='D' && dizi[i+1]=='E') {
				if(dizi[i+4]=='A') {
					printf("\n\nAX Binary= ");
					for(j=0; j<8; j++) {
						if(dAX[j]==1) {
							dAX[j]=0;
						} else {
							dAX[j]=1;
						}
						printf("%d,",dAX[j]);
					}
				}
				if(dizi[i+4]=='B') {
					printf("\n\nBX Binary= ");
					for(j=0; j<8; j++) {
						if(dBX[j]==1) {
							dBX[j]=0;
						} else {
							dBX[j]=1;
						}
						printf("%d,",dBX[j]);
					}
				}
				if(dizi[i+4]=='C') {
					printf("\n\nCX Binary= ");
					for(j=0; j<8; j++) {
						if(dCX[j]==1) {
							dCX[j]=0;
						} else {
							dCX[j]=1;
						}
						printf("%d,",dCX[j]);
					}
				}
				if(dizi[i+4]=='D') {
					printf("\n\nDX Binary= ");
					for(j=0; j<8; j++) {
						if(dDX[j]==1) {
							dDX[j]=0;
						} else {
							dDX[j]=1;
						}
						printf("%d,",dDX[j]);
					}
				}
			}

			if(dizi[i]=='S' && dizi[i+1]=='S') {

				if(dizi[i+2]=='D') {
					if(c!=0) {
						i=etiket;
					}
				} else {
					if(c==0) {
						i=etiket;
					}
				}
			}

			if(dizi[i]=='S' && dizi[i+1]=='N') {
				if(c<0) {
					i=etiket;
				}
			}

			if(dizi[i]=='S' && dizi[i+1]=='P') {
				if(c>0) {
					i=etiket;
				}
			}

		}
	}
	printf("\n\n\nAX= %d\nBX= %d\nCX= %d\nDX= %d",AX,BX,CX,DX);



	return 0;
}
