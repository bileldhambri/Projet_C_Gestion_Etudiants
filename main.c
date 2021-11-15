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
char cin[9];
float note;
}note;


typedef struct{
    char nom[20];
    float coeff;
    int nombre_etudiant;
    note note_partiel[40];
    note note_examen[40];
}matiere;


// vérification CIN De L'étudiant
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
int existe_cin(etudiant e[],char cin[],int n){
int i=0;
int existe=0;
while(i<n&&!existe){

    if(strcmp(e[i].cin,cin)==0)
    {
        existe=1;
    }
    else{
    i++;
    }
}
return existe;
}


//Gestion étudiants

void affichage_liste_etudiant(etudiant etudiants[],int n){
printf("\nN°      \t N°Cin       \t \t Nom                    Prenom          Age             Taille          \tPoids      \n\n\n");
for(int i=0;i<n;i++){

printf("%d \t\t",i+1);
afficher_etudiant(etudiants[i]);
printf("\n");
}
}




void saisie_etudiant(etudiant *e,etudiant et[],int n){

do{
printf("Donnez N°cin de l'etudiant :");
scanf("%s",&e->cin);
}while((strlen(e->cin)!=8)||!(verification_cin(e->cin))||(existe_cin(et,e->cin,n)));

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
void trier_liste_etudiant_age(etudiant etudiants[],int n){
etudiant aux_e;
for (int i=0;i<n-1;i++){
    for(int j=1;j<n;j++){
        if(etudiants[i].age>etudiants[j].age){
            aux_e=etudiants[i];
            etudiants[i]=etudiants[j];
            etudiants[j]=aux_e;
        }
    }
}

printf("\nN°      \tAge          N°Cin       \t \t Nom                    Prenom                        Taille        \tPoids      \n\n\n");
for(int i=0;i<n;i++){
printf("%d \t\t",i+1);
printf("%d \t\t",etudiants[i].age);
printf("%s \t\t",etudiants[i].cin);
printf("%s \t\t",etudiants[i].nom);
printf("%s \t\t\t\t",etudiants[i].prenom);
printf("%.2f \t\t",etudiants[i].taille);
printf("%.2f \n",etudiants[i].poids);
printf("\n");
}

}


void afficher_etudiant(etudiant e){
printf("%s \t\t",e.cin);
printf("%s \t\t",e.nom);
printf("%s \t\t",e.prenom);
printf("%d \t\t",e.age);
printf("%.2f \t\t\t",e.taille);
printf("%.2f \n",e.poids);
}




void supprimer_etudiant(etudiant etudiants[],int supp_e,int n){
for(int i=supp_e;i<n-1;i++){
    etudiants[i]=etudiants[i+1];
}
}


void copier_etudiant(etudiant e[],etudiant ce[],int n){
for (int i=0;i<n;i++){
    ce[i]=e[i];
}

}

void trier_rang_etudiant(note moy[],int n,etudiant e[]){
    note m;
for(int i=0;i<n-1;i++){
    for(int j=i;j<n;j++){
        if(moy[i].note<moy[j].note){
            m=moy[i];
            moy[i]=moy[j];
            moy[j]=m;
        }

    }


}

 printf("\n\nRang      \t\tNom de l'etudiant      \t\tCIN     \t\tMoyenne\n");
    for(int i=0;i<n;i++){
            printf("%d \t\t\t",i+1);
            printf("%s\t\t\t\t",e[indice_nom_etudiant(e,n,moy[i].cin)].nom);
            printf("%s\t\t",moy[i].cin);
            printf("%.2f\t\t\n",moy[i].note);
    }



}
//Gestion matiéres
void saisir_matiere(matiere *m){
printf("Donnez le nom de la matiere:");
scanf("%s",&m->nom);
do{
printf("Donnez le coefficient de la matiere :");
scanf("%f",&m->coeff);
}while((m->coeff<0)||(m->coeff>15));
printf("La matière a été ajouté avec sucées !");
}


void affichage_liste_matiere(matiere matiere_etudiant[],int nm){
printf("\nN°      \t\tNom      \t\tCoefficient   \n");
for(int i=0;i<nm;i++){
   printf("%d \t\t\t",i+1);
   printf("%s\t\t\t",matiere_etudiant[i].nom);
   printf("%.2f\n",matiere_etudiant[i].coeff);
}
}

void supprimer_matiere(matiere Matiere[],int supp_M,int nm){

for(int i=supp_M;i<nm;i++){
    Matiere[i]=Matiere[i+1];
}

}


void modifier_matiere(matiere Matiere[],int i_m,char nom[],float cf)
{
strcpy(Matiere[i_m].nom,nom);
Matiere[i_m].coeff=cf;
printf("La matière a été modifié avec succès !\n");
}


int existe_matiere(matiere Matiere[],char M[],int n)
{
     int i=0; int existe=0;
      while(i<n&&!existe)
    {
               if(strcmp(Matiere[i].nom,M)==0)
                    {
                            existe=1;
               }
               else{
                       i++;
                         }
                }
return existe;
}


//Gestion notes
int indice_note_p(note note_p[],int nm,char cin[]){
int i=0;
int trouve=0;
while(i<nm&&!trouve)
{
    if(strcmp(note_p[i].cin,cin)==0)
        trouve=1;
    else
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
    else
        i++;
}
return i;
}

float calcule_moyenne_etudiant(matiere matiere_etudiant[],int nm,char cin[],int n){
    float moy=0;
    float c=0;
    for(int i=0;i<nm;i++)
        {
        moy+=((matiere_etudiant[i].note_partiel[indice_note_p(matiere_etudiant[i].note_partiel,n,cin)].note*0.30)+(matiere_etudiant[i].note_examen[indice_note_e(matiere_etudiant[i].note_examen,n,cin)].note*0.70))*matiere_etudiant[i].coeff;
        c+=matiere_etudiant[i].coeff;
        }
return moy/c;


}


void calculer_moy_etudiants(note moyennes[],int n,matiere m[],int nm,etudiant e[],int *p){
    for(int i=0;i<n;i++)
    {
    (*p)++;
    // printf("%f\n",calcule_moyenne_etudiant(m,nm,e[i].cin,n));
    moyennes[i].note=calcule_moyenne_etudiant(m,nm,e[i].cin,n);
    strcpy(moyennes[i].cin,e[i].cin);
    }
    printf("Les moyennes des étudiants ont été calculés\n");
}



void ajouter_notes_etudiant(matiere matiere_etudiant[],float note_p,float note_e,int i_m,char cin[]){
note n1,n2;
strcpy(n1.cin,cin);
n1.note=note_p;
strcpy(n2.cin,cin);
n2.note=note_e;
matiere_etudiant[i_m].note_partiel[matiere_etudiant[i_m].nombre_etudiant]=n1;
matiere_etudiant[i_m].note_examen[matiere_etudiant[i_m].nombre_etudiant]=n2;
matiere_etudiant[i_m].nombre_etudiant++;
}

int indice_nom_etudiant(etudiant e[],int n,char cin[]){
char nom[20];
int i=0;
int trouve=0;
while(i<n&&!trouve)
{
    if(strcmp(e[i].cin,cin)==0){
        trouve=1;
        strcpy(nom,e[i].nom);
        //printf("%s",nom);
    }
    else{
    i++;
    }
}
return i;
}


void afficher_notes_etudiants(matiere matiere_etudiant[],int i_m,etudiant e[],int n)
{
    printf("\n\nN°      \t\tNom de l'etudiant      \t\tNote partiel     \t\tNote examen\n");
    for(int i=0;i<matiere_etudiant[i_m].nombre_etudiant;i++)
    {
         printf("%d \t\t\t",i+1);
         printf("%s\t\t\t\t",e[indice_nom_etudiant(e,n,matiere_etudiant[i_m].note_partiel[i].cin)].nom);
         //printf("%s\t\t\t",matiere_etudiant[i_m].note_partiel[i].cin);
         printf("%.2f \t\t\t\t",matiere_etudiant[i_m].note_partiel[i].note);
         printf("%.2f\n",matiere_etudiant[i_m].note_examen[i].note);

    }

}


void afficher_notes_examens_etudiants(matiere matiere_etudiant[],int i_m,etudiant e[],int n)
{
    printf("\n\nN°      \t\tNom de l'etudiant    \t\tNote examen\n");
    for(int i=0;i<matiere_etudiant[i_m].nombre_etudiant;i++)
    {
         printf("%d \t\t\t",i+1);
         printf("%s\t\t\t\t\t",e[indice_nom_etudiant(e,n,matiere_etudiant[i_m].note_examen[i].cin)].nom);
         printf("%.2f\n",matiere_etudiant[i_m].note_examen[i].note);

    }

}

void trie_moyenne_etudiants(note moy[],int n)
{
  for(int i=0;i<n-1;i++)
    {
    for(int j=i+1;j<n;j++)
    {
        if(moy[j].note>moy[i].note)
        {
            note mn;
            mn=moy[j];
            moy[j]=moy[i];
            moy[i]=mn;
        }
    }
  }

}


void affichge_moyennes_etudiants(note moy[],int n,etudiant e[])
{
    printf("\n\nN°      \t\tNom de l'etudiant      \t\tCIN     \t\tMoyenne\n");
    for(int i=0;i<n;i++){
            printf("%d \t\t\t",i+1);
            printf("%s\t\t\t\t",e[indice_nom_etudiant(e,n,moy[i].cin)].nom);
            printf("%s\t\t",moy[i].cin);
            printf("%.2f\t\t\n",moy[i].note);
    }

}

void copie_notes(note t1[],note t2[],int n){
for(int i=0;i<n;i++){
  t2[i]=t1[i];
}
}

void trie_note_examen_dec(matiere matier_etudiant[],int i_m){
    note e;
    int n=matier_etudiant[i_m].nombre_etudiant;
for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
        {
           if(matier_etudiant[i_m].note_examen[i].note<matier_etudiant[i_m].note_examen[j].note){
            e=matier_etudiant[i_m].note_examen[j];
            matier_etudiant[i_m].note_examen[j]=matier_etudiant[i_m].note_examen[i];
            matier_etudiant[i_m].note_examen[i]=e;
           }
        }
}
}



