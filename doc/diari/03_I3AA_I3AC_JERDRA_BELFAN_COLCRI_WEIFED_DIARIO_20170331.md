###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 24.03.2017
##Lavori svolti
Dragan: 
08:20 - 09:00: Riunione con il team e preparazione della postazione di lavoro
09:00 - 11:35: Cercato di mandare i dati dall'Arduino al server
11:35 - 12:20: Problema con la connessione tra arduino e server
13:15 - 14:15: Cercato di risolvere il problema ma senza successo
14:15 - 15:00: Redazione di una parte della documentazione
15:00 - 15:20: Continuato con la documentazione
15:20 - 15:35: redazione del diario
15:35 - 15:45: riordino postazione

Cristiano:
Fino alle 9 riunione con il team
La mattina mi sono occupato del problema che avevo avuto di punto in bianco l'altra settimana con l'upload degli sketch e sono riuscito a risolverlo (http://www.parkansky.com/arduino-error.htm) praticamente il pin 0 (RX) andava in conflitto con l'upload dello sketch. Il problema si risolve scollegando il pin 0 dove è attaccato il lettore RFID, caricare lo sketch e riattaccare il lettore.
Nella seconda parte della mattinata mi sono occupato di risolvere alcuni bug del mio codice, avevo dimenticato un return ma ho capito l'errore solo attivando il "verbose" che ha mostrato un warning che indicava la mancanza del return. Ho fatto inoltre in modo che il lettore RFID si disattivi per 6 secondi dopo l'utilizzo per non "intasare" di duplicati i log e le richieste al database senza comunque bloccare l'esecuzione del programma. Nella parte finale della mattinata e nel pomeriggio ho lavorato come da programma alla lettura/scrittura e ho completato la scrittura dei log nell'SD in caso di mancata connessione con il server/db. Sto riscontrando un problema con la lettura dei permessi da SD che è spiegato nel capitolo sottostante.

Pietro e Federico: 
8.20 - 9.00: Riunione con il team e preparazione postazione di lavoro
9.00 - 12.20: Una volta capito il funzionamento delle jQuery abbiamo applicato
una jQuery alle tabelle dei permessi e degli accessi che permette di ordinarle
(http://tablesorter.com/docs/). Dopodiché abbiamo generato
dei dati casuali e li abbiamo inseriti nelle tabelle del nostro database.
13.15 - 15.30: Finito di abbellire il sito col css e continuata la
documentazione.
15.30 - 15.45: Stesura diario e ordine della postazione di lavoro



##Problemi riscontrati e soluzioni adottate
Dragan
Problema: Connessione tra arduino e server. Fino alle 11:35 stavo andando avanti con il trasferimento dei dati, poi il mio computer non si é più connesso alla rete senza motivo.
Ho provato a cambiare arduino, a cambiare il codice ma nulla.
Soluzione: Da trovare settimana prossima

Cristiano: 
Sto riscontrando un problema tuttora irrisolto con la lettura di un file da SD. Non trova (nonstante sia presente) il file "permissions.txt" dove dovrebbero essere contenuti i codici RFID dei badge autorizzati in caso di problemi con la connessione al server/db. Anche facendo creare direttamente il file all'Arduino quando deve accedere al file non lo trova e non posso quindi leggere nulla. Trovo quest'errore alquanto strano dato che con il file "datalog.txt" dove scrivo i log funziona tutto correttamente. Risolverò il problema la prossima volta.
Infine sono piuttosto stretto sia con la memoria flash che con quella dinamica (da 45% prima dell'SD ora sono al 75%) e mi è apparso un warning che avverte su potenziali problemi di stabilità. Spero di non avere comunque problemi.

Pietro e Federico: 
il css della jQuery andava in conflitto con quello creato da noi, quindi
abbiamo impiegato un po' di tempo per trovare la parte di css che causava il
problema. Il problema stava nel tag così abbiamo eliminato dal css
della jquery quel pezzo di codice

##Punto di situazione del lavoro
Dragan: 
In linea con il gantt

Cristiano:
Come da programma

Pietro e Federico:
In linea

##Programma per la prossima settimana
Dragan: 
Risolvere il problema tra arduino e server, e andare avanti con la documentazione.

Cristiano:
Finire la parte SD e fare interrogazioni al database per sapere se un'utente può entrare o no e spedire log al DB (questo da fare se la connessione è presente).
 
Pietro e Federico:
Eseguire controllo sui dati inseriti(date e ore dei permessi), continuare la
documentazione, e cercare/correggere eventuali bug del sistema.
