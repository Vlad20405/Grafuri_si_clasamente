# Tema 2: Grafuri și clasamente - din cadrul disciplinei Proiectarea Algoritmilor

## Cerință: [O poți găsi aici](https://github.com/Vlad20405/Tema_2/blob/main/PA_tema2.pdf)

## Rulare & Verificare:
Pentru a rula și verifica funcționalitatea programului, trebuie să descărcați codul sursă atașat și să rulați comanda:
```shell
./checker.sh
```

## Informații generale:
* Pentru viitoarele persoane care doresc să îmbunătățească programul, se poate modifica orice în acesta, cu excepția fișierului `checker.sh` și a folderelor care conțin fișierele de `Input`, `RezultateGraf` și `RezultateScor`;
* Fișierul `main.c` este cel principal, în care s-a realizat deschiderea/închiderea fișierelor și fiecare cerință din temă prin apeluri către funcțiile aferente;
* În fișierul `main.h` se regăsesc toate structurile necesare pentru rezolvarea cerințelor, dar și legăturile dintre funcțiile necesare acestora;
* Am creat fișiere `.c` separate pentru funcțiile generice, de exemplu pentru liste, stive, grafuri;
* De asemenea, am creat fișierul `cerinte.c`, în care se regăsesc funcțiile pentru fiecare cerință în parte, și fișierul `functii.c`, care conține toate funcțiile create de mine pentru a putea rezolva sarcinile din temă.

## Rezolvarea cerințelor:

### Partea inițială:
* Aici am avut 4 subpuncte, de care m-am ocupat astfel:
* Am creat o funcție denumită `etapaInitiala()` care ia câte două echipe consecutiv din lista creată din fișierul de `Input`. Aceste echipe dispută un meci pe baza criteriului cerut în temă, iar echipa care iese învingătoare este introdusă în stiva de câștigători, iar echipa învinsă este introdusă în stiva de pierzători. Echipele sunt preluate în continuare până la finalizarea primei etape din campionat;
* După această parcurgere, am trecut la o nouă etapă, pentru care am implementat o nouă funcție denumită `etapaFinala()`. În această etapă, s-a creat o nouă rundă de meciuri între echipele care au ieșit învingătoare. În funcția `etapaFinala()`, m-am folosit de stiva de câștigători și de stiva de pierzători create la punctul anterior. Stiva de câștigători a fost actualizată prin intermediul unei liste secundare, iar în stiva de pierzători s-au adăugat noile elemente în continuarea acesteia. Acest proces s-a repetat până la aflarea echipei finaliste.

### Cerința 1:
* La această cerință, am avut de creat graful turneului. M-am folosit de funcția `introduceInGraf()` pentru a putea crea legăturile din graf pe baza meciurilor din campionat, iar în final am afișat matricea de adiacență.
 
### Cerința 2:
* Aici am avut ca sarcină crearea unei funcții, denumită `calculPrestigiu()`, care să calculeze prestigiul fiecărei echipe participante la turneu, iar în final am creat funcția `afisarePrestigiuEchipe()` pentru a putea face afișarea într-un fișier separat, așa cum cere cerința aferentă temei.