void trier_note_partiel_dec(matiere matier_etudiant[],int i_m){
    note e;
    int n=matier_etudiant[i_m].nombre_etudiant;
for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
        {
           if(matier_etudiant[i_m].note_partiel[i].note<matier_etudiant[i_m].note_partiel[j].note){
            e=matier_etudiant[i_m].note_partiel[j];
            matier_etudiant[i_m].note_partiel[j]=matier_etudiant[i_m].note_partiel[i];
            matier_etudiant[i_m].note_partiel[i]=e;
           }
        }
}


}
void supprimer_note_etudiants(matiere e[],int i_m,int i_e){
for(int i=i_e;i<e[i_m].nombre_etudiant-1;i++){
    e[i_m].note_examen[i]=e[i_m].note_examen[i+1];
    e[i_m].note_partiel[i]=e[i_m].note_partiel[i+1];

}
e[i_m].nombre_etudiant--;
}



void afficher_notes_partiel_etudiants(matiere matiere_etudiant[],int i_m,etudiant e[],int n)
{
    printf("\n\nN°      \t\tNom de l'etudiant    \t\tNote partiel\n");
    for(int i=0;i<matiere_etudiant[i_m].nombre_etudiant;i++)
    {
         printf("%d \t\t\t",i+1);
         printf("%s\t\t\t\t\t",e[indice_nom_etudiant(e,n,matiere_etudiant[i_m].note_partiel[i].cin)].nom);
         printf("%.2f\n",matiere_etudiant[i_m].note_partiel[i].note);

    }

}



