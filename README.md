# 🤖 Zrobotyzowane-stanowisko-typu-Pick-Place-z-systemem-transportu-liniowego---ARDUINO
## 📺 Demonstracja Wideo
Zachęcam do obejrzenia pełnego cyklu pracy urządzenia (detekcja, transport, manipulacja) pod poniższym linkiem:

👉 **[KLIKNIJ TUTAJ: Wideoprezentacja działania systemu na YouTube]** ((https://www.youtube.com/shorts/-lhYYwHI6BA))


## 📖 Przegląd Projektu
Projekt obejmuje zaprojektowanie, wykonanie i zaprogramowanie w pełni autonomicznego stanowiska zrobotyzowanego. System integruje transport liniowy z manipulacją 3-osiową w celu stworzenia zamkniętej pętli logistycznej (Close-Loop Process). 

Wszystkie elementy mechaniczne zostały opracowane w środowisku CAD i wykonane w technologii przyrostowej (Druk 3D), co pozwoliło na optymalizację wagi ramienia oraz precyzyjne dopasowanie gniazd pod sensorykę i napędy.

---

## 🏗️ Specyfikacja Techniczna

### 1. Konstrukcja Mechaniczna (CAD/3D Printing)
* **Kinematyka:** 3-osiowe ramię typu SCARA/Anthropomorphic (zależnie od Twojej konstrukcji) z chwytakiem dwuszczękowym.
* **Transporter:** Przenośnik taśmowy z regulowanym naciągiem, napędzany silnikiem DC.
* **Materiał:** Wykorzystanie filamentu PLA / PET-G dla zapewnienia odpowiedniej sztywności konstrukcji przy dynamicznych ruchach.

### 2. Elektronika i Sterowanie (Embedded Systems)
* **Jednostka centralna:** Arduino (Atmega328P) realizująca algorytm sterowania w czasie rzeczywistym.
* **Sensoryka:** Czujnik optyczny (bariera podczerwieni) pełniący funkcję limitera drogi transportu i triggera dla sekwencji ruchu robota.
* **Napędy:** Precyzyjne serwomechanizmy sterowane sygnałem PWM, zapewniające powtarzalność pozycji.

### 3. Logika Programowa (Software)
* **Algorytm sekwencyjny:** Implementacja maszyny stanów (Finite State Machine), eliminująca błędy synchronizacji między transporterem a ramieniem.
* **Synchronizacja:** Wykorzystanie przerwań i pętli sprawdzających stan czujnika (polling) do natychmiastowego zatrzymania linii po wykryciu detalu.
* **Kalibracja:** Funkcja bazowania (homing) po uruchomieniu układu, zapewniająca bezpieczeństwo mechaniczne.

---

## 🔄 Algorytm Działania (Workflow)
1.  **IDLE/START:** Transporter uruchamia ruch taśmy do przodu.
2.  **DETEKCJA:** Obiekt przerywa wiązkę czujnika optycznego -> Sygnał HIGH do Arduino.
3.  **BRAKING:** Natychmiastowe zatrzymanie silnika transportera (pozycja detalu ustalona).
4.  **PICK:** Ramię przemieszcza się nad detal, opuszcza chwytak i następuje zaciśnięcie szczęk.
5.  **PLACE:** Przeniesienie detalu po wyznaczonej trajektorii na początek transportera.
6.  **RELEASE:** Zwolnienie chwytaka i powrót ramienia do pozycji bezpiecznej (Home).
7.  **REPEAT:** Ponowne uruchomienie taśmy (powrót do kroku 1).

---

## 📈 Potencjał Rozwojowy
* Implementacja **Inverse Kinematics (IK)** dla płynniejszych ruchów ramienia.
* Dodanie **czujnika koloru** do sortowania detali na różne strony transportera.
* Zastąpienie Arduino sterownikiem **PLC (np. S7-1200)** w celu zbliżenia projektu do standardów przemysłowych.

---
**Autor:** [Mateusz Papierski]
*Student Automatyki i Robotyki Politechniki Poznańskiej*
