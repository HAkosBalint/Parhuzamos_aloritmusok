# FÉLÉVES FELADAT #

##-GAUSS-JORDAN OMP-##

- OpenMp: Gauss-Jordan elimináció egyenletrendszerek megoldására "nxm" es mátrix. 
- Szekvenciális és omp megoldások összehasonlítása: 
- Megfigyelhető, hogy minnél nagyobb a mátrix annál nagyobb gyorsítást érhetünk el párhuzamosítással.
- A grafikon gauss_jordan.jpg néven található meg. Az ehhez tartozó adatok a gaussjordan mappán belül data.csv néven található.

##-IFINITY-NORM PTHREAD/PYTHON-##

- Egy "nxn" es mátrix végtelen normájának kiszámítása szekvenciális és pthread felhasználásával valamint python multithreadinget használva.
- Kevés elemszámnál megfigyelhető hogy nem éri meg túl sok threadet létrehozni mivel ez időveszteséghez vezet, viszont minnél nagyobb a mátrix mérete annál hatékonyabb több szállal dolgozni. A kisebb elemű méréseket a "few_oc.jpg" tartalmazza, a nagyobb méretűeket pedig "infnorm_oc.jpg".
- A pythonban megvalósított multithreading nagyon lassúnak bizonyult, igen magas időkülömbségek jöttek ki. A grafikon a mérésekről: "python_c.jpg".
- Ellenben a pypy fordítót használva a c pthread-hez hasonló adatokat kapunk. Grafikon: "python_pypy".

##-A fileok a "feleves_feladat" mappában találhatóak meg. A mérési adatok a "Datas"-mappában találhatóak meg. Az "infinity_data.csv" az összes mért adatot, "python_data.csv" a pythonban és pypy-ban mért összehasonlítás.##

##-Pár mérési adat :##

    ##- Gauss Jordan:##
        1 1500 8.918000
        1 3000 75.267000

        0 1500 1.736000
        0 3000 14.628000
    
    ##- Infinitynorm:##
        0 1000 0.004000
        0 10000 0.394000
        0 15500 0.922000

        1 1000 0.3022737503051758
        1 10000 30.32253122329712
        1 15500 72.68398976325989

        4 1000 0.003000
        4 10000 0.117000
        4 15500 0.255000

    ##- Python#:#

        2 1000 0.05869603157043457
        2 10000 0.252208948135376
        2 15500 0.5282750129699707
