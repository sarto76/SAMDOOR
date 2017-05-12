###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 24.03.2017
##Lavori svolti
Dragan: 
08:20 - 08:50: Riunione con il team
08:50 - 09:50: Risoluzione problema arduino-ethernet
10:05 - 12:20: finito le query 
13:15 - 14:30: Testato le query e messo a posto i vari errori
14:30 - 15:20: iniziato la parte di trasferimento dati da arduino al server
15:20 - 15:35: redazione del diario
15:35 - 15:45: riordino postazione

Cristiano:
Svolta riunione con il team fino alle 9 e poi cercato di far funzionare l'Arduino fino alle 9.50 (misteriosamente non riusciva a collegarsi col server... poi è andato dopo qualche tentativo).
Successivamente ho finito di fare l'aggiornamento dell'RTC dal server, avevo riscontrato qualche problema con il parsing della data/ora ma infine ho notato che era un problema di battitura di alcuni indici. 
Poi ho lavorato sull'RFID ma al pomeriggio ho riscontrato un problema con l'Arduino spiegato sotto.

Pietro: 
8.20 - 8.50: Preparazione postazione + Riunione fra il team
8.50 - 9.15: Modifica al form che serve per dare un permesso a un utente + aggiunta controllo che la data e ora di fine del permesso non sia minore della data di inizio
9.15 - 12.20: Inizio aggiunta di delete e edit ai permessi + organizzazione gita di quarta

13.15 - 14.45: Fine aggiunta di delete e edit ai permessi, inizio visualizzazione permessi per aula e pensato ai controlli da svolgere per non sovrapporre i permessi
15.00 - 15.45: colloquio con federico, stesura diario e ordine postazione

Federico:
8.20 - 8.50: Riunione con il team

8.50 - 9.15: Correzione di un bug nel database, aggiunta di colonne e modificare delle query nel sito gestionale relativo alle modifiche nel database
9.15 - 14.45: Creazione css/html dei form per inserire/modificare dati dal gestionale
15.00 - 15.45: Punto della situazione con Belfanti, stesura diario.
##Problemi riscontrati e soluzioni adottate
Dragan
Problema: Connessione tra arduino e server
Soluzione: Cavo difettoso.

Cristiano: 
Ho riscontrato un problema che non ho ancora risolto con la mia board Arduino, non riesco più a caricare sketch sul microcontrollore e non riesco a capire perchè. Ha smesso di funzionare di punto in bianco. L'errore è stk500_recv(): programmer is not responding ma anche cercando non ho risolto il problema


Pietro: 
Nessun problema riscontrato.

Federico:
Problema relativo al database: tipi di dati incompatibili e correzione di essi, aggiunta di alcune colonne e modifica delle relazioni tra tabelle per far funzionare correttamente il tutto come prima.
##Punto di situazione del lavoro
Dragan: 
In linea con il gantt

Cristiano:
Mi trovo a buon punto.

Pietro:
Leggermente in anticipo rispetto al gantt.

Federico:
In linea, un po' in anticipo.
##Programma per la prossima settimana
Dragan: 
Finire la parte di trasferimento dati dall'arduino al server.
Cristiano:
Scrivere la parte relativa all'SD in caso di interruzione di connessione con il server.
Pietro:
Continuare la visualizzazione per l'accesso delle aule.
Federico:
Terminare e mettere a punto il css delle pagine del gestionale.
