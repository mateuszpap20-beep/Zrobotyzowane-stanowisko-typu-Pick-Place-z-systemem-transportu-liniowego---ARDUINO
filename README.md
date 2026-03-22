# 🤖 Zrobotyzowane-stanowisko-typu-Pick-Place-z-systemem-transportu-liniowego---ARDUINO
## 📺 Demonstracja Wideo
Zachęcam do obejrzenia pełnego cyklu pracy urządzenia (detekcja, transport, manipulacja) pod poniższym linkiem:

👉 **[KLIKNIJ TUTAJ: Wideoprezentacja działania systemu na YouTube]** ((https://www.youtube.com/shorts/-lhYYwHI6BA))


## 📖 Przegląd Projektu
Projekt obejmuje zaprojektowanie, wykonanie i zaprogramowanie w pełni autonomicznego stanowiska zrobotyzowanego. System integruje transport liniowy z manipulacją 3-osiową w celu stworzenia zamkniętej pętli logistycznej (Close-Loop Process). 

Wszystkie elementy mechaniczne zostały opracowane w środowisku CAD i wykonane w technologii przyrostowej (Druk 3D), co pozwoliło na optymalizację wagi ramienia oraz precyzyjne dopasowanie gniazd pod sensorykę i napędy.

---

## 🏗️ Specyfikacja Techniczna i Hardware

### 1. Konstrukcja Mechaniczna (CAD/3D Printing)
* **Ramię Robotyczne:** Wydrukowane w 3D ramię wieloosiowe wyposażone w serwomechanizmy modelarskie (micro servos) oraz dwuszczękowy chwytak dopasowany do kształtu przenoszonych detali (cylindrów).
* **System Transportowy:** Autorski projekt transportera z 3D-drukowaną taśmą modułową, napędzaną silnikiem z przekładnią. Zastosowano specjalne koła napędowe zapobiegające ześlizgiwaniu się taśmy.
* **Baza:** Komponenty osadzone na przezroczystej płycie z pleksi, co zapewnia sztywność układu oraz ułatwia estetyczne prowadzenie okablowania.

### 2. Elektronika i Sterowanie (Embedded Systems)
* **Jednostka sterująca:** **Arduino Uno** wyposażone w dedykowaną nakładkę (Sensor/Servo Shield) ułatwiającą podłączenie napędów i minimalizującą plątaninę kabli.
* **Detekcja detali:** Przemysłowy czujnik zbliżeniowy/optyczny (w obudowie cylindrycznej) zamontowany na końcu linii, pełniący funkcję cyfrowego sygnału wyzwalającego (Trigger) dla cyklu robota.
* **Zasilanie:** Zewnętrzne zasilanie wyprowadzone przez złącze śrubowe (terminal block), zapewniające stabilny prąd dla pracujących serwomechanizmów i napędu taśmy.
* **Napędy:** Precyzyjne serwomechanizmy sterowane sygnałem PWM, zapewniające powtarzalność pozycji.

### 3. Logika Programowa (Software)
* **Algorytm sekwencyjny:** Implementacja maszyny stanów (Finite State Machine), eliminująca błędy synchronizacji między transporterem a ramieniem.
* **Synchronizacja:** Wykorzystanie przerwań i pętli sprawdzających stan czujnika (polling) do natychmiastowego zatrzymania linii po wykryciu detalu.
* **Kalibracja:** Funkcja bazowania (homing) po uruchomieniu układu, zapewniająca bezpieczeństwo mechaniczne.

---

## 🔄 Algorytm Działania (Workflow)
1.  **TRANSPORT:** Silnik transportera przesuwa detal (beczkę) do strefy odbioru.
2.  **TRIGGER:** Detal wchodzi w pole widzenia czujnika cylindrycznego -> Sygnał trafia do mikrokontrolera.
3.  **STOP:** Natychmiastowe zatrzymanie napędu transportera.
4.  **PICK:** Sekwencyjny ruch ramienia: ustawienie pozycji, opuszczenie ramienia, zamknięcie chwytaka na detalu.
5.  **PLACE:** Przeniesienie detalu po ustalonej trajektorii i odłożenie go na sam początek transportera.
6.  **RESET:** Powrót ramienia do pozycji bezpiecznej (Home) i ponowne załączenie napędu taśmy.
---

## 📈 Potencjał Rozwojowy
* Implementacja **Inverse Kinematics (IK)** dla płynniejszych ruchów ramienia.

---
**Autor:** [Mateusz Papierski]
*Student Automatyki i Robotyki Politechniki Poznańskiej*
