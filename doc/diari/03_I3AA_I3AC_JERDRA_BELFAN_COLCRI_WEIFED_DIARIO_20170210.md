###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 10.02.2017
##Lavori svolti
**Dragan:** 
Oggi nella prima mezz'ora io e Pietro abbiamo finito l'Use Case grazie all'aiuto del docente. 
In seguito abbiamo fatto un colloquio di un'ora tra il team e il mandante per vedere come stesse andando il progetto. 
Dopo la pausa (10:05 - 14:00) sono riuscito a mettere l'arduino in rete, collegandolo alla rete di scuola sono riusciuto a pingarlo.
Dalle 14:00 alle 14:45 ho guardato su internet l'interazione tra il webserver e l'arduino ethernet, ho trovato un paio di esempi dove usano il protocollo UDP. 
Negli ultimi 45 minuti ho fatto il diario e ho redatto la parte dell'analisi dei costi della progettazione.

**Cristiano:**
Terminata documentazione della progettazione in mattinata.
Nel pomeriggio ho tentato di far funzionare l'NFC senza successo (vedi problemi riscontrati).


**Pietro:**
8.20 - 9.50: fine use case e implementazione di esso al pc con Dragan + colloquio col mandante --> punto della situazione e discussione sui lavori futuri
 
10.05 - 12.20: implementazione della pagina di login, il template css per la pagina login è stata presa da questo sito --> https://colorlib.com/wp/html5-and-css3-login-forms

12.20 - 15.20: implementazione struttura generale del sito + inizio implementazione di visualizzazione/aggiunta/modifica/eliminazione degli utenti.
La barra di navigazione (responsive) del sito l'ho presa da w3schools --> http://www.w3schools.com/howto/howto_js_topnav.asp

15.20 - 15.45: redazione diario e riordinamento della postazione

**Federico:**
Durante questa lezione ho apportato delle modifiche serie allo schema ER togliendo alcune tabelle e aggiungendone delle altre. Di seguito ho apportato queste modifiche anche al database che ho terminato e testato con delle righe di prova fasulle.
Durante la mattina ci siamo trovati con il gruppo ed il mandante per discutere dei progressi e dei prossimi passi da fare, così abbiamo deciso le prossime cose da sviluppare.
Nel pomeriggio insieme ho assistito Pietro che testava il mio database nel suo webserver, per ora funziona tutto come dovrebbe essere e non ci sono problemi.
Alla fine ho scritto il diario, organizzato tutti i files nelle mie cartelle in locale e caricato su gitHub il diario di oggi.


##Problemi riscontrati e soluzioni adottate
**Dragan:**
Problema: Il problema più grande é stato quello mettere l'arduino in rete.
Soluzione: Cercando in internet e parlandone con alcuni compagni che avevano lo stesso problema abbiamo visto che ogni Arduino ha un ip diverso in base al MAC Address, infine sono riuscito a metterlo in rete.

**Cristiano:**
Ho avuto grossi problemi con il modulo NFC (non riesco a farlo minimamente funzionare).
Il modulo NFC non dispone affatto di documentazione sufficiente o di qualità online, e a quanto pare dalle ricerche effettuate, fa parte di un sistema creato dalla casa seedstudio in cui è necessario uno shield apposito per far funzionare questi componenti (vedi [seedstudio.com/wiki/Grove](seedstudio.com/wiki/Grove "Grove approfondimento")). Non ho comunque desistito e ho postato online (https://www.seeed.cc/topic_detail.html?id=11299) una domanda riguardo a questo. Non mi aspetto di ricevere nessuna risposta in quanto le risposte precedenti non hanno avuto praticamente mai un riscontro e una domanda postata oggi (https://www.seeed.cc/HORRRRRRRRRIBLE-SUPPORT-FROM-SEEED-t-11268.html) non è confortante.


**Pietro:**
Non ho riscontrato problemi durante questa lezione.

**Federico:**
Ho riscontrato moltissimi problemi con MySQL Workbench, quindi ho cambiato l’editore di database con “Sequel Pro” che secondo me è molto più veloce e semplice da utilizzare.
Ho riscontrato diversi problemi nella creazione di una tabella che non mi dava un errore di duplicazione della chiave primaria. Non sapevo che le foreign key avessero bisogno di un nome, e queste andavano in conflitto con i nomi che avevo già dato la volta scorsa (cambiando i nomi delle foreign key ho risolto).

##Punto di situazione del lavoro
**Dragan:** 
In base al gantt mi trovo in anticipo di una settimana.

**Pietro:**
In linea.

**Federico:**
Sono in anticipo di una settimana rispetto al gantt preventivo.

**Cristiano:**
Avrei dovuto iniziare oggi con il modulo SD ma non c'è un Arduino Ethernet (ha un modulo sd integrato) con cavo USB. Ci sarebbe un Arduino Ethernet funzionante ma c'è bisogno di un cavo mini USB (non quelli micro USB più comuni) in più.

Sono leggermente indietro per via dell'NFC.

##Programma per la prossima settimana
**Dragan:**
Il programma per la prossima settimana é quello di scegliere tra i due protocolli (UDP o TCP), e provare a connettermi al webserver tramite l'Arduino.

**Cristiano:**
Conto di poter lavorare sulla scrittura dell'SD e possibilmente sull'RTC se questo arrivasse per tempo. Altrimenti potrei lavorare sull'apriporta (sarà usata una cassa da negozio)

**Pietro:**
La prossima lezione ho intenzione di finire la parte web di aggiunta/modifica/eliminazione degli utenti e delle aule. Inoltre ho intenzione di fare anche la pagina di visualizzazione di tutti gli accessi.

**Federico:**
La prossima lezione insieme a Pietro svilupperemo le query restanti e cercheremo di andare avanti con lo sviluppo della pagina di web.
