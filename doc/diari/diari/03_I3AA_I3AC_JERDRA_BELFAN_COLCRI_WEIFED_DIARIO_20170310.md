###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 10.03.2017
##Lavori svolti
**Dragan:**
Dalle 8:20 alle 8:40 riunione con il team.
Dalle 8:40 alle 12:20 io e Cristiano abbiamo fatto interagire l'Arduino con PHP, tramite il metodo POST.
Dalle 13:15 alle 13:45 ho fatto lo schema di rete del progetto con Visio. Collegamento tra Arduino, Server e rete di scuola (vedi schema su gitHub).
Dalle 13:45 alle 15:20 ho fatto gli schemi dei vari componenti dell arduino con Fritzing, il primo per il led di stato, il secondo per il RFID e il terzo per RTC (vedi schema su gitHub).
Dalle 15:20 alle 15:45 ho redatto di oggi.

**Cristiano:**
Dalle 8.20 alle 8.40 svolta una riunione con il team
La mattina ho lavorato sulla connessione fra il server e l'Arduino. Mi sono occupato di realizzare un semplice script PHP che ritornava il risultato di un "ping" al database SAMDOOR. 
Infine ho optato per delle richieste HTTP sfruttando il metodo POST del protocollo. Il server mi ritorna una risposta, che parso nell'Arduino per sapere se la connessione al database è stata stabilita con successo. Questo ci servirà per le interrogazioni con il database e lo script PHP servirà per far subentrare la scrittura sull'SD in caso di mancanza di connessione come richiesto dal committente. Questo compito mi ha impiegato l'intera giornata.

**Federico e Pietro:**

8.20 - 8.40: Riunione fra membri del team

8.40 - 12.20: È stata finita la pagina di visualizzazione accessi, e ottimizzata. Inoltre abbiamo iniziato a cercare dei template CSS per abbellire la tabella. (http://codepen.io/stursby/full/HdiJh)

13.15 - 14.45: Abbiamo preso e modificato un template css specifico per le tabelle, modificandolo a nostro piacimento. Poi abbiamo anche modificato leggermente il layout del sito per abbellire ulteriormente il sito e renderlo più user-friendly. 

15.00 - 15.20: Abbiamo corretto degli errori (riportati nell'apposito capitolo) che si verificavano nell'edit di un user o di una classe modificando delle query.

15.20 - 15.45: Stesura diario


##Problemi riscontrati e soluzioni adottate

**Cristiano:**
Ho riscontrato dei problemi con la rete di scuola che non faceva connettere l'Arduino al server. Utilizzando uno switch l'Arduino si è potuto connettere al server.

**Dragan:**
Problema: Ho avuto problemi a trovare il RFId su Fritzing.
Soluzione: Cercare un'immagine su google.

**Pietro e Federico:**
Problemi: Abbiamo riscontrato diversi bug che non permettevano di salvare lo stesso valore univoco (RFID/MAC ADDRESS) modificando altri dati nelle pagine del gestionale.
Inoltre non riuscivo a modificare il css per centrare le tabelle e la barra di navigazione, ho risolto disabilitando la cache del css.


Soluzioni: Abbiamo risolto cercando nelle query le righe escludendo quella attuale.


##Punto di situazione del lavoro
**Dragan:**
In linea con il gantt.

**Cristiano:**
Mi trovo a buon punto.

**Pietro:**
In linea con il gantt.

**Federico:**
In linea con il gantt.

##Programma per la prossima settimana
**Dragan:**
Il programma per la prossima settimana é quello di richiedere gli accessi per l'arduino dal server.

**Cristiano:**
Finire di sistemare la connessione del server (manca qualche test) e far funzionare l'RTC (se la batteria sarà arrivata).

**Pietro e Federico:** Perfezionare tutto il gestionale e implementare la gestione dei permessi.
