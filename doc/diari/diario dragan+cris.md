###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 10.02.2017
##Lavori svolti
Dragan: 
Dalle 8:20 alle 8:35 abbiamo fatto una riunione tra i membri, per stabilire come stiamo procedendo con il progetto e quale sarà il lavoro di 

tutti per oggi.
In seguito dalle 8:36 - 11:00 ho provato a fare dei programmi con l'UDP per vedere come funzionasse, e per la sicurezza ho scelto di utilizzare 

il protocollo TCP (parlandone con il team). 
Dalle 11:00 - 12:20 Ho cercato informazioni su internet sul protocollo TCP, guardato dei tutorial ed ho iniziato a fare un programma.
13:15 - 14:00 Ho cercato degli esempi per collegare l'arduino al webserver, usando un esempio già fatto sono riuscito ad accedere alla pagina 

web tramite l'ip dell'arduino.
14:00 - 14:45 Ho provato a implementare il codice del webserver con quello del TCP
15:00 - 15:30 Ho fatto il diario
15:30 - 15:45 Riunione con il team

**Cristiano:**
La mattina sono stato assente (giustificato dal capolaboratorio).
Nel tempo a disposizione ho lavorato sull'SD, informandomi su come poter leggere e scrivere dati da un file .CSV che sarà importato in MySQL in caso il sistema dovesse andare offline.
Cercando ho quindi trovato questo link sul sito ufficiale https://www.arduino.cc/en/Reference/SDCardNotes in cui spiegava come fare.
Ho iniziato a modificare il REQ-007 (Log accessi) per includere dettagliatamente cosa conterranno i log di accesso.
Ho inoltre tratto le seguenti conclusioni:
- Se il sistema andasse offline, non potendo interrogare il DB per chiedere se far entrare o no l'utente, l'apriporta rimarrà chiuso, possibilmente è da prevedere un LED di stato (verde aperto, rosso chiuso, rosso lampeggiante o giallo sistema offline/malfunzionamento).
- Il log in caso di sistema offline conterrà un booleano (è già stato aggiunto il campo alla tabella accessi nel DB) settato a "true" per indicare che il log è stato caricato da SD/durante un fail del sistema

##Problemi riscontrati e soluzioni adottate

Dragan: 
Problemi: Abbiamo avuto problemi con l'Arduino io e Cristiano, perché ogni volta che volevamo provare un codice dovevamo aspettare l'altro che 

finisse, poiché io dovevo fare la parte internet e lui la parte SD.
Soluzione: Aspettare che l'altro finisse e intanto lavorare su qualcosa d'altro.

**Cristiano:**
Ho guardato ancora una volta per l'NFC:
1. Non mi hanno risposto sul forum (vedere diario precedente) 
2. Lo shield compatibile con l'NFC è questo https://www.seeedstudio.com/Base-Shield-V2-p-1378.html ma non è scritto da nessuna parte se è compatibile con l'Arduino Ethernet
3. Ho trovato un nuovo chip NFC che non sembra male http://www.ebay.it/itm/PN532-NFC-RFID-Reader-Writer-Module-Arduino-Compatible-/271126360391 tuttavia utilizzerebbe i pin SDA e SCL già occupati dall'RTC, ma ho visto che il protocollo I2C supporta componenti multipli quindi perdendoci circa una lezione dovrei riuscire a mettere assieme i componenti

Sono ancora in attesa dell'RTC. E' un po' scomodo avere solo 1 Arduino Ethernet perchè serve anche a Dragan per la comunicazione in rete.

##Punto di situazione del lavoro

Dragan: 
Ancora una settimana avanti rispetto al gantt, questa attività che sto svolgendo adesso dovrei iniziarla settimana prossima.

**Cristiano:**
Leggermente indietro

##Programma per la prossima settimana

Dragan:
Far funzionare il webserver con il TCP.

**Cristiano:**
Finire lettura e scrittura SD
