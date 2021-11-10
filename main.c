#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char cin[9];
    char nom[20];
    char prenom[30];
    int age;
    float poids;
    float taille;
}etudiant;

typedef struct{
int cin;
float note;
}note;

typedef struct{
    char nom[20];
    float coeff;
    note note_partiel[40];
    note note_examen[40];
}matiere;

// vérification
int verification_cin(char cin[]){
int i=0;
int verif=1;
while(i<strlen(cin)&&verif){

    if(!((cin[i]>='0')&&(cin[i]<='9')))
    {
        verif=0;
    }
    i++;
}
return verif;
}

//étudiants

void affichage_liste_etudiant(etudiant etudiants[],int n){
printf("\nN°      \t N°Cin       \t \t Nom                    Prenom          Age             Taille          \tPoids      \n\n\n");
for(int i=0;i<n;i++){
printf("%d \t\t",i+1);
afficher_etudiant(etudiants[i]);
printf("\n");
}
}


void saisie_etudiant(etudiant *e){

do{
printf("Donnez N°cin de l'etudiant :");
scanf("%s",&e->cin);
}while((strlen(e->cin)!=8)||!(verification_cin(e->cin)));

printf("Donnez le nom de l'etudiant :");
scanf("%s",&e->nom);
printf("Donnez le prenom de l'etudiant :");
scanf("%s",&e->prenom);
do{
printf("Donnez l'age de l'etudiant :");
scanf("%d",&e->age);
}while(e->age<=10||e->age>80);
do{
printf("Donnez le poids de l'étudiant :");
scanf("%f",&e->poids);
}while(e->poids<=10||e->poids>200);
do{
printf("Donnez la taille de l'etduaint:");
scanf("%f",&e->taille);
}while(e->taille<=1||e->taille>2.5);
}

void trier_liste_etudiant_nom(etudiant etudiants[],int n){
etudiant aux_e;
for (int i=0;i<n-1;i++){
    for(int j=1;j<n;j++){
        if(strcmp(etudiants[i].nom,etudiants[j].nom)>0){
            aux_e=etudiants[i];
            etudiants[i]=etudiants[j];
            etudiants[j]=aux_e;
        }
    }
}
}


void afficher_etudiant(etudiant e){
printf("%s \t\t",e.cin);
printf("%s \t\t",e.nom);
printf("%s \t\t",e.prenom);
printf("%d \t\t",e.age);
printf("%.2f \t\t\t",e.poids);
printf("%.2f \n",e.taille);

}
void supprimer_etudiant(etudiant etudiants[],int supp_e,int n){
for(int i=supp_e;i<n;i++){
    etudiants[i]=etudiants[i+1];
}



}
void copier_etudiant(etudiant e[],etudiant ce[],int n){
for (int i=0;i<n;i++){
    ce[i]=e[i];
}

}


//matiéres
void saisir_matiere(matiere *m,int n){
printf("Donnez le nom de la matiere:");
scanf("%s",&m->nom);
printf("Donnez le coefficient de la matiere :");
scanf("%f",&m->coeff);
/*for(int i=0;i<n;i++){
    printf("Donnez la note de l'étudiant[%d]",i);
    scanf("%f",&m->note_partiel[i]);
}*/
}

void affichage_matiere(matiere m,int n){
printf("Nom: %s\n",m.nom);
printf("coefficient: %f \n",m.coeff);
printf("Les notes  : \n");
for(int i=0;i<n;i++){
    printf("%f \t",m.note_partiel[i]);
}

}
void affichage_liste_matiere(matiere matiere_etudiant[],int n,int nn){
for(int i=0;i<n;i++){

   affichage_matiere(matiere_etudiant[i],nn);
}
}
int indice_note_p(note note_p[],int nm,char cin[]){
int i=0;
int trouve=0;
while(i<nm&&!trouve)
{
    if(strcmp(note_p[i].cin,cin)==0)
        trouve=1;
i++;
}
return i;
}

int indice_note_e(note note_e[],int n,char cin[]){
int i=0;
int trouve=0;
while((i<n)&&!(trouve))
{
    if(strcmp(note_e[i].cin,cin)==0)
        trouve=1;
i++;
}
return i;
}

