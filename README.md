#  OrbitaLab — Solar System Simulator

A **real-time orbital mechanics simulator** built in C++ using the LIFAMI graphics library. The Sun, Mercury, Earth, and Moon orbit each other using **complex numbers** to model 2D rotations and transformations — a mathematically elegant approach to planetary motion.

---

##  Demo

The simulation runs automatically — no user interaction required. Close the window to exit.

Watch Mercury zip around the Sun while Earth moves more slowly, and the Moon traces its path around Earth — all updated every frame.

---

##  How It Works

### Mathematical Model

Orbital motion is modelled using **complex number multiplication** for rotation. A point rotated by angle θ is computed as:

```
new_position = center + (old_position - center) × e^(iθ)
```

This is implemented via the `rotate()` function using the custom `Complex` structure.

### Key Structures

```cpp
Complex       // 2D point/vector with overloaded operators (+, -, *, scalar)
SolarSystem   // positions of Sun, Mercury, Earth, Moon as Complex numbers
```

### Orbital Parameters (per frame)

| Body | Orbits | Angular Speed |
|---|---|---|
| Mercury | Sun | 0.001° |
| Earth | Sun | 0.0003° |
| Moon | Earth | (relative, faster) |

### Moon's Update Sequence
```
1. Compute Moon's local position relative to Earth
2. Update Earth's position around the Sun
3. Reposition Moon around Earth's new position
4. Apply Moon's own rotation around Earth
```

---

##  Build & Run

### Requirements
- C++ compiler (g++)
- [LIFAMI graphics library](https://perso.univ-lyon1.fr/thierry.excoffier/COURS/LIFAMI/)

### Compile
```bash
g++ -o orbitalab main.cpp -llifami
```

### Run
```bash
./orbitalab
```

---

##  Concepts Used

- Complex numbers for 2D rotation and transformation
- Operator overloading (`+`, `-`, `*`, scalar multiplication)
- Nested orbital mechanics (Moon orbiting Earth orbiting Sun)
- Trigonometric utilities (`to_deg`, `to_rad`, `make_complex_exp`)
- Homothety (`scale`) and rotation (`rotate`) functions

---

##  Visual Rendering

| Body | Color | Radius |
|---|---|---|
| Sun | Yellow | 10 px |
| Mercury | Red | 4 px |
| Earth | Blue | 5 px |
| Moon | White | 2 px |

Background: black (simulating space).

---

##  Project Structure

```
OrbitaLab/
├── src/
│   └── OrbitaLab.cpp            # Main source file
├── docs/
│   └── OrbitaLab.pdf         # Full project report (French)
└── OrbitaLab_README.md
```

---

## Academic Context

Developed as part of the **LIFAMI** course (C++ graphics programming) at **Université Claude Bernard Lyon 1** — Licence Mathématiques-Informatique, Year 1 (2025).
