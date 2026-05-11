
  <h1>C++ Graph Algorithms Engine</h1>
  <blockquote>Analiza wydajności struktur danych w algorytmach grafowych dla systemów o wysokiej dostępności.</blockquote>

  <p>
    <img src="https://img.shields.io/badge/C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++20" />
    <img src="https://img.shields.io/badge/GCC-A3D139?style=for-the-badge&logo=gnu&logoColor=white" alt="GCC" />
    <img src="https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white" alt="VS Code" />
    <img src="https://img.shields.io/badge/License-MIT-blue?style=for-the-badge" alt="License MIT" />
  </p>
</div>

<div align="center">

### Quick Stats

| Metryka | Wartość | Opis |
|---|---|---|
| **Złożoność Czasowa (Prim)** | `O(E log V)` | Zoptymalizowane użycie kolejki priorytetowej w `MST_Prim` |
| **Złożoność Pamięciowa** | `O(V + E)` | Wysoce wydajna lista sąsiedztwa dla grafów rzadkich |
| **Baza Kodowa** | `~400 LOC` | Czysta architektura z separacją interfejsu `IGraph` |
| **Czas Kompilacji** | `< 2s` | Błyskawiczny build dzięki podziałowi na nagłówki |

</div>

## Visual Preview

<div align="center">
  <img src="https://via.placeholder.com/800x350/1E1E1E/569CD6/?text=Graph+Algorithms+Benchmark+Terminal+Output" alt="Terminal Preview" />
</div>

## About & Business Value

Wydajność operacji na grafach jest fundamentalna w systemach nawigacyjnych, analizie sieci oraz silnikach decyzyjnych. Ten projekt dostarcza wysokowydajne i bezpieczne pod kątem pamięci implementacje kluczowych algorytmów grafowych (BFS, DFS, Minimalne Drzewo Rozpinające) w C++. Dzięki zastosowaniu wzorców projektowych opartych na interfejsach, projekt ułatwia analizę i bezkosztową wymianę struktur danych, co bezpośrednio przekłada się na redukcję zużycia zasobów obliczeniowych (CPU, RAM).

| Feature | Description | Business Value |
|---|---|---|
| **Interface-Driven Design** | Abstrakcja `IGraph` ukrywająca detale implementacyjne poszczególnych struktur. | Błyskawiczna adaptacja różnych reprezentacji grafów bez naruszania logiki biznesowej. |
| **Dual Representation** | Implementacja *Adjacency Matrix* (Macierz) oraz *Adjacency List* (Lista). | Oszczędność infrastruktury poprzez precyzyjne dopasowanie struktury do gęstości danych. |
| **Embedded Profiling** | Skonfigurowane moduły pomiarowe z wykorzystaniem modułu `std::chrono`. | Decyzje architektoniczne i optymalizacje poparte twardymi dowodami i telemetrią. |

### What Makes This Different?

<div align="center">
  <table>
    <tr>
      <th align="center">Typowe Projekty Akademickie</th>
      <th align="center">Ten Projekt (Ready-for-Production)</th>
    </tr>
    <tr>
      <td valign="top">
        <ul>
          <li>Sztywno zakodowane struktury danych.</li>
          <li>Mieszanie warstwy logiki z modelem.</li>
          <li>Brak weryfikacji i obsługi błędów w czasie runtime.</li>
          <li>Brak wbudowanych testów wydajności.</li>
        </ul>
      </td>
      <td valign="top">
        <ul>
          <li><strong>Elastyczność:</strong> Pełen polimorfizm oparty na <code>IGraph</code>.</li>
          <li><strong>Czysty Kod:</strong> Restrykcyjna separacja `*.h` oraz `*.cpp`.</li>
          <li><strong>Solidność:</strong> Zabezpieczenia, np. validacja ilości krawędzi (<code>std::invalid_argument</code>).</li>
          <li><strong>Benchmarking:</strong> Automatyczny pomiar MS przy różnych obciążeniach.</li>
        </ul>
      </td>
    </tr>
  </table>
</div>

## Tech Stack

<div align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B" alt="C++20" />
  <img src="https://img.shields.io/badge/Compiler-GCC_10%2B-A3D139?style=for-the-badge&logo=gnu" alt="GCC Compiler" />
  <img src="https://img.shields.io/badge/IDE-VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code" alt="VS Code" />
</div>

<br>