void modifier_notes_etudiants(matiere m[],int i_m,int i_n,float note_p,float note_e){

m[i_m].note_examen[i_n].note=note_e;
m[i_m].note_partiel[i_n].note=note_p;

}


//vérification des nombres des etudiants dans chaque matiere afin de calculer leurs moyennes
int verif_tous_etudiants_note(matiere m[],int n,int nm){
int verif=1,i=0;
while(i<nm&&verif){
    if(m[i].nombre_etudiant!=n){
        verif=0;
    }
    else{
        i++;
    }
}

return verif;

}

//vérifier que un étudiant a des notes dans chaque matiere
int verif_etudiant_note(matiere m[],int nm,char cin[]){
int test=0;
int verif=0;
for(int i=0;i<nm;i++){
    for(int j=0;j<m[i].nombre_etudiant;j++){
        if(strcmp(m[i].note_partiel[j].cin,cin)==0)
        {
            test++;
        }
    }
}
if(test==nm)
    verif=1;

return verif;
}

//PV notes
void affichage_pv_notes(matiere m[],int nm,etudiant e[],int n){
printf("\t\t");
for(int i=0;i<nm;i++)
{
printf("%s\t\t",m[i].nom);
}
printf("Moyenne générale");
printf("\n");
for(int i=0;i<n;i++){
    printf("%s\t\t",e[i].nom);
    for(int j=0;j<nm;j++)
    {
        printf("%.2f\t\t\t",(m[j].note_partiel[indice_note_p(m[i].note_partiel,m[i].nombre_etudiant,e[i].cin)].note*0.30)+(m[i].note_examen[indice_note_e(m[j].note_examen,m[j].nombre_etudiant,e[i].cin)].note*0.70));
    }
    printf("%.2f\n",calcule_moyenne_etudiant(m,nm,e[i].cin,n));

}
}

