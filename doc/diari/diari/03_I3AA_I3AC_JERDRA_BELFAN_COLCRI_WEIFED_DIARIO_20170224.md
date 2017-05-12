###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 24.02.2017
##Lavori svolti
**Dragan:**
8:20 - 9:50: Abbiamo fatto un colloquio con il mandante per discutere a che punto siamo arrivati e cosa dobbiamo fare e in che modo. In seguito ho iniziato a ricerca informazioni sul socket.

10.05 - 12:20: Sono andato avanti a ricercare informazioni per interagire tra arduino e il server con il metodo POST E GET, in modo da decidere quale utilizzare dei due. 

13:15 - 15:20: Nel pomeriggio abbiamo lavorato assieme io e Cristiano, per mettere in piedi un socket tra arduino e php, ma abbiamo avuto problemi.

15:20 - 15:45: Stesura diario e riordino materiale. 

**Cristiano:**
Terminata documentazione della progettazione in mattinata.
Nel pomeriggio ho tentato di far funzionare l'NFC senza successo (vedi problemi riscontrati)

**Federico e Pietro:**
8.20 - 9.50: Abbiamo cercato di correggere il problema del "bit" con l'aiuto del sore (spiegato nell'apposito capitolo). Abbiamo inoltre tenuto un incontro fra mandante per discutere di come sta andando il lavoro.

10.05 - 12.20: (Pietro) Mi è stata restituita e spiegata la valutazione del secondo progetto.
(Fede) Ho cercato su internet delle possibili soluzioni per rendere belle e responsive le pagine con gli input all'interno delle pagine php "modifica", "aggiungi".

Siamo riusciti a risolvere il problema riscontrato. Poi abbiamo iniziato a implementare la pagina della visualizzazione degli accessi.

13.15 - 15.30: Io e federico abbiamo continuato con l'implementazione della pagina che visualizza gli accessi, abbiamo pensato di farla in modo che al posto di "id_user" esce il nome dell'utente al quale appartiene quell'id. Questa cosa vale anche per l'id_room.

15.30 - 15.45: Stesura diario

##Problemi riscontrati e soluzioni adottate

**Cristiano e Dragan:**
Ho avuto grossi problemi con il modulo NFC (non riesco a farlo minimamente funzionare).
Il modulo NFC non dispone affatto di documentazione sufficiente o di qualità online, e a quanto pare dalle ricerche effettuate, fa parte di un sistema creato dalla casa seedstudio in cui è necessario uno shield apposito per far funzionare questi componenti (vedi [seedstudio.com/wiki/Grove](seedstudio.com/wiki/Grove "Grove approfondimento")). Non ho comunque desistito e ho postato online (https://www.seeed.cc/topic_detail.html?id=11299) una domanda riguardo a questo. Non mi aspetto di ricevere nessuna risposta in quanto le risposte precedenti non hanno avuto praticamente mai un riscontro e una domanda postata oggi (https://www.seeed.cc/HORRRRRRRRRIBLE-SUPPORT-FROM-SEEED-t-11268.html) non è confortante.

**Pietro e Federico:**
Problemi:
Quando si inseriva una stanza, il valore dello "state" rimaneva sempre ad 1, e usavamo il tipo di dati BIT.
Questo tipo di dati però era sbagliato, noi avevamo bisogno un valore booleano e Federico nell'implementazione del db aveva messo BIT.

Soluzioni:
La soluzione è stata cambiare il tipo di dato da BIT a TINYINT(1) che è il vero modo per rappresentare un valore booleano.

##Punto di situazione del lavoro
**Dragan:**
In linea con il gantt.

**Cristiano:**
Avrei dovuto iniziare oggi con il modulo SD ma non c'è un Arduino Ethernet (ha un modulo sd integrato) con cavo USB. Ci sarebbe un Arduino Ethernet funzionante ma c'è bisogno di un cavo mini USB (non quelli micro USB più comuni) in più.

Sono leggermente indietro per via dell'NFC.

**Pietro:**
In linea con il gantt.

**Federico:**
In linea con il gantt.

##Programma per la prossima settimana
**Dragan:**
Far funzionare il webserver con il TCP.

**Cristiano:**
Conto di poter lavorare sulla scrittura dell'SD e possibilmente sull'RTC se questo arrivasse per tempo. Altrimenti potrei lavorare sull'apriporta (sarà usata una cassa da negozio)

**Pietro:**
Iniziare la pagina per la gestione dei permessi.

**Federico:**
Terminare la visualizzazione degli accessi ed abbellire la pagina degli input (cosa che non ho fatto in questa lezione).
