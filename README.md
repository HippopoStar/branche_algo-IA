# branche\_algo-IA
From ft\_printf to CoreWar

## In '**ft\_printf**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/20/ft_printf.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/printf/subnotions/printf-introduction/videos/introduction-74)  
- Erreur lors de la combinaison de
	- une *precision* de *0*
	- le flag '*+*' ou le flag ' '
	- une conversion d'un *0* signe  
		Exemple : `ft_printf("%.0 i\n", 0);`
- Erreur concernant les unicodes
	- ne pas gerer la precision

## In '**Filler**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/634/filler.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/filler/subnotions/introduction-bec9387e-3c44-496f-9c56-67b9908c482f/videos/introduction-filler)  
[Ressources](https://projects.intra.42.fr/uploads/document/document/321/resources.zip)  

## In '**push\_swap**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/650/push_swap.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/push_swap/subnotions/introduction-e9cc20a3-1ab4-484c-93c8-e585f81bfa61/videos/introduction-push_swap)  
- Dans '*push\_swap*'
	- max 3 instructions avec l argument "2 1 0"
	- max 12 instructions avec l argument "1 5 2 4 3" **OU** 5 valeurs quelconques
	- max 5300 instructions avec 500 arguments
	```
	ARG=`ruby -e "puts (-250 .. 249).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | wc -l
	```
	- '*ps\_sort\_five*' ne trie pas la pile si lance avec la commande ci-dessus
- Dans '*checker*'
	- aucun argument : rendre la main sans afficher 'error'
	- argument depassant INT\_MAX : 'error'
- Ameliorer le Makefile et ajouter des instructions specifiques a chaque binaire (Norme)
- Liberer manuellement la memoire avec 'free'
- Rectifier les erreurs de Norme dans la 'libft' (presence d'operateurs en fin de ligne)

## In '**lem-in**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/185/lem-in.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/lem_in/subnotions/video-de-presentation/videos/video-de-presentation)  
Documentation :
[Algo' de chemins disjoints de Bhandari](http://www.macfreek.nl/memory/Disjoint_Path_Finding)  
- Enlever les flags 'sanitize' dans le Makefile
- lors du parsing :
	- comptabiliser le nombre de liaisons de chaque salle
	- renvoyer une erreur pour une liaison declaree plusieurs fois ?
- lors du premier passage de Bellman-Ford :  
/ ! \\ Attention : il ne va pas trouver tous les itineraires possibles !  
	Exemple : les itineraires employants des salles impliquees dans un itineraire plus court deja repertorie  
		implementer pour cela un algo' de backtracking ? (complexite ?)
	- pour chaque salle :
		- comptabiliser le nombre d'itineraires l'impliquant
		- sauvegarder quelque part son poids minimum ('room->weight' apres le premier passage)
	- pour chaque itineraire :
		- repertorier les salles impliquees (dans la stucture des salles elles-memes, en employant des nombres premiers ?)  
			-> il est necessaire qu'il existe davantage de nombres premiers < INT_MAX que d'itineraires possibles
		- sauvegarder quelque part le poids
- / ! \\ Attention au cas dans lequel '##start' ou '##end' precedent un commentaire
- Penser a liberer manuellement la memoire avec 'free'

## In '**mod1**'

[Sujet](https://cdn.intra.42.fr/pdf/pdf/896/mod1.fr.pdf)  
[Videos de l'e-learning (5 exemples)](https://elearning.intra.42.fr/notions/58)  
[Ressources](https://projects.intra.42.fr/uploads/document/document/59/resources.tgz)  

## In '**CoreWar**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/30/corewar.fr.pdf)  
[Video de l'e-learning](https://elearning.intra.42.fr/notions/corewar/subnotions/corewar-introduction/videos/corewar-introduction)  
[Ressources](https://cdn.intra.42.fr/pdf/pdf/31/resources_corewar.pdf)  
[op.h](https://projects.intra.42.fr/uploads/document/document/27/op.h)  
[op.c](https://projects.intra.42.fr/uploads/document/document/26/op.c)  
[VM and champs](https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar)  

## In '**CoreWar Championship**'
[Sujet](https://cdn.intra.42.fr/pdf/pdf/995/corewar-championship.fr.pdf)  
[Ressources](https://projects.intra.42.fr/uploads/document/document/379/corewar-championship.tar)  

