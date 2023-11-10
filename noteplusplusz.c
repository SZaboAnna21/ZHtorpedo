#include <stdio.h>
#define s 10
#define o 10

void init(int *T, char *E) {
    
    for(int i=0;i<s;i++){
        for(int j=0;j<o;j++) {
            *T=0;
            T++;}}

    for(int i=0;i<4;i++){
        *E='0';
        E++;}
    
    }  
	
void printTable(int T[s][o], char E[4]){
        
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++) {
            printf("%d\t",T[i][j]);
            
        }
        printf("\n");
    }
    for(int i=0;i<4;i++){
        printf("%c \n", E[i]);}
}

int johogy(char hogy[2]){
    if(hogy[0] == '|' || hogy[0] =='_') {
        return 1;
    }
    else{
        return 0;
    }
}

int joszam(int hossz, char Av){
    int jo;
    if(hossz < 6 && hossz > 0) {
        if (hossz == 3){
            if(Av == '0' || Av == '1'){
                jo = 1;}
            else {
                jo = 0;
            }
        }
        else {
            if (Av == '0')
            {jo =1;}
            else{
                jo = 0;
            }
        }
    }
    else{
        jo = 0;}
    
    return jo;}
	
int jooszlopsor(sor, oszlop){
    if (sor > 0 && sor < 11 && oszlop > 0 && oszlop < 11){
        return 1;}
    else {return 0;}

}

int submit(int *T, char *E, char hova[3], char hogy[2], int hossz){
    int oszlop = (int)hova[0] - 64;
    int sor;
    int hajo = hossz-2;
    E = E+hajo;
    char hajoA = *E; /// hajo avalibility '0' ha nincs egy se 
    if (hova[1] == '1' && hova[2] == '0'){
        sor = 10;}
    if (hova[2]=='\0') {
        sor = (int)hova[1] - 48;}
    int a, b, c;
    a = johogy(hogy);
    b = joszam(hossz,hajoA);
    c = jooszlopsor(sor ,oszlop);
    // kizarjuk a sarkokat onnan eleve nem idulhat
    if ((sor == 1 && oszlop == 1) || (sor == 1 && oszlop == 10) || (sor == 10 && oszlop == 1 ) || (sor == 10 && oszlop == 10)){
        c = 0;
    }
    // Ha minden beadott adat valid akkor megnezzuk ehelyezheto e
    if (a+b+c == 3) {
        int index = ((sor-1) *10) + (oszlop-1);
        T = T + index;
        if (hogy[0] == '_'){
            if ((10 - oszlop) >= hossz){
                while (hossz > 0){
                    if (*T == 0){
                        *T = 1;
                        T ++;
                        hossz = hossz -1;}
                    else {printf("A hely mar foglalt\n");
                    break;
                    }
                }
            }
            else {printf("Nem ferne ki\n");}
        }
        else{
            if ((10 - sor) >= hossz){
                while (hossz > 0){
                    if (*T == 0 ){
                        *T = 1;
                        T = (T + 10);
                        hossz = hossz -1;}
                    else {printf("A hely mar foglalt\n");
                    break;
                    }
                }
            }
            else{printf("Nem ferne ki\n");}
        }
    }
    else{printf("Valamelyik beadott adat nem valid\n");}
	
    if (hossz == 0 ){
        if (*E == '0'){
            *E = '1';
        }
        else if (*E =='1'){
            *E='2';}

        return 1;}
    else 
	{return 0;} 
}
int main(){
    int tabla[s][o];
    char elhhajok[4];
    char hova[3];
    int hossz;
    char hogy[2];

    init(tabla, elhhajok);
    printTable (tabla, elhhajok);
    while (elhhajok[0] != 1 && elhhajok[1] != 2 &&  elhhajok[2] != 1 && elhhajok[3] != 1 ){
        printf("Hova tegyuk, hol kezdodojon?: ");
        scanf("%s", &hova);
        printf("Hajo hossz?: ");
        scanf("%d", &hossz);
        printf("Hogy? : ");
        scanf("%s", &hogy);
        int sikerult = submit(tabla, elhhajok,hova, hogy,hossz);
        if (sikerult == 1 )
		{
			printf("Sikerult ");
			printTable(tabla, elhhajok);
		}	
    }
    return 0;
}