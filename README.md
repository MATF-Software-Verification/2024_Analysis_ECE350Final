# Analiza projekta 'ECE350Final'

U okviru predmeta **Verifikacija softvera**, analizirala sam projekat pod nazivom **ECE350Final**, koji je dostupan na adresi: [ECE350Final](https://github.com/loganizer405/ECE350Final).
Analizirana je **main** grana, a hash koda commita je: `9f2178701f3656a61eb08b5a3cc241ee477ca802`.
 Ovaj projekat implementira igru **Durak** u programskom jeziku **C++**.


## Opis igre

**Durak** je popularna kartaška igra koja se igra sa špilom od **36 karata**. Cilj igrača je da izbegnu da postanu „durak” (najgori igrač), odnosno da ostanu poslednji sa kartama u ruci. 

Igra se odvija prema sledećim pravilima:
- Igrači se smenjuju u **napadu** i **odbrani**.
- **Napadač** postavlja kartu na sto.
- **Odbrambeni igrač** mora odgovoriti odgovarajućom kartom.
- Ukoliko odbrambeni igrač ne može da se odbrani, karta prelazi u njegove ruke.
- Igra traje dok neki igrač ne ostane bez karata.

## Korišćeni alati

Za analizu i verifikaciju koda korišćeni su sledeći alati:

1. **Catch2** – za pisanje i izvršavanje jedinčnih testova.
2. **Valgrind Memcheck** – za otkrivanje curenja memorije i problema s upravljanjem memorijom.
3. **Valgrind Callgrind** – za profilisanje performansi i analizu poziva funkcija.
4. **Valgrind Massif** – za analizu upotrebe memorije tokom izvršavanja programa.
5. **Clang-Tidy** – za statičku analizu koda i uočavanje potencijalnih grešaka.
6. **CppCheck** – za statičku analizu koda sa fokusom na sigurnost i kvalitet.


## Jedinični testovi uz Catch2 i lcov

Jedinični testovi su napisani korišćenjem biblioteke **Catch2** u kombinaciji sa alatom **lcov** kako bi se osigurala visoka pokrivenost koda i pouzdanost aplikacije. Catch2 je omogućio jednostavnu i čitljivu sintaksu za pisanje testova, dok je alat **lcov** korišćen za generisanje vizualnih izveštaja o pokrivenosti, što je pomoglo da se identifikuju i testiraju neobrađene grane koda. Ovaj proces je omogućio unapređenje kvaliteta koda i smanjenje mogućnosti grešaka, osiguravajući da aplikacija zadovolji sve funkcionalne i performansne zahteve.

### Pokretanje testova

Da biste pokrenuli testove, pratite sledeće korake:

1. Klonirajte projekat pomoću sledeće komande:
    ```bash
    git clone https://github.com/MATF-Software-Verification/2024_Analysis_ECE350Final.git
    ```

2. Instalirajte alat **lcov**:
    ```bash
    sudo apt install lcov
    ```

3. Pozicionirajte se u direktorijum sa jediničnim testovima:
    ```bash
    cd unit_test/
    ```

4. Dodajte **+x** privilegiju za skriptu `run_tests.sh`:
    ```bash
    chmod +x run_tests.sh
    ```

5. Pokrenite testove:
    ```bash
    ./run_tests.sh
    ```

Ovim postupkom možete pokrenuti testove i generisati izveštaje o pokrivenosti koda.
## Prevođenje programa
Napomena: pre pokretanja svih Valgrind alata neophodno je da:
1. Klonirate projekat pomoću sledeće komande:
    ```bash
    git clone https://github.com/MATF-Software-Verification/2024_Analysis_ECE350Final.git
    ```
2. Pozicionirate se u `src` folder:
    ```bash
    cd src
    ```
3. Prevedete program naredbom:
    ```bash
    make
    ```

## Valgrind Memcheck
Nakon sto ste preveli program kao sto je opisano u delu **Prevođenje programa**, potrebno je da pratite sledeće korake:

1. Instalacija potrebnih alata

   ```bash
   sudo apt install valgrind
   ```

2. Pozicionirajte se u direktorijum gde se nalazi skript za pokretanje memcheck-a:
    ```bash
    cd ../valgrind/memcheck
    ```

3. Dodajte **+x** privilegiju za skriptu `run_memcheck.sh`:
    ```bash
    chmod +x run_memcheck.sh
    ```

4. Pokrenite skipt:
    ```bash
    ./run_memcheck.sh
    ```
Kada pokrenete skriptu na ovaj način, **Valgrind** analizira vaš program tokom njegove izvršne faze. To znači da će se sam program pokrenuti i izvršavati dok Valgrind prati memorijske greške. Potrebno je poznavati pravila igre, kako bi bilo moguce da se skript izvrsi do kraja.

## Valgrind Callgrind
Nakon sto ste preveli program kao sto je opisano u delu **Prevođenje programa**, potrebno je da pratite sledeće korake:
1. Instalacija potrebnih alata

   ```bash
   sudo apt install valgrind
   sudo apt-get install kcachegrind
   ```

2. Pozicionirajte se u direktorijum gde se nalazi skript za pokretanje callgrind-a:
    ```bash
    cd ../valgrind/callgrind
    ```

3. Dodajte **+x** privilegiju za skriptu `run_callgrind.sh`:
    ```bash
    chmod +x run_callgrind.sh
    ```

4. Pokrenite skipt:
    ```bash
    ./run_callgrind.sh
    ```
Pokretanje skripte će se sam program pokrenuti i izvršavati pa je potrebno je poznavati pravila igre, kako bi bilo moguce da se skript izvrsi do kraja.

## Valgrind Massif
Nakon sto ste preveli program kao sto je opisano u delu **Prevođenje programa**, potrebno je da pratite sledeće korake:
1. Instalacija potrebnih alata

   ```bash
   sudo apt install valgrind
   ```

2. Pozicionirajte se u direktorijum gde se nalazi skript za pokretanje massifa-a:
    ```bash
    cd ../valgrind/massif
    ```

3. Dodajte **+x** privilegiju za skriptu `run_massif.sh`:
    ```bash
    chmod +x run_massif.sh
    ```

4. Pokrenite skipt:
    ```bash
    ./run_massif.sh
    ```
Pokretanje skripte će se sam program pokrenuti i izvršavati pa je potrebno je poznavati pravila igre, kako bi bilo moguce da se skript izvrsi do kraja.

## Clang-tidy
Clang-Tidy je statički analizator koda koji pomaže u otkrivanju grešaka, unapređenju kvaliteta koda i primeni kodnih standarda u C++ projektima.

Da biste pokrenuli Clang-tidy , pratite sledeće korake:
1. Klonirajte projekat pomoću sledeće komande:
    ```bash
    git clone https://github.com/MATF-Software-Verification/2024_Analysis_ECE350Final.git
    ```
2. Instalacija potrebnih alata

   ```bash
   sudo apt-get install clang-tidy

   ```

3. Pozicionirajte se u direktorijum gde se nalazi skript za pokretanje clang-tidy:
    ```bash
    cd clang
    ```

4. Dodajte **+x** privilegiju za skriptu `run_clang.sh`:
    ```bash
    chmod +x run_clang.sh
    ```

5. Pokrenite skipt:
    ```bash
    ./run_clang.sh
    ```

## CppCheck
Cppcheck je alat za statičku analizu C++ koda koji pomaže u pronalaženju grešaka, sigurnosnih propusta i potencijalnih problema u kodu, bez potrebe za izvršavanjem programa.
Da biste pokrenuli CppCheck , pratite sledeće korake:
1. Klonirajte projekat pomoću sledeće komande:
    ```bash
    git clone https://github.com/MATF-Software-Verification/2024_Analysis_ECE350Final.git
    ```
2. Instalacija potrebnih alata

   ```bash
   sudo apt install cppcheck

   ```

3. Pozicionirajte se u direktorijum gde se nalazi skript za pokretanje cppcheck-a:
    ```bash
    cd cppcheck
    ```
4. Dodajte **+x** privilegiju za skriptu `run_cppCheck.sh`:
    ```bash
    chmod +x run_cppCheck.sh
    ```

5. Pokrenite skipt:
    ```bash
    ./run_cppCheck.sh
    ```
## Zaključak
Rezultate primene svih alata i sve zaključke, možete pogledati fajlu ProjectAnalysisReport.pdf.
## Autor

**Jelena Mitrović**  

Broj indeksa: **1019/2024** 

Kontakt: **jelenamitrovic296@gmail.com**
