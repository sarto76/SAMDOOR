###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 28.04.2017
##Lavori svolti
Cristiano:
Le 2 ore della mattina ho raccolto prove sul perchè non ho abbastanza ram e perchè non posso farci nulla per giustificare gli sforzi. Successivamente ho lavorato sulla lettura dall'SD usando la libreria PetitFS e l'ho completata. Il pomeriggio ho lavorato sull'RFID cercando di trovare un modo alternativo per farlo funzionare in modo che non rilegga erroneamente il badge più di una volta di fila ed ho risolto il problema. Infine ho collegato un LED che rappresenta la porta e che si accende per un breve lasso di tempo.

Dragan e Pietro: 
8.20 - 8.40: Abbiamo fatto una riunione visto che Dragan aveva dei problemi per la sua parte.
8.40 - 12.20: Abbiamo finito assieme la parte php di comunicazione fra server e arduino (inserimento dei dati nel database da parte dell'arduino).
13.15 - 15.20: Siamo andati avanti con la documentazione, ridisegnando a bella alcuni schemi di progettazione e modificandone alcuni(ad es. fritzing arduino ethernet)
15.20 - 15.45: stesura diario e riordinamento della postazione

##Problemi riscontrati e soluzioni adottate
Cristiano:
Riferimento mail *doc/allegati/estratto_mail_ottimizzaz.pdf* <br>
Ho passato al vaglio le proposte del docente in merito al problema dell'ottimizzazione della memoria ma i risultati non sono comunque stati soddisfacenti. <br><br>
**Proposte del docente:** <br><br>
1) Arduino Fat-fs: libreria wrapper di FatFs (attenzione: non PetitFs come specificato nella mail ma FatFs, libreria creata dallo stesso autore ma più ricco di opzioni e dunque più esoso di risorse).

La libreria non ha permesso di risparmiare risorse. Per verificarlo ho preso samdoor_minimal e ho sostituto le parti che utilizzavano la libreria SdFat e l'ho sostituita con questa libreria. Unendo gli esempi inclusi nella libreria per scrivere e leggere i dati dall'SD la memoria ha raggiunto 60% di Flash occupata e 71% di SRAM occupata (come prima, risparmiati 5% di flash che ricordo non sono un problema). Il risultato del codice si può visionare sotto src/samdoor_minimal_v2 come garanzia.

2) Ethernet: La libreria indicata non è per le versioni di Arduino e Shield che possediamo, dunque non mi è possibile utilizzarla. Il chip contenuto nello Shield che abbiamo a negli Arduino Ethernet originali che abbiamo a disposizione fanno uso del chip Wiznet W5100, la versione precedente del chip W5500 che invece è compatibile con la libreria (la libreria è un miglioramento di quella precedente perchè lavora su un chip più nuovo). 
Prove: [https://www.arduino.cc/en/reference/ethernet](https://www.arduino.cc/en/reference/ethernet "Ethernet 2"), [https://store.arduino.cc/arduino-ethernet-rev3-with-poe](https://store.arduino.cc/arduino-ethernet-rev3-with-poe "Ethernet Shield")

3) Ottimizzazione programma: Anche utilizzando le tecniche descritte nei link mi viene difficile credere di riuscire a stipare tutto il programma nel 4% della SRAM e sarebbe una perdita di tempo.

In conclusione per ora uso la libreria PetitFS che occupa molta poca memoria, poi leggo il badge e lo confronto con la lista nell'SD e a dipendenza del risultato apro/non apro la porta. Se avrò altro tempo proverò a scrivere alcuni log nella EEPROM (anche se la memoria è molto limitata).

**Altri problemi**

Problema con la libreria per la lettura, all'inizio non capivo come funzionasse il metodo per leggere i dati, ma poi facendo un po' di prove ho capito che inseriva i dati in un array di int (che fungeva da buffer) sottoforma di valori numerici, dunque mi è bastato convertire l'array di int in array di caratteri così da avere gli ID. <br>

Problema con la scheda RFID che legge più di una volta il valore del badge. Anche mettendo un delay che dovrebbe evitare questo problema continua a prendere più valori. Ho cambiato il codice spostando la comunicazione seriale su un altro pin (che mi ha risolto anche il problema di interferenza che avevo quando cercavo di caricare lo sketch avendo il pin 0 collegato al sensore RFID). Ho risolto disattivando la comunicazione seriale subito dopo la ricezione (così che fra il momento della ricezione e dell'elaborazione il lettore non possa rileggere di nuovo il badge) e riattivandolo alla fine dell'elaborazione.

Dragan e Pietro:
Nessuno

##Punto di situazione del lavoro
Cristiano:
Indietro con il programma per via dei problemi alla memoria e per i troppi compiti in confronto ai compagni.

Dragan: 
Mi trovo a buon punto.

Pietro:
In linea

##Programma per la prossima settimana
Cristiano: 
Fare funzionare l'invio di log al server, finire la documentazione e testare il progetto. Eventualmente fare la scrittura su EEPROM dei log offline.

Dragan e Pietro: 
Finire con la documentazione e mettere assieme tutto il progetto e testare il tutto