**Why This Stack?** Wybór **C++20** gwarantuje bezkompromisową wydajność i natywne wykonanie, eliminując nieprzewidywalność Garbage Collectora obecnego w wyższych językach. Zastosowanie kompilatora **GCC** (via g++) z odpowiednimi flagami pozwala na drastyczną optymalizację pamięciową. Środowisko pracy oparte o VS Code (`tasks.json` z auto-buildem) minimalizuje próg wejścia dla inżynierów dołączających do projektu (Developer Experience).

## Performance & Quality

Platforma testowa analizuje wydajność algorytmu Prima względem reprezentacji w pamięci:

| Typ Grafu (V: Wierzchołki, E: Krawędzie) | Czas: Macierz Sąsiedztwa | Czas: Lista Sąsiedztwa | Rezultat |
|---|---|---|---|
| O rzadkiej gęstości (V=2000, E=5000) | `[~ Wymaga profilowania]` | `[~ Wymaga profilowania]` | Znacząca przewaga Listy (Brak zbędnych iteracji) |
| O średniej gęstości (V=2000, E=50000) | `[~ Wymaga profilowania]` | `[~ Wymaga profilowania]` | Redukcja narzutu macierzy |


```


File generated successfully: /mnt/data/README.md


Przykładowy wyjściowy pomiar (Measured Metrics):
=========================================
  BENCHMARK: V = 2000, E = 50000
=========================================
--- MACIERZ SASIEDZTWA ---
Czas dzialania algorytmu Prima: [X] ms

--- LISTA SASIEDZTWA ---
Czas dzialania algorytmu Prima: [Y] ms
=========================================

```

### Applied Quality Layers

## Accessibility

W świecie komponentów backendowych (C++), "Dostępność" definiowana jest jako **Code Accessibility & Developer Experience (DX)**:

* **Płaskie Krzywe Uczenia:** Spójne API (np. `getOutgoingEdges`, `getVerticesCount`).
* **Semantic Code:** Silne typowanie i semantyka zmiennych ograniczające błędy deweloperskie.
* **Hermetyzacja Zależności:** Brak wymagań instalacji zewnętrznych bibliotek (Zero-Dependencies), wszystko oparte na standardzie języka (STL).
* **Środowisko:** Prekonfigurowany *workspace* (pliki `.vscode`), pozwalający na jedno-kliknięciowe budowanie projektu na każdej maszynie z zainstalowanym `g++`.

## Getting Started

### Prerequisites

* Kompilator wspierający **C++17/20** (np. GCC, Clang).
* Edytor wspierający integrację z systemem budowania (rekomendowany VS Code).

### Quick Start

```bash
# 1. Pobranie i przejście do głównego folderu
cd Graphs

# 2. Kompilacja całego projektu przy użyciu wbudowanego zadania lub ręcznie
g++ -fdiagnostics-color=always -g src/*.cpp -Iinclude -o projekt_grafy

# 3. Uruchomienie aplikacji testowo-weryfikacyjnej
./projekt_grafy

```

### Quality Checks

```bash
# Weryfikacja wycieków pamięci (Wymaga Valgrind - Linux)
valgrind --leak-check=full --show-leak-kinds=all ./projekt_grafy

# Analiza profilowania i obciążeń
gprof ./projekt_grafy gmon.out > analysis.txt

```

### Project Structure

```text
├── .vscode/               # Ustawienia kompilacji dla środowiska
│   ├── c_cpp_properties.json 
│   └── tasks.json         # Konfiguracja build toolchain
├── include/               # Publiczne nagłówki (Interfejsy)
│   ├── Algorithms.h       # API algorytmów 
│   ├── Graphs.h           # Klasy implementujące (Macierz, Lista)
│   └── IGraph.h           # Definicja kontraktu i krawędzi (Edge)
├── src/                   # Implementacja i logika bazowa
│   ├── Algorithms.cpp     
│   ├── Graphs.cpp         
│   └── main.cpp           # Moduł pomiarowy i uruchomieniowy
└── .gitignore             # Wykluczenia binarne dla gita

```

## Lessons Learned / Roadmap

| Priority | Feature / Module | Status |
| --- | --- | --- |
| 🔴 | **Algorytm Dijkstry** (Najkrótsza ścieżka z obsługą wag) | `W planach` |
| 🟡 | **Serializacja Danych** (Zapis/Odczyt grafu do CSV/JSON) | `Backlog` |
| 🟢 | **Grafy Skierowane** (Rozszerzenie kontraktu IGraph) | `Idea` |
| 🟢 | **Wsparcie dla CMake** (Niezależność od tasków VS Code) | `Idea` |



