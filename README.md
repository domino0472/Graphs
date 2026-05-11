Przepraszam za niedogodność. Oto pełny kod Markdown wygenerowanego pliku `README.md`, który możesz bezpośrednio skopiować:

```markdown
# Projekt Grafy - Algorytmy i Reprezentacje

## Opis projektu
Projekt ten to implementacja w języku C++ podstawowych struktur danych oraz algorytmów grafowych. Jego głównym celem jest dostarczenie ujednoliconego interfejsu dla różnych reprezentacji grafów (macierz sąsiedztwa i lista sąsiedztwa) oraz zbadanie ich wydajności poprzez pomiary czasu (benchmarki) wykonania popularnych algorytmów, takich jak algorytm Prima.

## Zaimplementowane funkcjonalności

### Reprezentacje grafu
Oparte na wspólnym interfejsie `IGraph`, obsługujące wagi krawędzi:
* **AdjacencyMatrixGraph** - reprezentacja za pomocą macierzy sąsiedztwa. Zoptymalizowana do sprawdzania występowania krawędzi, ale zajmująca więcej pamięci (`O(V^2)`).
* **AdjacencyListGraph** - reprezentacja za pomocą list sąsiedztwa. Zoptymalizowana pod kątem iteracji po krawędziach i zużycia pamięci w grafach rzadkich.

### Algorytmy grafowe
* **BFS (Breadth-First Search)** - przeszukiwanie wszerz wykorzystane do znajdowania najkrótszej ścieżki pomiędzy węzłami (`findShortestPathBFS`).
* **DFS (Depth-First Search)** - przeszukiwanie grafu w głąb (`traverseDFS`).
* **Algorytm Prima (MST)** - wyznaczanie minimalnego drzewa rozpinającego (Minimum Spanning Tree) wraz z jego całkowitą wagą (`findMST_Prim`).
* **Narzędzia pomocnicze** - generator losowych grafów spójnych gwarantujący brak izolowanych wierzchołków (`generateRandomConnectedGraph`).

### Pomiary wydajności (Benchmarki)
Aplikacja zawiera wbudowane testy wydajnościowe (`runBenchmark` w pliku `main.cpp`), które w sposób automatyczny:
1. Generują duży, losowy graf spójny.
2. Ładują dane do obu reprezentacji (lista i macierz).
3. Mierzą w milisekundach czas wykonania algorytmu Prima na obu strukturach, co ukazuje różnice wydajnościowe w zależności od gęstości grafu.

## Struktura repozytorium
```text
.
├── .gitignore                      # Reguły ignorowania plików dla Git
├── .vscode/                        # Ustawienia środowiska VS Code
│   ├── c_cpp_properties.json       # Konfiguracja IntelliSense dla C++20
│   └── tasks.json                  # Reguły automatycznej kompilacji
├── include/                        # Pliki nagłówkowe (deklaracje)
│   ├── Algorithms.h                # Deklaracje algorytmów grafowych
│   ├── Graphs.h                    # Klasy reprezentacji macierzowej i listowej
│   └── IGraph.h                    # Interfejs bazowy grafu oraz struktura Edge
└── src/                            # Pliki źródłowe (implementacje)
    ├── Algorithms.cpp              # Implementacje BFS, DFS, Prima i generatora
    ├── Graphs.cpp                  # Logika struktur danych macierzy i listy
    └── main.cpp                    # Główny punkt wejścia, testy poprawności i benchmarki

```

## Kompilacja i uruchomienie

### Wymagania

* Kompilator wspierający standard C++ (w konfiguracji `.vscode` ustawiono standard m.in. z rodziny `gnu++20` dla `gcc/g++`).
* System operacyjny: Linux, macOS lub Windows (np. z MinGW/WSL).

### Visual Studio Code

Projekt jest już skonfigurowany pod kątem VS Code. Aby go skompilować, użyj skrótu klawiszowego `Ctrl + Shift + B` (uruchomienie domyślnego zadania "C/C++: g++ build active file"). Plik wykonywalny zostanie utworzony w katalogu głównym pod nazwą `projekt_grafy`.

### Kompilacja z linii poleceń

Możesz ręcznie skompilować wszystkie pliki w terminalu za pomocą kompilatora g++:

```bash
g++ -g src/*.cpp -Iinclude -o projekt_grafy

```

### Uruchomienie programu

Po pomyślnej kompilacji, program można uruchomić wpisując:

```bash
# Linux / macOS
./projekt_grafy

# Windows
.\projekt_grafy.exe

```

Po uruchomieniu, w oknie konsoli wyświetlą się podstawowe testy małego grafu oraz wyniki wielkoskalowych benchmarków.

```

```
