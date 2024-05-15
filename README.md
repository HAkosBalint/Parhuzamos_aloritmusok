## Mérési Adatok

### Gauss-Jordan OpenMP

A mérések során a Gauss-Jordan OpenMP implementációval a következő eredményeket értük el:

- **1000x1000-es mátrix esetén:**
  - Szekvenciális: 1.736 másodperc
  - OpenMP: 0.302 másodperc

- **3000x3000-es mátrix esetén:**
  - Szekvenciális: 14.628 másodperc
  - OpenMP: 72.684 másodperc

A mérési adatok másodpercben vannak kifejezve. Az eredmények alapján megfigyelhető, hogy minél nagyobb a mátrix mérete, annál nagyobb a különbség a szekvenciális és OpenMP megközelítés között. Ez a párhuzamosítás hatékonyságát mutatja.

### Infinity-Norm Pthread/Python

Az Infinity-Norm számítása során a Pthread és Python megoldásokat is vizsgáltuk:

- **1000x1000-es mátrix esetén:**
  - Pthread: 0.004 másodperc
  - Python: 0.059 másodperc
  - PyPy: 0.302 másodperc

- **15500x15500-es mátrix esetén:**
  - Pthread: 0.922 másodperc
  - Python: 0.528 másodperc
  - PyPy: 72.684 másodperc

Az eredmények másodpercben vannak kifejezve. Megfigyelhető, hogy a Pthread megoldás jelentősen gyorsabb, mint a Python megoldás, különösen nagyobb méretű mátrixok esetén. A PyPy használata jelentős sebességnövekedést eredményez a Pythonhoz képest.

### Grafikonok

- **Gauss-Jordan OpenMP:** ![Gauss-Jordan OpenMP grafikon](gauss_jordan.jpg)
- **Infinity-Norm Pthread/Python:**
  - Kisebb méretű mérések: ![Kisebb méretű mérések grafikon](few_oc.jpg)
  - Nagyobb méretű mérések: ![Nagyobb méretű mérések grafikon](infnorm_oc.jpg)
  - Pythonban történő multithreading mérései: ![Pythonban történő multithreading grafikon](python_c.jpg)
  - PyPy fordítóval történő Python mérései: ![PyPy fordítóval történő grafikon](python_pypy.jpg)
