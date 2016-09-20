
# courtin @ courtin-550P5C-550P7C in ~ [0:17:03] 
$ gnuplot
zsh: command not found: gnuplot

# courtin @ courtin-550P5C-550P7C in ~ [0:17:06] C:127
$ sudo apt-get install gnuplot
[sudo] Mot de passe de courtin : 
Lecture des listes de paquets... Fait
Construction de l'arbre des dépendances       
Lecture des informations d'état... Fait
Les paquets suivants ont été installés automatiquement et ne sont plus nécessaires :
  scid-data tcllib tdom texlive-games
Veuillez utiliser « sudo apt autoremove » pour les supprimer.
The following additional packages will be installed:
  aglfn gnuplot-tex gnuplot5-data gnuplot5-qt
Paquets suggérés :
  feedgnuplot gnuplot-doc libgnuplot-iostream-dev python-gnuplot gnuplot5-doc
Les NOUVEAUX paquets suivants seront installés :
  aglfn gnuplot gnuplot-tex gnuplot5-data gnuplot5-qt
0 mis à jour, 5 nouvellement installés, 0 à enlever et 25 non mis à jour.
Il est nécessaire de prendre 1 056 ko dans les archives.
Après cette opération, 3 293 ko d'espace disque supplémentaires seront utilisés.
Souhaitez-vous continuer ? [O/n] 
Réception de:1 http://fr.archive.ubuntu.com/ubuntu xenial/universe amd64 aglfn all 1.7-3 [29,4 kB]
Réception de:2 http://fr.archive.ubuntu.com/ubuntu xenial/universe amd64 gnuplot-tex all 4.6.6-3 [10,1 kB]
Réception de:3 http://fr.archive.ubuntu.com/ubuntu xenial/universe amd64 gnuplot5-data all 5.0.3+dfsg2-1 [59,3 kB]
Réception de:4 http://fr.archive.ubuntu.com/ubuntu xenial/universe amd64 gnuplot5-qt amd64 5.0.3+dfsg2-1 [951 kB]
Réception de:5 http://fr.archive.ubuntu.com/ubuntu xenial/universe amd64 gnuplot all 4.6.6-3 [6 970 B]
1 056 ko réceptionnés en 0s (1 204 ko/s)
Sélection du paquet aglfn précédemment désélectionné.
(Lecture de la base de données... 399824 fichiers et répertoires déjà installés.)
Préparation du dépaquetage de .../archives/aglfn_1.7-3_all.deb ...
Dépaquetage de aglfn (1.7-3) ...
Sélection du paquet gnuplot-tex précédemment désélectionné.
Préparation du dépaquetage de .../gnuplot-tex_4.6.6-3_all.deb ...
Dépaquetage de gnuplot-tex (4.6.6-3) ...
Sélection du paquet gnuplot5-data précédemment désélectionné.
Préparation du dépaquetage de .../gnuplot5-data_5.0.3+dfsg2-1_all.deb ...
Dépaquetage de gnuplot5-data (5.0.3+dfsg2-1) ...
Sélection du paquet gnuplot5-qt précédemment désélectionné.
Préparation du dépaquetage de .../gnuplot5-qt_5.0.3+dfsg2-1_amd64.deb ...
Dépaquetage de gnuplot5-qt (5.0.3+dfsg2-1) ...
Sélection du paquet gnuplot précédemment désélectionné.
Préparation du dépaquetage de .../gnuplot_4.6.6-3_all.deb ...
Dépaquetage de gnuplot (4.6.6-3) ...
Traitement des actions différées (« triggers ») pour tex-common (6.04) ...
Running mktexlsr. This may take some time... done.
Traitement des actions différées (« triggers ») pour man-db (2.7.5-1) ...
Paramétrage de aglfn (1.7-3) ...
Paramétrage de gnuplot-tex (4.6.6-3) ...
Paramétrage de gnuplot5-data (5.0.3+dfsg2-1) ...
Paramétrage de gnuplot5-qt (5.0.3+dfsg2-1) ...
update-alternatives: utilisation de « /usr/bin/gnuplot5-qt » pour fournir « /usr/bin/gnuplot » (gnuplot) en mode automatique
update-alternatives: utilisation de « /usr/bin/gnuplot5-qt » pour fournir « /usr/bin/gnuplot5 » (gnuplot5) en mode automatique
Paramétrage de gnuplot (4.6.6-3) ...

# courtin @ courtin-550P5C-550P7C in ~ [0:17:26] 
$ gnuplot

        G N U P L O T
        Version 5.0 patchlevel 3    last modified 2016-02-21 

        Copyright (C) 1986-1993, 1998, 2004, 2007-2016
        Thomas Williams, Colin Kelley and many others

        gnuplot home:     http://www.gnuplot.info
        faq, bugs, etc:   type "help FAQ"
        immediate help:   type "help"  (plot window: hit 'h')

Terminal type set to 'qt'
gnuplot> qt
         ^
         invalid command

gnuplot> exit

# courtin @ courtin-550P5C-550P7C in ~ [0:17:40] 
$ gnuplot

        G N U P L O T
        Version 5.0 patchlevel 3    last modified 2016-02-21 

        Copyright (C) 1986-1993, 1998, 2004, 2007-2016
        Thomas Williams, Colin Kelley and many others

        gnuplot home:     http://www.gnuplot.info
        faq, bugs, etc:   type "help FAQ"
        immediate help:   type "help"  (plot window: hit 'h')

Terminal type set to 'qt'
gnuplot> plot 
gnuplot> exit

# courtin @ courtin-550P5C-550P7C in ~ [0:19:27] 
$ cd Programmation/cpp/TSE/TSE 

# courtin @ courtin-550P5C-550P7C in ~/Programmation/cpp/TSE/TSE on git:master x [0:19:39] 
$ ls
caisse.cpp   chariot.h   main.cpp     stock.cpp   ticket.h      TSE.pro.user.3.2-pre1
caisse.h     client.cpp  produit.cpp  stock.h     TSE.pro
chariot.cpp  client.h    produit.h    ticket.cpp  TSE.pro.user

# courtin @ courtin-550P5C-550P7C in ~/Programmation/cpp/TSE/TSE on git:master x [0:19:40] 
$ ls
caisse.cpp   chariot.h   main.cpp     stock.cpp   ticket.h      TSE.pro.user.3.2-pre1
caisse.h     client.cpp  produit.cpp  stock.h     TSE.pro
chariot.cpp  client.h    produit.h    ticket.cpp  TSE.pro.user

# courtin @ courtin-550P5C-550P7C in ~/Programmation/cpp/TSE/TSE on git:master x [0:19:55] 
$ 
