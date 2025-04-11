# Prosjekt til emnet TDT4102 Prosedyre og Objektorientert programmering. 
Dette prosjektet er et spill som går ut på å besvare bla. mattespørsmål for å prenge bomber før de eksploderer eggene til en skilpadde. Ideen er ikke original, men basert på minner av et liknende spill jeg spilte da jeg var yngre. 

Programmet starter med å lage en instanse av klassen LaserTurtleWindow. Denne klassen arver fra AnimationWindow og har knappene programmet bruker i tillegg til egne funksjoner. Deretter går den inn i en while-løkke og blir der til programmet stopper. 

Inne i while-løkka vil koden sjekke hvilken pageMode (egendefiert enum class) den er i. Knappene gir brukeren mulighet til å bytte mellom de forskjellige pageModene. De forskellige modene er:
- Startside. Default. Viser logoen, en "start"-knapp og en "takk"-knapp.
- Takkesiden. En side som takker alle tredjeparter til prosjektet. Inneholder en knapp som tar spilleren tilbake til Startsiden.
- Spillesiden. Her er det spillet faktisk kjører. 

Dersom den er i "playing", vil koden definere alle variablene som kreves for å lage spillet, og gå inn i en ny while-løkke. Variablene som defineres er:
- Liste for alle bombene som er i 
- Liste for eksplosjonensanimasjonene i lufta
- Liste for laseranimasjonene i lufta
- Instanse av laserCannon
- String for å lagre det brukeren har skrevet inn

Inne i denne kalles en rekke funksjoner i en viss rekkefølge. Ting som tegnes senere tegnes på toppen av det som var der:
- addBombs: her ligger logikken for om bomber skal legges til eller ikke. 
- drawBackground: tegner bakgrunnen. 
- drawBombs: tegner bombene som er i lufta
- drawEggs: tegner eggene sim fortsatt er der
- drawLasers: tegner laseranimasjonene som fortsatt er aktive
- laser.drawCannon: tegner laserkanonen og skilpadden :) i riktig retning 
- drawExplotions: tegner eksplosjonsanimasjonene som fortsatt er aktive
- drawTypingScreen: tegner skjermen som viser hva det er brukeren har skrevet inn så langt.
- getCharInput: leser av hvilke taster brukeren har trykket inn, og styrer logikken assosiert med det. 


## Bruk av KI og andre hjelpemidler
ChatGPT
- Logoen på forsiden
- Genererte unordered_mappet i fila "readKeyInput.cpp"

Grafikk
- Skilpadden er laget av Yuliya Pauliukevich (klyaksun) fra Vecteezy.com
- Eksplosjonssanimasjonene er laget av M DANIEL (danilcool78457001) fra Vecteezy.com




# Refleksjonsnotat
Ideen til prosjektet kom før selve kodinga. Deretter var det viktig å implementere den mest grunnleggende funksjonaliteten. Først bombe-klassen, og at de beveget seg riktig, deretter brukerimput for å eksplodere de. Grafikken utviklet seg naturlig underveis. Jeg så det som ville fått spillet til å se betydelig bedre ut. Alle delene ved koden ble gjort iterativt, først å få på plass de viktigste funksjonene, gå videre til noe annet, og komme tilbake dersom det var behov. Det var enkelte ting jeg gjerne skulle fått lagt inn, som forskjellige vanskelighetsgrader, og en sluttscore, men det ble det desverre ikke tid til. Alt i alt har prosjektet tatt en del tid, men har vært gøy. 