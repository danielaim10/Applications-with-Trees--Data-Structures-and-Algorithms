TEMA 2 - MUNTEANU IRINA DANIELA

Mai intai, am initilizat structura de tip node , adaugand pe langa nodurile 
copii doua variabile , value si level, care retine caracterul pe care il are
nodul, respectiv nivelul la care este in structura arborelui. Important este
ca root-ul nostru este pe nivelul 0.

CERINTA 1:
Incepem inserarea sufixelor pe care le-am format in main() prin adaugarea la
finalul fiecarui sufix caracterul $, dupa aceea apelam functia insertSuffix. 
Aceasta functie ia element cu element suffixul dat, ii afla indexul care este 
aflat usor datorita codului ASCII (singura exceptie o face caracterul $ care 
e pus pe indexul 0).Dupa aceea verificam daca acel copil deja exista, daca nu,
inseram valoarea pe care o are copilul in nod, si trecem la urmatorul suffix 
de inserat. In caz contrar, urmatorul nostru root va deveni copilul pentru a
putea continua prelucrarea.In final. functia de afisare aplica parcurgerea 
BFS a arborelui si afiseaza elemente in latime, tinand cont de cazul special,
adica nodul care are valoare $.

CERINTA 2: 3 functii cu utilitate diferita:
-numara nodurile frunza din arbore:Functia retine intr-o variabila numita
count.
Intai verificam daca root este null, adica nu are niciun copil, va returna 0.
Dacă cnull este încă 1 (adevărat) după buclă, înseamnă că toți copiii nodului 
curent sunt nuli, deci nodul curent este o frunză. Se incrementează count cu 1
pentru a număra această frunză.Pentru fiecare copil al nodului curent care nu 
este nul, se apelează recursiv funcția count_frunza pe acel copil.Valoarea 
returnată de apelul recursiv (numărul de noduri frunză din subarborele 
copilului)se adaugă la variabila count.

-numara sufixele de dimensiune k:Funcția verifică dacă nodul curent (root) are
valoarea $ (sfârșit de șir) și se află la nivelul k + 1.Dacă ambele condiții 
sunt îndeplinite, înseamnă că am ajuns la un sufix de lungime k și 
incrementează count cu 1 pentru a-l număra.Pentru fiecare copil al nodului 
curent care nu este nul, se apelează recursiv funcția countK pe acel copil.
Se incrementează variabila t pentru a ține evidența numărului de noduri 
traversate în calea curentă.
Valoarea returnată de apelul recursiv (numărul de sufixe de lungime k găsite 
în subarborele copilului) se adaugă la count.După parcurgerea recursivă a 
copiilor, se verifică dacă nodul curent este un $ (sfârșit de șir) și dacă t
este egal cu k (numărul de noduri traversate).
Dacă ambele condiții sunt îndeplinite, înseamnă că am găsit un sufix de 
lungime k format prin concatenarea etichetelor nodurilor de pe calea curentă
(excluzând nodul curent). Se incrementează count cu 1 pentru a-l număra.

-valoarea maxima de descendenti din nodurile arborelui:Pentru fiecare copil 
care nu este nul (root->children[i]), se incrementează current cu 1 pentru 
a contoriza un descendent suplimentar.
Verificam intre numarul de noduri curent si si numarul maxim determinat pana
atunci care este mai mare, si numarul mai mare il punem in maxc.

CERINTA 3:
Refacem initializarea deoarece de aceasta data avem de citit 2 variabile N si M
cat si 2 siruri de texte cu aplicatii diferite.
Functia check verifica daca cele M siruri de caractere sunt sufixe ale 
arborelui format din cele N cuvinte.
Se verifică dacă copilul cu indexul index al nodului curent (root) există. Dacă
nu există, înseamnă că sufixul nu există în arbore și se returnează 0.
Se compară valoarea caracterului din suffix (la indexul curent i) cu valoarea
copilului. Dacă nu coincid, înseamnă că sufixul nu se potrivește cu calea din 
arbore și se returnează 0.Daca aceste operatii se fac trecem copilul ca root si
continuam sa verificam copiii acestuia.
Se verifică dacă există un copil $ la nodul curent. Dacă există, înseamnă că 
sufixul se termină la un nod terminal ($), reprezentând un sufix complet, și se
returnează 1.
Dacă nu există un copil $, înseamnă că sufixul nu se termină la un nod terminal
și nu este un sufix complet al șirului original, și se returnează 0.
