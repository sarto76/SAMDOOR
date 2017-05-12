###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 07.04.2017
##Lavori svolti
Dragan: 
08:20 - 12:00: Visita alla SUPSI
13:15 - 14:20: Parlato della presentazione e approfondito sulle SUP
14:20 - 14:35: riunione con il team
14:35 - 14:45: Provato a trovare la soluzione per il problema dell'altra volta
14:45 - 15:00: Pausa
15:00 - 15:25: Continuato la ricerca della soluzione
15:25 - 15:35: Scrittura del diario
15:35 - 15:45: Riordino postazione

Pietro e Federico: 
08:20 - 12:00: Visita alla SUPSI
13:15 - 14:20: Parlato della presentazione e approfondito sulle SUP
14:20 - 14:35: riunione con il team
14.35 - 14.45: Compilazione di alcuni moduli urgenti riguardanti lo stage a Berlino
15.00 - 15.25: Dato che avevamo poco tempo, abbiamo solo apportato alcune migliorie al codice che riguarda la grafica e lo abbiamo "pulito"(tolto parti inutili)
15.25 - 15.35: Redazione diario
15.35 - 15.45: Ordine postazione

Cristiano:
La mattina visita alla SUPSI.
Nel mattino sono riuscito a risolvere il problema che ho avuto la volta scorsa con il file della scheda SD che è spiegato nel capitolo successivo. Nell'ultima ora ho scritto un po' della documentazione relativa all'implementazione.

##Problemi riscontrati e soluzioni adottate
Dragan
Problema: Uguale della stessa volta

Cristiano: 
Ho risolto il problema con la scheda SD che non leggeva il file "permissions.txt" caricando uno sketch di esempio per stampare sul serial monitor la lista dei file presenti su SD. Da lì ho scoperto che stranamente il file veniva letto "perm~.txt", che è diverso da "permissions.txt" dunque il metodo SD.open() per aprire il file su SD diceva sempre di non trovare il file. Ho corretto il problema rinominando il file "perm.txt", probabilmente taglia il nome dei file di una certa lunghezza.

Pietro e Federico: 
nessun problema riscontrato.

##Punto di situazione del lavoro
Dragan: 
Mi trovo a buon punto.

Cristiano:
Leggermente indietro a causa della visita SUPSI

Pietro e Federico:
In linea
##Programma per la prossima settimana
Dragan: 
Risolvere il problema tra arduino e server e andare avanti con la documentazione.

Cristiano:
Scrivere la parte relativa al caricamento dei log sul database e la lettura del file perm.txt

Pietro e Federico:
Eseguire controllo sui dati inseriti(date e ore dei permessi), continuare la documentazione
