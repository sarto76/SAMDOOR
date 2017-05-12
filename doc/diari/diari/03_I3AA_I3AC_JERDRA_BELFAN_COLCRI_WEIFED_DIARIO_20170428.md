###Diario Modulo 306
##Luogo: SAMT Trevano
##Data: 28.04.2017
##Lavori svolti
Cristiano:
Lavorato sulla scrittura/lettura dell'SD tutto il giorno (vedere capitolo successivo).
##Problemi riscontrati e soluzioni adottate
Cristiano:
Ho riscontrato un problema con la memoria dell'Arduino in quanto non risulta sufficiente per i requisiti proposti. Nonostante possano non sembrare un granchè la SRAM dell'Arduino Ethernet è limitata ad appena 2 KB, e la libreria SD ufficiale ne occupa una quantità immane, sia di flash che di SRAM. La libreria SD ufficiale dell'Arduino richiede di tenere liberi 512 byte (1/4 della memoria) come buffer. Allo stato attuale la memoria è occupata circa all'80%. Per risolvere il problema, ho sostituito la libreria ufficiale con una libreria wrapper (https://github.com/greiman/PetitFS) che occupa molta meno memoria (12% flash e 5% sram) della libreria per microcontrollori AVR Petit FAT File System (http://elm-chan.org/fsw/ff/00index_p.html). La lettura funziona a meraviglia mentre la scrittura no a causa di mancanza di esempi per questa particolare classe wrapper. Ho trovato altre risorse che potrebbero aiutarmi nel comprendere come utilizzare la libreria per la scrittura ma trattandosi di C/C++ non garantisco di riuscirci.

- http://www.atmel.com/Images/Atmel-42776-Using-the-Petit-FAT-File-System-Module-with-AVR_ApplicationNote_AVR42776.pdf
- https://gist.github.com/RickKimball/2325039
- http://elm-chan.org/fsw/ff/pf/write.html
- https://forum.arduino.cc/index.php?topic=338368.0

##Punto di situazione del lavoro

Indietro con il piano.

##Programma per la prossima settimana

Provare ancora a fare la scrittura su SD con la libreria in C/C++ altrimenti provare con scrittura su EEPROM (ma avrebbe solo 1KB di spazio) e se anche qua andasse male, continuare con il resto.