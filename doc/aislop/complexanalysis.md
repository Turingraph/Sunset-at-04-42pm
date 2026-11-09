The mathematical disciplines you're looking for are primarily Complex Analysis, Differential Geometry, and Dynamical Systems.

But there is another particularly relevant subject: Implicit Curves and Algebraic Geometry.

Your functions are interesting because they combine several mathematical operations:

- Complex polynomial transformations (`complex_x2`, `complex_x3`).
- Absolute-value reflections.
- Inequalities (`aura_inequality_amgm`, `aura_max`, `aura_pythagoras`).
- Periodic classification (`aura_custom_andmod`).

These operations interact to produce complicated geometric boundaries.

Here is the order I would recommend studying them.

## 1. Complex Analysis — most important starting point

This explains what happens when you transform coordinates using complex powers.

For example:

$$
f(z)=z^2,\qquad f(z)=z^3
$$

You will learn:

- Complex multiplication and powers.
- Polar representation of complex numbers.
- Conformal mappings.
- Critical points and branch behavior.
- How complex functions transform geometric shapes.

For your code, this is particularly important:

$$
z^n=r^ne^{in\theta}
$$

It explains why changing from `complex_x2` to `complex_x3` changes the angular structure of the resulting image.

## 2. Differential Geometry — understanding the curved shapes

This explains how mathematical transformations deform space.

Topics to study:

- Jacobian matrices.
- Local stretching and compression.
- Critical points.
- Coordinate transformations.
- Curvature of transformed curves.

For example, your cubic transformation has derivative:

$$
f'(z)=3z^2
$$

The derivative becomes zero at the origin, meaning the mapping has a critical point there.

This is relevant to understanding the concentration and deformation of your patterns.

## 3. Dynamical Systems and Fractal Geometry

This is where you investigate why certain patterns resemble Mandelbrot-like structures.

Study:

- Iterated function systems.
- Escape-time fractals.
- Julia sets.
- Mandelbrot sets.
- Self-similarity.
- Critical orbits.

One important distinction: your current functions are not necessarily fractals. They can produce complicated shapes without having genuine fractal self-similarity.

## 4. Algebraic Geometry and Implicit Curves

This is probably the most directly useful subject for explaining your particular code.

Your cubic transformation creates boundaries such as:

$$
x^3-3xy^2=k
$$

and

$$
3x^2y-y^3=k
$$

These are algebraic curves.

Your inequality functions select regions bounded by combinations of these curves.

Studying implicit equations will help you understand why the boundaries form branches, intersections, and lobes.

## 5. How these disciplines map to your functions

Your four families are actually useful mathematical experiments:

| Function | Transformation | Predicate | Mathematical concepts |
| --- | --- | --- | --- |
| Chainsawman | $z^2,z^3$ | AM-GM inequality | Complex analysis, inequalities |
| Disco | $z^2,z^3$ | Maximum | Piecewise functions, level sets |
| Hypnotize | $z^2,z^3$ | Pythagorean | Euclidean geometry, norm functions |
| Fractal | $z^2,z^3$ | Parity | Number theory, periodic functions |

Notice that you are independently varying two things:

1. The complex transformation.
2. The mathematical predicate applied afterward.

This is a great experimental setup for studying how different mathematical rules produce different geometries.

One caveat: I would need to see `aura_custom_bi()` and the implementations of `aura_inequality_amgm`, `aura_max`, and `aura_pythagoras` to derive the exact boundaries.

## 6. My recommended learning roadmap

Start herePhase 1 — Foundations

- Complex numbers
- Polar coordinates
- Complex multiplication and powers
- Polynomial functions

Phase 2 — Understanding the geometry

- Complex analysis
- Conformal mappings
- Jacobian matrices
- Critical points
- Implicit curves and level sets

Phase 3 — Understanding fractal-like behavior

- Dynamical systems
- Iterated functions
- Fractal geometry
- Julia sets and Mandelbrot sets

Phase 4 — Experimentation

- Numerical analysis
- Computational geometry
- Scientific visualization

## 7. Some particularly useful resources

- Visual Complex Analysis — Tristan Needham. Excellent for developing geometric intuition about complex functions.
- Complex Analysis — Stein and Shakarchi. More rigorous mathematical foundations.
- The Beauty of Fractals — Peitgen and Richter. Excellent visual exploration of fractal geometry.

My strongest recommendation: Start with Complex Analysis, then study Implicit Curves and Differential Geometry.

You don't need to learn all of fractal theory to understand your current functions.

In fact, I think a particularly interesting research question for your project would be:

How do polynomial complex mappings combined with nonlinear inequalities generate visually complex geometric structures?

That is a legitimate mathematical exploration, and you can investigate it systematically without implementing a single Mandelbrot iteration.