/*
int verifier_notes_etudiants(matiere m[],int nm,char cin[]){
int verif=1;

while(i<nm&&verif){
    if()

}




}*/



int main()
{
    etudiant etudiants[40]={"12345678\0","ahambri\0","bilel\0",25,83,1.80,"87784897","dhambri\0","bilel\0",22,83,1.80,"87784803","bhambri\0","zfzf\0",22,83,1.80};
    matiere matiere_etudiant[30]={"algorithme\0",1.45,0,17.0,20};
    note moyennes[40];
    int n=3,m=0;
    int nm=1;
    int choix,choix1,choix3;
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
printf("       ||                                                            4. Afficher Liste des étudiantes triée selon leurs noms                                       || \n");
printf("       ||                                                            5. Afficher Liste une étudiante triée selon leurs âges                                        || \n");
printf("       ||                                                            6. Calculer la moyenne d'un etudiant                                                          || \n");
printf("       ||                                                            7. Calculer les moyennes des étudiants                                                        || \n");
printf("       ||                                                            8. Afficher les moyennes des étudiants                                                        || \n");
printf("       ||                                                            9. Trier les rangs des étudiants                                                              || \n");
printf("       ||                                                            10. Affichage des notes/ PV                                                                   || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                            11. RETOUR AU MENU PRINCIPAL                                                                  || \n");
printf("       ||                                                            12. QUITTER L'APPLICATION                                                                     || \n");
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
saisie_etudiant(&etudiants[n],etudiants,n);
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
printf("La liste des étudiants triées selon leurs noms :\n");
affichage_liste_etudiant(copie_etudiants,n);
getch();
};break;
case 5:{
trier_liste_etudiant_age(etudiants,n);
 getch();
};break;
case 6:{

    affichage_liste_etudiant(etudiants,n);
    int num_e;
    do{
    printf("Donnez le numéro de l'étudiant :");
    scanf("%d",&num_e);
    }while(num_e<1||num_e>n);
    num_e--;
    if(verif_etudiant_note(matiere_etudiant,nm,etudiants[num_e].cin)){
    printf("La moyenne de l'étudiant %s est %.2f",etudiants[num_e].cin,calcule_moyenne_etudiant(matiere_etudiant,nm,etudiants[num_e].cin,n));
    }
    else{
        printf("Vous devez vérifier les notes de cet étudiant!");
    }
    getch();
};break;
case 7:{
    if(m==n){
        printf("Vous avez déja calculer les moyennes des étudiants !\n");
    }
    else{
  if(verif_tous_etudiants_note(matiere_etudiant,n,nm))
    calculer_moy_etudiants(moyennes,n,matiere_etudiant,nm,etudiants,&m);

  else
    printf("Vous devez d'abord ajouter les notes des étudiants dans chaque matière.");
    }

getch();
};break;
case 8:{

if(m==n){
affichge_moyennes_etudiants(moyennes,n,etudiants);
}
else{
    printf("Vous devez calculer les moyennes des étudiants!");
}
getch();
};break;
case 9:{
if(m!=n){
        printf("Vous devez calculer les moyennes des étudiants!");
}
else
trier_rang_etudiant(moyennes,m,etudiants);
getch();
};break;
case 10:{
if(m!=n){
        printf("Vous devez calculer les moyennes des étudiants!");
}
else
affichage_pv_notes(matiere_etudiant,nm,etudiants,n);
getch();
};break;
}
if(choix1==12)
    choix=3;
}while((choix1!=11)&&(choix1!=12));
};break;


