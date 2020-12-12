# Pila con vettore

[Implementazione su Repl](https://repl.it/@EsterMolinari/PilaVettoreSlide#main.cpp)

Una **pila** una struttura dati con accesso di tipo **LIFO**, ovvero **"Last In, First Out"**.
Questo tipo di accesso garantisce l'inserimento dei dati all'inizio della pila (*head*) e la rimozione dei dati sempre dall'inizio della pila. La sua struttura ricorda quella di una lista il cui accesso è limitato al primo elemento memorizzato al suo interno.

![Immagine di una pila](https://cdn.programiz.com/sites/tutorial2program/files/stack.png)

# Specifica sintattica della struttura dati
## Tipi di dato
* pila
* boolean
* tipoelem

## Operatori
* creapila:   ( )              → pila
* pilavuota:  (pila)           → boolean 
* leggipila:  (pila)           → tipoelem
* fuoripila:  (pila)           → pila
* inpila:     (tipoelem, pila) → pila

# Specifica semantica della struttura dati
## Tipi di dato
* pila: insieme delle sequenze p = <a1, a2, …, an>, n >= 0, di elementi di tipo tipoelem gestita con accesso LIFO
  * Identificatore pila: p
  * Identificatore pila aggiornata: p'
  * Identificatore tipoelem: a
* boolean: insieme dei valori di verità
  * Identificatore boolean: b

## Operatori
* creapila = p
  * post: p = <> (la sequenza vuota) 
* pilavuota(p) = b
  * post: b = vero se p = <>, b = falso altrimenti
* leggipila(p) = a
  * pre: p = <a1, a2, …, an> n >= 1
  * post: a = a1
* fuoripila(p) = p'
  * pre: p = <a1, a2, …, an> n >= 1
  * post: p' = <a2, a3, …, an> se n > 1, p’ = <> se n = 1
* inpila(a, p) = p'
  * pre: p = <a1, a2, …, an> n >= 0
  * post: p' = <a, a1, a2, …, an>

La pila è un particolare tipo di lista, infatti l'implementazione di una pila si può esprimere come
* creapila() → crealista()
* pilavuota(p) → listavuota(p) 
* leggipila(p) → leggilista(primolista(p), p)
* fuoripila(p) → canclista(primolista(p), p)
* inpila(a, p) → inslista(a, primolista(p))

Gli elementi della pila vanno memorizzati in ordine inverso, mantenendo il cursore alla testa della pila.

Contenuto del programma:
* **`main.cpp`**
  * Contiene il main
* **`lista.h`**
  * Contiene la dichiarazione e l'implementazione della classe `class Lista`
* **`nodo.h`**
  * Contiene la dichiarazione e l'implementazione della classe `class Nodo`
  
In questo programma, tutti i file `.h` contengono tutte le implementazioni, quindi non è presente alcun file `.cpp`.

###### Se dovesse essere presente un file `main`, è stato generato in automatico da Repl ed è un file binario non utile ai fini del funzionamento del programma.

## Operatori della classe `class Nodo`
1. `Nodo()`
    * Costruttore dell'oggetto `Nodo`
2. `Nodo(tipoelem a)`
    * Costruttore default dell'oggetto `Nodo`
3. `~Nodo()`
    * Distruttore dell'oggetto `Nodo`
4. `void setElemento(tipoelem a)`
    * Inserisce un elemento di tipo tipoelem nel nodo
5. `tipoelem getElemento() const`
    * Restituisce un elemento di tipo tipoelem dal nodo
6. `bool operator ==(Nodo &n)`
    * Sovraccarica l'operatore `==` per permetterne la stampa
  
## Operatori della classe `class Pila`
1. `Pila()`
    * Costruttore dell'oggetto `Pila`
2. `~Pila()`
    * Distruttore dell'oggetto `Pila`
3. `void creaPila()`
    * Crea una pila vuota
4. `bool pilaVuota() const`
    * Se la pila è vuota restituisce 1, altrimenti 0
5. `tipoelem leggiPila() const`
    * Restituisce un elemento di tipo tipoelem dalla pila
6. `void fuoriPila()`
    * Elimina un elemento in testa alla pila
        * Questo operatore può essere chiamato anche `void pop()`
7. `void inPila(tipoelem a)`
    * Inserisce un elemento di tipo tipoelem alla testa della pila
        * Questo operatore può essere chiamato anche `void push(tipoelem a)`
8. `friend void stampPila(Pila &p);`
    * Stampa tutti gli elementi di una pila
        * Vedere le note per l'uso della keyword `friend`

## Operatori della classe `class Libro`
1. Costruttori
    1. Default
        * `Libro()`
    2. Distruttore
        * `~Libro()`
2. `void setTitolo(string)`
    * Inserisce un elemento di tipo stringa nella lista
3. `string getTitolo() const`
    * Restituisce il titolo di un elemento
4. `bool operator==(Libro)`
    * Sovraccarica l'operatore == per permetterne l'output
    
## Nota sull'uso della keyword `friend`
La keyword `friend` viene usata per permettere ad una funzione non dichiarata nella sezione `public` della classe di poter utilizzare gli elementi contenuti nella sezione `private`. 
Nel programma, questa viene usata per la funzione:

`friend void stampPila(Pila &p);`

in quanto ha bisogno di poter accedere agli elementi della pila per poterli stampare.

###### **Attenzione!** La creazione di una "amicizia" non è transitiva (ovvero, un amico di un tuo amico non è il tuo amico) e non è ereditaria (quindi gli amici del figlio di un tuo amico non sono tuoi amici). Per altre informazioni, cliccare su [questo link](https://en.cppreference.com/w/cpp/language/friend)

## Nota sull'uso della espressione finale `const`
La dicitura `<nome_funzione> () const` viene utilizzata quando non si desidera modificare i dati della struttura in uso.
Nel programma, questa viene usata nei seguenti metodi:
* `tipoelem getElemento() const;`
* `bool pilaVuota() const;`
* `tipoelem leggiPila() const;`

## Nota sul sovraccarico degli operatori
In questo programma c'è il sovraccarico dell'operatore `<<` e dell'operatore `==`.
Entrambi si trovano in `nodo.h` e servono per la classe `Libro`.
* `std::ostream& operator<<(std::ostream&, const Nodo &n);`
  * Si occupa di permettere la stampa degli elementi di tipo Nodo come se fossero dati normali
    * In questo modo quando viene utilizzato `cout <<` non ci saranno problemi se l'oggetto da stampare ha un tipo definito dall'utente
* `bool operator ==(Nodo &n);`
  * Si occupa di permettere il confronto tra due elementi di tipo Nodo come se fossero dati normali
    * In questo modo posso utilizzare `==` anche con oggetti di tipo definito dall'utente

In generale, per sovraccaricare un operatore del tipo `<<` si scrive:

`std::ostream& operator<<(std::ostream&, const <nome_classe> <nome_oggetto>);`

Invece, per sovraccaricare un operatore del tipo `==` si scrive:

`bool operator==(<nome_classe> <nome_oggetto>);`
