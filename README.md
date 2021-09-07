# Repo-perso-Lucas-SOURY-Stage
Bonjour Guillaume c'est Lucas, Voici le Répo avec les projets que j'ai le plus apprecié lors de ma 1ère année.


Le Minishell : 
réalisé en C, je devais recréer une partie définie d'un Shell en suivant la forme de tcsh, le mien est capable de gérer les commandes "cd", "setenv", "unsetenv", "env" et "exit" en les entrant après un prompt "$>".
De plus il est capable de gérer les commandes classiques de Linux telles que "ls", "pwd", "echo", etc...
La gestion d'erreur est également prise en charge.
Le Minishell se lance en entrant "./mysh" après avoir compilé.


Le My_RPG : 
Comme son nom l'indique, nous devions créer un petit RPG à l'aide de la lib CSFML, avec un système de combat, de quête, un menu principal, un menu pause avec la touche "escape", un menu de pause, et un status.
Bien que le projet ne soit pas aussi propre que les autres, moi et mon collègue avont prit énormément de plaisir à le faire, car bien qu'il est été chronophage et énergivore, cela nous a fait gagner de grandes connaissances en organisations et répartition des tâches, en plus de l'adaption nécessaire lors d'un tel projet.
Le My_RPG se lance en entrant "./my_rpg" après avoir compilé.


Le My_Sokoban : 
Réalisé en C avec la lib ncurses, je devais développer une copie en mode terminal d'un jeu de type sokoban. 
ce dernier se joue sur une map en txt, délimitée par des murs ("#"), où le joueur ("P") doit déplacer toutes les boites ("X") sur les trous disponibles ("O"). 
Le joueur gagne si toutes les boites sont sur un trou, ou perd si une boite est coincée dans un endroit inaccessible. De plus, le jeu ne se lancera pas si la map est érronée (plus de boites que de trous, ou l'inverse) ou si le terminal ouvert est plus petit que la map en txt.
Le My_Sokoban se lance en entrant "./my_sokoban map_de_test.txt" après avoir compilé.