CC=g++										#désigne le compilateur utilisé
CFLAGS=-Wall -O 							#regroupe les options de compilation
LDFLAGS= 									#regroupe les options d'édition de liens
EXEC=a.out	 								#ou TARGET regroupe les exécutables
SRC=$(wildcard *.cpp)						#regroupe tous les fichiers sources du projet
OBJ=$(SRC:.c=.o)							#regroupe tous les fichiers objets du projet

all: 			$(EXEC)

a.out: 			$(OBJ)
				$(CC) -o $@ $^ $(LDFLAGS)

%.o: 			%.c 						#permet de construire un .o à partir d'un .c
				$(CC) -o $@ -c $< $(CFLAGS)

clean:
				rm -f *.o core

mrproper: 		clean
				rm -f $(EXEC)

#all : 		à placer généralement au début du fichier ; les dépendances associées correspondent
#			à l’ensemble des exécutables à produire ;
#clean : 	normalement pas de dépendance ; la commande associée supprime tous les
#			fichiers intermédiaires (notamment les fichiers objets) ;
#mrproper : la commande correspondante supprime tout ce qui peut être regénéré, ce
#			qui permet une reconstruction complète du projet lors de l’appel suivant à mak– all : à placer généralement au début du fichier ; les dépendances associées correspondent
#			à l’ensemble des exécutables à produire ;

#$@ : nom de la cible 
#$< : nom de la première dépendance 
#$ˆ : liste des dépendances 
#$? : liste des dépendances plus récentes que la cible 
#$* : nom d’un fichier sans son suffixe.