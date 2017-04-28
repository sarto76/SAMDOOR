##Lavori svolti

Cristiano:
La mattina visita alla SUPSI.
Nel mattino sono riuscito a risolvere il problema che ho avuto la volta scorsa con il file della scheda SD che è spiegato nel capitolo successivo. Nell'ultima ora ho scritto un po' della documentazione relativa all'implementazione.

##Problemi riscontrati e soluzioni adottate

Cristiano: 
Ho risolto il problema con la scheda SD che non leggeva il file "permissions.txt" caricando uno sketch di esempio per stampare sul serial monitor la lista dei file presenti su SD. Da lì ho scoperto che stranamente il file veniva letto "perm~.txt", che è diverso da "permissions.txt" dunque il metodo SD.open() per aprire il file su SD diceva sempre di non trovare il file. Ho corretto il problema rinominando il file "perm.txt", probabilmente taglia il nome dei file di una certa lunghezza.

##Punto di situazione del lavoro

Cristiano:
Come da programma


##Programma per la prossima settimana

Cristiano:
Scrivere la parte relativa al caricamento dei log sul database e la lettura del file perm.txt