#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int jetX, jetY;
int meteorX[5], meteorY[5];
int skor = 0;
char oyuncuAdi[50];




void haritaCiz() {
    system("CLS");
    system("color 9");

    printf("Uzay                              Skor Tablosu\n");
    printf("==============================    ==================\n");

    for (int y = 0; y < 8; y++) { 
        for (int x = 0; x < 30; x++) { 
        
            if (y == 0 || y == 7 || x == 0 || x == 29) { printf("%c", 178); } 
			else if (x == jetX && y == jetY) { printf(">"); } 
			
			
			else {
                int meteor = 0;
                for (int i = 0; i < 5; i++) {
                    if (x == meteorX[i] && y == meteorY[i]) { meteor = 1; break; }
                }
                printf(meteor ? "*" : " ");
            }
            
            
            
        }



        // Skor Tablom
        switch (y) {
            case 1:
                printf("    Oyuncu: %s", oyuncuAdi);
                break;
            case 3:
                printf("    Skor: %d", skor);
                break;
            default:
                printf(" ");
                break;
        }
        
        
        
        printf("\n");
    }
}








void durumGuncelle() {
	// Asteroitlerin hareketi
    for (int i = 0; i < 5; i++) { 
        meteorX[i]--;

        
        
        
        if (meteorX[i] < 1) {
            meteorX[i] = 28;
            meteorY[i] = rand() % 6 + 1;
        }

        
        
        if (meteorX[i] == jetX && meteorY[i] == jetY) {
            system("color c");
            printf("\n\n       Oyun Bitti!\n");
            
            
            
            
            FILE *dosya = fopen("skor.txt", "a");
            if (dosya != NULL) {
                fprintf(dosya, "Oyuncu: %s | Skor: %d\n", oyuncuAdi, skor);
                fclose(dosya);
            } else {
                printf("Hata Skor Dosyasi\n");
            }

       
       
       
       
            printf("\n\n  Tekrar oynamak icin : 1 \n\n  Cikmak icin         : 2\n ");
            int sec;
            scanf("%d", &sec);
            switch (sec){
           case 1:
                skor = 0;
                for (int i = 0; i < 5; i++) { 
                    meteorX[i] = 28 + i * 10;
                    meteorY[i] = rand() % 6 + 1;
                }
                break;
            case 2:
                exit(0);
                break;
                
                default:
                exit(0);
                break;
            
            } 
        }
    }
    skor++;
}









void girisAl() {
    if (_kbhit()) {
        char tus = _getch();
        switch (tus) {
            case 'w':
            case 'W':
            case  38:
                if (jetY > 1)
                    jetY--;
                break;
            case 's':
            case 'S':
            case  40:
                if (jetY < 6) 
                    jetY++;
                break;
            default:
                break;
        }
    }
}







int main() {
 
    system("color 1");
    printf("== Meteorlardan Kac ==\n");
    printf("\n\n  Oyuncu Adi: ");
    scanf("%s", oyuncuAdi);
    
    jetX = 5;
    jetY = 4; 

    for (int i = 0; i < 5; i++) { 
        meteorX[i] = 28 + i * 10; 
        meteorY[i] = rand() % 6 + 1; 
    }

    while (1) {
        haritaCiz();
        durumGuncelle();
        girisAl();
        Sleep(10);
    }

    return 0;
}

