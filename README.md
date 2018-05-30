Schedules
==

	-L’objectif de ce projet est d’écrire un programme qui permettra d’aider la personne chargée de faire les emplois du temps d’une jeune et petite université. Vous pouvez vous mettre en binôme et repartir du projet de 

	Les données et les contraintes sont les suivantes :

	- 1. Les professeurs :

		- 3 professeurs de mathématiques à plein-temps (384h/an).

			Le prof A ne peux pas assister aux cours de 8h30.
			Le  prof B Lundi, Mardi et Vendredi après-midi ne peux pas venir. 
			Le Prof C ne veut pas avoir des cours les Vendredi à 12h45
			
		- 3 professeurs de physique : 2 à plein temps (384h/an) 1 à mi-temps (192h/an) 1 vacataire payé à l’heure

			Le prof A ne vient pas aux cours de 8h30.
			Le Prof B vient que aux cours de 8h30 jusqu'à 12h45
			Le prof C Vient que Jeudi matin et Vendredi après-midi
			Le prof D est disponible toute la journée

		- 4 professeurs d’informatique : 2 à plein-temps, 1 à mi-temps, 1 vacataire

			Les profs A, B et C sont disponible toute la journée.
			Le Prof D ne vient pas les Lundis et Vendredis.
			
		- 4 professeurs de Chimie : 2 à plein-temps, 2 à mi-temps

			Le prof A ne peux pas venir à 8h30.
			Le prof B et C sont disponible 
			Le prof D ne vient pas aux cours de 8h30.
			
		- 4 professeurs d’anglais à plein temps.
		
	        5  professeurs de Français   2 à plein temps (384h/an) 2 à mi-temps (192h/an) 1 vacataire payé à l’heure
			  
	Chaque semestre 11 profs invités se partagent les cours avec les profs permanents. Les profs invités donnent 20h en présentiel devant les étudiants la semaine où ils viennent. C’est les profs qui décident en début d'année académique la division entre eux. Pour voir les division d’heures consultez ce lien:
	https://docs.google.com/spreadsheets/d/1vEvA8tnKSsQ6OyZM-sms-D1Dp2qEjHHi97lktvBMztU/edit?usp=sharing 

	- 2. Les classes:  2 promotions

		L0 : On compte au maximum 160 étudiants sur 4 spécialités différentes (4 EDT différents à faire)
		L1 : On compte au maximum 160 étudiants sur 4 spécialités différentes (4 EDT différents à faire)
		Pour les TPs et les cours de langues les groupes sont divisés en 2, donc 20 par TPs et cours de langue
		
	- 3. Les salles :

		2 salles de 160 étudiants (amphis pour les CM)
		5 salles de 40 étudiants
		7 salles de langues pour 20 étudiants
		2 salles d’info pour 20 étudiants
		2 laboratoires physique chimie pour les TPs physique / chimie
		
	- 4. Les horaires :

		4 créneaux horaires par jour :  8h30-10h00,  10h15-11h45,  12h45-14h15,  14h30-16h00
		Pour ce qui est des cours, le contenu des années est disponible ici :
		https://docs.google.com/spreadsheets/d/1SS45_jYSs5LmJqFlRA_UzDeq23cxjk3k7D_33NED5ks/edit?usp=sharing

	- 5. Maximum d’heures de cours:

		En une semaine= 30 heures
		En une journée = 6 heures (4 cours)
		Pour ce projet, on ne considérera que les 2 premières années : “Foundation Year” et “Year 1”.

	L’année “Foundation Year” est une L0 qui ne contient qu’un tronc commun pour les 160 étudiants et pas encore de spécialités. Les CM et CIs se font donc à 160 en amphi, mais les TDs se font à 40 (4 groupes) et les TPs / cours de langue (8 groupes) à 20. 

	Les spécialités (Chemical Engineering, Computer Science, Geophysical Engineering et Oil and Gas avec 40 étudiants par spécialité) ne commencent donc qu’en L1. Un CM ou un CI pour une spécialité, c’est donc 40 personnes seulement alors qu’un CM ou un CI en tronc commun, c’est un cours à 160.

	Pour évaluer les emplois du temps proposés par l’évolution, on propose les pénalités suivantes lorsqu’une contrainte forte est violée :
	  –1000 points par nb de cours simultanés > 1 dans une salle
	  –1000 points par nb de cours simultanés > 1 par classe
	  –1000 points par nb de cours simultanés > 1 par prof
	  –1000 points par nb d’heures > ou < au nb désiré par matière
	  –1000 points par cours dans la mauvaise salle
	...
	Ensuite, pour minimiser les contraintes faibles, on propose les pénalités suivantes :
	–1 point par matière/classe identique dans une même journée
	–1 point par jour de cours pour les profs et les élèves.
	–1 par "trou" dans une journée travaillée, pour les profs et pour les élèves.
	–1 point si 1 séance ou 4 séances de cours dans une même journée pour un prof ou pour une classe.
	...

Compilation
-

	- Générer le projet avec easea schedules.ez
	- Lancer hack.sh
	- Compiler à l'aide du makefile

Utilisation
-

	- Lancer schedules