float calcule_moyenne_etudiant(matiere matiere_etudiant[],int nm,char cin[],int n){
    float moy=0;
    for(int i=0;i<nm;i++)
        {

        moy+=(matiere_etudiant[i].note_partiel[indice_note_p(matiere_etudiant[i].note_partiel,n,cin)].note*0.30)+(matiere_etudiant[i].note_examen[indice_note_e(matiere_etudiant[i].note_examen,n,cin)].note*0.70)*matiere_etudiant[i].coeff;

        }
return moy;


}

/*void calcule_moyenne_des_etudiants(matiere matiere_etudiant[],int n,float moyenne[],int nm){
for(int i=0;i<n;i++){
    moyenne[i]=calcule_moyenne_etudiant(matiere_etudiant,n,nm);
}

}*/







int main()
{
    etudiant etudiants[40]={"12345678\0","ahambri\0","bilel\0",22,83,1.80,"87784897","dhambri\0","bilel\0",22,83,1.80,"87784803","bhambri\0","zfzf\0",22,83,1.80};
    matiere matiere_etudiant[30]={"algo\0",1.45,15.0,17.0,20};
    int n=3;
    int nm=1;
    int choix,choix1;
    /*saisie_etudiant(&etudiants[n]);
    n++;
    affichage_liste_etudiant(etudiants,n);
    saisir_matiere(&matiere_etudiant[nm],n);
    nm++;
    affichage_liste_matiere(matiere_etudiant,nm,n);*/


    getch();
do{
        system("cls");
    printf("\n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                       -MENU PRINCIPAL DE NOTRE APPlICATION-                                                               || \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("\n\n\n\n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------- BIENVENUE AU MENU PRINCIPAL DE NOTE APPLICATION ---------------------------------------------------|| \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------Veuillez choisir l'objectif de votre opération-------------------------------------------------------|| \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                             1. GESTION DES ETUDIANTS                                                                      || \n");
printf("       ||                                                             2. GESTION DES MATIERES                                                                       || \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                             3. QUITTER L'APPLICATION                                                                      || \n");
printf("       ||-----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("                                                                       Donnez votre choix:");
scanf("%d",&choix);
switch(choix){
case 1:{
do{ system("cls");
   printf("\n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------BIENVENUE DANS LE MENU DE GESTION GESTION DES ÉTUDIANTS-------------------------------------------------  || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------- Veuillez choisir une action ------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                            1. Afficher tous les etudiants                                                                || \n");
printf("       ||                                                            2. Ajouter un etudiant                                                                        || \n");
printf("       ||                                                            3. Supprimer un etudiant                                                                      || \n");
printf("       ||                                                            4. Afficher Liste des étudiantes triées selon leurs noms                                      || \n");
printf("       ||                                                            5. Calculer la moyenne d'un etudiant                                                          || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                            6. RETOUR AU MENU PRINCIPAL                                                                   || \n");
printf("       ||                                                            7. QUITTER L'APPLICATION                                                                      || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("                                                                    Donnez votre choix:");
scanf("%d",&choix1);
switch(choix1){
case 1:{
      if(n>=0)

     affichage_liste_etudiant(etudiants,n);

 getch();
};break;
case 2:{
saisie_etudiant(&etudiants[n]);
n++;
getch();
};break;
case 3:{
    affichage_liste_etudiant(etudiants,n);
    int sup_e;
    do{
       printf("Donnez le numéro de l'etudiant à supprimer :");
    scanf("%d",&sup_e);


    }while(sup_e<1||sup_e>n);
    sup_e--;
    supprimer_etudiant(etudiants,sup_e,n);
    n--;
    affichage_liste_etudiant(etudiants,n);
 getch();
};break;
case 4:{
etudiant copie_etudiants[40];
copier_etudiant(etudiants,copie_etudiants,n);
trier_liste_etudiant_nom(copie_etudiants,n);
printf("La liste des étudiantes triées selon leurs noms :\n");
affichage_liste_etudiant(copie_etudiants,n);
getch();
};break;

case 5:{

    affichage_liste_etudiant(etudiants,n);
    int num_e;
    do{
    printf("Donnez le numéro de l'étudiant :");
    scanf("%d",&num_e);
    }while(num_e<1||num_e>n);
    num_e--;
    printf("%s",etudiants[num_e]);

    getch();
};break;

}
if(choix1==7)
    choix=3;
}while((choix1!=6)&&(choix1!=7));
};break;


case 2:{
};break;
}
}while(choix!=3);
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------||  \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------||  \n");
printf("       ||                                                                     AU REVOIR!!                                                                          ||  \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------||  \n");

}








