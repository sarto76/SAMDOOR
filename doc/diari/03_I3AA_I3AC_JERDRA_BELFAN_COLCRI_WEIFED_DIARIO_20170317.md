###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 10.02.2017
##Lavori svolti
Dragan: 
Dalle 8:20 alle 9:00 riunione con il team e il mandante.
Dalle 9:00 alle 09:50 cercato di trovare l'id del RFID ma senza successo (vedi problemi/soluzioni).
Dalle 10:05 alle 12:20 lavorato sulla parte arduino-server-db, insieme a Pietro ho fatto delle query per riuscire a mandare i dati (id_rfid, macAddressArduino e statusPort).
Dalle 13:15 alle 14:45 Ho aiutato Pietro a finire le query per la parte di permessi.
Dalle 15:00 alle 15:20 Ho iniziato a mettere a posto la documentazione (togliendo campi inutili) e ho aggiunto le varie fonti che ho utilizzato.
Dalle 15:20 alle 15:35 Ho redatto il diario.
Dalle 15:35 alle 15:45 Ho rimesso a posto la postazione di lavoro.

Cristiano:

Svolta riunione col team fino alle 9.
Successivamente mi sono occupato di testare definitivamente la connessione con il database e la scrittura su SD.
Il pomeriggio ho collegato l'RTC all'Arduino e l'ho fatto funzionare e ho apportato modifiche sostanziali al codice. 

Pietro: 
8:20-9:00: Riunione con il team e il mandante.

9.00-9.50: Pensato alla migliore soluzione per sviluppare la pagina di permessi e ho iniziato a implementara

10:05-12:20: lavorato sulla parte arduino-server-db, insieme a Dragan ho fatto delle query per riuscire a mandare i dati (id_rfid, macAddressArduino e statusPort).

13.15-14.45: Con l'aiuto di Dragan ho implementato in parte la pagina di gestione dei permessi, in modo che si possano assegnare i permessi scegliendo un utente esistente, un' aula esistente, una data con ora di inizio e ora di fine.
			 Poi ho fatto in modo che la tabella dei permessi che vengono assegnati, venga visualizzata sulla pagina. 
			 
15.00-15.15: Ho scritto una scaletta con tutte le cose che devo migliorare nel sito e quelle che ancora devo fare, in modo da essere sicuro di non dimenticarmi nulla alla fine.

15.20-15.45: Redazione diario e riordinamento della postazione

Federico:
Assente

##Problemi riscontrati e soluzioni adottate

Dragan
Problema: Ho avuto problemi a trovare l'id del RFID, poiché il programma che aveva fatto Cristiano l'altra volta non funziona più.
Soluzione: Usare per adesso un'id statico.

Cristiano: 
Sto riscontrando dei problemi con il parsing dell'orario dal server all'Arduino ma niente di irrisolvibile.

Pietro: 
Nessun problema particolare riscontrato.

##Punto di situazione del lavoro
Dragan: 
In linea con il gantt

Cristiano
Mi trovo a buon punto.

Pietro:
In linea con la pianificazione

Federico:
-

##Programma per la prossima settimana
Dragan: 

**Cristiano:**
Finire di integrare l'RTC e la scrittura con l'SD con il programma e fare la parte di codice relativa al caso in cui la connessione con il database venga a mancare.

Pietro:
Devo implementare la possibilità di eliminare/modificare i permessi creati nella pagina di gestione dei permessi, e inoltre svolgere dei controlli sui dati prima di inserirli.

Federico:
-