case 2:{
do{ system("cls");
   printf("\n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------BIENVENUE DANS LE MENU DE GESTION GESTION DES MATIERES-------------------------------------------------   || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------- Veuillez choisir une action ------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                            1. Afficher tous les matieres                                                                 || \n");
printf("       ||                                                            2. Ajouter une matiere                                                                        || \n");
printf("       ||                                                            3. Supprimer une matiére                                                                      || \n");
printf("       ||                                                            4. Modifier une matiére                                                                       || \n");
printf("       ||                                                            5. Gestion notes                                                                              || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                            6. RETOUR AU MENU PRINCIPAL                                                                   || \n");
printf("       ||                                                            7. QUITTER L'APPLICATION                                                                      || \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("                                                                    Donnez votre choix:");
scanf("%d",&choix1);
switch(choix1){
case 1:{
      if(nm>=0)
        affichage_liste_matiere(matiere_etudiant,nm);

 getch();
};break;
case 2:{
int verif;
do{
saisir_matiere(&matiere_etudiant[nm]);
verif=existe_matiere(matiere_etudiant,matiere_etudiant[nm].nom,nm);
if(verif){
printf("\nCette matiére existe déja !");
getch();
}
}while(verif);
nm++;
getch();


};break;
case 3:{
int sup_m;

affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("Donnez le numéro de matiére à supprimer :");
scanf("%d",&sup_m);
}while(sup_m<1||sup_m>nm);
sup_m--;
supprimer_matiere(matiere_etudiant,sup_m,nm);
printf("Suppression effectuée avec succeés!");
nm--;
 getch();
};break;
case 4:{
int m_m;
char nom[20];
float cf;

affichage_liste_matiere(matiere_etudiant,nm);


do{
printf("Donnez le numéro de matiére à modifier :");
scanf("%d",&m_m);
}while(m_m<1||m_m>nm);
printf("Donnez le nom de la matiere:");
scanf("%s",&nom);
do{
printf("Donnez le coefficient de la matiere :");
scanf("%f",&cf);
}while((cf<0)||(cf>15));
modifier_matiere(matiere_etudiant,m_m-1,nom,cf);

};break;

case 5:{

do{
system("cls");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||----------------------------------------------BIENVENUE DANS LE MENU DES GESTIONS DES NOTES-----------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||--------------------------------------------------------- Veuillez choisir une action ----------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                            1. AJOUTER LES NOTES D'UN ETUDIANT                                                              || \n");
printf("       ||                                                            2. AFFICHER LES NOTES DES ETUDIANTS DANS UNE MATIERE                                            || \n");
printf("       ||                                                            3. SUPPRIMER LES NOTES D'UN ETUDIANT DANS UNE MATIERE                                           || \n");
printf("       ||                                                            4. MODFIER LES NOTES D'UN ETUDIANT DANS UNE MATIERE                                             || \n");
printf("       ||                                                            5. TRIER LES ETUDIANTS SELON LEURS NOTES DES EXAMENS DANS UNE MATIERE                           || \n");
printf("       ||                                                            6. TRIER LES ETUDIANTS SELON LEUERS NOTES DES PARTIELS DANS UNE MATIERE                         || \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||                                                           7. RETOUR AU MENU PRINCIPAL                                                                      || \n");
printf("       ||                                                           8. QUITTER L'APPLICATION                                                                         || \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("       ||------------------------------------------------------------------------------------------------------------------------------------------------------------|| \n");
printf("\n                                                                   Donner votre choix:");
scanf("%d",&choix3);
while((choix3>5)&&(choix3<1)){
    printf("réessayer votre choix");
    scanf("%d",&choix3);
}
switch(choix3){
case 1:{
int i_m,i_e;
if(nm>0){
affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("\n\nDonnez le numero de la matiere :");
scanf("%d",&i_m);
}while(i_m<=0||i_m>nm);
affichage_liste_etudiant(etudiants,n);
do{
printf("\n\nDonnez le numero de l'etudiant :");
scanf("%d",&i_e);
}while(i_e<=0||i_e>n);
float note_p,note_e;
do{
printf("\n\nDonnez la note du partiel :");
scanf("%f",&note_p);
}while(note_p<0||note_p>20);
do{
printf("\n\nDonnez la note de l'examen :");
scanf("%f",&note_e);
}while(note_e<0||note_e>20);
ajouter_notes_etudiant(matiere_etudiant,note_p,note_e,i_m-1,etudiants[i_e-1].cin);
//printf("%.2f\n",matiere_etudiant[i_m-1].note_partiel[nn].note);
//printf("%.2f\n",matiere_etudiant[i_m-1].note_examen[nn].note);
}
else{
    printf("Vous devez ajouter des matières!");
}
getch();


};break;


case 2:{
int i_m;
if(nm>0){
affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("\n\nDonnez le numero de la matiere :");
scanf("%d",&i_m);
}while(i_m<=0||i_m>nm);

afficher_notes_etudiants(matiere_etudiant,i_m-1,etudiants,n);
}
else{
     printf("Vous devez ajouter des matières!");
}

getch();
};break;

case 3:{

int i_m,i_e;
affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("\n\nDonnez le numero de la matiere :");
scanf("%d",&i_m);
}while(i_m<=0||i_m>nm);

afficher_notes_etudiants(matiere_etudiant,i_m-1,etudiants,n);
do{
printf("\n\nDonnez le numero de l'etudiant :");
scanf("%d",&i_e);
}while(i_e<=0||i_e>matiere_etudiant[i_m-1].nombre_etudiant);
supprimer_note_etudiants(matiere_etudiant,i_m-1,i_e-1);
printf("Les notes de l'étudiant ont été supprimer avec succès!");
getch();

};break;

case 4:{
int i_m,i_e;
affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("\n\nDonnez le numero de la matiere :");
scanf("%d",&i_m);
}while(i_m<=0||i_m>nm);

afficher_notes_etudiants(matiere_etudiant,i_m-1,etudiants,n);
do{
printf("\n\nDonnez le numero de l'etudiant :");
scanf("%d",&i_e);
}while(i_e<=0||i_e>matiere_etudiant[i_m-1].nombre_etudiant);
float note_p,note_e;
do{
printf("\n\nDonnez la note du partiel :");
scanf("%f",&note_p);
}while(note_p<0||note_p>20);
do{
printf("\n\nDonnez la note de l'examen :");
scanf("%f",&note_e);
}while(note_e<0||note_e>20);
modifier_notes_etudiants(matiere_etudiant,i_m-1,i_e-1,note_p,note_e);
};break;

case 5:{

int i_m;
 affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("\n\nDonnez le numero de la matiere :");
scanf("%d",&i_m);
}while(i_m<=0||i_m>nm);

trier_note_partiel_dec(matiere_etudiant,i_m-1);
afficher_notes_partiel_etudiants(matiere_etudiant,i_m-1,etudiants,n);
getch();

};break;
case 6:{
int i_m;
affichage_liste_matiere(matiere_etudiant,nm);
do{
printf("\n\nDonnez le numero de la matiere :");
scanf("%d",&i_m);
}while(i_m<=0||i_m>nm);
trie_note_examen_dec(matiere_etudiant,i_m-1);
afficher_notes_examens_etudiants(matiere_etudiant,i_m-1,etudiants,n);
getch();

};break;

case 8:{
    choix=3;
    choix1=7;
}break;
}
}while((choix3!=7)&&(choix3!=8));

};break;

}
if(choix1==7)
    choix=3;
}while((choix1!=6)&&(choix1!=7));
};break;

}
}while(choix!=3);
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------||  \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------||  \n");
printf("       ||                                                                     AU REVOIR!!                                                                          ||  \n");
printf("       ||----------------------------------------------------------------------------------------------------------------------------------------------------------||  \n");

}








